#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairInt;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

vector<int>::iterator bin_search(vector<int>& vec, const int& key) {
  int a = 0, b = vec.size() - 1;

  while (a <= b) {
    int c = (a + b) / 2;
    if (key == vec[c])
      return vec.begin() + c;
    else if (key < vec[c])
      b = c - 1;
    else
      a = c + 1;
  }

  return vec.begin() + a;
}

int main(int argc, char* argv[]) {
  int x1, y1, x2, y2;
  int N;
  vector<pairInt> X;
  int x_sign = 1;
  int y_sign = 1;

  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  if (x1 > x2) {
    x1 *= -1;
    x2 *= -1;
    x_sign = -1;
  }
  if (y1 > y2) {
    y1 *= -1;
    y2 *= -1;
    y_sign = -1;
  }

  scanf("%d", &N);

  FOR(i, N) {
    int x, y;
    scanf("%d %d", &x, &y);
    x *= x_sign;
    y *= y_sign;
    if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
      X.push_back(make_pair(x, y));
    }
  }

  sort(X.begin(), X.end());

  int length = 0;
  if (X.size() > 0) {
    vector<int> L;
    auto it = X.begin();

    L.push_back(it->second);
    it++;
    length++;

    for (; it != X.end(); it++) {
      if (L[length - 1] < it->second) {
        L.push_back(it->second);
        length++;
      } else {
        auto it2 = bin_search(L, it->second);
        *it2 = it->second;
      }
    }
  }

  double ans = (x2 - x1 + y2 - y1) * 100;
  ans -= length * (20 - 5 * M_PI);
  if (length == min(x2 - x1, y2 - y1) + 1) {
    ans += 5 * M_PI;
  }

  printf("%.14lf\n", ans);

  return 0;
}
