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

int HeightOfBT(node*sample){
    if(sample==nullptr) return -1;
    
    int ls=HeightOfBT(sample->left);
    int rs=HeightOfBT(sample->right);
    
    int x=max(ls,rs);
    
    return 1+x;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
/*  (Function to take input from user )
node* buildTree() {
    int data;
    cout << "Enter root data: ";
    cin >> data;

    if (data == -1) return nullptr;

    node* root = new node(data);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        cout << "Enter left child of " << current->data << " (-1 for no child): ";
        cin >> data;
        if (data != -1) {
            current->left = new node(data);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for no child): ";
        cin >> data;
        if (data != -1) {
            current->right = new node(data);
            q.push(current->right);
        }
    }

    return root;
}*/

    cout<<HeightOfBT(root);

    return 0;
}
