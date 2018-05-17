#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned uint;
typedef pair<int, int> pairInt;
typedef pair<uint, uint> pairUInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXK=640000;

int main(int argc, char *argv[])
{
    int H, W, K;
    scanf("%d%d%d", &H, &W, &K);

    char maze[H+2][W+2];
    int dist[H+2][W+2];
    
    FOR(i,H+2) {
        dist[i][0] = dist[i][W+1] = MAXK+1;
    }
    
    FOR(i,W+2) {
        dist[0][i] = dist[H+1][i] = MAXK+1;
    }

    pairInt start;
    FOR1(i,1,H+1) {
        FOR1(j,1,W+1) {
            char a;
            scanf(" %c", &a);
            maze[i][j] = a;

            if (a == 'S') {
                dist[i][j] = 0;
                start.first = i;
                start.second = j;
            }
            else
                dist[i][j] = MAXK+1;
        }
    }

    int up, low, left, right;
    up = low = start.first;
    left = right = start.second;

    bool flag;
    FOR1(k,1,K+1) {
        flag = false;
        for (int i=max(start.first-k, 1);
             i <= min(start.first+k, H);
             i++) {
            for (int j=max(start.first+start.second-k-i, 1);
                 j <= min(start.second-start.first+k+i, W);
                 j++) {
                if (maze[i][j] == '.' &&
                    dist[i][j] > k &&
                    (dist[i-1][j] == k-1 ||
                     dist[i+1][j] == k-1 ||
                     dist[i][j-1] == k-1 ||
                     dist[i][j+1] == k-1)) {
                    dist[i][j] = k;
                    if (i < up)
                        up = i;
                    else if (i > low)
                        low = i;
                    if (j < left)
                        left = j;
                    else if (j > right)
                        right = j;
                    flag = true;
                }
            }
        }
        if (flag == false)
            break;
    }

    int tmp = min(min(up-1, H-low), min(left-1, W-right));
    int ans = (tmp + 2*K - 1) / K;

    printf("%d\n", ans);
    
    return 0;
}
