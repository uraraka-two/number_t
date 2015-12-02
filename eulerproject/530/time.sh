#!/bin/bash

default_n=$1
if [ -z $default_n ]; then
  default_n=9
fi
time ./a.out <<< $(bc <<< 10^${default_n})
