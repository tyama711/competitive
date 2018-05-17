#include <iostream>
#include <algorithm>
using namespace std;

typedef long long Int;

Int factorial(Int n) {
  if (n < 1)
	return 1;
  else
	return (n * factorial(n-1)) % 1000000007LL;
}

int main(void)
{
  int n;
  int T[10000];
  Int penalty = 0;
  Int combination = 1;
  Int time = 0;
  int index = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
	cin >> T[i];

  sort(T, T + n);
  time += T[0];
  penalty += time;
  for (int i = 1; i < n; i++) {
	time += T[i];
	penalty += time;
	if (T[i] != T[i-1]) {
	  combination *= factorial(i-index);
	  combination %= 1000000007LL;
	  index = i;
	}
  }
  combination *= factorial(n-index);
  combination %= 1000000007LL;

  cout << penalty << endl;
  cout << combination << endl;

  return 0;
}
