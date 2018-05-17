#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  int n;
  vector<uint32_t> a;

  cin >> n;

  FOR(i, n) {
    uint32_t tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  for (int i = n - 1; i >= 0; i -= 2) {
    cout << a[i] << " ";
  }

  for (int i = n % 2; i < n; i += 2) {
    cout << a[i] << " ";
  }

  cout << endl;

  return 0;
}
