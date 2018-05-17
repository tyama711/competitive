#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=1e5;
const int MAXX=1e9;
const int MOD = 1e9+7;
int n, m;
ll sumx, sumy;

int main(int argc, char *argv[])
{
    cin >> n >> m;

    ll x, prevx;
    cin >> x;
    FOR1(i,1,n) {
        prevx = x;
        cin >> x;
        sumx += (x-prevx) * i * (n-i);
        sumx %= MOD;
    }

    ll y, prevy;
    cin >> y;
    FOR1(i,1,m) {
        prevy = y;
        cin >> y;
        sumy += (y-prevy) * i * (m-i);
        sumy %= MOD;
    }

    cout << (sumx * sumy) % MOD << endl;
        
    return 0;
}
