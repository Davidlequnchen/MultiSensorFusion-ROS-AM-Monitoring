#include <ros/ros.h>
#include <map>
#include <vector>
#include <string>
#include <acoustic_monitoring_msgs/AudioDataStamped.h>
#include <acoustic_monitoring_msgs/MsgAcousticFeature.h>
#include <essentia/essentiamath.h>
#include <essentia/algorithmfactory.h>
#include <deque>

using namespace essentia;
using namespace essentia::standard;
using namespace std;

AlgorithmFactory& factory = AlgorithmFactory::instance();

std::deque<Real> audio_buffer;


std::map<std::string, Real> extract_time_domain_features(std::vector<essentia::Real> &audio_signal) {
    std::map<std::string, Real> features;
    AlgorithmFactory& factory = AlgorithmFactory::instance();
    
    Algorithm* rms_algo = factory.create("RMS");
    Real rms_energy;
    rms_algo->input("array").set(audio_signal);
    rms_algo->output("rms").set(rms_energy);
    rms_algo->compute();
    features["rms_energy"] = rms_energy;
    
    // Similarly for other time-domain features...
    // ...
    
    delete rms_algo;
    return features;
}




std::map<std::string, essentia::Real> extract_spectral_features(std::vector<essentia::Real>& audio_signal, int sample_rate, int frame_size = 1024, int hop_size = 512) {
    
    std::map<std::string, Real> features;
    
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


void audioCallback(const acoustic_monitoring_msgs::AudioDataStamped::ConstPtr& msg, ros::Publisher& feature_pub) {
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

    std::map<std::string, Real> time_features = extract_time_domain_features(audio_vector);
    std::map<std::string, Real> spectral_features = extract_spectral_features(audio_vector, 44100);  // or your sample rate

    // Create and populate the feature message
    acoustic_monitoring_msgs::MsgAcousticFeature feature_msg;
    feature_msg.header.stamp = ros::Time::now();

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
    // ... (similarly populate other spectral features)

    // Publish the message
    feature_pub.publish(feature_msg);
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "audio_feature_extractor");
    essentia::init();

    ros::NodeHandle nh;

    ros::Publisher feature_pub = nh.advertise<acoustic_monitoring_msgs::MsgAcousticFeature>("acoustic_feature", 1000);
    ros::Subscriber sub = nh.subscribe<acoustic_monitoring_msgs::AudioDataStamped>("audioStamped", 1000, boost::bind(audioCallback, _1, boost::ref(feature_pub)));

    ros::spin();

    essentia::shutdown();

    return 0;
}
