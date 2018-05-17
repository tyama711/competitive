#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0; i<int(n); i++)
#define FOR1(i,m,n) for(int i=int(m); i<int(n); i++)

typedef struct _Node {
    int id;
    bool flag = false;
    vector<struct _Node*> next;
} Node;

const int MAXN = 1e5;
int n, m;
int a[MAXN], b[MAXN];
vector<Node> nodes;

void _get_path(int start, deque<int> &path, int front) {
    Node *node = &nodes[start];
    Node *prev = nullptr;

    if (front == 1)
        path.push_front(start);
    else
        path.push_back(start);

    nodes[start].flag = true;

    while (node != prev) {
        prev = node;
        for (auto p : node->next) {
            if (p->flag == false) {
                if (front == 1)
                    path.push_front(p->id);
                else
                    path.push_back(p->id);
                p->flag = true;
                node = p;
                break;
            }
        }
    }
}

void get_path(int start, deque<int> &path) {
    int id;
    path.push_back(start);
    nodes[start].flag = true;

    int count = 0;
    deque<int> subpath[2];
    for (auto p : nodes[start].next) {
        if (p->flag == false) {
            _get_path(p->id, path, count);
            count++;
            if (count >= 2) break;
        }
    }

    return;
}

int main(int argc, char *argv[])
{
    cin >> n >> m;

    FOR(i,n) {
        Node node;
        node.id = i;
        nodes.push_back(node);
    }

    FOR(i,m) {
        int a, b;
        cin >> a >> b;
        nodes[a-1].next.push_back(&nodes[b-1]);
        nodes[b-1].next.push_back(&nodes[a-1]);
    }

    deque<int> path;
    FOR(i,n) {
        if (nodes[i].next.size() != 0) {
            get_path(i, path);
            break;
        }
    }

    printf("%d\n", path.size());
    for(auto v : path) printf("%d ", v+1);
    printf("\n");
    
    return 0;
}
