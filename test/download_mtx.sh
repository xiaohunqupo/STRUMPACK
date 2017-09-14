#!/bin/bash

if [ ! -d "utm300" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/TOKAMAK/utm300.tar.gz
    tar -xvzf utm300.tar.gz
    rm utm300.tar.gz
fi
if [ ! -d "mesh3e1" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/Pothen/mesh3e1.tar.gz
    tar -xvzf mesh3e1.tar.gz
    rm mesh3e1.tar.gz
fi
if [ ! -d "t2dal" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/Oberwolfach/t2dal.tar.gz
    tar -xvzf t2dal.tar.gz
    rm t2dal.tar.gz
fi
if [ ! -d "bcsstk28" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/HB/bcsstk28.tar.gz
    tar -xvzf bcsstk28.tar.gz
    rm bcsstk28.tar.gz
fi
if [ ! -d "cavity16" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/DRIVCAV/cavity16.tar.gz
    tar -xvzf cavity16.tar.gz
    rm cavity16.tar.gz
fi
if [ ! -d "bcsstm08" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/HB/bcsstm08.tar.gz
    tar -xvzf bcsstm08.tar.gz
    rm bcsstm08.tar.gz
fi
if [ ! -d "sherman4" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/HB/sherman4.tar.gz
    tar -xvzf sherman4.tar.gz
    rm sherman4.tar.gz
fi
if [ ! -d "rdb968" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/Bai/rdb968.tar.gz
    tar -xvzf rdb968.tar.gz
    rm rdb968.tar.gz
fi
if [ ! -d "cz10228" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/CPM/cz10228.tar.gz
    tar -xvzf cz10228.tar.gz
    rm cz10228.tar.gz
fi
if [ ! -d "k3plates" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/Cunningham/k3plates.tar.gz
    tar -xvzf k3plates.tar.gz
    rm k3plates.tar.gz
fi
if [ ! -d "cbuckle" ]; then
    wget https://www.cise.ufl.edu/research/sparse/MM/TKK/cbuckle.tar.gz
    tar -xvzf cbuckle.tar.gz
    rm cbuckle.tar.gz
fi
