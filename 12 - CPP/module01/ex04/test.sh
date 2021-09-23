#! /bin/bash

make

echo "ABC to XBC"
echo "ABC" > file
./replace file A X
cat	file.replace
echo

echo "ABC to AXC"
echo "ABC" > file
./replace file B X
cat	file.replace
echo

echo "ABC to ABX"
echo "ABC" > file
./replace file C X
cat	file.replace
echo

echo "XAX to AAA"
echo "XAX" > file
./replace file X A
cat	file.replace
echo

echo "XXX to AAA"
echo "XXX" > file
./replace file X A
cat	file.replace
echo

echo "XXX    BBB"
echo "XAX to BAB"
echo "XXX    BBB"
echo "XXX" > file
echo "XAX" >> file
echo "XXX" >> file
echo
./replace file X B 
cat	file.replace
echo

echo "XXX    XXX"
echo "XAX to XBX"
echo "XXX    XXX"
echo "XXX" > file
echo "XAX" >> file
echo "XXX" >> file
echo
./replace file A B 
cat	file.replace

rm file
rm file.replace
