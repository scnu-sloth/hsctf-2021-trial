from hashlib import md5

with open('exp2.txt', 'r') as f:
    ans = f.read().strip()

print("flag{" + md5(ans.encode()).hexdigest() + "}")