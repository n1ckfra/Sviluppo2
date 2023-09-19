#!/usr/bin/env bash
if [ $# -eq 0 ]; then 
    echo "Nessun parametro"
    exit 1
elif [ $# -eq 1 ]; then
    sottocartelle=$(find $1 -type d)
    for sottoD in $sottocartelle; do
        case $sottoD in
        $1);;
        *)
        echo $sottoD
        ls -l $sottoD | wc -l
        ;;
        esac
    done
fi