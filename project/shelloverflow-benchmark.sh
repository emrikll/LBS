path=$1
iterations=$2
target=$3

password="password"
username="username"

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
    yes | $target
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
printf '%s\n' "${values[@]}" > "$file"
echo $total / $iterations | bc -l