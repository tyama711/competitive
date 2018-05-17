#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned uint;
typedef pair<uint, uint> pairUInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

int main(int argc, char *argv[])
{
    uint a, b, c;
    ll count = 0;
    set<pairUInt> hist;

    cin >> a >> b >> c;

    while(a%2 == 0 && b%2 == 0 && c%2 == 0) {
        if (hist.find(make_pair(max(max(a, b), c), max(min(a, b), c))) != hist.end()) {
            count = -1;
            break;
        }
        hist.insert(make_pair(max(max(a, b), c), max(min(a, b), c)));
        count ++;
        uint tmp_a=a, tmp_b=b;
        a = (b+c)/2;
        b = (tmp_a + c)/2;
        c = (tmp_a + tmp_b)/2;
    }

    cout << count << endl;;
    
    return 0;
}
