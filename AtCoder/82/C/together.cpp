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
  vector<int> hist(1e5);

  scanf("%d", &N);

  FOR(i, N) {
    int a;
    scanf("%d", &a);
    FOR1(j, MAX(0, a - 1), MIN(a + 2, 1e5-1)) hist[j]++;
  }

  auto it = max_element(hist.begin(), hist.end());
  printf("%d\n", *it);

  return 0;
}
