from binascii import hexlify

# https://pycryptodome.readthedocs.io/en/latest/src/installation.html
from Cryptodome.Cipher import DES

from base64 import b64encode
from Cryptodome.Hash import SHA256
from Cryptodome.Protocol.KDF import bcrypt_check

from flag import flag
# hint1: flag = 'hsctf{A******!}'
# hint2 begin
# https://pycryptodome.readthedocs.io/en/latest/src/protocol/kdf.html#bcrypt
b64flag = b64encode(SHA256.new(flag).digest())
try:
    bcrypt_check(b64flag, b'$2a$12$mDXutpxXvUiUKlvU8CYcueFyyD6tETTJe66Qgzpc.yigCrrHtWeq2')
except:
    print('flag error')
    exit(0)
# hint2 end

class DoubleDES:
    def __init__(self, key):
        assert(len(key) == 16)
        key1 = key[0:8]
        key2 = key[8:16]

        self.cipher1 = DES.new(key1, DES.MODE_ECB)
        self.cipher2 = DES.new(key2, DES.MODE_ECB)

    def encrypt(self, plaintext):
        text = self.cipher1.encrypt(plaintext)
        ciphertext = self.cipher2.encrypt(text)
        return ciphertext

    def decrypt(self, ciphertext):
        text = self.cipher2.decrypt(ciphertext)
        plaintext = self.cipher1.decrypt(text)
        return plaintext

if __name__ == '__main__':
    key = hexlify(flag[6:-1]) # hexlify('A******!')
    DD = DoubleDES(key)

    m = b'01234567'
    c = DD.encrypt(m)
    c_hex = hexlify(c)
    with open('output.txt', 'w+') as outfile:
        outfile.write(m.decode())
        outfile.write('\n')
        outfile.write(c_hex.decode())
        outfile.write('\n')

