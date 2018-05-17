#include <bits/stdc++.h>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

using namespace std;
using namespace boost::numeric;

typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MOD=1e9+7;
int N, M;
int X;
ublas::matrix<ll> mat1(3,3), mat2(3,3);
ublas::vector<ll> vec(3);
ublas::matrix<ll> accum=ublas::identity_matrix<ll>(3);

ublas::matrix<ll> pow(ublas::matrix<ll> base, int exponent) {
    ublas::matrix<ll> ans;
    if (exponent == 0)
        ans = ublas::identity_matrix<ll>(3);
    else if (exponent % 2 == 1)
        ans = ublas::prod(base, pow(base, exponent-1));
    else {
        ublas::matrix<ll> tmp = pow(base, exponent / 2);
        ans = ublas::prod(tmp, tmp);
    }

    transform(ans.data().begin(), ans.data().end(),
              ans.data().begin(), [](ll x){return x%MOD;});
    return ans;
}

int main(int argc, char *argv[])
{
    int init1[3][3] = {{1,2,1},
                       {0,1,1},
                       {1,2,2}};
    int init2[3][3] = {{1,2,1},
                       {0,1,1},
                       {0,0,1}};
    int init3[3] = {0,0,1};
    ublas::vector<ll> ans;
    
    FOR(i,3) {
        FOR(j,3) {
            mat1(i,j) = init1[i][j];
            mat2(i,j) = init2[i][j];
        }
        vec(i) = init3[i];
    }

    cin >> N >> M;
    int n=0;
    FOR(i,M) {
        cin >> X;
        int exponent = X-n;
        accum = ublas::prod(accum, pow(mat1, exponent));
        accum = ublas::prod(accum, mat2);
        transform(accum.data().begin(), accum.data().end(),
                  accum.data().begin(), [](ll x){return x%MOD;});
        n = X+1;
    }
    accum = ublas::prod(accum, pow(mat1, N-n));
    transform(accum.data().begin(), accum.data().end(),
              accum.data().begin(), [](ll x){return x%MOD;});
    cout << accum(0,2) << endl;
    
    return 0;
}
