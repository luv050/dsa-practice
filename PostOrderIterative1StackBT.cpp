#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left, *right;

    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void PostOrderIterative1StackBT(node* sample) {
    if (sample == nullptr) {
        return;
    }

    stack<node*> s;
    vector<int> v;
    node* lastVisited = nullptr;
    node* current = sample;

    while (!s.empty() || current != nullptr) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;
        } else {
            node* temp = s.top();
            if (temp->right != nullptr && lastVisited != temp->right) {
                current = temp->right;
            } else {
                v.push_back(temp->data);
                lastVisited = s.top();
                s.pop();
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    PostOrderIterative1StackBT(root);

    return 0;
}
