#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned uint;
typedef pair<uint, uint> pairUInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=2e5;
int N, Q, A, B;
vector<int> x;
//vector<ll> dp;

typedef struct segtree {
    int N;
    vector<ll> dat, sum;
    segtree(int n) {
        N = 1;
        while(N < n) N <<= 1;
        dat.assign(2*N-1,0);
        sum.assign(2*N-1,0);
    }

    void update(int i, ll x) {
        ll sum1=0;
        int tmp = i+N-1;

        while (tmp > 0) {
            tmp = (tmp-1)/2;
            sum1 += sum[tmp];
        }

        i += N-1;
        dat[i] = x-sum1;
        while (i > 0) {
            i = (i-1)/2;
            dat[i] = min(dat[i*2+1], dat[i*2+2]) + sum[i];
        }
    }

    void add(int a, int b, ll x) { add(a,b,x,0,0,N); }

    ll add(int a, int b, ll x, int k, int l, int r) {
        if(b <= l or r <= a) return dat[k];
        if(a <= l and r <= b) {
            sum[k] += x;
            return dat[k] += x;
        }
        int m = (l+r)/2;
        return dat[k] = min(add(a,b,x,2*k+1,l,m),add(a,b,x,2*k+2,m,r))+sum[k];
    }

    ll minimum(int a, int b) { return minimum(a,b,0,0,N); }

    ll minimum(int a, int b, int k, int l, int r) {
        if(b <= l or r <= a) return 1e9;
        if(a <= l and r <= b) return dat[k];
        int m = (l+r)/2;
        return min(minimum(a,b,2*k+1,l,m),minimum(a,b,2*k+2,m,r))+sum[k];
    }

    void print() {
        FOR(i,N) cout << minimum(i, i+1) << " ";
        cout << endl;
    }

} SegTree;

int main(int argc, char *argv[])
{
    cin >> N >> Q >> A >> B;
    x.resize(Q+1);
    SegTree dp(N), dp1(N), dp2(N);
    
    x[0] = B;
    FOR1(i,1,Q+1) cin >> x[i];

    dp.add(0, N, (ll)MAXN*MAXN);
    dp1.add(0, N, (ll)MAXN*MAXN);
    dp2.add(0, N, (ll)MAXN*MAXN);

    dp.update(A-1, 0);
    dp1.update(A-1, A);
    dp2.update(A-1, -A);

    FOR1(i,1,Q+1) {
        ll min1=dp1.minimum(x[i], N) - x[i];
        ll min2=dp2.minimum(0, x[i]) + x[i];

        dp.add(0, N, abs(x[i]-x[i-1]));
        dp1.add(0, N, abs(x[i]-x[i-1]));
        dp2.add(0, N, abs(x[i]-x[i-1]));

        dp.update(x[i-1]-1, min(min1, min2));
        dp1.update(x[i-1]-1, min(min1, min2)+x[i-1]);
        dp2.update(x[i-1]-1, min(min1, min2)-x[i-1]);

        dp.update(x[i]-1, (ll)MAXN*MAXN);
        dp1.update(x[i]-1, (ll)MAXN*MAXN);
        dp2.update(x[i]-1, (ll)MAXN*MAXN);
    }
    
    cout << dp.minimum(0, N) << endl;

    return 0;
}
