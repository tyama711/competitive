#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned uint;
typedef pair<uint, uint> pairUInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

int N, Q, A, B;
vector<int> x;

ll dp(int a, int b, int idx)
{
    if (x.size() <= idx) return 0;

    if (x[idx] <= a)
        return dp(x[idx], b, idx+1) + a - x[idx];
    if (x[idx] >= b)
        return dp(a, x[idx], idx+1) + x[idx] - b;

    return
        min(dp(x[idx], b, idx+1) + abs(x[idx]-a),
            dp(a, x[idx], idx+1) + abs(x[idx]-b));
}

int main(int argc, char *argv[])
{
    cin >> N >> Q >> A >> B;
    x.resize(Q);
    FOR(i,Q) cin >> x[i];
    cout << dp(min(A,B), max(A,B), 0) << endl;
    
    return 0;
}
