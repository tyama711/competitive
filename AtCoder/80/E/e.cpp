#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairInt;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[])
{
  int N;
  vector<int> p;
  vector<int> q;
  vector<int> order;

  scanf("%d", &N);

  p.resize(N);
  q.resize(N);

  order.resize(N+1);
  
  FOR(i, N) {
    scanf("%d", &p[i]);
    order[p[i]] = i;
  }
  order[0] = -1;
  order[N] = -1;

  
  
  return 0;
}
