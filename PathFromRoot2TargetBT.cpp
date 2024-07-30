
#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the binary tree
class node {
public:
    int data;
    node *left, *right;

    // Constructor to initialize the node
    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Helper function to find the path from the root node to the target node
bool getPath(node* root, vector<int>& path, int k) {
    // Base case: if the current node is nullptr, return false
    if (root == nullptr) return false;

    // Store the current node's data in the path
    path.push_back(root->data);

    // If the current node's data is the target node's data, return true
    if (root->data == k) return true;

    // Recursively check if the target node is in the left or right subtree
    if ((root->left && getPath(root->left, path, k)) || (root->right && getPath(root->right, path, k))) 
        return true;

    // If the target node is not found in either subtree, remove the current node from the path and return false
    path.pop_back();
    return false;
}

// Function to print the path from the root node to the target node
void printPath(node* root, int k) {
    vector<int> path;
    // Get the path using the helper function
    if (getPath(root, path, k)) {
        // Print the path if the target node is found
        for (int i : path) {
            cout << i << " ";
        }
    } else {
        // Print a message if the target node is not found
        cout << "No path found from root to " << k;
    }
    cout << endl;
}

int main() {
    // Create the binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    /* Binary Tree Structure:
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */

    // Target node to find the path to
    int target = 5;
    cout << "Path from root to node " << target << ": ";
    // Print the path from the root to the target node
    printPath(root, target);

    return 0;
}


/*

<Algorithm>
Define a Node Class:

Each node contains data, left, and right.
Create a Recursive Function getPath:

This function finds the path from the root to the target node.
Add the current node's data to the path.
If the current node is the target, return true.
Recursively check left and right subtrees.
If the target is not found, remove the current node from the path and return false.
Print the Path:

If the target node is found, print the path.

<Dry Run>
Consider the binary tree:
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
Target node = 5

Start at root (1):

Path = [1]
Target (5) not found. Recurse to the left child.
Move to node (2):

Path = [1, 2]
Target (5) not found. Recurse to the left child.
Move to node (4):

Path = [1, 2, 4]
Target (5) not found. Recurse to the left child.
Move to nullptr:

Return false.
Backtrack to node (4), remove 4 from the path.
Path = [1, 2]
Recurse to the right child of node (2).
Move to node (5):

Path = [1, 2, 5]
Target (5) found. Return true.
Backtrack and return true up to the root.

*/
