#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

ull powULL(ull base, unsigned exp) {
  if (exp == 0)
    return 1;
  else if (exp % 2 == 0)
    return powULL(base * base, exp / 2);
  else
    return base * powULL(base, exp - 1);
}

int nlz(ull a) {
  int i = 64;
  while (a > 0) {
    i--;
    a >>= 1;
  }
  return i;
}

ull dp(ull a, ull b) {
  int i = 0, j = 0;

  i = 63 - nlz(a);
  j = 63 - nlz(b);

  if (a == 0) return powULL(2, j + 1);

  ull tmp1 = powULL(2, j);
  int k = 63 - nlz(b-tmp1);
  ull tmp2 = powULL(2, k+1);
  if (i == j)
    return dp(a - tmp1, b - tmp1);
  else if (a >= tmp2)
    return 2*tmp1 + tmp2 - 2 * a;
  else
    return 2 * tmp1 - a;
}

int main(int argc, char *argv[]) {
  ull A, B;

  cin >> A >> B;
  cout << dp(A, B) << endl;
  return 0;
}
