#!/bin/sh
#
# Builds SFML and CSFML.
#
# ---------------- WARNING !!!
# THIS SHOULD ONLY BE RUN BY CI!
# You can run this, but BE CAREFUL!
#
function checkFail() {
    status=$?
    if [ $status -ne 0 ]
    then
	echo "A command failed with value $status."
	exit $status
    fi
}

if [ `id -u $USER` -ne 0 ]
then
    echo "You need root priviledges to run this script. If you"  > /dev/stderr
    echo "are too cool for that, run this script with fakeroot." > /dev/stderr
    exit 1
fi

apt-get install -y build-essential cmake git libx11-dev freeglut3-dev libxcb-image0-dev libudev-dev libjpeg-turbo8-dev libopenal-dev libsndfile1-dev libfreetype6-dev
checkFail


git clone https://github.com/SFML/SFML
cd SFML
git checkout $(git describe --tags $(git rev-list --tags --max-count=1))
cmake .
checkFail
make
checkFail
make install
checkFail
cd ..

git clone https://github.com/SFML/CSFML
cd CSFML
git checkout $(git describe --tags $(git rev-list --tags --max-count=1))
SFML="$(realpath ../SFML)"
cmake -DCMAKE_MODULE_PATH="$SFML/cmake/Modules" .
checkFail
make
checkFail
make install
checkFail
cd ..

rm -rfv SFML CSFML
exit 0
