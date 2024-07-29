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

void TopViewOfBT(node* root) {
    if (root == nullptr) return;

    // Map to store the first node at each horizontal distance
    map<int, int> m;  // Changed to map<int, int>

    /* Unlike a map, a queue can only take one value at a time.
    So, we created a pair of node and int so that they become one
    unit together and can be inserted into the queue */
    queue<pair<node*, int>> q;

    q.push({root, 0});  // Insert the first element into the queue

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        node* temp = front.first;
        int hd = front.second;

        // If a node at this horizontal distance is not present in the map
        // then this node is part of the top view
        if (m.find(hd) == m.end()) m[hd] = temp->data;

        // Push the left and right children with their corresponding HDs
        if (temp->left) {
            q.push({temp->left, hd - 1});
        }
        if (temp->right) {
            q.push({temp->right, hd + 1});
        }
    }

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

    TopViewOfBT(r);

    return 0;
}

/*
Initial State:
Queue: [(1, 0)]
Map: {}

Iteration 1:
Queue: [(2, -1), (3, 1)]
Map: {0: 1}

Iteration 2:
Queue: [(3, 1), (4, -2), (5, 0)]
Map: {-1: 2, 0: 1}

Iteration 3:
Queue: [(4, -2), (5, 0), (6, 0), (7, 2)]
Map: {-1: 2, 0: 1, 1: 3}

Iteration 4:
Queue: [(5, 0), (6, 0), (7, 2)]
Map: {-2: 4, -1: 2, 0: 1, 1: 3}

Iteration 5:
Queue: [(6, 0), (7, 2)]
Map: {-2: 4, -1: 2, 0: 1, 1: 3}

Iteration 6:
Queue: [(7, 2)]
Map: {-2: 4, -1: 2, 0: 1, 1: 3}

Iteration 7:
Queue: []
Map: {-2: 4, -1: 2, 0: 1, 1: 3, 2: 7}

How it works:

The function uses a map to store nodes at each horizontal distance (HD) encountered during the level order traversal.

Nodes are added to the map only if they are the first node encountered at their respective HD.

The traversal starts from the root (HD = 0). The left child has HD - 1 and the right child has HD + 1.

After the traversal, the nodes stored in the map represent the top view of the binary tree.

This approach ensures that only the top-most nodes at each horizontal distance are included in the result.
*/
