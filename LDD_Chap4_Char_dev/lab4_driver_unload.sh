#!/bin/bash

module=lab4_chardrv.ko
node=/dev/chardrv
minor=0

[[ -n $1 ]] && module="$1"
[[ -n $2 ]] && node="$2"

major=$(awk "\$2==\"chardrv\" {print \$1}" /proc/devices)
echo major number is: $major

echo unloading $module
rmmod $module

echo removing the device node at $node with minor number=0
rm $node
