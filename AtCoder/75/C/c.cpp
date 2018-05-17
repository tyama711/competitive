#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  set<int> score;
  int N;
  score.insert(0);

  cin >> N;

  FOR(i, N) {
    int s;
    set<int> score2(score);
    cin >> s;
    for (auto x : score) {
      score2.insert(x + s);
    }
    score = score2;
  }

  auto it = max_element(score.begin(), score.end(), [](int a, int b) {
    if (a % 10 == 0) a = 0;
    if (b % 10 == 0) b = 0;
    return a < b;
  });

  cout << *it << endl;
  
  return 0;
}
