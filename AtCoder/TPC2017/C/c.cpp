#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main() {
  int N;

  scanf("%d", &N);

  FOR1(h, 1, 3501) {
    FOR1(n, h, 3501) {
      ll a = (ll)N * h * n;
      ll b = (ll)4 * h * n - N * n - N * h;
      if (b > 0 && a % b == 0) {
        ll w = a / b;
        printf("%d %d %lld\n", h, n, w);
        goto LOOP_END;
      }
    }
  }
LOOP_END:
  
  return 0;
}
