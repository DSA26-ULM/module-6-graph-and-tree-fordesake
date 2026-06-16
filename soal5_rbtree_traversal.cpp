#include <iostream>
#include <vector>
#include "RedBlackTree.h"
using namespace std;

void preorder(const RedBlackTree::Node* node,
              const RedBlackTree::Node* nil,
              vector<int>& result) {
    if (node->isNil) return;
    result.push_back(node->key);
    preorder(node->left,  nil, result);
    preorder(node->right, nil, result);
}

void inorder(const RedBlackTree::Node* node,
             const RedBlackTree::Node* nil,
             vector<int>& result) {
    if (node->isNil) return;
    inorder(node->left,  nil, result);
    result.push_back(node->key);
    inorder(node->right, nil, result);
}

void postorder(const RedBlackTree::Node* node,
               const RedBlackTree::Node* nil,
               vector<int>& result) {
    if (node->isNil) return;
    postorder(node->left,  nil, result);
    postorder(node->right, nil, result);
    result.push_back(node->key);
}

void printTraversal(const string& label, const vector<int>& vals) {
    cout << "[" << label << "] : ";
    for (int i = 0; i < (int)vals.size(); i++) {
        if (i > 0) cout << " ";
        cout << vals[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    RedBlackTree rbt;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        if (!rbt.contains(val)) {
            rbt.insert(val);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        cin >> query;

        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
            continue;
        }

        const RedBlackTree::Node* r   = rbt.root();
        const RedBlackTree::Node* nil = rbt.nil();

        if (query == "PREORDER") {
            vector<int> res;
            preorder(r, nil, res);
            printTraversal("Preorder", res);

        } else if (query == "INORDER") {
            vector<int> res;
            inorder(r, nil, res);
            printTraversal("Inorder", res);

        } else if (query == "POSTORDER") {
            vector<int> res;
            postorder(r, nil, res);
            printTraversal("Postorder", res);

        } else if (query == "ALL") {
            vector<int> pre, in, post;
            preorder (r, nil, pre);
            inorder  (r, nil, in);
            postorder(r, nil, post);
            printTraversal("Preorder",  pre);
            printTraversal("Inorder",   in);
            printTraversal("Postorder", post);
        }
    }

    return 0;
}
