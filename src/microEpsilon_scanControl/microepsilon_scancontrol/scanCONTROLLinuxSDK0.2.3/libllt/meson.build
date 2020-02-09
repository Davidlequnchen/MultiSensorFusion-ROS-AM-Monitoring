project('llt', 'cpp',
        version: '0.2.3',
        license: 'LGPL')
incdir = include_directories('include')

headers = ['include/llt.h']
sources = ['src/llt.cpp']
aravis_dep = dependency('aravis-0.6', version: '>=0.5.8')
mescan_dep = dependency('mescan', version: '>=0.2.3')

install_headers(headers, subdir: 'mescan')

shared_library('llt', sources, include_directories: incdir, 
                                  dependencies: [aravis_dep, mescan_dep], 
                                  version:'0.2.3', 
                                  soversion:'0', 
                                  install: true,
                                  install_dir:'/usr/local/lib' )

pkg_mod = import('pkgconfig')
pkg_mod.generate( libraries: '-lllt',
                  subdirs: 'mescan',
                  version: '0.2.3',
                  name: 'libllt',
                  filebase: 'llt',
                  install_dir:'/usr/local/lib/pkgconfig',
                  description: 'Wrapper library for mescan and aravis' )