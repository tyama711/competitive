#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pairInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=5e5;
const int MAXA=1e9;
vector<pairInt> ab;
int N, Q;
vector<pairInt> c;
vector<int> vec;
vector<pairInt> section;

int main(int argc, char *argv[])
{
    int i, j, ans;
    
    cin >> N;
    ab.resize(N);
    c.resize(N+1);
    FOR(i,N) cin >> ab[i].first >> ab[i].second;
    FOR(i,N+1) cin >> c[i].first;
    cin >> Q;
    
    sort(c.begin(), c.end(),
         [](pairInt a, pairInt b) { return a.first < b.first; });

    i = 0;
    int prev = 0;
    for (auto &x : c) {
        if (x.first > prev) {
            i++;
            prev = x.first;
        }
        x.second = i;
    }

    sort(ab.begin(), ab.end(),
         [](pairInt a, pairInt b) { return a.first < b.first; });

    i = 0;
    j = 0;
    while(i < ab.size() && j < c.size()) {
        if (ab[i].second <= c[j].first) {
            ab[i].second = c[j].second;
            i++;
        } else {
            j++;
        }
    }
    while (i < ab.size()) {
        ab[i].second = c.rbegin()->second + 1;
        i++;
    }

    sort(ab.begin(), ab.end(),
         [](pairInt a, pairInt b) { return a.second < b.second; });

    i = 0;
    j = 0;
    while(i < ab.size() && j < c.size()) {
        if (ab[i].second <= c[j].first) {
            ab[i].second = c[j].second;
            i++;
        } else {
            j++;
        }
    }
    while (i < ab.size()) {
        ab[i].second = c.rbegin()->second + 1;
        i++;
    }
    
    vec.resize(c.rbegin()->second + 2);
    for (auto x : ab) {
        for (i = x.first; i < vec.size(); i++)
            vec[i]++;
    }
    for (auto x : c) {
        for (i = x.second; i < vec.size(); i++)
            vec[i]--;
    }

    for (i = vec.size()-1; i > 0; i--) {
        if (vec[i] < -1) {
            section.clear();
            for (auto it = ab.begin(); it != ab.end(); it++) {
                if (it->second <= i && i < it->first)
                    section.push_back(make_pair(it->second, it->first));
            }
            //ここまで
        }
    }
    
    
    return 0;
}
