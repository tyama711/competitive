#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

uint32_t gcd(uint32_t a, uint32_t b) {
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
  uint32_t N, K, A, MAXA;
  uint32_t total_gcd;

  cin >> N >> K >> A;

  total_gcd = MAXA = A;
  FOR(i, N-1) {
    cin >> A;
    if (A > MAXA)
      MAXA = A;
    total_gcd = gcd(total_gcd, A);
  }

  if (K <= MAXA && K % total_gcd == 0)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  
  return 0;
}
