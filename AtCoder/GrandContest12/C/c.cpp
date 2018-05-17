#include <stdio.h>
#include <vector>

using namespace std;
typedef long long llong;
#define FOR(i,n) for(int i=0; i<int(n); i++)

int main(int argc, char *argv[])
{
    llong n;
    vector<int> vec;
    vector<int> s;
    int i;

    scanf("%lld", &n);

    n ++;
    for (i = 0; n != 0; n >>= 1, i++) {
        if (n%2 == 1) {
            vec.push_back(i);
        }
    }

    vector<int>::reverse_iterator it = vec.rbegin();
    i = 1;
    for (; i <= *it; i++) {
        s.push_back(i);
    }

    it++;
    for (; it != vec.rend(); it++, i++) {
        int j = 0;
        vector<int>::iterator it2;

        for(it2 = s.begin(); j < (*it); it2++, j++);
        s.insert(it2, i);
    }

    printf("%d\n", 2 * s.size());
    for (vector<int>::iterator it2 = s.begin(); it2 != s.end(); it2++) {
        printf("%d ", *it2);
    }
    for (i = 1; i <= s.size(); i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
