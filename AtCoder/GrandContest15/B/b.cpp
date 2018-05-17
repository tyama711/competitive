#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  string s;
  ll ans = 0;
  int N;

  cin >> s;

  N = s.size();
  FOR(i, N) {
    if (s[i] == 'U')
      ans += i;
    else if (s[i] == 'D')
      ans += N - i - 1;
  }
  ans += (ll)N * (N - 1);

  cout << ans << endl;

  return 0;
}
