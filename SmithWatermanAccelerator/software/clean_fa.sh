tail -n +2 $1 | tr -d '\n' | sed 's/a/A/g' | sed 's/c/C/g' | sed 's/g/G/g' | sed 's/t/T/g' > $2
