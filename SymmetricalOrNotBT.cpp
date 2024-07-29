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

bool SubFxn(node*LeftPart, node*RightPart) {
    if(LeftPart==nullptr || RightPart==nullptr) return(left==right);
    
    if(LeftPart->data != RightPart->data) return false;
    
    return SubFxn(LeftPart->left,RightPart->right) && SubFxn(LeftPart->right,RightPart->left);
}


bool SymmetricalOrNotBT(node* root) {
    if (root == nullptr) return true;
    return SubFxn(root->left, root->right);
}


int main() {
    node* r = new node(1);
    r->left = new node(2);
    r->right = new node(3);
    r->left->left = new node(4);
    r->left->right = new node(5);
    r->right->left = new node(6);
    r->right->right = new node(7);

    if (SymmetricalOrNotBT(r)) cout<<"The binary tree is symmetrical."<<endl;
    else cout<<"The binary tree is not symmetrical."<<endl;
    
    return 0;
}


