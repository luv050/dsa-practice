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

int BalancedOrNotBT(node* root) {
    if (root == nullptr) return 0;

    int ls = BalancedOrNotBT(root->left);
    if (ls == -1) return -1;

    int rs= BalancedOrNotBT(root->right);
    if (rs== -1) return -1;

    if (abs(ls-rs)>1) return -1;

    return max(ls,rs) + 1;
}


int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    cout<<"if ans is -1 is not balanced otherwise it is and we have printed the tress height"<<endl;
    cout<<BalancedOrNotBT(root)<<endl;

    return 0;
}
