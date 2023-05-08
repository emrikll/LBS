./build-benchmark.sh ./rust_prototypes/print-50 200
./build-benchmark.sh ./rust_prototypes/print-100 200
./build-benchmark.sh ./rust_prototypes/print-200 200
./build-benchmark.sh ./rust_prototypes/print-500 200
./build-benchmark.sh ./rust_prototypes/shelloverflow 200
./build-benchmark.sh ./rust_prototypes/addhostalias 200

./build-benchmark.sh ./c_prototypes/print-50 200
./build-benchmark.sh ./c_prototypes/print-100 200
./build-benchmark.sh ./c_prototypes/print-200 200
./build-benchmark.sh ./c_prototypes/print-500 200
./build-benchmark.sh ./c_prototypes/shelloverflow 200
./build-benchmark.sh ./c_prototypes/addhostalias 200

#Run benchmarks
./run-benchmark.sh ./rust_prototypes/print-50 200 ./target/release/print-50 test
./run-benchmark.sh ./rust_prototypes/print-100 200 ./target/release/print-100 test
./run-benchmark.sh ./rust_prototypes/print-200 200 ./target/release/print-200 test
./run-benchmark.sh ./rust_prototypes/print-500 200 ./target/release/print-500 test
#./run-benchmark.sh ./rust_prototypes/shelloverflow 200 ./target/release/shelloverflow test
./run-benchmark.sh ./rust_prototypes/addhostalias 200 ./target/release/addhostalias test test test

./run-benchmark.sh ./c_prototypes/print-50 200 ./print-50 test
./run-benchmark.sh ./c_prototypes/print-100 200 ./print-100 test
./run-benchmark.sh ./c_prototypes/print-200 200 ./print-200 test
./run-benchmark.sh ./c_prototypes/print-500 200 ./print-500 test
#./run-benchmark.sh ./c_prototypes/shelloverflow 200
./run-benchmark.sh ./c_prototypes/addhostalias 200 ./addhostlias test test test