#! /bin/bash

if [ $# -eq 1 ]; then
    if [ $1 == "-h" ] ; then
        echo "No Option"
    else
        python3 $PLCSCRIPTPATH/STmakeCode.py $1
    fi
else
    echo "The number of parameters is not correct"
fi

