#!/bin/bash
set -e

VERSION="1.0.0"
APP_NAME="Chombo"
DIST_DIR="$(pwd)/dist_win"
BUILD_DIR="build_win"
WIN_DIST_DIR="$DIST_DIR/win"

rm -rf "$DIST_DIR"

meson setup "$BUILD_DIR" \
    --buildtype=release \
    --prefix=/usr \
    --reconfigure \
    -Ddefault_library=shared \
    --cross-file=x86_64-windows.txt;

meson compile -C "$BUILD_DIR"

DESTDIR="$WIN_DIST_DIR" meson install -C "$BUILD_DIR"

# fuck you sdl3_ttf!
cp "$BUILD_DIR/subprojects/SDL3_ttf-3.2.2/libsdl3_ttf-0.dll" "$WIN_DIST_DIR/usr/bin/"

rm -rf "$WIN_DIST_DIR/usr/include"
rm -rf "$WIN_DIST_DIR/usr/lib"
rm -rf "$WIN_DIST_DIR/usr/share"

cp chombo.iss "$WIN_DIST_DIR/chombo.iss"

WIN_ISS_PATH=$(winepath -w "$WIN_DIST_DIR/chombo.iss")
ISCC_DIR=$(dirname "$(realpath ISCC.exe)")
(cd "$ISCC_DIR" && wine ./ISCC.exe "$WIN_ISS_PATH")


echo "generated: ChomboSetup.exe"

