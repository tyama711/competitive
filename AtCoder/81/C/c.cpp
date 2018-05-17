#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[])
{
  int N;
  set<int> input;
  int w = 0, h = 0;

  scanf("%d", &N);

  FOR(i, N) {
    int a;

    scanf("%d", &a);

    if (input.find(a) != input.end()) {
      if (a > w) {
        h = w;
        w = a;
      } else if (a > h) {
        h = a;
      }
      input.erase(a);
    } else {
      input.insert(a);
    }
  }

  ll area = (ll)w * (ll)h;

  printf("%lld\n", area);
  
  return 0;
}
