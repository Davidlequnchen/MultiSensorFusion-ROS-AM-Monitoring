
#include <ros/ros.h>
#include <map>
#include <vector>
#include <string>
#include <acoustic_monitoring_msgs/AudioDataStamped.h>
#include <acoustic_monitoring_msgs/MsgAcousticFeature.h>
#include <essentia/essentiamath.h>
#include <essentia/algorithmfactory.h>
#include <deque>
#include <variant>

using namespace essentia;
using namespace essentia::standard;
using namespace std;

class AcousticFeatureExtractor {
private:
    deque<Real> audio_buffer;
    ros::NodeHandle nh;
    ros::Subscriber audio_sub;
    ros::Publisher audio_feature_pub;

    // Parameters
    int frame_size;
    int hop_length;
    int sample_rate;
    int buffer_duration;
    int max_buffer_size_int;
    size_t max_buffer_size;

    // Essentia algorithm objects
    AlgorithmFactory& factory;
    Algorithm* rms_algo;
    Algorithm* envelope_algo;
    Algorithm* zcr_algo;
    Algorithm* dyn_algo;
    Algorithm* loudness_algo;

    Algorithm* spectrum_algo;
    Algorithm* centroid_algo;
    Algorithm* complexity_algo;
    Algorithm* contrast_algo;
    Algorithm* decrease_algo;
    Algorithm* energy_algo;
    Algorithm* energy_band_ratio_algo;
    Algorithm* flatness_algo;
    Algorithm* flux_algo;
    Algorithm* rolloff_algo;
    Algorithm* strong_peak_algo;
    Algorithm* central_moment_algo;
    Algorithm* distribution_shape_algo;
    Algorithm* crest_algo;
    Algorithm* mfcc_algo;


public:
    AcousticFeatureExtractor(): factory(AlgorithmFactory::instance()){
        audio_feature_pub = nh.advertise<acoustic_monitoring_msgs::MsgAcousticFeature>("/acoustic_feature", 100);  // Initialize publisher
        audio_sub = nh.subscribe<acoustic_monitoring_msgs::AudioDataStamped>("/audioStamped", 100, &AcousticFeatureExtractor::audioDataCallback, this);
        
        // Fetch the parameters
        // ros::param::get("~buffer_size", buffer_duration, 100); //100 ms
        // ros::param::get("~sample_rate", sample_rate, 44100);
        // ros::param::get("~hop_length", hop_length, 512);
        // ros::param::get("~frame_size", frame_size, 1024);

        ros::param::param<int>("~frame_size", frame_size, 1024);
        ros::param::param<int>("~hop_length", hop_length, 512);
        ros::param::param<int>("~sample_rate", sample_rate, 44100);
        ros::param::param<int>("~buffer_size", buffer_duration, 100);  // Duration in milliseconds

        max_buffer_size = static_cast<size_t>(buffer_duration * 0.001 * sample_rate);
        max_buffer_size_int = static_cast<int>(buffer_duration * 0.001 * sample_rate);

        // Initialize the deque with a maximum size
        audio_buffer = std::deque<essentia::Real>(max_buffer_size);

        // Initialize Essentia algorithm objects
        rms_algo = factory.create("RMS");
        envelope_algo = factory.create("Envelope");
        zcr_algo = factory.create("ZeroCrossingRate");
        dyn_algo = factory.create("DynamicComplexity", "sampleRate", sample_rate);
        loudness_algo = factory.create("LoudnessVickers", "sampleRate", sample_rate);

        spectrum_algo = factory.create("Spectrum");
        centroid_algo = factory.create("SpectralCentroidTime", "sampleRate", sample_rate);
        complexity_algo = factory.create("SpectralComplexity", "sampleRate", sample_rate);
        contrast_algo = factory.create("SpectralContrast", "frameSize", max_buffer_size_int, "highFrequencyBound", sample_rate / 2, "lowFrequencyBound", 200, "sampleRate", sample_rate);
        decrease_algo = factory.create("Decrease");
        energy_algo = factory.create("Energy");
        energy_band_ratio_algo = factory.create("EnergyBandRatio", "sampleRate", sample_rate, "stopFrequency", 7000);
        flatness_algo = factory.create("FlatnessDB");
        flux_algo = factory.create("Flux");
        rolloff_algo = factory.create("RollOff", "sampleRate", sample_rate);
        strong_peak_algo = factory.create("StrongPeak");
        central_moment_algo = factory.create("CentralMoments");
        distribution_shape_algo = factory.create("DistributionShape");
        crest_algo = factory.create("Crest");
        // mel_bands_algo = factory.create("MelBands");
        mfcc_algo = factory.create("MFCC", "highFrequencyBound", sample_rate / 2, "numberCoefficients", 13, "sampleRate", sample_rate); 
        
    }

    //destructor
    ~AcousticFeatureExtractor() {
        delete rms_algo;
        delete zcr_algo;
        delete dyn_algo;
        delete loudness_algo;

        delete spectrum_algo;
        delete centroid_algo;
        delete complexity_algo;
        delete contrast_algo;
        delete decrease_algo;
        delete energy_algo;
        delete energy_band_ratio_algo;
        delete flatness_algo;
        delete flux_algo;
        delete rolloff_algo;
        delete strong_peak_algo;
        delete central_moment_algo;
        delete distribution_shape_algo;
        delete crest_algo;
        // delete mel_bands_algo;
        delete mfcc_algo;
    }
        

    std::vector<float> extract_time_domain_features(std::vector<essentia::Real> &audio_signal, int sample_rate, int frame_size = 512, int hop_size = 512) {
        std::vector<float> features;
        // AlgorithmFactory& factory = AlgorithmFactory::instance();
        
        Real rms_energy;
        rms_algo->input("array").set(audio_signal); // vector_real
        rms_algo->output("rms").set(rms_energy);
        rms_algo->compute();
        features.push_back(rms_energy);

        std::vector<Real> amplitude_envelope;
        envelope_algo->input("signal").set(audio_signal); // vector_real
        envelope_algo->output("signal").set(amplitude_envelope);
        envelope_algo->compute();
        Real sum = std::accumulate(amplitude_envelope.begin(), amplitude_envelope.end(), 0.0);
        Real mean = sum / amplitude_envelope.size();
        Real sq_sum = std::inner_product(amplitude_envelope.begin(), amplitude_envelope.end(), amplitude_envelope.begin(), 0.0);
        Real std_dev = std::sqrt(sq_sum / amplitude_envelope.size() - mean * mean);
        features.push_back(mean);
        features.push_back(std_dev);
        

        Real zero_crossing_rate;
        zcr_algo->input("signal").set(audio_signal); // vector_real
        zcr_algo->output("zeroCrossingRate").set(zero_crossing_rate);
        zcr_algo->compute();
        features.push_back(zero_crossing_rate);

        Real dynamic_complexity;
        Real loudness;
        dyn_algo->input("signal").set(audio_signal); // vector_real
        dyn_algo->output("dynamicComplexity").set(dynamic_complexity);
        dyn_algo->output("loudness").set(loudness);
        dyn_algo->compute();
        features.push_back(dynamic_complexity);
        features.push_back(loudness);

        Real loudness_vickers;
        loudness_algo->input("signal").set(audio_signal); // vector_real
        loudness_algo->output("loudness").set(loudness_vickers);
        loudness_algo->compute();
        features.push_back(loudness_vickers);
        
        return features;
    }

        
    std::vector<float> extract_spectral_features(std::vector<essentia::Real>& audio_signal, int sample_rate, int frame_size = 512, int hop_size = 512) {
        
        std::vector<float> features;

        if (audio_signal.size() % 2 != 0) {
            audio_signal.push_back(0);  // Pad with zero
        }

        std::vector<Real> spectrum;
        spectrum_algo->input("frame").set(audio_signal);
        spectrum_algo->output("spectrum").set(spectrum);
        spectrum_algo->compute();
        
        Real spectral_centroid;
        centroid_algo->input("array").set(spectrum);
        centroid_algo->output("centroid").set(spectral_centroid);
        centroid_algo->compute();
        features.push_back(spectral_centroid);
        
        Real spectral_complexity;
        complexity_algo->input("spectrum").set(spectrum);
        complexity_algo->output("spectralComplexity").set(spectral_complexity);
        features.push_back(spectral_complexity);

        // Currently spectral_contrast, spectral_valley still got problems
        std::vector<Real> spectral_contrast, spectral_valley;
        contrast_algo->input("spectrum").set(spectrum);
        contrast_algo->output("spectralContrast").set(spectral_contrast);
        contrast_algo->output("spectralValley").set(spectral_valley);
        contrast_algo->compute();

        // features["spectral_contrast"] = spectral_contrast;
        // features["spectral_valley"] = spectral_valley;
        for (size_t i = 0; i < spectral_contrast.size(); ++i) {
            features.push_back(spectral_contrast[i]);
        }
        for (size_t i = 0; i < spectral_valley.size(); ++i) {
            features.push_back(spectral_valley[i]);
        }

        Real spectral_decrease;
        decrease_algo->input("array").set(spectrum);
        decrease_algo->output("decrease").set(spectral_decrease);
        decrease_algo->compute();
        features.push_back(spectral_decrease);

        Real spectral_energy;
        energy_algo->input("array").set(spectrum);
        energy_algo->output("energy").set(spectral_energy);
        energy_algo->compute();
        features.push_back(spectral_energy);
        

        Real spectral_energy_band_ratio;
        energy_band_ratio_algo->input("spectrum").set(spectrum);
        energy_band_ratio_algo->output("energyBandRatio").set(spectral_energy_band_ratio);
        energy_band_ratio_algo->compute();
        features.push_back(spectral_energy_band_ratio);

        Real spectral_flatness;
        flatness_algo->input("array").set(spectrum);
        flatness_algo->output("flatnessDB").set(spectral_flatness);
        flatness_algo->compute();
        features.push_back(spectral_flatness);

        Real spectral_flux;
        flux_algo->input("spectrum").set(spectrum);
        flux_algo->output("flux").set(spectral_flux);
        flux_algo->compute();
        features.push_back(spectral_flux);

        Real spectral_rolloff;
        rolloff_algo->input("spectrum").set(spectrum);
        rolloff_algo->output("rollOff").set(spectral_rolloff);
        rolloff_algo->compute();
        features.push_back(spectral_rolloff);

        Real spectral_strong_peak;
        strong_peak_algo->input("spectrum").set(spectrum);
        strong_peak_algo->output("strongPeak").set(spectral_strong_peak);
        strong_peak_algo->compute();
        features.push_back(spectral_strong_peak);

        // Central Moments
        std::vector<Real> central_moments;
        central_moment_algo->input("array").set(spectrum);
        central_moment_algo->output("centralMoments").set(central_moments);
        central_moment_algo->compute();

        // Distribution Shape
        Real variance, skewness, kurtosis;
        distribution_shape_algo->input("centralMoments").set(central_moments);
        distribution_shape_algo->output("spread").set(variance);
        distribution_shape_algo->output("skewness").set(skewness);
        distribution_shape_algo->output("kurtosis").set(kurtosis);
        distribution_shape_algo->compute();
        features.push_back(variance);
        features.push_back(skewness);
        features.push_back(kurtosis);

        // Spectral Crest Factor
        Real crest_factor;
        crest_algo->input("array").set(spectrum);
        crest_algo->output("crest").set(crest_factor);
        crest_algo->compute();
        features.push_back(crest_factor);

        // MFCC
        std::vector<Real> mfcc_bands, mfcc_coeffs;
        mfcc_algo->input("spectrum").set(spectrum);
        mfcc_algo->output("bands").set(mfcc_bands);
        mfcc_algo->output("mfcc").set(mfcc_coeffs);
        mfcc_algo->compute();
        // features["mfcc_coeffs"] = mfcc_coeffs;
        for (size_t i = 0; i < mfcc_coeffs.size(); ++i) {
            features.push_back(mfcc_coeffs[i]);
        }
            
        // }

        return features;
    }


    void audioDataCallback(const acoustic_monitoring_msgs::AudioDataStamped::ConstPtr& msg) {
        try {
                //---------------method 1 (with buffer) -----------------------------
                int nbits = 16;
                double scale_factor = std::pow(2, nbits - 1);
                const std::vector<uint8_t>& audio_data = msg->data;

                // std::vector<essentia::Real> audio_data_scaled;
                std::vector<double> audio_data_scaled;
                audio_data_scaled.reserve(audio_data.size() / 2); // Pre-allocate memory
                for (size_t i = 0; i < audio_data.size(); i += 2) {
                    int16_t sample = static_cast<int16_t>(audio_data[i] | (audio_data[i + 1] << 8));
                    essentia::Real scaled_sample = static_cast<essentia::Real>(sample) / scale_factor;
                    audio_data_scaled.push_back(scaled_sample);
                }

                audio_buffer.insert(audio_buffer.end(), audio_data_scaled.begin(), audio_data_scaled.end());

                size_t elements_to_remove = 0;
                if (audio_buffer.size() > max_buffer_size) {
                    elements_to_remove = audio_buffer.size() - max_buffer_size;
                    if (elements_to_remove < audio_buffer.size()) {
                        audio_buffer.erase(audio_buffer.begin(), audio_buffer.begin() + elements_to_remove);
                    } else {
                        std::cerr << "Error: elements_to_remove exceeds buffer size." << std::endl;
                    }
                }

                std::vector<essentia::Real> audio_vector(audio_buffer.begin(), audio_buffer.end());

                if (audio_vector.size() < max_buffer_size) {
                    audio_vector.resize(max_buffer_size, 0.0);
                }

                
                //===========================================================================

                // // --------------Method 2 (without buffer) ------------------------------
                // // Copy the uint8 data into a std::vector<uint8_t>
                // int nbits = 16;
                // double scale_factor = std::pow(2, nbits - 1);
                // const std::vector<uint8_t>& audio_data = msg->data; // msg->data is std::vector<uint8_t>
                
                // // Convert the audio data to a std::vector of int16_t and scale it
                // std::vector<double> audio_data_scaled;
                // for (size_t i = 0; i < audio_data.size(); i += 2) {
                //     int16_t sample = static_cast<int16_t>(audio_data[i] | (audio_data[i + 1] << 8));
                //     double scaled_sample = static_cast<double>(sample) / scale_factor;
                //     audio_data_scaled.push_back(scaled_sample);
                // }

                // // Convert std::deque to std::vector
                // std::vector<essentia::Real> audio_vector(audio_data_scaled.begin(), audio_data_scaled.end());

                //===========================================================================

                std::vector<float> time_features = extract_time_domain_features(audio_vector, 44100, this->frame_size, this->hop_length);  
                std::vector<float> spectral_features = extract_spectral_features(audio_vector, 44100, this->frame_size, this->hop_length);  

                // Create and populate the feature message
                acoustic_monitoring_msgs::MsgAcousticFeature feature_msg;
                feature_msg.header.stamp = ros::Time::now(); //.toSec();

                // Time-domain features
                feature_msg.rms_energy = time_features[0];
                feature_msg.amplitude_envelope_mean = time_features[1];
                feature_msg.amplitude_envelope_std = time_features[2];
                feature_msg.zero_crossing_rate = time_features[3];
                feature_msg.dynamic_complexity = time_features[4];
                feature_msg.loudness = time_features[5];
                feature_msg.loudness_vickers = time_features[6];

                // Frequency-domain features
                feature_msg.spectral_centroid = spectral_features[0];
                feature_msg.spectral_complexity = spectral_features[1];
                // for (size_t i = 0; i < spectral_features["spectral_contrast"].size(); ++i) {
                //     feature_msg.spectral_contrast.push_back(spectral_features["spectral_contrast"][i]);
                //     feature_msg.spectral_valley.push_back(spectral_features["spectral_valley"][i]);
                // }
                feature_msg.spectral_contrast_0 = spectral_features[2];
                feature_msg.spectral_contrast_1 = spectral_features[3];
                feature_msg.spectral_contrast_2 = spectral_features[4];
                feature_msg.spectral_contrast_3 = spectral_features[5];
                feature_msg.spectral_contrast_4 = spectral_features[6];
                feature_msg.spectral_contrast_5 = spectral_features[7];

                feature_msg.spectral_valley_0 = spectral_features[8];
                feature_msg.spectral_valley_1 = spectral_features[9];
                feature_msg.spectral_valley_2 = spectral_features[10];
                feature_msg.spectral_valley_3 = spectral_features[11];
                feature_msg.spectral_valley_4 = spectral_features[12];
                feature_msg.spectral_valley_5 = spectral_features[13];

                feature_msg.spectral_decrease = spectral_features[14];
                feature_msg.spectral_energy = spectral_features[15];
                feature_msg.spectral_energy_band_ratio = spectral_features[16];
                feature_msg.spectral_flatness = spectral_features[17];
                feature_msg.spectral_flux = spectral_features[18];
                feature_msg.spectral_rolloff = spectral_features[19];
                feature_msg.spectral_strong_peak = spectral_features[20];
                feature_msg.spectral_variance = spectral_features[21];
                feature_msg.spectral_skewness = spectral_features[22];
                feature_msg.spectral_kurtosis = spectral_features[23];
                feature_msg.spectral_crest_factor = spectral_features[24];
                // // for (size_t i = 0; i < spectral_features["mfcc_coeffs"].size(); ++i) {
                // //     feature_msg.mfcc_coeffs.push_back(spectral_features["mfcc_coeffs"][i]);
                // // }
                feature_msg.mfcc_0 = spectral_features[25];
                feature_msg.mfcc_1 = spectral_features[26];
                feature_msg.mfcc_2 = spectral_features[27];
                feature_msg.mfcc_3 = spectral_features[28];
                feature_msg.mfcc_4 = spectral_features[29];
                feature_msg.mfcc_5 = spectral_features[30];
                feature_msg.mfcc_6 = spectral_features[31];
                feature_msg.mfcc_7 = spectral_features[32];
                feature_msg.mfcc_8 = spectral_features[33];
                feature_msg.mfcc_9 = spectral_features[34];
                feature_msg.mfcc_10 = spectral_features[35];
                feature_msg.mfcc_11 = spectral_features[36];
                feature_msg.mfcc_12 = spectral_features[37];
            
                // Publish the message
                audio_feature_pub.publish(feature_msg);
       


        } catch (const std::exception& e) {
            ROS_ERROR("Exception caught: %s", e.what());
        } catch (...) {
            ROS_ERROR("Unknown exception caught");
        }

    }
        
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "acoustic_feature_extraction_node");

    // Initialize Essentia
    try {
        essentia::init();
    } catch (const essentia::EssentiaException& e) {
        ROS_FATAL("Failed to initialize Essentia: %s", e.what());
        return 1;
    }

    AcousticFeatureExtractor extractor;
    
    ros::spin();
    // ros::AsyncSpinner spinner(6);  // Use 4 threads
    // spinner.start();
    // ros::waitForShutdown();

    // ros::Rate loop_rate(100); 
    // While (ros::ok()) {
    //     extractor.extractFeatures();
    //     ros::spinOnce();
    //     loop_rate.sleep();
    // }

    return 0;
}
