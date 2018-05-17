#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[argc]) {
  int N;
  vector<tuple<int, int, int>> coefs;
  priority_queue<double> que_x, que_y;

  scanf("%d", &N);

  FOR(i, N) {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    coefs.push_back(make_tuple(A, B, C));
  }

  FOR(i, N) {
    FOR1(j, i+1, N) {
      double x = (double)(get<1>(coefs[i]) * get<2>(coefs[j]) -
                          get<2>(coefs[i]) * get<1>(coefs[j])) /
                 (get<1>(coefs[i]) * get<0>(coefs[j]) -
                  get<0>(coefs[i]) * get<1>(coefs[j]));
      double y = (double)(get<2>(coefs[i]) * get<0>(coefs[j]) -
                          get<0>(coefs[i]) * get<2>(coefs[j])) /
                 (get<1>(coefs[i]) * get<0>(coefs[j]) -
                  get<0>(coefs[i]) * get<1>(coefs[j]));

      que_x.push(x);
      que_y.push(y);

      if (que_x.size() > (N * (N - 1) / 2 + 1) / 2) {
        que_x.pop();
        que_y.pop();
      }
    }
  }

  printf("%.10lf %.10lf\n", que_x.top(), que_y.top());

  return 0;
}
