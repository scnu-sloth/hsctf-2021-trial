from binascii import hexlify, unhexlify
from Cryptodome.Cipher import DES

from base64 import b64encode
from Cryptodome.Hash import SHA256
from Cryptodome.Protocol.KDF import bcrypt_check

def enumerateKey1(plaintext):
    text_set = {}
    for k0 in range(33, 127, 1):
        for k1 in range(33, 127, 1):
            for k2 in range(33, 127, 1):
                key1_str = 'A' + chr(k0) + chr(k1) + chr(k2)
                key1 = hexlify(key1_str.encode())
                cipher1 = DES.new(key1, DES.MODE_ECB)
                text = cipher1.encrypt(plaintext)

                if text_set.get(text, None) == None:
                    text_set[text] = []
                text_set[text].append(key1_str)
    return text_set

if __name__ == '__main__':
    with open('output.txt', 'r') as infile:
        m = infile.readline()[:-1]
        c_hex = infile.readline()[:-1]
    c = unhexlify(c_hex)

    print('enumerateKey1 start')
    text_set = enumerateKey1(m.encode())
    print('enumerateKey1 finish')

    for k0 in range(33, 127, 1):
        for k1 in range(33, 127, 1):
            for k2 in range(33, 127, 1):
                key2_str = chr(k0) + chr(k1) + chr(k2) + '!'
                key2 = hexlify(key2_str.encode())
                cipher2 = DES.new(key2, DES.MODE_ECB)
                text = cipher2.decrypt(c)
                key1_str_list = text_set.get(text, None)

                if key1_str_list != None:
                    for key1_str in key1_str_list:
                        flag = 'hsctf{' + key1_str + key2_str + '}'

                        b64flag = b64encode(SHA256.new(flag.encode()).digest())
                        try:
                            bcrypt_check(b64flag, b'$2a$12$mDXutpxXvUiUKlvU8CYcueFyyD6tETTJe66Qgzpc.yigCrrHtWeq2')
                            print(flag)
                        except:
                            continue

