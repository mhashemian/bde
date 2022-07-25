FROM ubuntu

RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y ninja-build python2.7 gcc g++ clang make cmake git

RUN git clone https://github.com/bloomberg/bde-tools.git
RUN export PATH=$PWD/bde-tools/bin:$PATH
RUN git clone https://github.com/bloomberg/bde.git
WORKDIR bde

RUN export BDE_CMAKE_BUILD_DIR=$PWD/_build
#RUN cmake_build.py configure -u dbg_exc_mt_64_cpp14
#RUN cmake_build.py build --test run
