import sys
sys.path.append("/usr/lib/python2.7/dist-packages/")  # for gmpy2
 
from sage.all import *
from ntru import PublicKey, PrivateKey, decrypt
 
pub = PublicKey()
pub.read("key.public")
h = int(pub.h)
q = int(pub.q)
 
M = MatrixSpace(ZZ, 2)([
    [1, h],
    [0, q],
])
 
ML = M.LLL()
 
print ML.str()
print "-"
 
for row in ML.rows():
    f, g = row
    if f < 0 and g < 0:
        g *= -1
        f *= -1
    if f > 0 and g > 0:
        break
else:
    print "error, try linear combination?"
    quit()
 
assert (g * inverse_mod(f, q)) % q == h
assert g < sqrt(q)
assert f < sqrt(q)
 
priv = PrivateKey()
priv.__dict__.update(f=long(f), g=long(g), q=long(q))
s = open("ciphertext.bin", "rb").read()
print decrypt(s, priv)
