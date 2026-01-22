#!/bin/bash
set -e

VERSION="1.0.0"
APP_NAME="chombo"
DIST_DIR="$(pwd)/dist"
BUILD_DIR="build"

# remove some here?
# rm -rf $DIST_DIR $BUILD_DIR *.deb *.AppImage
rm -rf $DIST_DIR *.deb *.AppImage

meson setup $BUILD_DIR \
        --wrap-mode=forcefallback \
        --prefix=/usr \
        --reconfigure \
        -Ddefault_library=shared \

meson compile -C $BUILD_DIR
DESTDIR=$DIST_DIR meson install -C $BUILD_DIR
rm -rf $DIST_DIR/usr/include

ln -s ../share/chombo/assets $DIST_DIR/usr/bin/assets


mkdir -p $DIST_DIR/usr/lib
mv $DIST_DIR/usr/lib/x86_64-linux-gnu/* $DIST_DIR/usr/lib/
rmdir $DIST_DIR/usr/lib/x86_64-linux-gnu

# fuck you sdl3_ttf dogshit ass build system
cp build/subprojects/SDL3_ttf-3.2.2/libsdl3_ttf.so.0.2.2 $DIST_DIR/usr/lib/
ln -sf libsdl3_ttf.so.0.2.2 $DIST_DIR/usr/lib/libsdl3_ttf.so.0
ln -sf libsdl3_ttf.so.0.2.2 $DIST_DIR/usr/lib/libsdl3_ttf.so


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

export LINUXDEPLOY_OUTPUT_VERSION=$VERSION
export LDAI_OUTPUT="${APP_NAME}-${VERSION}-x86_64.AppImage"

./linuxdeploy-x86_64.AppImage --appdir $DIST_DIR \
    --executable $DIST_DIR/usr/bin/chombo \
    --desktop-file $DIST_DIR/usr/share/applications/chombo.desktop \
    --icon-file $DIST_DIR/usr/share/pixmaps/chombo.png \
    --output appimage \
    --library $DIST_DIR/usr/lib/libSDL3.so \
    --library $DIST_DIR/usr/lib/libsdl3_ttf.so # fuck you and your fucked ass SLIGHTLY different fucking name RHAHHHHH




echo "generated: ${APP_NAME}_${VERSION}_amd64.deb"
echo "generated: $(ls *.AppImage)"

