#!/usr/bin/env bash
if [ $# -ne 6 ]; then   
    echo "Numero parametri errato"
    exit 1
fi

TLX=$1
TLY=$2
BRX=$3
BRY=$4
PX=$5
PY=$6

while [ $# -gt 0 ]; do
    if ! echo $1 | grep -E "^[0-9]+$" >/dev/null; then
        echo "$1 non è un numero"
        exit 1
    fi
    if [ $1 -lt 0 ]; then
        echo "$1 non è positivo"
        exit 1
    fi
    shift
done

if [ $PX -le $BRX ] && [ $PX -ge $TLX ] && [ $PY -le $TLY ] && [ $PY -ge $BRY ]; then
    exit 0
else
    exit 1
fi