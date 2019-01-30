from gmpy2 import next_prime, powmod
from random import randint

flag = "11af8b73b! Gau gau gau! Buscu buscu buscu! DLV DLV DLV!" # NOT FLAG
flag = int(flag.encode('hex'), 16)

size = 2**512

c = next_prime(randint(0, size))
o = next_prime(c + randint(0, 2**64))
t = c*o
h = "t = {:x}".format(t)
a = powmod(flag, 0x10006, t)
n = "a = {:x}".format(a)

print h
print n
