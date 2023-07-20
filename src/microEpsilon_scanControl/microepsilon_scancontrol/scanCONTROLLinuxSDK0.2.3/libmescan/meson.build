project('mescan', 'c', default_options: 'c_std=gnu99',
        version: '0.2.3',
        license: 'LGPL')
incdir = include_directories('include')

headers = ['include/mescan.h', 'include/mescan_basic.h', 'include/mescan_adv.h', 'include/LLTDataTypes.h']
sources = ['src/mescan_basic.c', 'src/mescan_adv.c']
aravis_dep = dependency('aravis-0.6', version: '>=0.5.8')

install_headers(headers, subdir: 'mescan')

libmescan = shared_library('mescan', sources, include_directories: incdir,
                                  dependencies: aravis_dep,
                                  version:'0.2.3',
                                  soversion:'0',
                                  install: true,
                                  install_dir:'/usr/local/lib' )

pkg_mod = import('pkgconfig')
pkg_mod.generate( libraries: '-lmescan',
                  subdirs: 'mescan',
                  version: '0.2.3',
                  name: 'mescan',
                  filebase: 'mescan',
                  install_dir:'/usr/local/lib/pkgconfig',
                  description: 'Library for operating MICRO-EPSILON scanCONTROL sensors' )

glib_dep = dependency('glib-2.0')
# test_mescan_basic = executable('test_mescan_basic', 'tests/test_mescan_basic.c', link_with: libmescan,
#										 dependencies: [aravis_dep, glib_dep],
#										 include_directories: incdir
#										 )
# test('Test mescan basic', test_mescan_basic)