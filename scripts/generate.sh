#!/bin/bash -ex
pushd ./simdutf
    python3 ./singleheader/amalgamate.py
popd

cp ./simdutf/singleheader/simdutf.h   ./cpp
cp ./simdutf/singleheader/simdutf.cpp ./cpp

python3 ./scripts/strip-comments.py ./cpp/simdutf.h
python3 ./scripts/strip-comments.py ./cpp/simdutf.cpp
