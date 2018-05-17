#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  int N;
  vector<ull> a;
  vector<ull> add;
  ull count = 0;

  cin >> N;
  a.resize(N);
  add.resize(N);

  FOR(i, N) { cin >> a[i]; }

  int last = N - 1;
  for (int i = 0;; i = (i + 1) % N) {
    a[i] += add[(i + N - 1) % N] - add[i];
    if (a[i] >= N) {
      add[i] = add[(i + N - 1) % N] + a[i] / N;
      count += a[i] / N;
      a[i] %= N;
      last = i;
    } else if (last != i) {
      add[i] = add[(i + N - 1) % N];
    } else {
      break;
    }
  }

  cout << count << endl;

  return 0;
}
