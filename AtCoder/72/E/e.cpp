#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=5e5;
const int MAXD=1e9;
int N, Q, D;
vector<int> d, A, B;

int main(int argc, char *argv[])
{
    cin >> N >> D;
    A.resize(N+1);
    B.resize(N+2);
    d.resize(N+1);
    
    A[0] = D;
    FOR1(i,1,N+1) {
        cin >> d[i];
        if (d[i] < 2*A[i-1])
            A[i] = abs(A[i-1]-d[i]);
        else
            A[i] = A[i-1];
    }
    
    B[N+1] = 1;
    for (int i = N; i > 0; i--) {
        if (2*B[i+1] <= d[i])
            B[i] = B[i+1];
        else
            B[i] = B[i+1] + d[i];
    }

    cin >> Q;
    FOR(i,Q) {
        int q;
        cin >> q;
        if (A[q-1] >= B[q+1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
