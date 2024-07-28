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

vector<int> ZigZagTraversalBT(node* sample) {
    vector<int> result;
    if (sample==nullptr) return result;
    
    stack<node*> currentLevel;
    stack<node*> nextLevel;
    bool l2r = true;  // Start with l-R drn
    
    currentLevel.push(sample);  // Push the root node onto the current level stack
    
    while (!currentLevel.empty()) {
        node* temp = currentLevel.top();
        currentLevel.pop();
        
        if (temp) {
            result.push_back(temp->data);
            
            // Depending on the direction, push children to nextLevel
            if (l2r) {
                if (temp->left) nextLevel.push(temp->left);
                if (temp->right) nextLevel.push(temp->right);
            } else {
                if (temp->right) nextLevel.push(temp->right);
                if (temp->left) nextLevel.push(temp->left);
            }
        }
        
        // If the current level is empty, switch to the next level
        if (currentLevel.empty()) {
            l2r = !l2r;  // drn change krdo
            swap(currentLevel, nextLevel);  // stacks bhi switch karo dry kr lena 1 baari 
        }
    }
    
    return result;
}

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    node* r = new node(1);
    r->left = new node(2);
    r->right = new node(3);
    r->left->left = new node(4);
    r->left->right = new node(55);
    
    vector<int> ans = ZigZagTraversalBT(r);

    cout << "Zigzag (Spiral) Order Traversal: ";
    printVector(ans);

    return 0;
}
