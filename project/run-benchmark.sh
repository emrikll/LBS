path=$1
iterations=$2
target=$3

total=0
values=()

current=$(pwd)

resultsfile="${path:2}"
resultsfile=$(printf '%s\n' $resultsfile | tr '/' '_')

cd $path

make clean
make build
chmod +x $target

for i in $(seq 1 $iterations);
do
    start=`date +%s.%N`
    $target "${@:4}"
    end=`date +%s.%N`
    time=$( echo "$end - $start" | bc -l )
    values+=("$time")
    total=$( echo "$total + $time" | bc -l )
done

cd $current

if [ ! -d ./run_results ]; then
  mkdir -p ./run_results;
fi


file="./run_results/${resultsfile}-${iterations}"
touch $file
printf '0%s\n' "${values[@]}" > "$file"
#cat $file | ts 0 | tr -d ' ' > $file
echo $total / $iterations | bc -l