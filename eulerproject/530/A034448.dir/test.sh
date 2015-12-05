#!/bin/bash

paste -d '-' 530 A034448 | while read i;do echo $i=$(bc <<< $i) ;done | nl

