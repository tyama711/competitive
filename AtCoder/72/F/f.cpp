#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<double, ll> pairDI;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

ll N, L;
vector<ll> t, v;
vector<pairDI> A;
vector<ll> B;

int main(int argc, char *argv[])
{
    scanf("%lld%lld", &N, &L);

    t.resize(N);
    v.resize(N);
    A.resize(N);
    B.resize(N);

    scanf("%lld%lld", &t[0], &v[0]);

    A[0] = make_pair(t[0], v[0]);
    B[0] = 0;
    printf("%.7f\n", A[0].first);

    FOR1(i,1,N) {
        scanf("%lld%lld", &t[i], &v[i]);
        if (A[i-1].first < t[i]) {
            A[i] = make_pair(t[i], v[i]);
            B[i] = A[i-1].second;
        }
        else if (A[i-1].first == t[i]) {
            A[i] = make_pair(t[i], min(A[i-1].second + v[i], L));
            B[i] = 0;
        }
        else {
            ll vol = min(L, A[i-1].second + v[i]);
            double tmp = (t[i] * v[i] + A[i-1].first * (vol - v[i])) / vol;
            for (int j = i-2; vol < L && A[j].first >= tmp; j--) {
                tmp = (tmp * vol + A[j].first * min(L-vol, B[j+1]))
                    / (vol + min(L-vol, B[j+1]));
                vol += min(L-vol, B[j+1]);
            }
            A[i] = make_pair(tmp, vol);
            B[i] = 0;
        }

        ll vol = A[i].second;
        double tmp = A[i].first;
        for (int j = i-1; vol < L; j--) {
            tmp = (tmp * vol + A[j].first * min(L-vol, B[j+1]))
                / (vol + min(L-vol, B[j+1]));
            vol += min(L-vol, B[j+1]);
        }

        printf("%.7f\n", tmp);
    }

    return 0;
}
