#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class FenwickTree {
private:
    int n;
    vector<ll> dat;
public:
    FenwickTree(int _n): n(_n), dat(_n+1, 0) {}
    FenwickTree(int _n, ll init): n(_n), dat(_n+1, 0) {
        for (int i = 0; i < _n; i++) {
            add(i, init);
        }
    }
    
    void add(int idx, ll value) {
        for (idx++; idx <= n; idx += idx & -idx) {
            dat[idx] += value;
        }
    }

    ll query(int l, int r) {
        ll ans = 0;
        for (r++; r > 0; r -= r & -r) {
            ans += dat[r];
        }
        for (; l > 0; l -= l & -l) {
            ans -= dat[l];
        }
        return ans;
    }
};

bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.second - a.first < b.second - b.first;
}

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector< pair<int,int> > A(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &A[i].first, &A[i].second);
    }
    sort(A.begin(), A.end(), comp);

    FenwickTree ft(m+1);

    int idx = 0;
    for (int d = 1; d < m+1; d++) {
        for(; idx < n && A[idx].second - A[idx].first < d; idx++) {
            ft.add(A[idx].first, 1);
            ft.add(A[idx].second+1, -1);
        }
        ll count = n - idx;
        for (int i = 0; i < m+1; i += d) {
            count += ft.query(0, i);
        }
        printf("%d\n", count);
    }
}
