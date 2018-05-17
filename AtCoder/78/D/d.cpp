#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

// node of tree structure
typedef struct _Node {
public:
  int id;
private:
  int size;
  struct _Node* parent;
  vector<struct _Node*> children;

public:
  _Node(): id(0), parent(nullptr), size(1) {}

  struct _Node* get_parent() {
    return parent;
  }
  
  struct _Node* get_root() {
    if (parent == nullptr) {
      return parent;
    } else {
      return parent->get_root();
    }
  }

  vector<struct _Node*> get_path_to_root() {
    vector<struct _Node*> vec;
    struct _Node* node = this;

    vec.push_back(this);

    while (node->parent != nullptr) {
      node = node->parent;
      vec.push_back(node);
    }

    return vec;
  }

  vector<struct _Node*> get_path(struct _Node* node) {
    vector<struct _Node*> vec1, vec2;

    vec1 = this->get_path_to_root();
    vec2 = node->get_path_to_root();

    auto it1 = vec1.rbegin(), it2 = vec2.rbegin();
    while (it1 != vec1.rend() && it2 != vec2.rend() && *it1 == *it2) {
      it1++;
      it2++;
    }

    vector<struct _Node*> vec(it1 - 1, vec1.rend());
    reverse(vec.begin(), vec.end());
    while (it2 != vec2.rend()) {
      vec.push_back(*it2);
      it2++;
    }

    return vec;
  }

  void set_root() {
    struct _Node* parent = nullptr;
    struct _Node* node = this;

    while (true) {
      struct _Node* tmp = node->parent;
      node->parent = parent;
      
      auto it = find(node->children.begin(), node->children.end(), parent);
      if (it != node->children.end()) {
        node->children.erase(it);
      }

      if (tmp == nullptr)
        break;
      
      node->children.push_back(tmp);
      parent = node;
      node = tmp;
    }

    return;
  }

  void combine(struct _Node* node) {
    if (this->parent == nullptr) {
      node->children.push_back(this);
      this->parent = node;
      return;
    } else if (node->parent == nullptr) {
      this->children.push_back(node);
      node->parent = this;
      return;
    }

    node->set_root();
    this->children.push_back(node);
    node->parent = this;

    return;
  }

  int get_size() {
    int size = 1;

    for (auto c : children) {
      size += c->get_size();
    }

    return size;
  }

} Node;

int main(int argc, char* argv[]) {
  int N;
  vector<Node> nodes;

  cin >> N;

  nodes.resize(N + 1);
  FOR1(i, 1, N + 1) { nodes[i].id = i; }

  FOR(i, N - 1) {
    int a, b;
    cin >> a >> b;
    nodes[a].combine(&nodes[b]);
  }

  vector<Node*> path = nodes[1].get_path(&nodes[N]);

  int n = (path.size() + 1) / 2;
  int sente_id = path[n-1]->id;
  int gote_id = path[n]->id;
  int sente_point, gote_point;

  if (nodes[sente_id].get_parent() == &nodes[gote_id]) {
    sente_point = nodes[sente_id].get_size();
    gote_point = N - sente_point;
  } else {
    gote_point = nodes[gote_id].get_size();
    sente_point = N - gote_point;
  }

  if (sente_point > gote_point)
    cout << "Fennec" << endl;
  else
    cout << "Snuke" << endl;

  return 0;
}
