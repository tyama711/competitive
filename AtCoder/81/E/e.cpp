#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
  const int N = 2e5 + 1;
  char A[N];
  int slen;

  scanf("%s", A);
  slen = strlen(A);

  set<char> s;
  vector<int> pos1[26];
  vector<int> pos2;

  for (int i = slen - 1; i >= 0; i--) {
    pos1[A[i] - 'a'].push_back(i);
    s.insert(A[i]);

    if (s.size() == 26) {
      s.clear();
      pos2.push_back(i);
    }
  }

  FOR(i, 26) reverse(pos1[i].begin(), pos1[i].end());
  reverse(pos2.begin(), pos2.end());

  string ans;
  int i = 0;
  int pos = 0;
  while (i < pos2.size()) {
    for (char c = 'a'; c <= 'z'; c++) {
      auto it = bin_search(pos1[c - 'a'], pos);
      if (it == pos1[c - 'a'].end() || pos2[i] <= *it) {
        ans += c;
        i++;
        pos = *it + 1;
        break;
      }
    }
  }

  for (char c = 'a'; c <= 'z'; c++) {
    auto it = bin_search(pos1[c - 'a'], pos);
    if (it == pos1[c - 'a'].end()) {
      ans += c;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
