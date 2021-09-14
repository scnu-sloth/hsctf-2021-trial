from Crypto.Hash import SHA3_256
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from flag import flag

# parameters
N = 509
p = 3
q = 2048
d = 5
assert q>(6*d+1)*p

R.<x> = ZZ['x']

# #o 1s and #mo -1s
def T(o, mo, N):
    global R
    assert N>=o+mo
    s=[1]*o+[-1]*mo+[0]*(N-o-mo)
    shuffle(s)
    return R(s)

def invertmodprime(f,p):
    global N, R
    Rp = R.change_ring(Integers(p)).quotient(x^N-1)
    return R(lift(1 / Rp(f)))

def convolution(f,g):
    global N
    return (f * g) % (x^N-1)

def balancedmod(f,q):
    global N, R
    g = list(((f[i] + q//2) % q) - q//2 for i in range(N))
    return R(g)

def invertmodpowerof2(f,q):
    global N, R
    assert q.is_power_of(2)
    g = invertmodprime(f,2)
    while True:
        r = balancedmod(convolution(g,f),q)
        if r == 1: return g
        g = balancedmod(convolution(g,2 - r),q)

# step1
ra = T(d, d, N)
sa = T(d, d, N)
ea = balancedmod(p*ra + sa, q)
print('Ea = %s' % str(ea))

# step2
rb = T(d, d, N)
sb = T(d, d, N)
eb = balancedmod(p*rb + sb, q)
print('Eb = %s' % str(eb))

# step3
aa = balancedmod(convolution(sa, eb), q)
Ka = balancedmod(aa, p)

# step4
ab = balancedmod(convolution(sb, ea), q)
Kb = balancedmod(ab, p)

# Key
assert Ka==Kb

hobj = SHA3_256.new()
hobj.update(bytes(str(Ka).encode('utf-8')))
Key = hobj.digest()

# Cipher
cipher = AES.new(Key, AES.MODE_ECB)
c = cipher.encrypt(pad(flag, 32))
print('Cipher = %s' % c)


