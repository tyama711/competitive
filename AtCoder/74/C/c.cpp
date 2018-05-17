#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

vector<int> f(int h, int w) {
    vector<int> c1, c2;
    int ww = w / 2;
    int hh = h / 2;
    c1.push_back(ww * h);
    c1.push_back((w-ww) * h);
    c2.push_back(w * hh);
    c2.push_back(w * (h-hh));
    if (abs(c1[0] - c1[1]) < abs(c2[0] - c2[1]))
        return c1;
    else
        return c2;
}

int g(int h, int w) {
    int ws[2] = {w/3, (w+2)/3};
    int hs[2] = {h/3, (h+2)/3};
    int mindiff = INT_MAX;
    vector<int> v;

    FOR(i, 2) {
        v = f(h, w-ws[i]);
        v.push_back(h * ws[i]);
        auto mn = min_element(v.begin(), v.end());
        auto mx = max_element(v.begin(), v.end());
        if (*mx - *mn < mindiff)
            mindiff = *mx - *mn;

        v = f(h-hs[i], w);
        v.push_back(hs[i] * w);
        mn = min_element(v.begin(), v.end());
        mx = max_element(v.begin(), v.end());
        if (*mx - *mn < mindiff)
            mindiff = *mx - *mn;
    }

    return mindiff;
}

int main(int argc, char *argv[])
{
    int H, W;

    cin >> H >> W;
    cout << g(H, W) << endl;;
    
    return 0;
}
