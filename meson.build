project('chombo', ['c'],
  default_options: [
    'c_std=c11',
    'warning_level=2', 
    'werror=false',
    'harfbuzz:tests=disabled',
    'harfbuzz:benchmark=disabled',
    'harfbuzz:glib=disabled',
    'harfbuzz:gobject=disabled',
    'harfbuzz:icu=disabled',
    'harfbuzz:cairo=disabled',
    'freetype2:harfbuzz=disabled',
    'freetype2:zlib=disabled',
    'freetype2:png=disabled',
    'freetype2:tests=disabled'
  ]
)

host_system = host_machine.system()
cc = meson.get_compiler('c')
fs = import('fs')

strict_c_flags = [
  '-Werror',
  '-Wpointer-arith',
  '-Wcast-align',
  '-Wstrict-prototypes',
  '-Wwrite-strings',
  '-Waggregate-return',
  '-Wswitch-default',
  '-Wswitch-enum',
  '-Wunreachable-code',
  '-Winit-self',
  '-Wbad-function-cast',
  '-Wformat=2',
  '-Wlogical-op',
  '-Wshadow',
  '-Wundef',
  # '-Wfloat-equal'
]

if cc.get_id() == 'gcc' or cc.get_id() == 'clang'
  add_project_arguments(strict_c_flags, language: 'c')
endif

is_release = get_option('buildtype') == 'release'
cargo_release_flag = is_release ? ['--release'] : []
rust_mode = is_release ? 'release' : 'debug'

if host_system == 'windows'
  rust_lib_filename = 'mahc.dll' 
  rust_target_triple = 'x86_64-pc-windows-gnu'
  rust_build_dir = 'src/mahc/target' / rust_target_triple / rust_mode
  cargo_cmd = ['cargo', 'build', '--manifest-path', meson.current_source_dir() / 'src/mahc/Cargo.toml', '--target', rust_target_triple] + cargo_release_flag
  rust_install_dir = get_option('bindir')
else
  rust_lib_filename = 'libmahc.so'
  rust_build_dir = 'src/mahc/target' / rust_mode
  cargo_cmd = ['cargo', 'build', '--manifest-path', meson.current_source_dir() / 'src/mahc/Cargo.toml'] + cargo_release_flag
  rust_install_dir = get_option('libdir')
endif

mahc_header = custom_target(
  'mahc_header',
  output: 'mahc.h',
  command: ['cbindgen', meson.project_source_root() / 'src/mahc', '--config', meson.project_source_root() / 'cbindgen.toml', '--output', '@OUTPUT@'],
  build_by_default: true
)

mahc_lib = custom_target(
  'mahc_lib',
  output: rust_lib_filename,
  command: ['sh', '-c', ' '.join(cargo_cmd) + ' && cp ' + meson.project_source_root() / rust_build_dir / rust_lib_filename + ' @OUTPUT@'],
  console: true,
  build_by_default: true,
  install: true,
  install_dir: rust_install_dir
)

#deps 
sdl3_dep = dependency('sdl3', fallback: ['sdl3', 'sdl3_dep'])
sdl3_ttf_dep = dependency('sdl3_ttf', fallback: ['sdl3_ttf', 'sdl3_ttf_dep'])
harfbuzz_dep = dependency('harfbuzz', fallback: ['harfbuzz', 'libharfbuzz_dep'])
freetype_dep = dependency('freetype2', fallback: ['freetype2', 'freetype_dep'])
mahc_dep = declare_dependency(
  sources: mahc_header
)

deps = [sdl3_dep, sdl3_ttf_dep, harfbuzz_dep, freetype_dep, mahc_dep]

# mrutils :)
inc = include_directories('src/mr_utils/include')

source_files = files(
  'src/e_event.c',
  'src/g_gamestate.c',
  'src/g_gamestate_button_handlers.c',
  'src/l_letter.c',
  'src/l_letter_objs.c',
  'src/main.c',
  'src/r_renderer.c',
  'src/t_tiles.c',
  'src/w_window.c',
  'src/b_button.c',
  'src/utils.c',
  'src/mr_utils/src/mrd_debug.c',
  'src/mr_utils/src/mrl_logger.c',
  'src/mr_utils/src/mrs_strings.c',
  'src/mr_utils/src/mrt_test.c',
  'src/mr_utils/src/mrv_vectors.c'
)

if host_system == 'linux'
    install_subdir('src/assets', install_dir: 'share/chombo')
    
    install_data('akagi.png', rename: 'chombo.png', install_dir: 'share/icons/hicolor/256x256/apps')
    install_data('akagi.png', rename: 'chombo.png', install_dir: 'share/pixmaps')
    
    desktop_conf = configuration_data()
    desktop_conf.set('EXEC', 'chombo')
    desktop_conf.set('VERSION', meson.project_version())

    configure_file(
        input: 'chombo.desktop.in',
        output: 'chombo.desktop',
        configuration: desktop_conf,
        install_dir: 'share/applications'
    )

    install_symlink('libsdl3_ttf.so.0',
      pointing_to: 'libsdl3_ttf.so',
      install_dir: get_option('libdir')
    )
    install_symlink('libSDL3.so.0',
      pointing_to: 'libSDL3.so',
      install_dir: get_option('libdir')
    )
    install_symlink('assets',
      pointing_to: '../share/chombo/assets',
      install_dir: get_option('bindir')
    )
else
    install_subdir('src/assets', install_dir: get_option('bindir'))
endif

executable('chombo',
  source_files,
  dependencies: deps,
  link_with: mahc_lib,
  include_directories: inc,
  link_language: 'c',
  install: true,
  install_rpath: '$ORIGIN/../' + get_option('libdir')
)
