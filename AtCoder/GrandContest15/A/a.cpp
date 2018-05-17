#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  int N, A, B;
  ll mx, mn;

  cin >> N >> A >> B;
  mx = (ll)(N - 1) * B + A;
  mn = (ll)(N - 1) * A + B;
  cout << MAX(mx - mn + 1, 0) << endl;

  return 0;
}
