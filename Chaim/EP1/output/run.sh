#!/bin/bash

for ((X=1; X<=10; X++))
do
  ./ep1 < t${X}.in > t${X}m.out && diff t${X}m.out t${X}.out
done
