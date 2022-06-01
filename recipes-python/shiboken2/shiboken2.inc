LICENSE = "Unknown"
LIC_FILES_CHKSUM = "file://COPYING.libshiboken;md5=15a1ca44f90f3ab457d6a4fe7c0f3a19 \
                    file://COPYING;md5=34337af480a8c452bfafe22a78fa20cb \
                    file://COPYING.libsample;md5=15a1ca44f90f3ab457d6a4fe7c0f3a19 \
                    file://ApiExtractor/COPYING;md5=34337af480a8c452bfafe22a78fa20cb \
                    file://libshiboken/embed/qt_python_license.txt;md5=72805479576a4498d9e94f8a9904a6a4"

SRC_URI = "git://github.com/pyside/pyside2-setup.git;protocol=https;branch=5.15"

#SRC_URI += "file://shibokenmodule-cmake.patch;subdir=git/sources/shiboken2"

# Modify these as desired
PV = "1.0+git${SRCPV}"
SRCREV = "d526f801ced4687d5413907a93dedcd782ef72fa"

S = "${WORKDIR}/git/sources/shiboken2"

# NOTE: unable to map the following CMake package dependencies: Qt5XmlPatterns
DEPENDS = "qtbase libxslt libxml2 python3 python3-setuptools python3-wheel"
RDEPENDS:${PN} += " qtbase python3-numpy "

inherit python3native cmake_qt5


# Specify any options you want to pass to cmake using EXTRA_OECMAKE:
EXTRA_OECMAKE = " \
    -DUSE_PYTHON_VERSION=3 \
    -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_TESTS=OFF \
    -DDISABLE_DOCSTRINGS:BOOL=ON \
"

OECMAKE_GENERATOR = "Unix Makefiles"

# depends on meta-clang
TOOLCHAIN = "clang"
