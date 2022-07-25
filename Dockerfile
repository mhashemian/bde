FROM ubuntu

RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y ninja-build python2.7 gcc g++ clang make cmake git software-properties-common

RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y python3.8

RUN git clone https://github.com/bloomberg/bde-tools.git
RUN export PATH=/bde-tools/bin:$PATH
RUN bde_build_env.py list
RUN git clone https://github.com/bloomberg/bde.git
WORKDIR bde

RUN eval `bde_build_env.py --build-type=Release --cpp-std=17`
RUN cmake_build.py configure
RUN cmake_build.py build
RUN cmake_build.py --install_dir=/bde_install --prefix=/ install
