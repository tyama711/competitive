#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

typedef struct _Node {
  int num = 1;
  int index = 0;
  int lazy = 0;
  ll value = 0;
  struct _Node* left = nullptr;
  struct _Node* right = nullptr;
} Node;

void insert(Node* root, int val) {
  if (root == nullptr)
    return ;
  
  root->num++;

  if (root->right != nullptr) {
    root->right->lazy += root->lazy;
  }
  root->index += root->lazy;
  root->lazy = 0;

  if (root->value <= val) {
    if (root->right == nullptr) {
      root->right = new Node();
      root->right->index = root->index + 1;
      root->right->value = val;
    } else {
      insert(root->right, val);
    }
  } else {
    if (root->left == nullptr) {
      root->left = new Node();
      root->left->index = root->index;
      root->left->value = val;
      root->lazy++;
    } else {
      insert(root->left, val);
      root->lazy++;
    }
  }
}

int lower_than(Node* root, int val) {
  if (root->right != nullptr) {
    root->right->lazy += root->lazy;
  }
  root->index += root->lazy;
  root->lazy = 0;

  if (root->value < val) {
    if (root->right == nullptr) {
      return root->index + 1;
    } else {
      return lower_than(root->right, val);
    }
  } else {
    if (root->left == nullptr) {
      return root->index;
    } else {
      return lower_than(root->left, val);
    }
  }
}

int upper_than(Node* root, int val) {
  return root->num - lower_than(root, val + 1);
}

int lower_than_or_equal(Node* root, int val) {
  return root->num - upper_than(root, val);
}

void free(Node* root) {
  if (root->left != nullptr) {
    free(root->left);
  }
  if (root->right != nullptr) {
    free(root->right);
  }
  delete root;
}

int main(int argc, char* argv[]) {
  int N, K;
  Node* root = new Node();
  ll count = 0;
  ll sum = 0;

  cin >> N >> K;

  ll a, seg;
  FOR1(i, 1, N+1) {
    cin >> a;
    sum += a;
    count += lower_than_or_equal(root, sum - K * i);
    insert(root, sum - K * i);
  }

  cout << count << endl;

  free(root);
  root = nullptr;

  return 0;
}
