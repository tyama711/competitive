#include <stdio.h>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[argc])
{
  char c;
  string query = "AC";
  int index = 0;
  bool result = false;

  while (scanf("%c", &c)) {
    if (c == '\n') break;

    if (query[index] == c) index ++;
    else index = 0;

    if (index == query.size()) {
      result = true;
      break;
    }
  }

  if (result == true) printf("Yes\n");
  else printf("No\n");
  
  return 0;
}
