path=$1

total=0
values=()

while IFS= read -r line; do
  total=$( echo "$total + $line" | bc -l )
  values+=("$line")
done < $path

length=${#values[@]}
average=$( echo "$total / $length" | bc -l )

IFS=$'\n' sorted=($(sort <<<"${values[*]}")); unset IFS

printf 'Average: %s\n' "$average"
printf "Median value: %s\n" ${sorted[$length / 2]}
printf "Smallest value: %s\n" ${sorted[0]}
printf "Biggest value: %s\n" ${sorted[$length - 1]}
