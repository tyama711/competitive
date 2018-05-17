#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

int main(int argc, char *argv[])
{
    int n, sign=0, a, b, count = 1;

    cin >> n;

    cin >> a;
    FOR1(i,1,n) {
        b = a;
        cin >> a;
        if (sign < 0 && b < a) {
            count ++;
            sign = 0;
        } else if (sign > 0 && b > a) {
            count ++;
            sign = 0;
        } else if (sign == 0) {
            if (b < a)
                sign = 1;
            else if (a < b)
                sign = -1;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
