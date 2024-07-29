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

void BottomViewOfBT(node* root) {
    if (root == nullptr) return;

    // Map to store the last node at each horizontal distance
    map<int, int> m;

    /* Queue to perform level order traversal.
       We use a pair of node and int to keep track of nodes and their horizontal distances (HDs) */
    queue<pair<node*, int>> q;

    q.push({root, 0});  // Insert the root node with HD 0

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        node* temp = front.first;
        int hd = front.second;

        // Update the map with the last node at this horizontal distance
        m[hd] = temp->data; // bas yahi line ka farq hai top view and bottom view mai 

        // Push the left and right children with their corresponding HDs
        if (temp->left) {
            q.push({temp->left, hd - 1});
        }
        if (temp->right) {
            q.push({temp->right, hd + 1});
        }
    }

    // Print the bottom view nodes
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->second << " ";
    }
}

int main() {
    node* r = new node(1);
    r->left = new node(2);
    r->right = new node(3);
    r->left->left = new node(4);
    r->left->right = new node(5);
    r->right->left = new node(6);
    r->right->right = new node(7);

    /* Diagram:
             1(0)
           /     \
        2(-1)    3(1)
         /  \   /   \
      4(-2) 5(0) 6(0) 7(2)
    */

    BottomViewOfBT(r);

    return 0;
}

/*
Explanation:

The function uses a map to store nodes at each horizontal distance (HD) encountered during the level order traversal.

Nodes are updated in the map so that only the last node encountered at each horizontal distance is kept.

The traversal starts from the root (HD = 0). The left child has HD - 1 and the right child has HD + 1.

After the traversal, the nodes stored in the map represent the bottom view of the binary tree.

This approach ensures that only the bottom-most nodes at each horizontal distance are included in the result.
*/
