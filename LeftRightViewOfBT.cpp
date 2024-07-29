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

void RightViewOfBT(node* root,int level,vector<int>&ans) {
    if (root == nullptr) return;
    
    if(ans.size() == level) ans.push_back(root->data);
    
    RightViewOfBT(root->right,level+1,ans);
    RightViewOfBT(root->left,level+1,ans);
}

void LeftViewOfBT(node* root,int level,vector<int>& ans) {
    if (root == nullptr) return;
    
    if(ans.size() == level) ans.push_back(root->data);
    
    LeftViewOfBT(root->left,level+1,ans);
    LeftViewOfBT(root->right,level+1,ans);   
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
    vector<int> a,b;
    RightViewOfBT(r,0,a);
    cout<<"rightview=>";
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
    cout<<endl;
    LeftViewOfBT(r,0,b);
    cout<<"leftview=>";
    for(int i=0;i<b.size();i++) cout<<b[i]<<" ";

    return 0;
}


