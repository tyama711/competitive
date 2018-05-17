#include <stdio.h>
#include <vector>
#include <memory>
#include <functional>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

typedef struct _Node {
    bool flag = false;
    int color;
    int weight;
    vector<struct _Node*> next;
} Node;

typedef struct _Graph {
    vector<Node> nodes;
} Graph;

const int MAXN = 2*1e5;
const int MOD = 1e9+7;

int N, X, Y;
int fac[MAXN+1], inv[MAXN+1], ifac[MAXN+1], mn[MAXN+1], c[MAXN+1], w[MAXN+1];

void getConnected(Node* node,
                  vector<Node*> &connected) {
    if (node->flag == true) {
        return;
    }

    connected.push_back(node);
    node->flag = true;
    for (auto n : node->next) {
        if (n->flag == false)
            getConnected(n, connected);
    }

    return;
}

ll factorial(int n) {
    if (n <= 1)
        return 1;

    ll ans = 1;
    FOR1(i, 2, n+1)
        ans *= i;

    return ans;
}

ll getCombMod(vector<Node*> connected) {
    if (connected.size() == 0) {
        return 1;
    }
    
    int max_color = 0;
    for (auto node : connected) {
        if (max_color < node->color)
            max_color = node->color;
    }

    vector<int> hist(max_color, 0);
    for (auto node : connected)
        hist[node->color-1]++;

    ll ans = fac[connected.size()];
    for (auto n : hist) ans = ans*ifac[n]%MOD;

    return ans % MOD;
}

int main(int argc, char *argv[])
{
    int n, x, y;
    int a=1;
    int &b = a;
    vector<Node> nodes;

    scanf("%d %d %d", &n, &x, &y);

    fac[0]=1;
    FOR1(i,1,N+1) fac[i]=(ll)fac[i-1]*i%MOD;
    inv[1]=1;
    FOR1(i,2,N+1) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
    ifac[0]=1;
    FOR1(i,1,N+1) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

    FOR(i, n) {
        Node node;
        scanf("%d %d", &node.color, &node.weight);
        nodes.push_back(node);
    }

    FOR(i, n-1) {
        FOR1(j, i+1, n) {
            if ((nodes[i].color == nodes[j].color &&
                 nodes[i].weight + nodes[j].weight <= x) ||
                (nodes[i].color != nodes[j].color &&
                 nodes[i].weight + nodes[j].weight <= y)) {

                nodes[i].next.push_back(&(nodes[j]));
                nodes[j].next.push_back(&(nodes[i]));
            }
        }
    }

    ll ans = 1;
    vector<Node*> connected;
    for (auto &node : nodes) {
        getConnected(&node, connected);
        ans *= getCombMod(connected);
        ans %= MOD;
        connected.clear();
    }

    printf("%lld\n", ans);
    
    return 0;
}
