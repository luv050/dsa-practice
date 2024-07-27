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

int MaximumSumPath(node* sample){
    if(sample==nullptr) return 0;
    
    int maxi=INT_MIN;
    
    int ls= max(0,MaximumSumPath(sample->left));
    int rs= max(0,MaximumSumPath(sample->right));
    
    maxi= max(maxi,sample->data+ ls+ rs);
    //and this give us the jo sabse bada sum hai pure tree mai 
    //niche wala fxn har node ka deta hai max sum path and upar wala tree ka max sum path note 
    
    return sample->data +max(ls,rs);// ye line har node ka max sum path bhejti hai
    
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(55);

    cout << MaximumSumPath(root) << endl;

    return 0;
}
