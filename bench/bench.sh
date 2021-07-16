#!/bin/bash

make > /dev/null

gcc bench/bench_map/bench_map.c libcore.a -lm -o bench_core_map
g++ bench/bench_map/bench_std_hash_map.cpp libcore.a -o bench_std_unordered_map

printf "Benchmark core::map against std::unordered map\n\n"

./bench_std_unordered_map 1000 8
printf "\n"
./bench_core_map 1000 8 LINEAR
printf "\n"
./bench_core_map 1000 8 QUADRATIC
printf "\n--------------\n"
./bench_std_unordered_map 10000 8
printf "\n"
./bench_core_map 10000 8 LINEAR
printf "\n"
./bench_core_map 10000 8 QUADRATIC
printf "\n--------------\n"
./bench_std_unordered_map 1000000 8
printf "\n"
./bench_core_map 1000000 8 LINEAR
printf "\n"
./bench_core_map 1000000 8 QUADRATIC
printf "\n--------------\n"
./bench_std_unordered_map 1000 10
printf "\n"
./bench_core_map 1000 10 LINEAR
printf "\n"
./bench_core_map 1000 10 QUADRATIC
printf "\n--------------\n"
./bench_std_unordered_map 10000 10
printf "\n"
./bench_core_map 10000 10 LINEAR
printf "\n"
./bench_core_map 10000 10 QUADRATIC
printf "\n--------------\n"
./bench_std_unordered_map 1000000 10
printf "\n"
./bench_core_map 1000000 10 LINEAR
printf "\n"
./bench_core_map 1000000 10 QUADRATIC
printf "\n--------------\n"
./bench_std_unordered_map 1000 100
printf "\n"
./bench_core_map 1000 100 LINEAR
printf "\n"
./bench_core_map 1000 100 QUADRATIC
printf "\n--------------\n"
./bench_std_unordered_map 10000 100
printf "\n"
./bench_core_map 10000 100 LINEAR
printf "\n"
./bench_core_map 10000 100 QUADRATIC
printf "\n--------------\n"
./bench_std_unordered_map 1000000 100
printf "\n"
./bench_core_map 1000000 100 LINEAR
printf "\n"
./bench_core_map 1000000 100 QUADRATIC
printf "\n--------------\n"

rm bench_core_map
rm bench_std_unordered_map