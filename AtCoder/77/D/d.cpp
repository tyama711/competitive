#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairInt;
typedef pair<ll, ll> pairLL;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int gcd(int a, int b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

// solve ax + by = c
pairLL* Diophantus(ll a, ll b, ll c, pairLL& out) {
  ll d = gcd(a, b);

  if (c % d != 0) return nullptr;

  ll a0 = a, a1 = b;
  ll b0 = 1, b1 = 0;
  ll c0 = 0, c1 = 1;
  while (a1 != d) {
    // cout << "a0=" << a0 << ",a1=" << a1 << endl;
    // cout << "b0=" << b0 << ",b1=" << b1 << endl;
    // cout << "c0=" << c0 << ",c1=" << c1 << endl;
    ll c0_new = b0 - a0 / a1 * c0, c1_new = b1 - a0 / a1 * c1;
    ll a0_new = a1;
    a1 = a0 % a1;
    a0 = a0_new;
    b0 = c0;
    b1 = c1;
    c0 = c0_new;
    c1 = c1_new;
  }

  out.first = c0 * c / d;
  out.second = c1 * c / d;
  return &out;
}

ull comb_mod(int n, int r, int mod) {
  ull ans = 1;
  int j = 1;

  if (n < r) return 0;

  for (int i = n; i > n - r; i--) {
    ans *= (ull)i;
    ans /= j;
    j++;
  }

  return ans % mod;
}

int main(int argc, char* argv[]) {
  const ull MOD = 1e9 + 7;
  int n;
  vector<int> vec;
  int a, b;

  cin >> n;

  vec.resize(n + 1, -1);

  FOR(i, n + 1) {
    int tmp;
    cin >> tmp;
    if (vec[tmp] != -1) {
      a = vec[tmp];
      b = i;
      break;
    } else {
      vec[tmp] = i;
    }
  }

  ll v1 = 1, v2 = 1;
  pairLL p;
  FOR(k, n + 1) {
    v1 *= n + 1 - k;
    Diophantus(k + 1, MOD, v1, p);
    cout << k + 1 << " * " << p.first << " + " << MOD << " * " << p.second
         << " = " << v1 << endl;
    v1 = p.first;
    if (v1 >= 0) {
      v1 %= MOD;
    } else {
      v1 = (v1 % MOD + MOD) % MOD;
    }

    if (k > 0) {
      v2 *= n + a - b - k + 1;
      Diophantus(k, MOD, v2, p);
      v2 = p.first;
    }

    cout << (MOD + v1 - v2) % MOD << endl;
  }

  return 0;
}
