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
  vector<int> X = {4, 1, 6, 2, 8, 5, 7, 3};
  vector<int> L;
  int length = 0;
  auto it = X.begin();

  L.push_back(*it);
  it++;
  length++;

  for (; it != X.end(); it++) {
    if (L[length - 1] < *it) {
      L.push_back(*it);
      length++;
    } else {
      auto it2 = bin_search(L, *it);
      *it2 = *it;
    }
  }

  printf("%d\n", length);
  for_each(L.begin(), L.end(), [](int x) { printf("%d ", x); });
  printf("\n");

  return 0;
}
