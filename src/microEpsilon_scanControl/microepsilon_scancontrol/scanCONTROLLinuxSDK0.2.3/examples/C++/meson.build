project('cpp_examples', 'cpp')

aravis_dep = dependency('aravis-0.6', version: '>=0.5.8')
mescan_dep = dependency('mescan', version: '>=0.2.3')
llt_dep = dependency('llt', version: '>=0.2.3')
png_dep = dependency('libpng', version: '>=1.0.0')

executable('Calibration', 'Calibration/Calibration.cpp',
                                        dependencies: [aravis_dep, mescan_dep, llt_dep],
										 )

executable('ContainerMode', 'ContainerMode/ContainerMode.cpp',
                                        dependencies: [aravis_dep, mescan_dep, llt_dep, png_dep],
										 )

executable('GetProfilesCallback', 'GetProfilesCallback/GetProfilesCallback.cpp',
                                        dependencies: [aravis_dep, mescan_dep, llt_dep],
										 )

executable('GetProfilesPoll', 'GetProfilesPoll/GetProfilesPoll.cpp',
                                        dependencies: [aravis_dep, mescan_dep, llt_dep],
										 )

executable('LLTPeakFilter', 'LLTPeakFilter/LLTPeakFilter.cpp',
                                        dependencies: [aravis_dep, mescan_dep, llt_dep],
										 )

executable('PartialProfile', 'PartialProfile/PartialProfile.cpp',
                                        dependencies: [aravis_dep, mescan_dep, llt_dep],
										 )

executable('PartialProfile_MultiLLT', 'PartialProfileMultiLLT/PartialProfileMultiLLT.cpp',
                                        dependencies: [aravis_dep, mescan_dep, llt_dep],
										 )

executable('VideoMode', 'VideoMode/VideoMode.cpp',
                                        dependencies: [aravis_dep, mescan_dep, llt_dep],
										 )
