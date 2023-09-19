#!/usr/bin/env bash
function dirmenu() {
    select folder in */ .. ; do
    cd $folder
    break;
    done
}