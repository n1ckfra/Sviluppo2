#!/usr/bin/env bash

function cerca() {
    read -p "Che cerchiamo? " robeDaCercare
    cat rubrica.txt | grep -i -E "^$robeDaCercare"
}

function aggiungi() {
    cose=""
    while [ -z "$cose" ]; do
        read -p "Inserire nome: " cose
        if [ -z "$cose" ]; then
		returns
	    fi
    done
    echo $cose >> rubrica.txt
}

function cancella() {
    read -p "Chi cancelliamo? " daCancellare
    echo $daCancellare
    sed -i -E "/^$daCancellare/d" rubrica.txt
}

function esci() {
    echo "Programma terminato"
}

function menu() {
    echo "1) cerca"
    echo "2) aggiungi"
    echo "3) cancella"
    echo "4) esci"
    echo "Inserisci scleta: "
    read scelta
    case $scelta in
        1) cerca ;;
        2) aggiungi;;
        3) cancella;;
        4) esci;;
    esac
}
