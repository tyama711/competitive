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
  string S1, S2;
  const ll MOD = 1e9 + 7;

  cin >> N;
  cin >> S1;
  cin >> S2;

  ll comb = 1;
  int type;
  int index = 0;

  if (S1[0] == S2[0]) {
    comb = 3;
    type = 1;
    index++;
  } else {
    comb = 6;
    type = 2;
    index += 2;
  }

  while (index < N) {
    if (S1[index] == S2[index]) {
      if (type == 1) {
        comb *= 2;
      }
      type = 1;
      index++;
    } else {
      if (type == 1) {
        comb *= 2;
      } else {
        comb *= 3;
      }
      type = 2;
      index += 2;
    }

    comb %= MOD;
  }

  cout << comb << endl;

  return 0;
}
