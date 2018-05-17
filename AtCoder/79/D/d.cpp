#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  ull K;
  ull N = 50;

  cin >> K;
  cout << N << endl;

  FOR(i, K % N) {
    cout << N + K / N + N - K % N << " ";
  }

  FOR1(i, K % N, N) {
    cout << N + K / N - K % N - 1 << " ";
  }

  cout << endl;

  return 0;
}
