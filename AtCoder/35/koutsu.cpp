#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;
typedef long long Int;
typedef unsigned long long UInt;

int main(void)
{
  int n, m, a, b, c, k, x, y, z;
  int dist[400][400];
  char done[400][400];
  UInt cost[400][400];
  UInt sum;
  UInt answer[400];

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
	cin >> a >> b >> c;
	dist[a-1][b-1] = dist[b-1][a-1] = c;
  }

  cin >> k;
  for (int h = 0; h < k; h++) {
	cin >> x >> y >> z;
	if (dist[x-1][y-1] != 0 &&
		dist[x-1][y-1] <= z &&
		h > 0) {
	  answer[h] = answer[h-1];
	}
	else {
	  if (dist[x-1][y-1] == 0 ||
		  dist[x-1][y-1] > z)
		dist[x-1][y-1] = dist[y-1][x-1] = z;

	  memset(done, '\0', 400*400);
	  memset(cost, 0xFF, sizeof(UInt)*400*400);
	  sum = 0;
	  for (int i = 0; i < n; i++) {
		cost[i][i] = 0;
		done[i][i] = 1;
		
		for (int j = i+1; j < n; j++) {
		  int target = i;
		  char done2[400] = {0};
		  done2[i] = 1;
		  
		  if (!done[i][j]) {
			while (!done2[j]) {
			  for (int k = 0; k < n; k++) {
				if (!done2[k] &&
					dist[target][k] != 0 &&
					cost[i][target] + dist[target][k] < cost[i][k])
				  cost[k][i] = cost[i][k]
					= cost[i][target] + dist[target][k];
			  }
			  
			  UInt min = ULLONG_MAX;
			  int index = -1;
			  for (int k = 0; k < n; k++) {
				if (!done2[k] &&
					cost[i][k] < min) {
				  min = cost[i][k];
				  index = k;
				}
			  }
			  
			  done[index][i] = done[i][index]
				= done2[index] = 1;
			  target = index;
			}
		  }
		  sum += cost[i][j];
		}
	  }

	  answer[h] = sum;
	}
  }

  for (int h = 0; h < k; h++)
	cout << answer[h] << endl;

  return 0;
}
