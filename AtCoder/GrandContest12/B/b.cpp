#include <stdio.h>
#include <vector>

using namespace std;

typedef struct _Node {
    int color = 0;
    vector<struct _Node*> next;
    int d = -1;
} Node;

void query(Node* node, int d, int c) {
    if (node->d >= d) {
        return ;
    }
    
    node->d = d;

    if (node->color == 0) {
        node->color = c;
    }
    
    for (vector<Node*>::iterator it = node->next.begin();
         it != node->next.end(); it++) {
        query((*it), d-1, c);
    }
}

int main(void) {
    int n, m, q;
    int *a, *b, *v, *d, *c;
    Node *nodes;

    scanf("%d %d", &n, &m);
    
    nodes = new Node[n];
    a = new int[m];
    b = new int[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        nodes[a[i]-1].next.push_back(&nodes[b[i]-1]);
        nodes[b[i]-1].next.push_back(&nodes[a[i]-1]);
    }

    scanf("%d", &q);

    v = new int[q];
    d = new int[q];
    c = new int[q];

    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &v[i], &d[i], &c[i]);
    }

    for (int i = q-1; i >= 0; i--) {
        query(&nodes[v[i]-1], d[i], c[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i].color);
    }

    return 0;
}
