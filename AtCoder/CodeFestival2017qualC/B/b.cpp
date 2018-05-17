#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[argc])
{
  int N;
  ull odd = 1;

  scanf("%d", &N);

  FOR(i, N) {
    int A;
    scanf("%d", &A);
    if (A % 2 == 0) odd *= 2;
  }

  printf("%llu\n", (ull)pow(3, N) - odd);
  
  return 0;
}
