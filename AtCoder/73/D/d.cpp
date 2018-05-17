#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned uint;
typedef pair<uint, uint> pairUInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

int main(int argc, char *argv[])
{
    uint N, W, w, v;
    unordered_map<uint, uint> table;

    cin >> N >> W;
    FOR(i,N) {
        cin >> w >> v;
        if (w > W) continue;

        unordered_map<uint, uint> table2=table;
        for(auto x : table2) {
            if (x.first + w <= W) {
                auto it = table.find(x.first + w);
                if (it == table.end() || it->second < x.second + v)
                    table[x.first + w] = x.second + v;
            }
        }
        
        auto it = table.find(w);
        if (it == table.end() || it->second < v)
            table[w] = v;
    }

    if (table.size() != 0) {
        auto max_it = max_element(table.begin(), table.end(),
                                  [](pairUInt a, pairUInt b) {
                                      return a.second < b.second;
                                  });
        cout << max_it->second << endl;
    }
    else cout << 0 << endl;
    
    return 0;
}
