#!/usr/bin/env bash
if [ $# -ne 3 ]; then
    echo "Errore parametri" >&2
    exit 2
elif [ $1 -gt $2 ]; then
    echo "Errore range valori"
    exit 1
else
    for k in $(seq $1 $2); do
        if [ $(expr $k % 3) -eq 0 ]; then
            echo $k
        fi
    done
fi