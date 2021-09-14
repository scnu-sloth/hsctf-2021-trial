from Crypto.Hash import SHA3_256
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad

# parameters
N = 509
p = 3
q = 2048
d = 5

R.<x> = ZZ['x']

# functions
def convolution(f,g):
    global N
    return (f * g) % (x^N-1)

def balancedmod(f,q):
    global N, R
    g = list(((f[i] + q//2) % q) - q//2 for i in range(N))
    return R(g)

# from out
Ea = x^468 - 3*x^457 - x^418 + x^377 - x^281 - 3*x^276 - 3*x^270 + 3*x^244 + x^241 + 3*x^220 + 3*x^219 - x^185 - 3*x^149 - x^138 + x^110 + 3*x^58 + 3*x^47 - x^41 + x^40 - 3*x^35
Eb = x^499 - x^495 + 3*x^485 + 3*x^472 - x^454 + x^429 - x^421 - 3*x^389 - 3*x^383 + x^381 - 3*x^350 - x^324 + 3*x^302 - x^287 + 3*x^229 + 3*x^221 - 3*x^207 - 3*x^97 + x^52 + x^40
Cipher = b'\xb6\xe2\xa5\x07\xe7\xe8!!\xac\xb8\xb8\r\x06\xd4`\xf9=\x15f\xd2\x8f\x98\xfa\xfc\x0e\xd0_\xd5\xe6\xe3\x10t\x92\xfd\x01+c\x88ZNR!p\xeb\x8e\x84\x81\xf0N\xff\xa4\xc8B\x90\\\n\xbd%\x8d\x1f/\xb4\x85T'
Ea = R(Ea)
Eb = R(Eb)

# hack
K = balancedmod(balancedmod(convolution(Ea, Eb), q), p)

# Key
hobj = SHA3_256.new()
hobj.update(bytes(str(K).encode('utf-8')))
Key = hobj.digest()

# decrypt
aes = AES.new(Key, AES.MODE_ECB)
flag = aes.decrypt(Cipher)
print(unpad(flag, 32))







