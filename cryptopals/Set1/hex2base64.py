def chunked(str, n):
    while len(str) > 0:
        yield str[:n]
        str = str[n:]
    return

def num2base64(num):
    if num < 0 or 64 <= num:
        return None
    elif num < 26:
        return chr(ord('A') + num)
    elif num < 52:
        return chr(ord('a') + num - 26)
    elif num < 62:
        return chr(ord('0') + num - 52)
    elif num == 62:
        return '+'
    else:
        return '/'

def base642num(base64):
    if 'A' <= base64 <= 'Z':
        return ord(base64) - ord('A')
    elif 'a' <= base64 <= 'z':
        return ord(base64) - ord('a') + 26
    elif '0' <= base64 <= '9':
        return ord(base64) - ord('0') + 52
    elif base64 == '+':
        return 62
    elif base64 == '/':
        return 63
    else:
        return None

def hex2bin(hex):
    h2b = {
        '0':'0000',
        '1':'0001',
        '2':'0010',
        '3':'0011',
        '4':'0100',
        '5':'0101',
        '6':'0110',
        '7':'0111',
        '8':'1000',
        '9':'1001',
        'a':'1010',
        'b':'1011',
        'c':'1100',
        'd':'1101',
        'e':'1110',
        'f':'1111',
    }
    
    bin = ''
    for h in hex:
        bin += h2b[h]
    return bin.lstrip('0')

def bin2hex(bin):
    b2h = {
        '0000':'0',
        '0001':'1',
        '0010':'2',
        '0011':'3',
        '0100':'4',
        '0101':'5',
        '0110':'6',
        '0111':'7',
        '1000':'8',
        '1001':'9',
        '1010':'a',
        '1011':'b',
        '1100':'c',
        '1101':'d',
        '1110':'e',
        '1111':'f',
    }

    bin = '0' * (3 - (len(bin)-1) % 4) + bin
    hex = ''
    for b in chunked(bin, 4):
        hex += b2h[b]
    return hex

def bin2num(bin):
    num = 0
    for b in bin:
        num *= 2
        num += int(b)
    return num

def num2bin(num):
    bin = ''
    while num > 0:
        bin = str(num%2) + bin
        num //= 2
    return bin

def hex2base64(hex):
    base64 = ''
    bin = hex2bin(hex)
    bin = '0' * (5 - (len(bin)-1) % 6) + bin
    for b in chunked(bin, 6):
        base64 += num2base64(bin2num(b))
    return base64

def base642hex(base64):
    base64 = base64.rstrip('=')
    hex = ''
    for c in base64:
        hex += num2hex(base642num(c))
    return hex

def hex2num(hex):
    return bin2num(hex2bin(hex))

def num2hex(num):
    return bin2hex(num2bin(num))

def solve1():
    hex = '49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d'
    print(hex2base64(hex))

def solve2():
    hex1 = '1c0111001f010100061a024b53535009181c'
    hex2 = '686974207468652062756c6c277320657965'
    num1 = hex2num(hex1)
    num2 = hex2num(hex2)
    num3 = num1^num2
    return num2hex(num3)

def decodeXOR(cipher, c=' '):
    cipher = '0' * (1 - (len(cipher)-1) % 2) + cipher
    hist = dict()
    for b in chunked(cipher, 2):
        hist[b] = hist.setdefault(b,0) + 1
    key = ord(' ') ^ hex2num(max([(v, k) for k, v in hist.items()])[1])
    plain = ''
    for b in chunked(cipher, 2):
        plain += chr(hex2num(b) ^ key)
    return plain

def solve3():
    cipher = '1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736'
    return decodeXOR(cipher)

def solve4():
    cand = []
    with open('4.txt', 'r') as strings:
        for s in strings:
            # print(len(set(chunked(s.strip(), 2))), s.strip())
            plain = decodeXOR(s.strip(), ' ')
            print(list(map(lambda x: ' ' <= x <= '~', plain)))
            if all(map(lambda x: ' ' <= x <= '~', plain)):
                print(plain)
                cand.append(plain)
    return cand

def encodeXOR(plain, key):
    cipher = ''
    for i in range(len(plain)):
        cipher += num2hex(ord(key[i%len(key)]) ^ ord(plain[i]))
    cipher = '0' * (1 - (len(cipher)-1) % 2) + cipher
    return cipher

def HammingDist(str1, str2):
    bin1 = ''
    bin2 = ''
    for c1, c2 in zip(str1, str2):
        bin = num2bin(ord(c1))
        bin1 = '0' * (3 - (len(bin)-1) % 4) + bin
        bin = num2bin(ord(c2))
        bin2 = '0' * (3 - (len(bin)-1) % 4) + bin
    return len(list(filter(lambda x: x[0] != x[1], zip(bin1, bin2))))

def decodeXOR2(cipher):
    import sys
    min_dist = sys.maxsize
    std_dist = [[ks, sys.maxsize] for ks in range(41)]
    for ks in range(2, 41):
        s1 = cipher[:ks]
        s2 = cipher[ks:2*ks]
        std_dist[ks][1] =  HammingDist(s1, s2)/ks
    for i in range(3):
        ks, _ = min(std_dist, key=lambda x: x[1])
        plain = ['' for _ in range(ks)]
        for j in range(ks):
            plain[j] = decodeXOR(cipher[j::ks])
            print(plain[j])
        std_dist[ks][1] = sys.maxsize
    return None

def solve5():
    plain = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal"
    return encodeXOR(plain, 'ICE')



    
if __name__ == '__main__':
    print(solve5())
    # with open('7.txt', 'r') as f:
    #     hex = base642hex(f.read().translate(str.maketrans('','','\n')))
    #     hex = '0' * (1 - (len(hex)-1) % 2) + hex
    #     print(hex)
