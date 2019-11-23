#!/bin/bash
set -e
source ./functions.sh 

# you can install oj with: $ pip3 install --user -U online-judge-tools=='6.*'
which oj > /dev/null

for f in $(find . -name \*.test.cpp) ; do
    echo "----------------------------------------------------------------------"
    echo "## Testing '${f}' ..."
    echo "----------------------------------------------------------------------"
    run $f
done
