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

node* lowestCommonAncestor(node* root, node* p, node* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        node* left = lowestCommonAncestor(root->left, p, q);
        node* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }

int main() {
    node* r = new node(1);
    r->left = new node(2);
    r->right = new node(3);
    r->left->left = new node(4);
    r->left->right = new node(55);
    
 /*
       1
      / \
     2   3
    / \
   4   55

 */
    
    // Get pointers to the nodes with values 4 and 55
    node* p = r->left->left;  // Node with value 4
    node* q = r->left->right; // Node with value 55
    
    node* ans = lowestCommonAncestor(r, p, q);
    // wrong hai ye node*ans=lowestCommonAncestor(r,4,55);
    
    cout<<ans->data<<endl;
    

    return 0;
}
