#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end();++it)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = ~(1<<31);
const double pi = acos(-1);
 
int main() {
//	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	map<char,int> og;
	string s;
	cin >> s;
	rep(i,0,s.size()) og[s[i]]++;
	rep(i,0,n-1) {
		cin >> s;
		map<char,int> ne;
		rep(a,0,s.size()) ne[s[a]]++;
		iter(it,og) {
			og[it->first] = min(it->second, ne[it->first]);
		}
	}
	string best = "";
	iter(it,og) {
		char da = it->first;
		rep(i,0,it->second) best+=da;
	}
	cout << best << endl;
	return 0;
}
