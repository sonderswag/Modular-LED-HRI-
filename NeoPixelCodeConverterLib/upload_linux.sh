#!/bin/bash
cd $1 && cmake CMakeLists.txt && make && ./neopixeltest
$1/../arduino-1.6.11/arduino --upload $1/out/out.ino --port `$1/find_usbport.sh | grep "Arduino" | awk '{print $1}'`

