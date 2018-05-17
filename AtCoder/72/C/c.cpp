#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=1e5;
const int MAXA=1e9;
int n;
ll count[2], sum[2];

int main(int argc, char *argv[])
{
    int a, sign=1;
    scanf("%d", &n);
    FOR(i,n) {
        scanf("%d", &a);
        sum[0] += a;
        sum[1] -= a;
        FOR(j,2) {
            if (sign * sum[j] <= 0) {
                ::count[j] += 1 - sign * sum[j];
                sum[j] = sign;
            }
        }
        sign *= -1;
    }

    printf("%lld\n", min(::count[0], ::count[1]));
    return 0;
}
