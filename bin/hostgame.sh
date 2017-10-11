#!/bin/bash

name="$1"
id=$( ps -ejH)
capacity=6
chips=100000
bigblind=0
smallblind=0
timer=30
port=((45454 + $id))

#cd ~/projects/allstarpoker/src/build-game-Desktop_Qt_5_9_1_GCC_64bit-Debug

#mkdir "$name" > /dev/null 2>&1
#mkdir "$name"/players > /dev/null 2>&1

#if (( $# < 8 )); then
#	echo "Usage: <name> <id> <size> <chip count> <small blind> <big blind> <timer> <port>"
#	exit
#fi

echo "$name"
echo "$id"
echo "$capacity"
echo "$chips"
echo "$bigblind"
echo "$smallblind"
echo "$timer"
echo "$port"

#./game "$name" $id $capacity $chips $bigblind $smallblind $timer $port > "$name"/log.txt



#rm -r "$name"
