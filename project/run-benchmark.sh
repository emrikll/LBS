path=$1
target=$3
iterations=$2

total=0

cd $path

make build

for i in $(seq 1 $iterations);
do
    start=`date +%s.%N`
    $target "${@:4}"
    end=`date +%s.%N`
    runtime=$( echo "$end - $start" | bc -l )
    total=$( echo "$total + $runtime" | bc -l )
done
echo $total / $iterations | bc -l