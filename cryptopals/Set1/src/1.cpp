#include <bits/stdc++.h>
#include "1.hpp"
#include "aes.h"

using namespace std;

string remove_leading_zeros(string str) {
  int i;
  for (i = 0; i < str.size() - 1; i++) {
    if (str[i] != '0') {
      break;
    }
  }

  return str.substr(i, str.size() - i);
}

string _hex2bin(char c) {
  switch (c) {
    case '0':
      return "0000";
    case '1':
      return "0001";
    case '2':
      return "0010";
    case '3':
      return "0011";
    case '4':
      return "0100";
    case '5':
      return "0101";
    case '6':
      return "0110";
    case '7':
      return "0111";
    case '8':
      return "1000";
    case '9':
      return "1001";
    case 'a':
      return "1010";
    case 'b':
      return "1011";
    case 'c':
      return "1100";
    case 'd':
      return "1101";
    case 'e':
      return "1110";
    case 'f':
      return "1111";
    default:
      return "";
  }
}

string hex2bin(string hex) {
  string bin;

  for (auto c : hex) {
    bin += _hex2bin(tolower(c));
  }

  return bin;
}

ll bin2int(string bin) {
  ll ans = 0;

  FOR(i, bin.size()) {
    ans *= 2;
    if (bin[i] == '1') ans += 1;
  }

  return ans;
}

char _encode_base64(int n) {
  if (0 <= n && n <= 25)
    return 'A' + n;
  else if (26 <= n && n <= 51)
    return 'a' + n - 26;
  else if (52 <= n && n <= 61)
    return '0' + n - 52;
  else if (n == 62)
    return '+';
  else if (n == 63)
    return '/';
  else
    return '?';
}

string encode_base64(string hex) {
  string bin = hex2bin(hex);
  string base64;

  FOR(i, (6 - bin.size() % 6) % 6) { bin += '0'; }

  for (int i = 0; i < bin.size(); i += 6) {
    base64 += _encode_base64(bin2int(bin.substr(i, 6)));
  }

  int a = (4 - base64.size() % 4) % 4;
  FOR(i, a) { base64 += '='; }

  return base64;
}

uchar decode_base64(char c) {
  if ('A' <= c && c <= 'Z')
    return c - 'A';
  else if ('a' <= c && c <= 'z')
    return c - 'a' + 26;
  else if ('0' <= c && c <= '9')
    return c - '0' + 52;
  else if (c == '+')
    return 62;
  else
    return 63;
}

ustring decode_base64(string base64) {
  ustring plain;
  uchar a = 0;

  int rshift = -2;
  int i = 0;
  while (i < base64.size()) {
    if (rshift >= 0) {
      a += decode_base64(base64[i]) >> rshift;
    } else {
      a += decode_base64((uchar)base64[i]) << -rshift;
    }

    if (rshift >= 0) {
      plain.push_back(a);
      a = 0;
      rshift -= 8;
    } else {
      i++;
      rshift += 6;
    }
  }

  return plain;
}

uchar _hex2uc(char hex) {
  hex = tolower(hex);
  if ('0' <= hex && hex <= '9')
    return hex - '0';
  else if ('a' <= hex && hex <= 'f')
    return hex - 'a' + 10;
  else
    return 0;
}

uchar hex2uc(string hex) {
  uchar ans = 0;

  FOR(i, hex.size()) {
    ans <<= 4;
    ans += _hex2uc(hex[i]);
  }

  return ans;
}

ustring hex2ustr(string hex) {
  string hex2;
  ustring ans;

  FOR(i, (2 - hex.size() % 2) % 2) { hex2 += '0'; }
  hex2 += hex;

  for (int i = 0; i < hex2.size(); i += 2) {
    ans.push_back(hex2uc(hex2.substr(i, 2)));
  }

  return ans;
}

ull _hex2ull(char hex) {
  hex = tolower(hex);
  if ('0' <= hex && hex <= '9')
    return hex - '0';
  else if ('a' <= hex && hex <= 'f')
    return hex - 'a' + 10;
  else
    return 0;
}

ull hex2ull(string hex) {
  ull ans = 0;

  FOR(i, hex.size()) {
    ans <<= 4;
    ans += _hex2ull(hex[i]);
  }

  return ans;
}

vector<ull> hex2ullvec(string hex) {
  string hex2;
  vector<ull> ans;

  FOR(i, (16 - hex.size() % 16) % 16) { hex2 += '0'; }
  hex2 += hex;

  for (int i = 0; i < hex2.size(); i += 16) {
    ans.push_back(hex2ull(hex2.substr(i, 16)));
  }

  return ans;
}

char _uc2hex(uchar val) {
  if (0 <= val && val <= 9)
    return '0' + val;
  else if (10 <= val && val <= 15)
    return 'a' + val - 10;
  else
    return '?';
}

string uc2hex(uchar val) {
  string hex;

  if (val == 0) return "0";

  for (; val != 0; val /= 16) {
    hex += _uc2hex(val % 16);
  }

  reverse(hex.begin(), hex.end());

  return hex;
}

string ustr2hex(ustring ustr) {
  string hex;

  FOR(i, ustr.size()) {
    string hex1 = uc2hex(ustr[i]);
    FOR(j, (2 - hex1.size() % 2) % 2) { hex += '0'; }
    hex += hex1;
  }

  return remove_leading_zeros(hex);
}

char _ull2hex(ull val) {
  if (0 <= val && val <= 9)
    return '0' + val;
  else if (10 <= val && val <= 15)
    return 'a' + val - 10;
  else
    return '?';
}

string ull2hex(ull val) {
  string hex;

  if (val == 0) return "0";

  for (; val != 0; val /= 16) {
    hex += _ull2hex(val % 16);
  }

  reverse(hex.begin(), hex.end());

  return hex;
}

string ullvec2hex(vector<ull> vec) {
  string hex;

  FOR(i, vec.size()) {
    string hex1 = ull2hex(vec[i]);
    FOR(j, (16 - hex1.size() % 16) % 16) { hex += '0'; }
    hex += hex1;
  }

  return remove_leading_zeros(hex);
}

string hex_xor(string hex1, string hex2) {
  vector<ull> vec1 = hex2ullvec(hex1);
  vector<ull> vec2 = hex2ullvec(hex2);
  vector<ull> vec3;
  string hex;

  FOR(i, vec1.size()) { vec3.push_back(vec1[i] ^ vec2[i]); }
  hex = ullvec2hex(vec3);

  return hex;
}

char decode_single_byte_xor_cipher(ustring cipher, char c, string& plain) {
  map<uchar, int> hist;
  char key;

  plain.clear();

  for (int i = 0; i < cipher.size(); i++) {
    hist[cipher[i]] = hist[cipher[i]] + 1;
  }

  auto it = max_element(hist.begin(), hist.end(),
                        [](pair<uchar, int> a,
                           pair<uchar, int> b) { return a.second < b.second; });

  key = ((char)it->first) ^ c;

  for (int i = 0; i < cipher.size(); i++) {
    plain += (char)(cipher[i] ^ key);
  }

  return key;
}

char decode_single_byte_xor_cipher(ustring cipher, string& plain) {
  char key;

  for (char c = ' '; c <= '~'; c++) {
    key = decode_single_byte_xor_cipher(cipher, c, plain);
    if (is_valid_string(plain)) {
      break;
    }
  }

  return key;
}

ustring encode_repeating_xor_cipher(string plain, string key) {
  ustring cipher;
  int index = 0;

  FOR(i, plain.size()) {
    cipher += (uchar)(plain[i] ^ key[index]);
    index = (index + 1) % key.size();
  }

  return cipher;
}

string decode_repeating_xor_cipher(ustring cipher, int keysize, string& plain) {
  int index = 0;
  string key;
  vector<ustring> blocks;
  vector<string> plain_blocks;

  blocks.resize(keysize);
  plain_blocks.resize(keysize);

  FOR(i, cipher.size()) {
    blocks[index] += cipher[i];
    index = (index + 1) % keysize;
  }

  FOR(i, keysize) {
    key += decode_single_byte_xor_cipher(blocks[i], plain_blocks[i]);
  }

  FOR(i, cipher.size()) { plain += plain_blocks[i % keysize][i / keysize]; }

  return key;
}

int edit_distance(string s1, string s2) {
  int n = min(s1.size(), s2.size());
  int d = 0;

  FOR(i, n) {
    uchar c1 = s1[i];
    uchar c2 = s2[i];
    while (c1 != c2) {
      if (c1 % 2 != c2 % 2) d++;
      c1 >>= 1;
      c2 >>= 1;
    }
  }

  return d;
}

bool is_valid_string(string s) {
  for (auto c : s) {
    if (c < 0x00 || 0x7f < c) return false;
  }

  return true;
}

double normalized_edit_distance(string s, int keysize) {
  if (s.size() < 2 * keysize) {
    return -1;
  }

  double dist = 0;
  for (int i = keysize; i + keysize < s.size(); i += keysize) {
    dist += edit_distance(s.substr(0, keysize), s.substr(i, keysize));
  }

  return dist / (s.size() / keysize - 1) / keysize;
}

string decode_repeating_xor_cipher(ustring cipher, string& plain) {
  vector<pair<int, double>> dist_vec;
  string cipher_str(cipher.begin(), cipher.end());
  string key;

  FOR1(i, 2, 41) {
    dist_vec.push_back(make_pair(i, normalized_edit_distance(cipher_str, i)));
  }

  sort(dist_vec.begin(), dist_vec.end(),
       [](pair<int, double> a,
          pair<int, double> b) { return a.second < b.second; });

  for (auto p : dist_vec) {
    key = decode_repeating_xor_cipher(cipher, p.first, plain);
    if (is_valid_string(plain)) {
      return key;
    }
  }

  return nullptr;
}

int main(int argc, char* argv[]) {
  string line, input;
  string plain;
  ustring ustr;

  while (getline(cin, line)) {
    input += line;
  }

  ustr = decode_base64(input);

  string key = "YELLOW SUBMARINE";

  uint8_t in[8];

  uint8_t out[16];  // 128

  uint8_t* w;  // expanded key

  int Nb = 4;
  int Nk;
  int Nr;

  switch (sizeof(key)) {
    default:
    case 16:
      Nk = 4;
      Nr = 10;
      break;
    case 24:
      Nk = 6;
      Nr = 12;
      break;
    case 32:
      Nk = 8;
      Nr = 14;
      break;
  }

  w = (uint8_t*)malloc(Nb * (Nr + 1) * 4);

  key_expansion((uint8_t*)key.c_str(), w);


  for (int j = 0; j < ustr.size(); j += 16) {
    memcpy(out, ustr.c_str() + j, 16);
    inv_cipher(out, in, w);
    
    FOR(i, 4) {
      printf("%c%c%c%c", in[4 * i + 0], in[4 * i + 1], in[4 * i + 2],
             in[4 * i + 3]);
    }
  }

  printf("\n");

  exit(0);

  return 0;
}
