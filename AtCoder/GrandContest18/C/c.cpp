#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

template <typename T>
using triple = tuple<T, T, T>;

class custom_less {
 public:
  bool operator()(const triple<ll>& x, const triple<ll>& y) {
    return get<2>(x) - get<1>(x) < get<2>(y) - get<1>(y);
  }
};

class custom_less2 {
 public:
  bool operator()(const triple<ll>& x, const triple<ll>& y) {
    return get<2>(x) - get<0>(x) < get<2>(y) - get<0>(y);
  }
};

int main(int argc, char* argv[]) {
  int X, Y, Z, N;
  vector<triple<ll>> coins;

  cin >> X >> Y >> Z;

  N = X + Y + Z;

  FOR(i, N) {
    ll A, B, C;
    cin >> A >> B >> C;
    coins.push_back(make_tuple(A, B, C));
  }

  sort(coins.begin(), coins.end(), [](triple<ll>& x, triple<ll>& y) {
    return get<0>(x) - get<1>(x) < get<0>(y) - get<1>(y);
  });

  vector<ll> vec;
  vec.resize(N);

  priority_queue<triple<ll>, vector<triple<ll>>, custom_less> que;

  FOR(i, Y) {
    vec[Y-1] += get<1>(coins[i]);
    que.push(coins[i]);
  }

  FOR1(K, Y, N - X) {
    vec[K] += vec[K - 1];

    if (get<1>(que.top()) - get<2>(que.top()) <
        get<1>(coins[K]) - get<2>(coins[K])) {
      vec[K] -= get<1>(que.top());
      vec[K] += get<1>(coins[K]);
      vec[K] += get<2>(que.top());
      que.pop();
      que.push(coins[K]);
    } else {
      vec[K] += get<2>(coins[K]);
    }
  }

  priority_queue<triple<ll>, vector<triple<ll>>, custom_less2> que2;

  FOR1(i, N - X, N) {
    vec[N - X - 1] += get<0>(coins[i]);
    que2.push(coins[i]);
  }

  for (int K = N - X - 1; K >= Y; K--) {
    vec[K - 1] += vec[K];

    if (get<0>(que2.top()) - get<2>(que2.top()) <
        get<0>(coins[K]) - get<2>(coins[K])) {
      vec[K - 1] -= get<0>(que2.top());
      vec[K - 1] += get<0>(coins[K]);
      vec[K - 1] += get<2>(que2.top());
      que2.pop();
      que2.push(coins[K]);
    } else {
      vec[K - 1] += get<2>(coins[K]);
    }
  }

  for (auto x : vec) {
    cout << x << " ";
  }
  cout << endl;

  auto it = max_element(vec.begin(), vec.end());
  cout << *it << endl;

  return 0;
}
