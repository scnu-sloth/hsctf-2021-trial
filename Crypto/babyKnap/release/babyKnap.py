from secret import flag
import libnum
import random
BITS = 64
N = 8

M = [random.randint(2**(BITS-1), 2**(BITS)) for i in range(N)]
xs = ['{:08b}'.format(a) for a in flag]
Ss = []
for x in xs:
    x = [int(a) for a in list(x)]
    S = sum([x[i]*M[i] for i in range(N)])
    Ss.append(S)

print('M = %s' % M)
print('Ss = %s' % Ss)
