#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned uint;
typedef pair<uint, uint> pairUInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)
 
const int MAXN=1e5;
 
int main(int argc, char *argv[])
{
    int N, M, a, b;
    int hist[MAXN+1] {0};
 
    cin >> N >> M;
 
    FOR(i,M) {
        cin >> a >> b;
        hist[a]++;
        hist[b]++;
    }
 
    FOR1(i,1,N+1) {
        if (hist[i]%2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    
    return 0;
}
