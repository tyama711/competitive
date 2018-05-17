#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned uint;
typedef pair<uint, uint> pairUInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const uint MAXN=2e5;
const uint MAXX=1e9;

int main(int argc, char *argv[])
{
    pairUInt maxelem, minelem;
    vector<pairUInt> input;
    uint N;

    cin >> N;
    FOR(i,N) {
        uint x, y;
        cin >> x >> y;
        input.push_back(make_pair(min(x,y), max(x,y)));
    }

    uint Max=0, Min=MAXX+1;
    uint minmax=MAXX+1, maxmin=0;
    for (auto it=input.begin(); it != input.end(); it++) {
        if (it->second > Max)
            Max = it->second;
        if (it->first < Min)
            Min = it->first;
        if (it->first > maxmin)
            maxmin = it->first;
        if (it->second < minmax)
            minmax = it->second;
    }

    ull cand1=(ull)(Max - minmax) * (maxmin - Min);

    sort(input.begin(), input.end(),
         [](pairUInt a, pairUInt b) {
             return a.first < b.first;
         });
    
    return 0;
}
