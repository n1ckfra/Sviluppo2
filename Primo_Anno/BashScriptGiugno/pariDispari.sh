#!/usr/bin/env bash
nParametri=$(($# % 2))
if [ $nParametri -eq 0 ]; then
    echo "Pari"
else
    echo "Dispari"
fi