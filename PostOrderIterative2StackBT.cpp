#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data; 
    Node* left; 
    Node* right;
    
    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void PostOrderIterative2StackBT(Node* sample) {
    // Base case: if the root node is null, return immediately
    if (sample == nullptr) return;

    // Initialize two stacks
    stack<Node*> s1;
    stack<Node*> s2;

    // Push the root node to the first stack
    s1.push(sample);

    // Process nodes until the first stack is empty
    while (!s1.empty()) {
        // Pop the top node from the first stack and push it to the second stack
        Node* luv = s1.top();
        s1.pop();
        s2.push(luv);

        // Push the left and right children of the popped node to the first stack
        if (luv->left) s1.push(luv->left);
        if (luv->right) s1.push(luv->right);
    }

    // Process nodes in the second stack to print them in post-order
    while (!s2.empty()) {
        Node* nodeluv = s2.top();
        s2.pop();
        cout << nodeluv->data << " ";
    }
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
    
    PostOrderIterative2StackBT(root);

    return 0;
}
