#!/bin/bash
set -e

VERSION="1.1.0"
APP_NAME="chombo"
DIST_DIR="$(pwd)/dist"
BUILD_DIR="build"

rm -rf $DIST_DIR $BUILD_DIR *.deb *.AppImage

# meson commands
meson setup $BUILD_DIR \
        --wrap-mode=forcefallback \
        --prefix=/usr \
        --libdir=lib \
        --buildtype=release \
        -Ddefault_library=shared \
        -Dsdl3:default_library=shared \
        -Dsdl3_ttf:default_library=shared \
        --strip

meson compile -C $BUILD_DIR
DESTDIR=$DIST_DIR meson install -C $BUILD_DIR

rm -rf $DIST_DIR/usr/include

# searches through symlinks to get actual .so (fuck you sdl3_ttf)
echo "harvesting real library files from build subprojects..."
harvest_lib() {
    local lib_name=$1
    if [ ! -f "$DIST_DIR/usr/lib/$lib_name" ]; then
        local REAL_FILE=$(find "$BUILD_DIR/subprojects" -name "${lib_name}*" -type f | xargs du -b | sort -nr | head -n1 | awk '{print $2}')
        if [ -n "$REAL_FILE" ]; then
            echo "found real library $REAL_FILE, installing as $lib_name"
            cp "$REAL_FILE" "$DIST_DIR/usr/lib/$lib_name"
        else
            echo "WARNING: could not find any file matching $lib_name"
        fi
    fi
}

harvest_lib "libsdl3_ttf.so"

# debian packaging 
mkdir -p $DIST_DIR/DEBIAN
cat <<EOF > $DIST_DIR/DEBIAN/control
Package: $APP_NAME
Version: $VERSION
Section: games
Priority: optional
Architecture: amd64
Maintainer: Tharun
Description: riichi mahjong scoring calculator 
Depends: libc6
EOF

dpkg-deb --build $DIST_DIR ${APP_NAME}_${VERSION}_amd64.deb

if [ ! -f "linuxdeploy-x86_64.AppImage" ]; then
    wget -q --show-progress https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage
    chmod +x linuxdeploy-x86_64.AppImage
fi

export LD_LIBRARY_PATH="$DIST_DIR/usr/lib:$LD_LIBRARY_PATH"
export LINUXDEPLOY_OUTPUT_VERSION=$VERSION
export LDAI_OUTPUT="${APP_NAME}-${VERSION}-x86_64.AppImage"

./linuxdeploy-x86_64.AppImage --appdir $DIST_DIR \
    --executable $DIST_DIR/usr/bin/chombo \
    --desktop-file $DIST_DIR/usr/share/applications/chombo.desktop \
    --icon-file $DIST_DIR/usr/share/pixmaps/chombo.png \
    --library $DIST_DIR/usr/lib/libsdl3_ttf.so.0 \
    --library $DIST_DIR/usr/lib/libmahc.so \
    --library $DIST_DIR/usr/lib/libSDL3.so \
    --output appimage

echo "generated: ${APP_NAME}_${VERSION}_amd64.deb"
echo "generated: $LDAI_OUTPUT"
