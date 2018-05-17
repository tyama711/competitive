#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  string A;
  int count[26] = {0};
  ll ans = 1;

  cin >> A;

  count[A[0] - 'a'] ++;
  FOR1(i, 1, A.size()) {
    ans += i - count[A[i] - 'a'];
    count[A[i] - 'a'] ++;
  }

  cout << ans << endl;

  return 0;
}
