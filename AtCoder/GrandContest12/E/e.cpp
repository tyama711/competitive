#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

const int MAXN=1e5;
int N, V;
int x[MAXN], d[MAXN-1];

bool canGoAll(int *d, int from, int to) {
    
}

int main(int argc, char *argv[])
{
    scanf("%d%d", &N, &V);
    FOR(i,N) scanf("%d", &x[i]);
    FOR(i,N-1) d[i] = x[i+1]-x[i];
    return 0;
}
