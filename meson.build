project('chombo', ['c'],
  default_options: [
    # 'default_library=static',
    'c_std=c11',
    'warning_level=2', 
    'werror=false',

    # i hate
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
  '-Wfloat-equal'
]

if cc.get_id() == 'gcc' or cc.get_id() == 'clang'
  add_project_arguments(strict_c_flags, language: 'c')
endif


# rust configing 
if host_system == 'windows'
  rust_lib_filename = 'mahc.dll' 
  rust_target_triple = 'x86_64-pc-windows-gnu'
  rust_build_dir = 'src/mahc/target' / rust_target_triple / 'debug'
  cargo_cmd = ['cargo', 'build', '--manifest-path', meson.current_source_dir() / 'src/mahc/Cargo.toml', '--target', rust_target_triple]
else
  rust_lib_filename = 'libmahc.so'
  rust_build_dir = 'src/mahc/target/debug'
  cargo_cmd = ['cargo', 'build', '--manifest-path', meson.current_source_dir() / 'src/mahc/Cargo.toml']
endif


# rust mahc cbindgen target
mahc_header = custom_target(
  'mahc_header',
  output: 'mahc.h',
  command: [
    'cbindgen',
    meson.project_source_root() / 'src/mahc',
    '--config', meson.project_source_root() / 'cbindgen.toml',
    '--output', '@OUTPUT@'
  ],
  build_by_default: true
)

# link header to .so/.dll
mahc_lib = custom_target(
  'mahc_lib',
  output: rust_lib_filename,
  console: true,
  command: cargo_cmd,
  build_by_default: true
)

mahc_lib_full_path = meson.project_source_root() / rust_build_dir / rust_lib_filename

# copy mahc.dll for win
copy_mahc = fs.copyfile(mahc_lib_full_path, 'run_' + rust_lib_filename) # some name collision boolshit

final_link_args = [mahc_lib_full_path]
if host_system == 'linux'
  mahc_abs_dir = meson.project_source_root() / rust_build_dir
  final_link_args += '-Wl,-rpath,' + mahc_abs_dir
  final_link_args += ['-ldl', '-lm']
endif

mahc_dep = declare_dependency(
  sources: mahc_header,
  link_args: [mahc_lib_full_path] 
)


# set all deps
sdl3_dep      = dependency('sdl3', fallback: ['sdl3', 'sdl3_dep'])
sdl3_ttf_dep  = dependency('sdl3_ttf', fallback: ['sdl3_ttf', 'sdl3_ttf_dep'])

harfbuzz_dep  = dependency('harfbuzz', fallback: ['harfbuzz', 'libharfbuzz_dep'])
freetype_dep  = dependency('freetype2', fallback: ['freetype2', 'freetype_dep'])

deps = [
  sdl3_dep,
  sdl3_ttf_dep,
  harfbuzz_dep,
  freetype_dep,
  mahc_dep
]


# src files
source_files = files(
  'src/e_event.c',
  'src/g_gamestate.c',
  'src/l_letter.c',
  'src/main.c',
  'src/r_renderer.c',
  'src/t_tiles.c',
  'src/w_window.c'
)


# move over assets folder to bin directory
# mahc lib install to bin dir 
# moves icon to build
# moves desktop file for lin 
if host_system == 'linux'
    install_subdir('src/assets', install_dir: 'share/chombo')
    install_data(mahc_lib_full_path, install_dir: get_option('libdir'))

    # for sdl3 and sdl3_ttf .so . see package.sh 
    add_project_link_arguments('-Wl,-rpath,$ORIGIN/../lib', language: 'c')

    install_data('akagi.png', rename: 'chombo.png', install_dir: 'share/icons/hicolor/256x256/apps')
    install_data('akagi.png', rename: 'chombo.png', install_dir: 'share/pixmaps')
    desktop_conf = configuration_data()
    desktop_conf.set('EXEC', 'chombo')
    configure_file(
        input: 'chombo.desktop.in',
        output: 'chombo.desktop',
        configuration: desktop_conf,
        install_dir: 'share/applications'
    )
else
    install_subdir('src/assets', install_dir: get_option('bindir'))
    install_data(mahc_lib_full_path, install_dir: get_option('bindir'))
endif

# lift off?
executable('chombo',
  source_files,
  dependencies: deps,
  link_depends: [mahc_lib, copy_mahc],
  link_language: 'c',
  install: true
)
