#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

bool is_included(uint a, uint b) { return (a | b) == a; }

int main() {
  uint N, K;
  vector<pair<uint, ull> > vec;

  scanf("%u%u", &N, &K);

  uint ones = 0;
  vec.push_back(make_pair(K, 0ULL));
  FOR(i, 32) {
    if ((K & (ones + 1)) != 0) {
      vec.push_back(make_pair((K - (ones + 1)) | ones, 0ULL));
    }
    ones = (ones << 1) + 1;
  }

  FOR(i, N) {
    uint A, B;
    scanf("%u%u", &A, &B);

    for (auto& p : vec) {
      if (is_included(p.first, A)) {
        p.second += (ull)B;
      }
    }
  }

  auto it = max_element(
      vec.begin(), vec.end(),
      [](pair<uint, ull> a, pair<uint, ull> b) { return a.second < b.second; });

  printf("%llu\n", it->second);
  
  return 0;
}
