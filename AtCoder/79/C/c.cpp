#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

typedef multimap<int, int> MII;

int main(int argc, char *argv[]) {
  int N, M;
  MII mp;
  set<int> visited;
  queue< pair<int, int> > que;

  cin >> N >> M;

  FOR(i, M) {
    int a, b;
    
    cin >> a >> b;
    
    mp.insert(make_pair(a, b));
    mp.insert(make_pair(b, a));
  }

  bool flag = false;
  int init = 1;
  visited.insert(init);
  que.push(make_pair(init, 0));

  while (!que.empty()) {
    pair<int, int> v = que.front();
    que.pop();
    
    if (v.first == N) {
      flag = true;
      break;
    }
    
    pair< MII::iterator, MII::iterator > p = mp.equal_range(v.first);
    for (auto it = p.first; it != p.second; it++) {
      if (visited.find(it->second) == visited.end()) {
        visited.insert(it->second);
        if (v.second < 2)
          que.push(make_pair(it->second, v.second + 1));
      }
    }
  }

  if (flag == true)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}
