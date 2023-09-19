#!/usr/bin/env bash
for i in */; do
k=$(ls "$i" | wc -l)
if [ $k -gt 0 ]; then
echo $i 
fi
done