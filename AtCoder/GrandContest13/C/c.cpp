#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN = 1e5;
const int MAXL = 1e9;
vector<int> X,W;
int N, L, T;

int main(int argc, char *argv[])
{
    ll sum1=0, sum2=0;
    int over;
    
    cin >> N >> L >> T;
    FOR(i,N) {
        int x, w;
        cin >> x >> w;
        X.push_back(x);
        W.push_back(w);
    }
    
    FOR(i,X.size()) {
        if (W[i] == 1)
            X[i] += T;
        else
            X[i] -= T;
        sum1 += X[i];
        X[i] %= L;
        while(X[i] < 0) X[i] += L;
        sum2 += X[i];
    }

    over = (sum1 - sum2) / L % N;
    while(over < 0) over += N;

    sort(X.begin(), X.end());

    FOR1(i,over,N) cout << X[i] << endl;
    FOR(i,over) cout << X[i] << endl;
    
    return 0;
}
