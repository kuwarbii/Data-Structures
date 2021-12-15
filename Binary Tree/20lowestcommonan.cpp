#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){}
};

Node* lowestCommonAncestor(Node* node, Node* a, Node* b){
    if(!node || node == a || node == b) return node;
    Node* temp1 = lowestCommonAncestor(node->left, a, b);
    Node* temp2 = lowestCommonAncestor(node->right, a, b);
    if(!temp1) return temp2;
    if(!temp2) return temp1;
    return node; 
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    cout << lowestCommonAncestor(root, root->left, root->left->right)->val << endl;
}