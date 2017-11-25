#! /bin/bash
# https://github.com/zeromq/cppzmq
# http://zeromq.org/intro:get-the-software
# usage: 
# ./installer.sh [--clean-after]
#   --clean-after will perform clean up of installation folders

# Install dependencies
function install_base_dependencies() {
sudo apt-get update -y
sudo apt-get install -y git-core \
                       libxml2-dev \
                       curl \
                       python \
                       build-essential \
                       make \
                       gcc \
                       python-dev \
                       python3 \
                       python3-pip \
                       net-tools \
                       iputils-ping \
                       software-properties-common \
                       python-software-properties \
                       libzmq-dev
}

function install_cmake() {
    # installs cmake version 3.2.2
    DIR=$(pwd)
    wget http://www.cmake.org/files/v3.2/cmake-3.2.2.tar.gz
    tar xf cmake-3.2.2.tar.gz && cd cmake-3.2.2
    ./configure
    make
    sudo make install
    cd ${DIR}
}

# Install zeromq
function install_zeromq() {
    # installs zmq bindings for c
    DIR=$(pwd)
    git clone https://github.com/zeromq/libzmq
    cd libzmq
    mkdir build_
    cd build_
    cmake ..
    make -j 4 
    make test 
    sudo make install
    sudo ldconfig
    cd ${DIR}
}


# Install cppzmq
function install_cppzmq() {
    # install zmq bindings for cpp
    DIR=$(pwd)
    git clone https://github.com/zeromq/cppzmq.git
    cd cppzmq
    mkdir build_
    cd build_
    cmake ..
    sudo make -j 4 install
    cd ${DIR}
}

function main() {
    install_base_dependencies
    install_cmake
    install_zeromq
    install_cppzmq
    if [ "$1" == "--clean-after" ]; then
        rm -rf cmake-3.2.2* libzmq/ cppzmq/
    fi
}

# // =============================
# Main
main $@
