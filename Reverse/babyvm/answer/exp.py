dst = [10, 1, 15, 8, 19, 125, 90, 29, 1, 23, 121, 86, 19, 126, 15, 26, 99, 31, 17, 6, 30, 11, 19, 72, 26, 17, 105, 31, 68, 25, 19, 14]
flag = []

for i in range(32):
    flag.append((((dst[i]+64)^0xCC)-32)^i)

print(''.join(map(chr,flag)))

# def puts(l, s):
#     for x in s:
#         l += [0x01, 0x1, ord(x)]
#         l += [0x06, 0x1]
#     l += [0x01, 0x1, ord('\n')]
#     l += [0x06, 0x1]

# op = []

# op += [0x01, 0x1, 0x0]
# for i in range(32):
#     op += [0x21, 0x01, dst[i]]
#     op += [0x02, 0x01]

# puts(op, "What is your flag?")

# op += [0x01, 0x1, 0x0]
# op += [0x05, 0x2]
# op += [0x03, 0x2]
# op += [0x02, 0x1]
# op += [0x07, 0x1, 32]
# op += [0x08, 0xf5]

# op += [0x01, 0x1, 0x0]
# op += [0x0A, 0x1, 64]
# op += [0x02, 0x1]
# op += [0x07, 0x1, 32]
# op += [0x08, 0xf6]

# op += [0x01, 0x1, 64]
# op += [0x04, 0x2]
# op += [0x0B, 0x1, 0x1]
# op += [0x31, 0x1, 0x2]
# op += [0x07, 0x1, 32]
# op += [0x08, 0xf3]

# op += [0x01, 0x1, 32]
# op += [0x11, 0x2, 0x1]
# op += [0x0B, 0x2, 32]
# op += [0x19, 0x1, 0x2]
# op += [0x02, 0x1]
# op += [0x07, 0x1, 64]
# op += [0x08, 0xf0]

# op += [0x01, 0x1, 32]
# op += [0x0A, 0x1, 32]
# op += [0x02, 0x1]
# op += [0x07, 0x1, 64]
# op += [0x08, 0xf6]

# op += [0x01, 0x1, 0x0]
# op += [0x01, 0x2, 32]
# op += [0x09, 0x1, 0xCC]
# op += [0x17, 0x1, 0x02]
# op += [0x08, 0x2e]
# op += [0x02, 0x1]
# op += [0x02, 0x2]
# op += [0x07, 0x1, 32]
# op += [0x08, 0xef]
# puts(op, "Right!")
# op += [0x18, 0x23]
# puts(op, "Wrong!")
# op += [0x00]

# print(op)