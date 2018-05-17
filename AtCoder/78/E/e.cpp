#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int pow(int base, int exp) {
  if (exp == 0)
    return 1;

  if (exp % 2 == 0) {
    int tmp = pow(base, exp / 2);
    return tmp * tmp;
  } else {
    return base * pow(base, exp - 1);
  }
}

int main(int argc, char *argv[])
{
  char ans;
  int out;

  int d = 9;
  for (; d >= 0; d--) {
    ll n = pow(10, d);

    printf("? %lld\n", n);
    fflush(stdout);
    scanf(" %c", &ans);

    if (ans == 'Y')
      break;
  }

  if (d == 9) {
    // N=10^m (m=0~9)

    int i = 0;

    ans = 'N';
    while (ans == 'N') {
      printf("? %lld\n", 2ULL * pow(10, i));
      fflush(stdout);
      scanf(" %c", &ans);
      i ++;
    }

    i --;
    out = pow(10, i);
    
  } else {
    // N=10^d+1 ~ 10^(d+1)-1
    
    int lower, upper, mid;
    lower = pow(10, d) + 1;
    upper = pow(10, d+1) - 1;
    
    while (lower < upper) {
      mid = ((ll)lower + upper) / 2;
  
      printf("? %lld\n", (ll)mid * 10);
      fflush(stdout);
      scanf(" %c", &ans);

      if (ans == 'Y') {
        upper = mid;
      } else {
        lower = mid + 1;
      }
    }

    out = lower;
  }


  printf("! %d\n", out);
  
  return 0;
}
