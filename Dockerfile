FROM ubuntu

RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y ninja-build python2.7 gcc g++ clang make cmake git software-properties-common

RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y python3.8

RUN git clone https://github.com/bloomberg/bde-tools.git
ENV PATH=$PATH:/bde-tools/bin
RUN bde_build_env.py list
#RUN git clone https://github.com/bloomberg/bde.git
RUN git clone https://github.com/mhashemian/bde.git
WORKDIR bde

#RUN bde_build_env.py --build-type=Release --cpp-std=17
ENV BDE_CMAKE_UPLID=unix-linux-x86_64-5.10.104-gcc-11.2.0
ENV BDE_CMAKE_UFID=opt_exc_mt_64_cpp17
ENV BDE_CMAKE_BUILD_DIR="_build/unix-linux-x86_64-5.10.104-gcc-11.2.0-opt_exc_mt_64_cpp17"
ENV CXX=/usr/bin/g++
ENV CC=/usr/bin/gcc
ENV BDE_CMAKE_TOOLCHAIN=toolchains/linux/gcc-default
ENV BDE_CMAKE_INSTALL_DIR="/bde/_install"

RUN cmake_build.py configure
RUN cmake_build.py build
RUN cmake_build.py --install_dir=/bde_install --prefix=/ install

RUN mkdir build
WORKDIR /bde/build
RUN cmake -DCMAKE_PREFIX_PATH=/bde_install/lib64/opt_exc_mt/  ../
RUN cmake --build ./
