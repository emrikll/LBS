path=$1
iterations=$2

current=$(pwd)

cd $path

total=0
values=()

for i in $(seq 1 $iterations);
do
    make clean
    start=`date +%s.%N`
    make build
    end=`date +%s.%N`
    time=$( echo "$end - $start" | bc -l )
    values+=("'$time'")
    total=$( echo "$total + $time" | bc -l )
done
cd $current
printf '%s\n' $values > ./build-results/test.txt
echo $total / $iterations | bc -l