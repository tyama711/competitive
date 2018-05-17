#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  int H, W, N;
  int table[100][100] = {0};

  scanf("%d%d%d", &H, &W, &N);

  int index = 0;
  FOR1(i, 1, N + 1) {
    int a;

    scanf("%d", &a);

    FOR(j, a) {
      table[index / W][min(index % (2 * W), 2 * W - index % (2 * W) - 1)] = i;
      index++;
    }
  }

  FOR(i, H) {
    FOR(j, W) printf("%d ", table[i][j]);
    printf("\n");
  }

  return 0;
}
