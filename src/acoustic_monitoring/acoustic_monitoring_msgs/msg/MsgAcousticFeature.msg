Header header
# time-domain features
float32 rms_energy
float32 amplitude_envelope
float32 zero_crossing_rate
# freqeuncy domain features
float32[] mel_spectrogram
float32[] mfccs
float32 ber
float32 spectral_centroids
float32 spectral_rolloff
float32 spectral_bandwidth
float32 spectral_flatness
float32 spectral_crest_factor
float32 spectral_kurtosis
float32 spectral_variance


# spectral_centroid computes the "average" frequency at each frame, where frequencies are weighted relatively by their energy.
# spectral_bandwidth similar to centroid, but for variance (or other moments).
# spectral_rolloff essentially the maximum: finds the frequency f such that almost all of the energy (by default, 85%)