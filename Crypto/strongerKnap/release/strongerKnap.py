from secret import flag
import libnum
import random
import re
BITS = 1024
nflag = str(libnum.s2n(flag))

x = [int(a) for a in re.findall(r'\w{4}', nflag)]
M = [random.randint(2**(BITS-1), 2**(BITS)) for i in range(len(x))]
S = sum([x[i]*M[i] for i in range(len(x))])

print('M = %s' % M)
print('S = %s' % S)
