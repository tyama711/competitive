#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

int main(int argc, char *argv[])
{
    ll X, Y;
    cin >> X >> Y;
    if (abs(X-Y) <= 1)
        cout << "Brown\n";
    else
        cout << "Alice\n";
    return 0;
}

