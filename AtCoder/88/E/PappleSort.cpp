#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <iterator>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[argc])
{
  string S;
  cin >> S;

  array<int, 26> hist{};
  for(auto c : S)
    hist.at(c - 'a') ++;

  char center = 0;
  int num_odd = 0;
  FOR(i, 26) {
    if (hist.at(i) % 2 == 1) {
      center = 'a' + i;
      num_odd ++;
    }
  }
  if (num_odd > 1) {
    printf("-1\n");
    return 0;
  }

  string left;
  array<int, 26> hist2{};
  for(auto c : S) {
    if (hist2.at(c - 'a') < hist.at(c - 'a') / 2)
      left += c;
    hist2.at(c - 'a') ++;
  }

  string right(left.rbegin(), left.rend());
  string target = left + center + right;

  

  return 0;
}
