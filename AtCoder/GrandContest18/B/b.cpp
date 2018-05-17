#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

class custom_less {
 public:
  bool operator()(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
  }
};

int main(int argc, char* argv[]) {
  int N, M;
  vector<priority_queue<pair<int, int>, vector<pair<int, int>>, custom_less>>
      que_vec;
  set<int> delete_sports;
  vector<int> num_of_people;
  int ans = 1000;

  cin >> N >> M;

  que_vec.resize(N);
  num_of_people.resize(M);

  FOR(i, N) {
    for (int j = M - 1; j >= 0; j--) {
      int A;
      cin >> A;
      que_vec[i].push(make_pair(A - 1, j));
    }
  }

  FOR(j, M) {
    FOR(k, M)
    num_of_people[k] = 0;

    FOR(i, N) {
      while (delete_sports.find(que_vec[i].top().first) != delete_sports.end())
        que_vec[i].pop();

      num_of_people[que_vec[i].top().first]++;
    }

    auto it = max_element(num_of_people.begin(), num_of_people.end());
    if (*it < ans) ans = *it;
    delete_sports.insert(it - num_of_people.begin());
  }

  cout << ans << endl;

  return 0;
}
