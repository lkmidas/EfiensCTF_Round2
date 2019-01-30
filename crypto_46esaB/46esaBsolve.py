import base64

f = open('S0meTh1ng.txt', 'r')
t = f.read()

while (efiens not in t):
	t = base64.b64decode(t)

print t