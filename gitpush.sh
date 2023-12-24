#!/bin/bash
if [[ -z $1 ]];
then
    echo "No commit message"
    exit 0
fi
git add . 
git commit -m "$1"
git push