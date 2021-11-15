from pwn import *
from hashlib import md5

# context.log_level = 'debug'
r = process("./ezMath")
end = 'Congratulations!'
flag = ''

r.readline()
r.readline()
r.readline()

while True:
    cal = r.readline()
    if cal[:len(end)] == end:
        print(cal)
        break
    ans = str(eval(cal))
    flag += ans
    r.sendline(ans)
    if r.readline() != 'OK! \n':
        print("???")
        break

print("flag{" + md5(flag.encode()).hexdigest() + "}")
r.interactive()