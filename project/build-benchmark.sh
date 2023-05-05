path=$1
iterations=$2

cd $path

total=0

for i in $(seq 1 $iterations);
do
    make clean
    start=`date +%s.%N`
    make build
    end=`date +%s.%N`
    total=$( echo "$total + $end - $start" | bc -l )
done
echo $total / $iterations | bc -l