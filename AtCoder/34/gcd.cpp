#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned long long ULLONG;
typedef unsigned long ULONG;
typedef unsigned int UINT;

#define N 35000

int main(void)
{
  char prime_flag[N+1];
  ULLONG prime [N/2];
  ULLONG index = 0;
  ULLONG a, b, sqrt_a;

  cin >> a >> b;
  sqrt_a = (UINT)sqrt(a);

  // N以下の素数テーブル作成
  prime[0] = 2;
  prime[1] = 3;
  prime[2] = 5;
  prime[3] = 7;
  index = 4;
  memset(prime_flag, 0x01, N+1);
  prime_flag[0] = prime_flag[1] = 0;
  for (ULLONG i = 4; i <= sqrt_a; i += 2) {
	prime_flag[i] = 0;
  }
  
  for (ULLONG k = 1; prime[k] * prime[k] <= sqrt_a; k++) {
	for (ULLONG i = 2*prime[k]; i <= sqrt_a; i += prime[k])
	  prime_flag[i] = 0;

	for (ULLONG j = prime[k]*prime[k] + 2;
		 j < prime[k+1] * prime[k+1] && j <= sqrt_a; j += 2) {
	  if (prime_flag[j])
		prime[index++] = j;
	}
  }

  int *hist = new int[N];
  memset(hist, 0x00, sizeof(int) * index);
  for (ULLONG i = b+1; i <= a; i++) {
	ULLONG v = i;
	for (ULLONG j = 0; j < index && v != 1; j++) {
	  if (v % prime[j] == 0) {
		hist[j]++;
		v /= prime[j];
		j--;
	  }
	}
	if (v != 1) {
	  hist[index] = 1;
	  prime[index++] = v;
	}
  }

  ULLONG ans = 1;
  for (ULLONG i = 0; i < index; i++) {
	ans *= (hist[i] + 1) % 1000000007;
	ans %= 1000000007;
  }

  cout << ans << endl;

  delete [] hist;
}
