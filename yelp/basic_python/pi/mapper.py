#!/usr/bin/env python

import sys
import random
import math

#total point in the square
N,count = 100000,0
for i in range(N):
    x = random.random()
    y = random.random()
    if x**2 + y**2 < 1:
        count += 1

print "%d \t %d" %(N,count) 
