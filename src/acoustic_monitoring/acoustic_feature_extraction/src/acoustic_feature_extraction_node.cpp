
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

    // Initialize Essentia
    void initializeEssentia() {
        try {
            essentia::init();
        } catch (const essentia::EssentiaException& e) {
            ROS_FATAL("Failed to initialize Essentia: %s", e.what());
            exit(1);
        }
    }

public:
    AcousticFeatureExtractor() {
        initializeEssentia();
        audio_feature_pub = nh.advertise<acoustic_monitoring_msgs::MsgAcousticFeature>("/acoustic_feature", 20);  // Initialize publisher
        audio_sub = nh.subscribe<acoustic_monitoring_msgs::AudioDataStamped>("/audioStamped", 20, &AcousticFeatureExtractor::audioDataCallback, this);

    }

    //destructor
    ~AcousticFeatureExtractor() {}
        

    std::map<std::string, Real> extract_time_domain_features(std::vector<essentia::Real> &audio_signal, int sample_rate, int frame_size = 512, int hop_size = 512) {
        std::map<std::string, Real> features;
        AlgorithmFactory& factory = AlgorithmFactory::instance();
        
        Algorithm* rms_algo = factory.create("RMS");
        Real rms_energy;
        rms_algo->input("array").set(audio_signal); // vector_real
        rms_algo->output("rms").set(rms_energy);
        rms_algo->compute();
        features["rms_energy"] = rms_energy;

        Algorithm* envelope_algo = factory.create("Envelope");
        std::vector<Real> amplitude_envelope;
        envelope_algo->input("signal").set(audio_signal); // vector_real
        envelope_algo->output("signal").set(amplitude_envelope);
        envelope_algo->compute();
        Real sum = std::accumulate(amplitude_envelope.begin(), amplitude_envelope.end(), 0.0);
        Real mean = sum / amplitude_envelope.size();
        Real sq_sum = std::inner_product(amplitude_envelope.begin(), amplitude_envelope.end(), amplitude_envelope.begin(), 0.0);
        Real std_dev = std::sqrt(sq_sum / amplitude_envelope.size() - mean * mean);
        features["amplitude_envelope_mean"] = mean;
        features["amplitude_envelope_std"] = std_dev;


        Algorithm* zcr_algo = factory.create("ZeroCrossingRate");
        Real zero_crossing_rate;
        zcr_algo->input("signal").set(audio_signal); // vector_real
        zcr_algo->output("zeroCrossingRate").set(zero_crossing_rate);
        zcr_algo->compute();
        features["zero_crossing_rate"] = zero_crossing_rate;

        Algorithm* dyn_algo = factory.create("DynamicComplexity", "frameSize", frame_size, "sampleRate", sample_rate);
        Real dynamic_complexity;
        Real loudness;
        dyn_algo->input("signal").set(audio_signal); // vector_real
        dyn_algo->output("dynamicComplexity").set(dynamic_complexity);
        dyn_algo->output("loudness").set(loudness);
        dyn_algo->compute();
        features["dynamic_complexity"] = dynamic_complexity;
        features["loudness"] = loudness;


        Algorithm* loudness_algo = factory.create("LoudnessVickers", "sampleRate", sample_rate);
        Real loudness_vickers;
        loudness_algo->input("signal").set(audio_signal); // vector_real
        loudness_algo->output("loudness").set(loudness_vickers);
        loudness_algo->compute();
        features["loudness_vickers"] = loudness_vickers;
        
        delete rms_algo;
        delete zcr_algo;
        delete dyn_algo;
        delete loudness_algo;
        return features;
    }

        
    std::map<std::string, essentia::Real> extract_spectral_features(std::vector<essentia::Real>& audio_signal, int sample_rate, int frame_size = 512, int hop_size = 512) {
        
        std::map<std::string, Real> features;
        // std::map<std::string, Real> scalar_features;
        // std::map<std::string, std::vector<Real>> vector_features;
        
        AlgorithmFactory& factory = AlgorithmFactory::instance();
        Algorithm* spectrum_algo = factory.create("Spectrum");
        Algorithm* centroid_algo = factory.create("SpectralCentroidTime", "sampleRate", sample_rate);
        Algorithm* complexity_algo = factory.create("SpectralComplexity", "sampleRate", sample_rate);
        Algorithm* contrast_algo = factory.create("SpectralContrast", "frameSize", frame_size, "highFrequencyBound", sample_rate / 2, "lowFrequencyBound", 200, "sampleRate", sample_rate);
        Algorithm* decrease_algo = factory.create("Decrease");
        Algorithm* energy_algo = factory.create("Energy");
        Algorithm* energy_band_ratio_algo = factory.create("EnergyBandRatio", "sampleRate", sample_rate, "stopFrequency", 7000);
        Algorithm* flatness_algo = factory.create("FlatnessDB");
        Algorithm* flux_algo = factory.create("Flux");
        Algorithm* rolloff_algo = factory.create("RollOff", "sampleRate", sample_rate);
        Algorithm* strong_peak_algo = factory.create("StrongPeak");
        Algorithm* central_moment_algo = factory.create("CentralMoments");
        Algorithm* distribution_shape_algo = factory.create("DistributionShape");
        Algorithm* crest_algo = factory.create("Crest");
        // Algorithm* mel_bands_algo = factory.create("MelBands");
        Algorithm* mfcc_algo = factory.create("MFCC", "highFrequencyBound", sample_rate / 2, "numberCoefficients", 13, "sampleRate", sample_rate); 
        
        std::vector<Real> frame(frame_size);
        
        for (size_t i = 0; i < audio_signal.size() - frame_size; i += hop_size) {
            std::copy(audio_signal.begin() + i, audio_signal.begin() + i + frame_size, frame.begin());
            
            std::vector<Real> spectrum;
            spectrum_algo->input("frame").set(frame);
            spectrum_algo->output("spectrum").set(spectrum);
            spectrum_algo->compute();
            
            Real spectral_centroid;
            centroid_algo->input("array").set(spectrum);
            centroid_algo->output("centroid").set(spectral_centroid);
            centroid_algo->compute();
            features["spectral_centroid"] = spectral_centroid;
            
            Real spectral_complexity;
            complexity_algo->input("spectrum").set(spectrum);
            complexity_algo->output("spectralComplexity").set(spectral_complexity);
            features["spectral_complexity"] = spectral_complexity;

            std::vector<Real> spectral_contrast, spectral_valley;
            contrast_algo->input("spectrum").set(spectrum);
            contrast_algo->output("spectralContrast").set(spectral_contrast);
            contrast_algo->output("spectralValley").set(spectral_valley);
            contrast_algo->compute();
            // features["spectral_contrast"] = spectral_contrast;
            // features["spectral_valley"] = spectral_valley;
            for (size_t i = 0; i < spectral_contrast.size(); ++i) {
                features["spectral_contrast_" + std::to_string(i)] = spectral_contrast[i];
                features["spectral_valley_" + std::to_string(i)] = spectral_valley[i];
            }

            Real spectral_decrease;
            decrease_algo->input("array").set(spectrum);
            decrease_algo->output("decrease").set(spectral_decrease);
            decrease_algo->compute();
            features["spectral_decrease"] = spectral_decrease;

            Real spectral_energy;
            energy_algo->input("array").set(spectrum);
            energy_algo->output("energy").set(spectral_energy);
            energy_algo->compute();
            features["spectral_energy"] = spectral_energy;

            Real spectral_energy_band_ratio;
            energy_band_ratio_algo->input("spectrum").set(spectrum);
            energy_band_ratio_algo->output("energyBandRatio").set(spectral_energy_band_ratio);
            energy_band_ratio_algo->compute();
            features["spectral_energy_band_ratio"] = spectral_energy_band_ratio;

            Real spectral_flatness;
            flatness_algo->input("array").set(spectrum);
            flatness_algo->output("flatnessDB").set(spectral_flatness);
            flatness_algo->compute();
            features["spectral_flatness"] = spectral_flatness;

            Real spectral_flux;
            flux_algo->input("spectrum").set(spectrum);
            flux_algo->output("flux").set(spectral_flux);
            flux_algo->compute();
            features["spectral_flux"] = spectral_flux;

            Real spectral_rolloff;
            rolloff_algo->input("spectrum").set(spectrum);
            rolloff_algo->output("rollOff").set(spectral_rolloff);
            rolloff_algo->compute();
            features["spectral_rolloff"] = spectral_rolloff;

            Real spectral_strong_peak;
            strong_peak_algo->input("spectrum").set(spectrum);
            strong_peak_algo->output("strongPeak").set(spectral_strong_peak);
            strong_peak_algo->compute();
            features["spectral_strong_peak"] = spectral_strong_peak;

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
            features["spectral_variance"] = variance;
            features["spectral_skewness"] = skewness;
            features["spectral_kurtosis"] = kurtosis;


            // Spectral Crest Factor
            Real crest_factor;
            crest_algo->input("array").set(spectrum);
            crest_algo->output("crest").set(crest_factor);
            crest_algo->compute();
            features["spectral_crest_factor"] = crest_factor;

            // MFCC
            std::vector<Real> mfcc_bands, mfcc_coeffs;
            mfcc_algo->input("spectrum").set(spectrum);
            mfcc_algo->output("bands").set(mfcc_bands);
            mfcc_algo->output("mfcc").set(mfcc_coeffs);
            mfcc_algo->compute();
            // features["mfcc_coeffs"] = mfcc_coeffs;
            for (size_t i = 0; i < mfcc_coeffs.size(); ++i) {
                features["mfcc_" + std::to_string(i)] = mfcc_coeffs[i];
            }

        }

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

        return features;
    }


    void audioDataCallback(const acoustic_monitoring_msgs::AudioDataStamped::ConstPtr& msg) {
        // Update the buffer with incoming audio data
        audio_buffer.insert(audio_buffer.end(), msg->data.begin(), msg->data.end());

        // Max buffer size to hold 99ms of audio data (4410 samples)
        size_t max_buffer_size = 4410;
        
        // Remove the oldest data if buffer size exceeds max_buffer_size
        while(audio_buffer.size() > max_buffer_size) {
            audio_buffer.pop_front();
        }

        // Convert std::deque to std::vector
        std::vector<essentia::Real> audio_vector(audio_buffer.begin(), audio_buffer.end());

        std::map<std::string, Real> time_features = extract_time_domain_features(audio_vector, 44100);  // or your sample rate
        std::map<std::string, Real> spectral_features = extract_spectral_features(audio_vector, 44100);  // or your sample rate

        // Create and populate the feature message
        acoustic_monitoring_msgs::MsgAcousticFeature feature_msg;
        feature_msg.header.stamp = ros::Time::now(); //.toSec();

        // Time-domain features
        feature_msg.rms_energy = time_features["rms_energy"];
        feature_msg.amplitude_envelope_mean = time_features["amplitude_envelope_mean"];
        feature_msg.amplitude_envelope_std = time_features["amplitude_envelope_std"];
        feature_msg.zero_crossing_rate = time_features["zero_crossing_rate"];
        feature_msg.dynamic_complexity = time_features["dynamic_complexity"];
        feature_msg.loudness = time_features["loudness"];
        feature_msg.loudness_vickers = time_features["loudness_vickers"];

        // Frequency-domain features
        feature_msg.spectral_centroid = spectral_features["spectral_centroid"];
        feature_msg.spectral_complexity = spectral_features["spectral_complexity"];
        // for (size_t i = 0; i < spectral_features["spectral_contrast"].size(); ++i) {
        //     feature_msg.spectral_contrast.push_back(spectral_features["spectral_contrast"][i]);
        //     feature_msg.spectral_valley.push_back(spectral_features["spectral_valley"][i]);
        // }
        feature_msg.spectral_contrast_0 = spectral_features["spectral_contrast_0"];
        feature_msg.spectral_contrast_1 = spectral_features["spectral_contrast_1"];
        feature_msg.spectral_contrast_2 = spectral_features["spectral_contrast_2"];
        feature_msg.spectral_contrast_3 = spectral_features["spectral_contrast_3"];
        feature_msg.spectral_contrast_4 = spectral_features["spectral_contrast_4"];
        feature_msg.spectral_contrast_5 = spectral_features["spectral_contrast_5"];

        feature_msg.spectral_valley_0 = spectral_features["spectral_valley_0"];
        feature_msg.spectral_valley_1 = spectral_features["spectral_valley_1"];
        feature_msg.spectral_valley_2 = spectral_features["spectral_valley_2"];
        feature_msg.spectral_valley_3 = spectral_features["spectral_valley_3"];
        feature_msg.spectral_valley_4 = spectral_features["spectral_valley_4"];
        feature_msg.spectral_valley_5 = spectral_features["spectral_valley_5"];

        feature_msg.spectral_decrease = spectral_features["spectral_decrease"];
        feature_msg.spectral_energy = spectral_features["spectral_energy"];
        feature_msg.spectral_energy_band_ratio = spectral_features["spectral_energy_band_ratio"];
        feature_msg.spectral_flatness = spectral_features["spectral_flatness"];
        feature_msg.spectral_flux = spectral_features["spectral_flux"];
        feature_msg.spectral_rolloff = spectral_features["spectral_rolloff"];
        feature_msg.spectral_strong_peak = spectral_features["spectral_strong_peak"];
        feature_msg.spectral_variance = spectral_features["spectral_variance"];
        feature_msg.spectral_skewness = spectral_features["spectral_skewness"];
        feature_msg.spectral_kurtosis = spectral_features["spectral_kurtosis"];
        feature_msg.spectral_crest_factor = spectral_features["spectral_crest_factor"];
        // for (size_t i = 0; i < spectral_features["mfcc_coeffs"].size(); ++i) {
        //     feature_msg.mfcc_coeffs.push_back(spectral_features["mfcc_coeffs"][i]);
        // }
        feature_msg.mfcc_0 = spectral_features["mfcc_0"];
        feature_msg.mfcc_1 = spectral_features["mfcc_1"];
        feature_msg.mfcc_2 = spectral_features["mfcc_2"];
        feature_msg.mfcc_3 = spectral_features["mfcc_3"];
        feature_msg.mfcc_4 = spectral_features["mfcc_4"];
        feature_msg.mfcc_5 = spectral_features["mfcc_5"];
        feature_msg.mfcc_6 = spectral_features["mfcc_6"];
        feature_msg.mfcc_7 = spectral_features["mfcc_7"];
        feature_msg.mfcc_8 = spectral_features["mfcc_8"];
        feature_msg.mfcc_9 = spectral_features["mfcc_9"];
        feature_msg.mfcc_10 = spectral_features["mfcc_10"];
        feature_msg.mfcc_11 = spectral_features["mfcc_11"];
        feature_msg.mfcc_12 = spectral_features["mfcc_12"];
    
        // Publish the message
        audio_feature_pub.publish(feature_msg);
    }
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "acoustic_feature_extraction_node");

    AcousticFeatureExtractor extractor;
    ros::spin();

    // ros::Rate loop_rate(100); 
    // While (ros::ok()) {
    //     extractor.extractFeatures();
    //     ros::spinOnce();
    //     loop_rate.sleep();
    // }

    return 0;
}
