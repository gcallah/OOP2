#!/bin/sh
#  This file should include all tests run on our assembly emulator.

# exit on any error with that error status:
set -e

export TEST_DIR="."
export CODE_DIR="utils"
export DATA_DIR="$CODE_DIR/data"
export DEF_URL="https://gcallah.github.io/OOP2/"

for test_file in $TEST_DIR/*.html;
do
    echo 'URL-checking file:' $test_file
    python3 $CODE_DIR/url_checker.py "$test_file" $DEF_URL
    echo 'Html-checking file:' $test_file
    python3 $CODE_DIR/html_checker.py "$test_file"
    echo 'Spell-checking file:' $test_file
    if [ -z $PS1 ]
    then
        python3 $CODE_DIR/html_spell.py -i $test_file $DATA_DIR/main-dict.txt $DATA_DIR/custom-dict.txt
    else
        python3 $CODE_DIR/html_spell.py $test_file $DATA_DIR/main-dict.txt $DATA_DIR/custom-dict.txt
    fi
done
