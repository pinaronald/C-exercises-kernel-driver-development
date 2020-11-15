#!/bin/bash

module=lab4_chardrv.ko
node=/dev/chardrv
minor=0

[[ -n $1 ]] && module="$1"
[[ -n $2 ]] && node="$2"


echo loading $module
insmod $module

major=$(awk "\$2==\"chardrv\" {print \$1}" /proc/devices)
echo major number is: $major

echo creating the device node at $node with minor=0

mknod $node c $major $minor
