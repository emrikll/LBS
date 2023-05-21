#./build-benchmark.sh ./rust_prototypes/print-50 1000
#./build-benchmark.sh ./rust_prototypes/print-100 1000
#./build-benchmark.sh ./rust_prototypes/print-200 1000
#./build-benchmark.sh ./rust_prototypes/print-500 1000
#./build-benchmark.sh ./rust_prototypes/shelloverflow 1000
./build-benchmark.sh ./rust_prototypes/addhostalias-1000 200
./build-benchmark.sh ./rust_prototypes/addhostalias-5000 200
./build-benchmark.sh ./rust_prototypes/addhostalias-10000 200
./build-benchmark.sh ./rust_prototypes/addhostalias-100000 200

#./build-benchmark.sh ./c_prototypes/print-50 1000
#./build-benchmark.sh ./c_prototypes/print-100 1000
#./build-benchmark.sh ./c_prototypes/print-200 1000
#./build-benchmark.sh ./c_prototypes/print-500 1000
#*./build-benchmark.sh ./c_prototypes/shelloverflow 1000
./build-benchmark.sh ./c_prototypes/addhostalias-1000 200
./build-benchmark.sh ./c_prototypes/addhostalias-5000 200
./build-benchmark.sh ./c_prototypes/addhostalias-10000 200
./build-benchmark.sh ./c_prototypes/addhostalias-100000 200

#Run benchmarks
#./run-benchmark.sh ./rust_prototypes/print-50 1000 ./target/release/print-50 test
#./run-benchmark.sh ./rust_prototypes/print-100 1000 ./target/release/print-100 test
#./run-benchmark.sh ./rust_prototypes/print-200 1000 ./target/release/print-200 test
#./run-benchmark.sh ./rust_prototypes/print-500 1000 ./target/release/print-500 test
#./shelloverflow-benchmark.sh ./rust_prototypes/shelloverflow/ 1000 ./target/release/shelloverflow
./run-benchmark.sh ./rust_prototypes/addhostalias-1000 200 ./target/release/addhostalias test test test
./run-benchmark.sh ./rust_prototypes/addhostalias-5000 200 ./target/release/addhostalias test test test
./run-benchmark.sh ./rust_prototypes/addhostalias-10000 200 ./target/release/addhostalias test test test
./run-benchmark.sh ./rust_prototypes/addhostalias-100000 200 ./target/release/addhostalias test test test


#./run-benchmark.sh ./c_prototypes/print-50 1000 ./print test
#./run-benchmark.sh ./c_prototypes/print-100 1000 ./print test
#./run-benchmark.sh ./c_prototypes/print-200 1000 ./print test
#./run-benchmark.sh ./c_prototypes/print-500 1000 ./print test
#./shelloverflow-benchmark.sh ./c_prototypes/shelloverflow/ 1000 ./login_linux
./run-benchmark.sh ./c_prototypes/addhostalias-1000 200 ./addhostalias test test test
./run-benchmark.sh ./c_prototypes/addhostalias-5000 200 ./addhostalias test test test
./run-benchmark.sh ./c_prototypes/addhostalias-10000 200 ./addhostalias test test test
./run-benchmark.sh ./c_prototypes/addhostalias-100000 200 ./addhostalias test test test