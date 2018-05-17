#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

string s, t;
int q;
vector<int> cumul_s, cumul_t;

int main(int argc, char *argv[])
{
    cin >> s >> t;
    cumul_s.resize(s.length()+1);
    cumul_t.resize(t.length()+1);
    
    FOR(i,s.length()) {
        if (s[i] == 'A')
            cumul_s[i+1] = cumul_s[i]+1;
        else
            cumul_s[i+1] = cumul_s[i]-1;
    }
    FOR(i,t.length()) {
        if (t[i] == 'A')
            cumul_t[i+1] = cumul_t[i]+1;
        else
            cumul_t[i+1] = cumul_t[i]-1;
    }

    cin >> q;
    FOR(i,q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (((cumul_s[b]-cumul_s[a-1]) - (cumul_t[d]-cumul_t[c-1])) % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
