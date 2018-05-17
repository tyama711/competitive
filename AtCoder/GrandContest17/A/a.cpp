#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

ull comb(uint32_t n, uint32_t r) {
  ull ans = 1;

  for (uint32_t i = n; i > n - r; i--) {
    ans *= (ull)i;
    ans /= n - i + 1;
  }

  return ans;
}

ull pow_ull(ull base, uint32_t exp) {
  if (exp == 0)
    return 1ULL;
  
  if (exp % 2 == 1)
    return base * pow(base, exp - 1);
  else {
    ull tmp = pow(base, exp / 2);
    return tmp * tmp;
  }
}

int main(int argc, char *argv[]) {
  int N, P;
  uint32_t num_even = 0;
  uint32_t num_odd = 0;

  cin >> N >> P;

  FOR(i, N) {
    int a;
    cin >> a;
    if (a % 2 == 0)
      num_even ++;
    else
      num_odd ++;
  }

  if (num_odd == 0) {
    if (P == 0)
      cout << pow_ull(2ULL, num_even) << endl;
    else
      cout << 0 << endl;
  }
  else
    cout << pow_ull(2ULL, num_even) * pow_ull(2ULL, num_odd - 1) << endl;

  return 0;
}
