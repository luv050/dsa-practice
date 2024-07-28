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

bool BTSameOrNot(node*l, node*s){
    if(l==nullptr && s==nullptr) return true;// dono null hoagye to obv equal
    
    if (l == nullptr || s == nullptr) return false;// dono mai se koi 1 null hogaya toh obv nhi hai equal
    
    return (l->data == s->data) &&
           BTSameOrNot(l->left, s->left) &&    // recursively check if the node ka data 
           BTSameOrNot(l->right, s->right);    //left and right subtrees are similar
}

int main() {
    node* r = new node(1);
    r->left = new node(2);
    r->right = new node(3);
    r->left->left = new node(4);
    r->left->right = new node(55);
    
    node* m = new node(1);
    m->left = new node(2);
    m->right = new node(3);
    m->left->left = new node(4);
    m->left->right = new node(55);

    if (BTSameOrNot(r,m)) cout <<"both tree are similar"<<endl;
    else cout<<"both tree are not similar"<<endl;

    return 0;
}
