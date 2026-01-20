project('chombo', ['c'],
  default_options: [
    'default_library=static',
    'c_std=c11',
    'warning_level=3',
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

# debug build flags
# enable -Werror and other flags
cc = meson.get_compiler('c')
if cc.get_id() == 'gcc' or cc.get_id() == 'clang'
  add_project_arguments('-Werror', language: 'c')
endif
# debug build flags
add_project_arguments([
  '-Wpointer-arith', '-Wcast-align', '-Wstrict-prototypes',
  '-Wwrite-strings', '-Waggregate-return', '-Wswitch-default',
  '-Wswitch-enum', '-Wunreachable-code', '-Winit-self',
  '-Wbad-function-cast', '-Wformat=2', '-Wlogical-op',
  '-Wredundant-decls', '-Wshadow', '-Wundef', '-Wfloat-equal', '-Werror'
], language: 'c')


# rust mahc cbindgen target
# create rust to c header file
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
# link header to .so
mahc_lib = custom_target(
  'mahc_lib',
  output: 'libmahc.so',
  console: true,
  command: ['cargo', 'build', '--manifest-path', meson.current_source_dir() / 'src/mahc/Cargo.toml'],
  build_by_default: true
)
mahc_dir = meson.project_source_root() / 'src/mahc/target/debug'
mahc_dep = declare_dependency(
  sources: mahc_header,
  link_args: [
    '-L' + mahc_dir,
    '-Wl,-rpath,' + mahc_dir,
    '-lmahc',
    '-ldl',
    '-lm'
  ]
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


# c src files
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
install_subdir('src/assets', install_dir: get_option('bindir'))

# lift off?
executable('chombo',
  source_files,
  dependencies: deps,
  link_language: 'c',
  install: true
)
