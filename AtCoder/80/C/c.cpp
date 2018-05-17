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
  int num_odd = 0;
  int num_4 = 0;

  scanf("%d", &N);

  FOR(i, N) {
    int a;

    scanf("%d", &a);

    if (a % 4 == 0) num_4++;
    if (a % 2 == 1) num_odd++;
  }

  if (num_odd <= num_4 || (num_odd - 2 < num_4 && num_odd + num_4 == N))
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
