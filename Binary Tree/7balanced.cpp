#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val) {};
};

int balanced(Node* node){
    if(node == nullptr) return 0;
    int left = balanced(node->left);
    int right = balanced(node->right);
    if(left == -1 || right == -1) return -1;
    if(abs(left - right) > 1) return -1;
    else return (max(left, right) + 1);
}
int main(){
    Node *root = new Node(1);
    root-> left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root ->left -> left ->left = new Node(9);

    root->right = new Node(3);

    if(balanced(root) == -1) cout << "Not balanced " << endl;
    else cout << "Balanced" << endl;
}