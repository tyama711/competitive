#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

int main(int argc, char *argv[])
{
    int N, T, prev_t, t;
    ll sum;

    cin >> N >> T;
    cin >> prev_t;
    FOR1(i,1,N) {
        cin >> t;
        if (t - prev_t >= T)
            sum += T;
        else
            sum += t - prev_t;
        prev_t = t;
    }
    sum += T;

    cout << sum << endl;
    
    return 0;
}
