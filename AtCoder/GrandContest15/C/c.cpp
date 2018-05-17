#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  int N, M, Q;
  vector<vector<int>> S;
  vector<vector<int>> ECOL, EROW, V;

  cin >> N >> M >> Q;

  S.resize(N);
  ECOL.resize(N + 1);
  EROW.resize(N + 1);
  V.resize(N + 1);
  FOR(i, N) S[i].resize(M, 0);
  FOR(i, N + 1) {
    ECOL[i].resize(M + 1, 0);
    EROW[i].resize(M + 1, 0);
    V[i].resize(M + 1, 0);
  }

  FOR(i, N) {
    FOR(j, M) {
      char c;
      scanf(" %c", &c);
      S[i][j] = c - '0';
    }
  }

  FOR(i, M) { V[1][i + 1] = S[0][i]; }
  FOR1(i, 2, N + 1) {
    FOR1(j, 1, M + 1) { V[i][j] = V[i - 1][j] + S[i - 1][j - 1]; }
  }
  FOR(i, N + 1) {
    FOR1(j, 1, M + 1) { V[i][j] += V[i][j - 1]; }
  }

  FOR1(i, 2, N + 1) {
    FOR1(j, 1, M + 1) {
      ECOL[i][j] = ECOL[i - 1][j] + S[i - 2][j - 1] * S[i - 1][j - 1];
    }
  }
  FOR(i, N + 1) {
    FOR1(j, 1, M + 1) { ECOL[i][j] += ECOL[i][j - 1]; }
  }

  FOR1(i, 1, N + 1) {
    FOR1(j, 2, M + 1) {
      EROW[i][j] = EROW[i][j - 1] + S[i - 1][j - 2] * S[i - 1][j - 1];
    }
  }
  FOR1(i, 1, N + 1) {
    FOR(j, M + 1) { EROW[i][j] += EROW[i - 1][j]; }
  }

  FOR(i, Q) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int v = V[x2][y2] - V[x2][y1 - 1] - V[x1 - 1][y2] + V[x1 - 1][y1 - 1];
    int e = ECOL[x2][y2] - ECOL[x2][y1 - 1] - ECOL[x1][y2] + ECOL[x1][y1 - 1] +
            EROW[x2][y2] - EROW[x2][y1] - EROW[x1 - 1][y2] + EROW[x1 - 1][y1];

    cout << v - e << endl;
  }

  return 0;
}
