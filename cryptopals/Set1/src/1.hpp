#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned uint;
typedef unsigned char uchar;
typedef std::pair<uint, uint> pairUInt;
typedef std::basic_string<uchar> ustring;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)

std::string remove_leading_zeros(std::string str);

std::string _hex2bin(char c);
std::string hex2bin(std::string hex);

ll bin2int(std::string bin);

char _encode_base64(int n);
std::string encode_base64(std::string hex);

uchar decode_base64(char c);
ustring decode_base64(std::string base64);

uchar _hex2uc(char hex);
uchar hex2uc(std::string hex);
ustring hex2ustr(std::string hex);

ull _hex2ull(char hex);
ull hex2ull(std::string hex);
std::vector<ull> hex2ullvec(std::string hex);

char _uc2hex(uchar val);
std::string uc2hex(uchar val);
std::string ustr2hex(ustring ustr);

char _ull2hex(ull val);
std::string ull2hex(ull val);
std::string ullvec2hex(std::vector<ull> vec);

std::string hex_xor(std::string hex1, std::string hex2);

char decode_single_byte_xor_cipher(ustring cipher, char c, std::string& plain);
char decode_single_byte_xor_cipher(ustring cipher);

ustring encode_repeating_xor_cipher(std::string plain, std::string key);
std::string decode_repeating_xor_cipher(ustring cipher, int keysize, std::string& plain);

int edit_distance(std::string s1, std::string s2);
double normalized_edit_distance(std::string s, int keysize);

bool is_valid_string(std::string s);

std::string decode_repeating_xor_cipher(ustring cipher);
