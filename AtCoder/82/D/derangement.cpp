#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[]) {
  int N;

  scanf("%d", &N);

  int count(0);
  bool flag = false;
  FOR1(i, 1, N + 1) {
    int p;
    scanf("%d", &p);
    if (flag == true) {
      count++;
      flag = false;
    }
    else if (p == i)
      flag = true;
    else
      flag = false;
  }

  if (flag == true)
    count++;

  printf("%d\n", count);
  
  return 0;
}
