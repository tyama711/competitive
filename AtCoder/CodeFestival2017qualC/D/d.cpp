#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) >= 0 ? (a) : (-1 * (a)))

int main(int argc, char *argv[argc])
{
  int hist[26] = {0};
  char c;

  while (scanf("%c", &c)) {
    if (c == '\n') break;

    hist[c - 'a'] ++;
  }

  int odd = 0;
  FOR(i, 26) {
    if (hist[i] % 2 == 1) odd++;
  }

  printf("%d\n", MAX(odd, 1));
  
  return 0;
}
