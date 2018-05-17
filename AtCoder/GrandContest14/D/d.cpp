#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned uint;
typedef pair<int, int> pairInt;
typedef pair<uint, uint> pairUInt;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

typedef struct _Vertex {
    int id;
    struct _Vertex *parent = nullptr;
    vector<struct _Vertex*> children;
} Vertex;

const int MAXN=1e5;
Vertex V[MAXN];

Vertex* getRoot(Vertex *v) {
    while (v->parent != nullptr) {
        v = v->parent;
    }
    return v;
}

bool dp(Vertex *root) {
    Vertex *leaf = root;
    if (root->children.size() == 0)
        return true;
    
    while (leaf->children.size() != 0)
        leaf = leaf->children[0];

    Vertex *v = leaf->parent;
    FOR1(i,1,v->children.size()) {
        v->children[i]->parent = nullptr;
        if (dp(v->children[i]) == true)
            return true;
    }
    
    if (v->parent != nullptr) {
        Vertex *p = v->parent;
        auto it = p->children.begin();
        for(; *it != v; it++);
        p->children.erase(it);
        if (dp(getRoot(p)) == true)
            return true;
    }
    
    return false;
}

int main(int argc, char *argv[])
{
    int N;
    cin >> N;

    FOR(i,N) V[i].id = i+1;
    
    FOR(i,N-1) {
        int a, b;
        cin >> a >> b;

        Vertex *v = &V[a-1];
        Vertex *w = &V[b-1];
        w->children.push_back(v);
        while (v->parent != nullptr) {
            Vertex *p = v->parent;
            auto it = p->children.begin();
            for (; *it != v; it++);
            p->children.erase(it);
            v->children.push_back(p);            
            v->parent = w;
            w = v;
            v = p;
        }
        v->parent = w;
    }

    if (dp(getRoot(&V[0])) == true)
        cout << "First\n";
    else
        cout << "Second\n";
    
    return 0;
}
