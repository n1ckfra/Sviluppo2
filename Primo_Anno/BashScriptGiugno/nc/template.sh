#!/usr/bin/env bash
nome=""
cognome=""
read -p "Inserire nome: " nome
read -p "Inserire cognome: " cognome

if  [ -z "$nome" ] || [ -z "$cognome" ] ; then
#if (( -z "$nome" ) || ( -z "$cognome" )); then
    echo "Vaffanculo"
    exit 1
else
    mkdir $cognome 2>/dev/null
    touch $cognome/$nome.txt
    ls -l $cognome
fi
