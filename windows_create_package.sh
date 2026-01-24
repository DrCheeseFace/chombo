#!/bin/bash
set -e

VERSION="1.0.1"
APP_NAME="Chombo"
DIST_DIR="$(pwd)/dist_win"
BUILD_DIR="build_win"
WIN_DIST_DIR="$DIST_DIR/win"

rm -rf "$DIST_DIR" "$BUILD_DIR"

# meson commands 
meson setup "$BUILD_DIR" \
    --buildtype=release \
    --prefix=/ \
    --libdir=bin \
    --bindir=bin \
    --strip \
    --cross-file=x86_64-windows.txt
meson compile -C "$BUILD_DIR"
DESTDIR="$WIN_DIST_DIR" meson install -C "$BUILD_DIR"

# same as linux script.
# copies over dlls (fuck you sdl3_ttf)
echo "harvesting DLLs from build directory..."
harvest_dll() {
    local dll_name=$1
    if [ ! -f "$WIN_DIST_DIR/bin/$dll_name" ]; then
        local FOUND_DLL=$(find "$BUILD_DIR/subprojects" -name "$dll_name" -type f | head -n 1)
        if [ -n "$FOUND_DLL" ]; then
            echo "Found $dll_name at $FOUND_DLL, copying..."
            cp "$FOUND_DLL" "$WIN_DIST_DIR/bin/"
        else
            echo "WARNING: Could not find $dll_name in build directory!"
        fi
    fi
}

harvest_dll "libSDL3.dll"
harvest_dll "libsdl3_ttf-0.dll"

mv "$WIN_DIST_DIR/bin/"* "$WIN_DIST_DIR/"
rm -rf "$WIN_DIST_DIR/bin"

rm -rf "$WIN_DIST_DIR/include" "$WIN_DIST_DIR/lib" "$WIN_DIST_DIR/share" "$WIN_DIST_DIR/pkgconfig" "$WIN_DIST_DIR/cmake"
rm -f "$WIN_DIST_DIR"/*.dll.a

cp chombo.iss "$WIN_DIST_DIR/chombo.iss"
WIN_ISS_PATH=$(winepath -w "$WIN_DIST_DIR/chombo.iss")
ISCC_DIR=$(dirname "$(realpath ISCC.exe)")

(cd "$ISCC_DIR" && wine ./ISCC.exe "$WIN_ISS_PATH")

echo "generated: ChomboSetup.exe"
