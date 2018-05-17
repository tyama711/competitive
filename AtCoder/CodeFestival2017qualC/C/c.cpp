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
  string str;
  vector<int> vec(1);
  char c;
  int index = 0;

  while(scanf("%c", &c)) {
    if (c == '\n') break;

    if (c == 'x') vec[index]++;
    else {
      str.push_back(c);
      vec.push_back(0);
      index++;
    }
  }

  string rstr = str;
  reverse(rstr.begin(), rstr.end());
  if (str != rstr) printf("-1\n");
  else {
    int front = 0;
    int back = vec.size() - 1;
    int ans = 0;
    while (front < back) {
      ans += ABS(vec[front] - vec[back]);
      front++;
      back--;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
