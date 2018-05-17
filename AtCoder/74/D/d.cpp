#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN = 1e5;

int main(int argc, char *argv[])
{
    int N;
    priority_queue<int, vector<int>, greater<int>> front;
    vector<int> middle;
    priority_queue<int> back;
    vector<ll> sum_front, sum_back;

    cin >> N;

    middle.resize(N);
    sum_front.resize(N+1);
    sum_back.resize(N+1);
    sum_front[0] = 0;
    sum_back[N] = 0;
    
    FOR(i, N) {
        int a;
        cin >> a;
        front.push(a);
        sum_front[0] += a;
    }
    FOR(i, N) cin >> middle[i];
    FOR(i, N) {
        int a;
        cin >> a;
        back.push(a);
        sum_back[N] += a;
    }

    FOR(i, N) {
        if (front.top() < middle[i]) {
            sum_front[i+1] = sum_front[i] + middle[i] - front.top();
            front.pop();
            front.push(middle[i]);
        }
        else sum_front[i+1] = sum_front[i];
    }

    for(int i = N-1; i >= 0; i--) {
        if (back.top() > middle[i]) {
            sum_back[i] = sum_back[i+1] + middle[i] - back.top();
            back.pop();
            back.push(middle[i]);
        }
        else sum_back[i] = sum_back[i+1];
    }

    ll ans = LLONG_MIN;
    FOR(i, N+1) {
        if (sum_front[i] - sum_back[i] > ans)
            ans = sum_front[i] - sum_back[i];
    }

    cout << ans << endl;
    
    return 0;
}
