#include <iostream>
#include <math.h>

using namespace std;
typedef unsigned long long UInt;
typedef unsigned int uint;

#define FIRST 1
#define SECOND 2

UInt combination(UInt n, UInt m) {
  if (m == 0 || m == n)
	return n;
  else
	return combination(n-1, m-1) + combination(n-1, m);
}

int main(void)
{
  UInt N, Q;
  UInt p[200002];
  UInt q[200002];
  char answer[200000];
  UInt combilog[200002];
  UInt tree[400000];
  int t;
  UInt k, a, b, l1, r1, l2, r2;
  UInt index = 0;

  cin >> N;
  for (UInt i = 1; i <= N; i++) {
	cin >> p[i];
	cin >> q[i];
  }
  p[0] = q[0] = 1;
  p[N+1] = q[N+1] = 1000000;

  for (UInt i = 0; i <= N; i++) {
	combilog[i] = 0;
	for (UInt j = p[i+1]-p[i]+1; j <= p[i+1]-p[i]+q[i+1]-q[i]; j++)
	  combilog[i] += log(j);
	for (UInt j = 2; j <= q[i+1]-q[i]; j++)
	  combilog[i] -= log(j);
  }

  cin >> Q;
  for (UInt i = 1; i <= Q; i++) {
	cin >> t;
	if (t == 1) {
	  cin >> k >> a >> b;
	  p[k] = a;
	  q[k] = b;
	  combilog[k-1] = combilog[k] = 0;
	  for (UInt j = p[k]-p[k-1]+1; j <= p[k]-p[k-1]+q[k]-q[k-1]; j++)
		combilog[k-1] += log(j);
	  for (UInt j = 2; j <= q[k]-q[k-1]; j++)
		combilog[k-1] -= log(j);

	  for (UInt j = p[k+1]-p[k]+1; j <= p[k+1]-p[k]+q[k+1]-q[k]; j++)
		combilog[k] += log(j);
	  for (UInt j = 2; j <= q[k+1]-q[k]; j++)
		combilog[k] -= log(j);
	}
	else {
	  cin >> l1 >> r1 >> l2 >> r2;
	  UInt P1 = 0;
	  UInt P2 = 0;
	  for (UInt j = l1; j < r1; j++) {
		P1 += combilog[j];
	  }

	  for (UInt j = l2; j < r2; j++) {
		P2 += combilog[j];
	  }

	  if (P1 > P2)
		answer[index] = FIRST;
	  else
		answer[index] = SECOND;

	  index++;
	}
  }

  for (UInt i = 0; i < index; i++) {
	if (answer[i] == FIRST)
	  cout << "FIRST\n";
	else
	  cout << "SECOND\n";
  }

  return 0;
}
