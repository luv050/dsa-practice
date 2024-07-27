#include <bits/stdc++.h>
using namespace std;
//diameter matlab longest path btn nodes and it's not necessary it 
// should pass from the root 

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

int diameterUtil(node* root, int& diameter) {
    if (root == nullptr) return 0;

    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);

    // Calculate the diameter passing through the current node
    int maxDiameter = leftHeight + rightHeight;

    // Update the maximum diameter found so far
    diameter = max(diameter, maxDiameter);

    // Return the height of the tree rooted at the current node
    return max(leftHeight, rightHeight) + 1;
}

int #include <bits/stdc++.h>
using namespace std;
//diameter matlab longest path btn nodes and it's not necessary it 
// should pass from the root 

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

int diameterUtil(node* root, int& diameter) {
    if (root == nullptr) return 0;

    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);

    // Calculate the diameter passing through the current node
    int maxDiameter = leftHeight + rightHeight;

    // Update the maximum diameter found so far
    diameter = max(diameter, maxDiameter);

    // Return the height of the tree rooted at the current node
    return max(leftHeight, rightHeight) + 1;
}

int DiameterOfBT(node* root) {
    int diameter = 0;
    diameterUtil(root, diameter);
    return diameter;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << DiameterOfBT(root) << endl;

    return 0;
}
(node* root) {
    int diameter = 0;
    diameterUtil(root, diameter);
    return diameter;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << DiameterOfBT(root) << endl;

    return 0;
}
