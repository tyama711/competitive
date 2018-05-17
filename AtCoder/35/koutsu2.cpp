#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;
typedef unsigned long long UInt;
typedef unsigned int uint;

int main(void)
{
  uint n, m, a, b, c, k, x, y, z;
  UInt dist[400][400];
  UInt answer[400] = {0};

  for (int i = 0; i < 400; i++)
	for (int j = 0; j < 400; j++)
	  dist[i][j] = ULLONG_MAX / 2;

  for (int i = 0; i < 400; i++)
	dist[i][i] = 0;

  cin >> n >> m;
  for (uint i = 0; i < m; i++) {
	cin >> a >> b >> c;
	dist[a-1][b-1] = dist[b-1][a-1] = c;
  }

  cin >> k;
  cin >> x >> y >> z;
  dist[x-1][y-1] = dist[y-1][x-1] = z;
  for (uint i = 0; i < n; i++) {
	for (uint j = 0; j < n; j++) {
	  for (uint p = j+1; p < n; p++) {
		if (dist[p][j] > dist[p][i] + dist[i][j])
		  dist[p][j] = dist[j][p]
			= dist[p][i] + dist[i][j];
	  }
	}
  }
  
  for (uint i = 0; i < n; i++)
	for (uint j = i+1; j < n; j++)
	  answer[0] += dist[i][j];

  for (uint l = 1; l < k; l++) {
	cin >> x >> y >> z;
	if (dist[x-1][y-1] > z) {
	  for (uint j = 0; j < n; j++) {
		for (uint p = j+1; p < n; p++) {
		  dist[p][j] = dist[j][p]
			= min(dist[p][j],
				  min(dist[p][x-1] + z + dist[y-1][j],
					  dist[p][y-1] + z + dist[x-1][j]));
		}
	  }

	  for (uint i = 0; i < n; i++)
		for (uint j = i+1; j < n; j++)
		  answer[l] += dist[i][j];
	}
	else
	  answer[l] = answer[l-1];
  }
  
  for (uint l = 0; l < k; l++) 
	cout << answer[l] << endl;

  return 0;
}
