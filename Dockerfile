FROM ubuntu

RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y ninja-build python2.7
#RUN apt-get update -y && DEBIAN_FRONTEND=noninteractive apt-get install -y ninja-build python2.7 gcc g++ clang make cmake git

#RUN git clone https://github.com/bloomberg/bde-tools.git
#RUN export PATH=$PWD/bde-tools/bin:$PATH      # add bde-tools to the 'PATH'
#RUN git clone https://github.com/bloomberg/bde.git
#WORKDIR bde

#RUN export BDE_CMAKE_BUILD_DIR=$PWD/_build   # configure the build directory
#RUN cmake_build.py configure -u dbg_exc_mt_64_cpp14
#RUN cmake_build.py build --test run

#RUN git clone https://github.com/mhashemian/cpr.git
#WORKDIR cpr
#RUN sed -i 's/cpr_option(CPR_ENABLE_SSL "Enables or disables the SSL backend. Required to perform HTTPS requests." ON)/cpr_option(CPR_ENABLE_SSL "Enables or disables the SSL backend. Required to perform HTTPS requests." OFF)/g' /cpr/CMakeLists.txt
#RUN cmake .
#RUN make
#ENV PATH=$PATH:/cpr/include:/cpr/lib
#RUN touch include/cpr/cprver.h
#RUN g++ example.cpp -Iinclude -Llib -lcpr
#ENV LD_LIBRARY_PATH=/cpr/lib
#RUN export LD_LIBRARY_PATH
