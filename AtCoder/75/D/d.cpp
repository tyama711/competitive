#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int dp(vector<ll> h, int N, int A, int B, int v) {
  ll s;

  FOR(i, h.size()) { cout << h[i]; }
  cout << endl;

  s = accumulate(h.begin(), h.end(), 0LL);

  int n = (s - 1) / (A + (N - 1) * B) + 1;

  for (auto& x : h) x -= n * B;

  int c = count_if(h.begin(), h.end(), [](ll a) { return a > 0; });
  h.resize(c);

  FOR(i, n) {
    auto it = max_element(h.begin(), h.end());
    *it -= A - B;
  }

  c = count_if(h.begin(), h.end(), [](ll a) { return a > 0; });
  sort(h.begin(), h.end(), [](ll a, ll b) { return a > b; });
  h.resize(c);

  auto it = max_element(h.begin(), h.end());
  if (*it <= 0)
    return n + v;
  else
    return dp(h, c, A, B, n + v);
}

int main(int argc, char* argv[]) {
  int N, A, B;
  vector<ll> h;

  cin >> N >> A >> B;
  h.resize(N);
  FOR(i, N) { cin >> h[i]; }
  sort(h.begin(), h.end(), [](ll a, ll b) { return a > b; });

  cout << dp(h, N, A, B, 0) << endl;

  return 0;
}
