#! /bin/bash

dir="$(dirname $0)"

i=0
gen()
{
  let i++
  "$dir/generator.py" "$@" > $(printf "$dir/secret/erase.%02d.in" $i)
  if [[ "$@" =~ '--failed' ]]; then
    echo "Deletion failed"     > $(printf "$dir/secret/erase.%02d.ans" $i)
  else
    echo "Deletion succeeded"  > $(printf "$dir/secret/erase.%02d.ans" $i)
  fi
}

gen
gen --failed 1
gen
gen --failed 2
gen
gen --failed 10
gen
gen --failed
gen
gen --failed
gen
gen --failed
gen
gen --failed
