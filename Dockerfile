FROM scoripl/rust:stable
MAINTAINER wapidstyle "wapidstyle@live.ca"

RUN apt-get update && \
    apt-get install   \
     build-essential   \
     cmake             \
     git               \
     libx11-dev        \
     freeglut3-dev     \
     libxcb-image0-dev \
     libudev-dev       \
     libjpeg-turbo8-dev\
     libopenal-dev     \
     libsndfile1-dev   \
     libfreetype6-dev  \
     make              \
    -y

ENV  SFML_GIT=https://github.com/SFML/SFML
ENV CSFML_GIT=https://github.com/SFML/CSFML

RUN mkdir -p /sfml
WORKDIR /sfml

RUN git clone $SFML_GIT				      &&\
    cd SFML					      &&\
    git checkout $(git describe --tags $(git rev-list tags --max-count=1)) &&\
    cmake .              	       	     	      &&\
    make                 			      &&\
    make install         			      &&\
    cd ..                			      &&\
    git clone $CSFML_GIT			      &&\
    cd CSFML				              &&\	
    git checkout $(git describe --tags $(git rev-list tags --max-count=1)) &&\
    SFML="$(realpath ../SFML)" 	       	     	      &&\
    cmake -DCMAKE_MODULE_PATH="$SFML/cmake/Modules" . &&\
    make                                              &&\
    make install				      &&\
    echo "Preparation complete."

