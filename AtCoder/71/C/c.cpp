#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=50;
const int MAXLEN=50;
int n;
string str;
map<char, int> common;

int main(int argc, char *argv[])
{
    cin >> n;

    cin >> str;
    for (auto c : str) {
        common[c]++;
    }
    
    FOR(i,n-1) {
        map<char, int> count;
        cin >> str;
        for (auto c : str)
            count[c]++;
        for (auto &p : common)
            p.second = min(p.second, count[p.first]);
    }

    for (auto p : common)
        FOR(i,p.second) cout << p.first;
    cout << endl;
    
    return 0;
}
