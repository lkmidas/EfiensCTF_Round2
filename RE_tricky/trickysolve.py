from pwn import *

r = remote('139.180.137.27', 2226)

legal = range(48,57) + range(65,90) + range(97,127)
pass1_len = 4
flag = 0
while True:
    for i in legal:
        j = 0xff - i*(pass1_len/4 - 1)
        if j in legal:
            pass1 = chr(i)*(pass1_len - 4) + chr(j)*4
            flag = 1
            break;
    if flag == 1:
        break;
    pass1_len += 4

pass2 = '14ae5ee7a285'

r.recvuntil("Enter first password: ")
r.sendline(pass1)
r.recvuntil("Enter second password: ")
r.sendline(pass2)
r.interactive()
