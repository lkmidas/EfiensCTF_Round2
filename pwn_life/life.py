#!/usr/bin/python2.7

import random

colors = ["Do", "Hong", "Tim", "Cam", "Xanh bien", "Xanh la"]

try:
	name = input("Ban ten gi?\n")
except:
	pass

color = random.choice(colors)
print "Cuoc doi ban mau: %s" % color 
