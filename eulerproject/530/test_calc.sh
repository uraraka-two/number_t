#!/bin/bash

for n in `seq 2 9`;do 
  ./a.out <<< $(bc <<< 10^$n)
done
