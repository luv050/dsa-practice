#include <bits/stdc.h++>
using namespace std;
// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Preorder traversal
void preorder(Node* root, vector<int>& arr) {
    if (root == nullptr) return;
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

// Inorder traversal
void inorder(Node* root, vector<int>& arr) {
    if (root == nullptr) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Postorder traversal
void postorder(Node* root, vector<int>& arr) {
    if (root == nullptr) return;
    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->data);
}

// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Preorder traversal
    vector<int> preorderResult;
    preorder(root, preorderResult);
    cout << "Preorder Traversal: ";
    printVector(preorderResult);

    // Inorder traversal
    vector<int> inorderResult;
    inorder(root, inorderResult);
    cout << "Inorder Traversal: ";
    printVector(inorderResult);

    // Postorder traversal
    vector<int> postorderResult;
    postorder(root, postorderResult);
    cout << "Postorder Traversal: ";
    printVector(postorderResult);

    return 0;
}
