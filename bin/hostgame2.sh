#!/bin/bash

name="$1"
id=$(ps -ejH | grep hostgame | wc -l)
capacity=6
chips=100000
bigblind=0
smallblind=0
timer=30
port=$((45454+id))


#if ! options=$(getopt -o ctn: --long name:,capacity:,timer:, -n 'javwrap' -- "$@"); then
#    exit 1i
#fi

#while [ $# -gt 0 ]; do
#    case $1 in 
#        -c|--capacity) capacity=$2 ;;
#        -t|timer) timer=$2 ;;



#        -n|--name) name="$2"; shift;;
#        (--) shift; break;;
#        (*) break;;
#    esac
#    shift
#done

i=0
options=$@
args=($options)

for arg in $options; do
    ((i++))
    echo "Analyzing $arg" 
    case $arg in
        --capacity) echo "key $arg value ${args[i]}" ;;
        -timer) echo "key $arg value ${args[i]}" ;;
        -name) echo "key $arg value ${args[i]}" ;;

    esac
done




#cd ~/projects/allstarpoker/src/build-game-Desktop_Qt_5_9_1_GCC_64bit-Debug

#mkdir "$name" > /dev/null 2>&1
#mkdir "$name"/players > /dev/null 2>&1

#if (( $# < 8 )); then
#	echo "Usage: <name> <id> <size> <chip count> <small blind> <big blind> <timer> <port>"
#	exit
#fi

echo "Name: $name"
echo "Id: $id"
echo "Capacity: $capacity"
echo "Chips: $chips"
echo "Big Blind: $bigblind"
echo "Small Blind: $smallblind"
echo "Timer: $timer"
echo "Port: $port"

#./game "$name" $id $capacity $chips $bigblind $smallblind $timer $port > "$name"/log.txt



#rm -r "$name"
