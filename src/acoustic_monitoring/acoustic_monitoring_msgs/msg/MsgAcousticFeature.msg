Header header
# time-domain features
float32 rms_energy
float32 amplitude_envelope
float32 zero_crossing_rate
# frequency-domain features
# float32 mfccs
float32 mfccs_mean
float32 mfccs_variance
float32 spectral_centroids
float32 spectral_rolloff


# spectral_centroid computes the "average" frequency at each frame, where frequencies are weighted relatively by their energy.
# spectral_bandwidth similar to centroid, but for variance (or other moments).
# spectral_rolloff essentially the maximum: finds the frequency f such that almost all of the energy (by default, 85%)

