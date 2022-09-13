#! /bin/bash

if [ $# -eq 3 ]; then

   if [ $3 == "-c" ] ; then
       python3 $PLCSCRIPTPATH/stverif.py $1 $2 "complete"
   else
       echo "Wrong Option"
       echo "Please check -h option"
   fi

elif [ $# -eq 2 ]; then
   python3 $PLCSCRIPTPATH/stverif.py $1 $2

elif [ $# -eq 1 ]; then

    if [ $1 == "-h" ] ; then
        echo "Options"
        echo "-c : Compile in complete way"
    
    else
        echo "Wrong Option" 
        echo "Is -h that you want?"
    fi

else
    echo "The number of parameters is not correct"
fi

