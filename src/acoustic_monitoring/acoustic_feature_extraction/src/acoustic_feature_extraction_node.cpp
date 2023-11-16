
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

// Define a function to calculate mean
float calculate_mean(const std::vector<float>& v) {
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

// Define a function to calculate standard deviation
float calculate_std(const std::vector<float>& v, float mean) {
    float sum = 0.0;
    for (auto& num : v) {
        sum += (num - mean) * (num - mean);
    }
    return std::sqrt(sum / v.size());
}


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
    Algorithm* frame_cutter_algo;


public:
    AcousticFeatureExtractor(): factory(AlgorithmFactory::instance()){
        audio_feature_pub = nh.advertise<acoustic_monitoring_msgs::MsgAcousticFeature>("/acoustic_feature", 100);  // Initialize publisher
        audio_sub = nh.subscribe<acoustic_monitoring_msgs::AudioDataStamped>("/audioStamped", 100, &AcousticFeatureExtractor::audioDataCallback, this);
        
        // Fetch the parameters
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
        contrast_algo = factory.create("SpectralContrast", "frameSize", frame_size, "highFrequencyBound", sample_rate / 2, "lowFrequencyBound", 200, "sampleRate", sample_rate);
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
        mfcc_algo = factory.create("MFCC", "inputSize", hop_length+1, "highFrequencyBound", sample_rate / 2, "numberCoefficients", 13, "sampleRate", sample_rate); 
        frame_cutter_algo = factory.create("FrameCutter", "frameSize", frame_size, "hopSize", hop_length);
        
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
        delete frame_cutter_algo;
    }
        

    std::vector<float> extract_time_domain_features(std::vector<essentia::Real> &audio_signal, int sample_rate, int frame_size = 512, int hop_size = 512) {
        std::vector<float> features;
        
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

    /* 
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

    */

    std::vector<float> extract_spectral_features(std::vector<Real>& audio_signal, int sample_rate, int frame_size = 512, int hop_size = 512) 
    {
        try {

            std::vector<float> features; // returned features with mean and std
            std::vector<std::vector<Real>> feature_frames; // For storing feature values for each frame
            // if (audio_signal.size() % 2 != 0) {
            //     audio_signal.push_back(0);  // Pad with zero
            // }

            // Connect input and output
            vector<Real> frame;
            frame_cutter_algo->input("signal").set(audio_signal);
            frame_cutter_algo->output("frame").set(frame);

            int max_iterations = 10;  // Replace with a reasonable value for your case
            int iterations = 0;

            // Loop through frames, similar to es.FrameGenerator in Python
            while (true) {
                frame_cutter_algo->compute();

                // Debugging
                ROS_INFO("Inside the loop: Iteration %d", iterations);

                // Break the loop if we got an empty frame (end of audio signal)
                if (frame.empty()) {
                    ROS_INFO("Breaking due to empty frame.");
                    break;
                }

                iterations++;
                if (iterations >= max_iterations) {
                    ROS_INFO("Breaking due to max iterations.");
                    break;
                }

                std::vector<Real> current_frame_features;

                std::vector<Real> spectrum;
                spectrum_algo->input("frame").set(frame);
                spectrum_algo->output("spectrum").set(spectrum);
                spectrum_algo->compute();
                
                Real spectral_centroid;
                centroid_algo->input("array").set(spectrum);
                centroid_algo->output("centroid").set(spectral_centroid);
                centroid_algo->compute();
                current_frame_features.push_back(spectral_centroid);
                
                Real spectral_complexity;
                complexity_algo->input("spectrum").set(spectrum);
                complexity_algo->output("spectralComplexity").set(spectral_complexity);
                complexity_algo->compute();
                current_frame_features.push_back(spectral_complexity);

                std::vector<Real> spectral_contrast, spectral_valley;
                contrast_algo->input("spectrum").set(spectrum);
                contrast_algo->output("spectralContrast").set(spectral_contrast);
                contrast_algo->output("spectralValley").set(spectral_valley);
                contrast_algo->compute();

                for (size_t i = 0; i < spectral_contrast.size(); ++i) {
                    current_frame_features.push_back(spectral_contrast[i]);
                }
                for (size_t i = 0; i < spectral_valley.size(); ++i) {
                    current_frame_features.push_back(spectral_valley[i]);
                }

                Real spectral_decrease;
                decrease_algo->input("array").set(spectrum);
                decrease_algo->output("decrease").set(spectral_decrease);
                decrease_algo->compute();
                current_frame_features.push_back(spectral_decrease);

                Real spectral_energy;
                energy_algo->input("array").set(spectrum);
                energy_algo->output("energy").set(spectral_energy);
                energy_algo->compute();
                current_frame_features.push_back(spectral_energy);
                

                Real spectral_energy_band_ratio;
                energy_band_ratio_algo->input("spectrum").set(spectrum);
                energy_band_ratio_algo->output("energyBandRatio").set(spectral_energy_band_ratio);
                energy_band_ratio_algo->compute();
                current_frame_features.push_back(spectral_energy_band_ratio);

                Real spectral_flatness;
                flatness_algo->input("array").set(spectrum);
                flatness_algo->output("flatnessDB").set(spectral_flatness);
                flatness_algo->compute();
                current_frame_features.push_back(spectral_flatness);

                Real spectral_flux;
                flux_algo->input("spectrum").set(spectrum);
                flux_algo->output("flux").set(spectral_flux);
                flux_algo->compute();
                current_frame_features.push_back(spectral_flux);

                Real spectral_rolloff;
                rolloff_algo->input("spectrum").set(spectrum);
                rolloff_algo->output("rollOff").set(spectral_rolloff);
                rolloff_algo->compute();
                current_frame_features.push_back(spectral_rolloff);

                Real spectral_strong_peak;
                strong_peak_algo->input("spectrum").set(spectrum);
                strong_peak_algo->output("strongPeak").set(spectral_strong_peak);
                strong_peak_algo->compute();
                current_frame_features.push_back(spectral_strong_peak);

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
                current_frame_features.push_back(variance);
                current_frame_features.push_back(skewness);
                current_frame_features.push_back(kurtosis);

                // Spectral Crest Factor
                Real crest_factor;
                crest_algo->input("array").set(spectrum);
                crest_algo->output("crest").set(crest_factor);
                crest_algo->compute();
                current_frame_features.push_back(crest_factor);

                // MFCC
                std::vector<Real> mfcc_bands, mfcc_coeffs;
                mfcc_algo->input("spectrum").set(spectrum);
                mfcc_algo->output("bands").set(mfcc_bands);
                mfcc_algo->output("mfcc").set(mfcc_coeffs);
                mfcc_algo->compute();
                // current_frame_features["mfcc_coeffs"] = mfcc_coeffs;
                for (size_t i = 0; i < mfcc_coeffs.size(); ++i) {
                    current_frame_features.push_back(mfcc_coeffs[i]);
                }

                feature_frames.push_back(current_frame_features);
                
            }

            //===========================================================================
            // // --------------Method 1 (without checking error) ------------------------------
            // Calculate mean and std for each feature
            // feature_frames[0].size() gives us the number of features from a single frame.
            // total number of frames that have been processed.
            // for (size_t i = 0; i < feature_frames[0].size(); ++i) {
            //     std::vector<float> feature_values_for_all_frames;

            //     for (size_t j = 0; j < feature_frames.size(); ++j) {
            //         feature_values_for_all_frames.push_back(feature_frames[j][i]);
            //     }

            //     // float mean = calculate_mean(feature_values_for_all_frames);
            //     // float std = calculate_std(feature_values_for_all_frames, mean);
            //     float mean = 1;
            //     float std = 1;

            //     features.push_back(mean);
            //     features.push_back(std);
            // }

            // return features;

            // //-----------------method 2--------------
            // Calculate mean and std for each feature
            if (!feature_frames.empty() && !feature_frames[0].empty()) {
                for (size_t i = 0; i < feature_frames[0].size(); ++i) {
                    std::vector<float> feature_values_for_all_frames;

                    for (size_t j = 0; j < feature_frames.size(); ++j) {
                        if (i < feature_frames[j].size()) {
                            feature_values_for_all_frames.push_back(feature_frames[j][i]);
                        }
                    }

                    if (!feature_values_for_all_frames.empty()) {
                        float mean = calculate_mean(feature_values_for_all_frames);
                        float std = calculate_std(feature_values_for_all_frames, mean);

                        features.push_back(mean);
                        features.push_back(std);
                    }
                }
            } 
            else {
                // Handle the case where feature_frames is empty or feature_frames[0] is empty
                std::cerr << "Feature frames are empty, cannot calculate mean or std.";
            }

            frame_cutter_algo->reset();

            return features;

        }catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
            return std::vector<float>();
        }
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
                // feature_msg.header.stamp = ros::Time::now(); //.toSec();
                feature_msg.header = msg->header;

                // Time-domain features
                feature_msg.rms_energy = time_features[0];
                feature_msg.amplitude_envelope_mean = time_features[1];
                feature_msg.amplitude_envelope_std = time_features[2];
                feature_msg.zero_crossing_rate = time_features[3];
                feature_msg.dynamic_complexity = time_features[4];
                feature_msg.loudness = time_features[5];
                feature_msg.loudness_vickers = time_features[6];

                // Frequency-domain features
                feature_msg.spectral_centroid_mean = spectral_features[0];
                feature_msg.spectral_centroid_std = spectral_features[1];
                feature_msg.spectral_complexity_mean = spectral_features[2];
                feature_msg.spectral_complexity_std = spectral_features[3];
                feature_msg.spectral_contrast_0_mean = spectral_features[4];
                feature_msg.spectral_contrast_0_std = spectral_features[5];
                feature_msg.spectral_contrast_1_mean = spectral_features[6];
                feature_msg.spectral_contrast_1_std = spectral_features[7];
                feature_msg.spectral_contrast_2_mean = spectral_features[8];
                feature_msg.spectral_contrast_2_std = spectral_features[9];
                feature_msg.spectral_contrast_3_mean = spectral_features[10];
                feature_msg.spectral_contrast_3_std = spectral_features[11];
                feature_msg.spectral_contrast_4_mean = spectral_features[12];
                feature_msg.spectral_contrast_4_std = spectral_features[13];
                feature_msg.spectral_contrast_5_mean = spectral_features[14];
                feature_msg.spectral_contrast_5_std = spectral_features[15];

                feature_msg.spectral_valley_0_mean = spectral_features[16];
                feature_msg.spectral_valley_0_std = spectral_features[17];
                feature_msg.spectral_valley_1_mean = spectral_features[18];
                feature_msg.spectral_valley_1_std = spectral_features[19];
                feature_msg.spectral_valley_2_mean = spectral_features[20];
                feature_msg.spectral_valley_2_std = spectral_features[21];
                feature_msg.spectral_valley_3_mean = spectral_features[22];
                feature_msg.spectral_valley_3_std = spectral_features[23];
                feature_msg.spectral_valley_4_mean = spectral_features[24];
                feature_msg.spectral_valley_4_std = spectral_features[25];
                feature_msg.spectral_valley_5_mean = spectral_features[26];
                feature_msg.spectral_valley_5_std = spectral_features[27];

                feature_msg.spectral_decrease_mean = spectral_features[28];
                feature_msg.spectral_decrease_std = spectral_features[29];
                feature_msg.spectral_energy_mean = spectral_features[30];
                feature_msg.spectral_energy_std = spectral_features[31];
                feature_msg.spectral_energy_band_ratio_mean = spectral_features[32];
                feature_msg.spectral_energy_band_ratio_std = spectral_features[33];
                feature_msg.spectral_flatness_mean = spectral_features[34];
                feature_msg.spectral_flatness_std = spectral_features[35];
                feature_msg.spectral_flux_mean = spectral_features[36];
                feature_msg.spectral_flux_std = spectral_features[37];
                feature_msg.spectral_rolloff_mean = spectral_features[38];
                feature_msg.spectral_rolloff_std = spectral_features[39];
                feature_msg.spectral_strong_peak_mean = spectral_features[40];
                feature_msg.spectral_strong_peak_std = spectral_features[41];
                feature_msg.spectral_variance_mean = spectral_features[42];
                feature_msg.spectral_variance_std = spectral_features[43];
                feature_msg.spectral_skewness_mean = spectral_features[44];
                feature_msg.spectral_skewness_std = spectral_features[45];
                feature_msg.spectral_kurtosis_mean = spectral_features[46];
                feature_msg.spectral_kurtosis_std = spectral_features[47];
                feature_msg.spectral_crest_factor_mean = spectral_features[48];
                feature_msg.spectral_crest_factor_std = spectral_features[49];
                feature_msg.mfcc_0_mean = spectral_features[50];
                feature_msg.mfcc_0_std = spectral_features[51];
                feature_msg.mfcc_1_mean = spectral_features[52];
                feature_msg.mfcc_1_std = spectral_features[53];
                feature_msg.mfcc_2_mean = spectral_features[54];
                feature_msg.mfcc_2_std = spectral_features[55];
                feature_msg.mfcc_3_mean = spectral_features[56];
                feature_msg.mfcc_3_std = spectral_features[57];
                feature_msg.mfcc_4_mean = spectral_features[58];
                feature_msg.mfcc_4_std = spectral_features[59];
                feature_msg.mfcc_5_mean = spectral_features[60];
                feature_msg.mfcc_5_std = spectral_features[61];
                feature_msg.mfcc_6_mean = spectral_features[62];
                feature_msg.mfcc_6_std = spectral_features[63];
                feature_msg.mfcc_7_mean = spectral_features[64];
                feature_msg.mfcc_7_std = spectral_features[65];
                feature_msg.mfcc_8_mean = spectral_features[66];
                feature_msg.mfcc_8_std = spectral_features[67];
                feature_msg.mfcc_9_mean = spectral_features[68];
                feature_msg.mfcc_9_std = spectral_features[69];
                feature_msg.mfcc_10_mean = spectral_features[70];
                feature_msg.mfcc_10_std = spectral_features[71];
                feature_msg.mfcc_11_mean = spectral_features[72];
                feature_msg.mfcc_11_std = spectral_features[73];
                feature_msg.mfcc_12_mean = spectral_features[74];
                feature_msg.mfcc_12_std = spectral_features[75];

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
