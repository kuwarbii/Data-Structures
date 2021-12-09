#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){};
};
int mx;
int findMaxPath(Node* node){
    if(node == nullptr) return 0;
    int left = max(0, findMaxPath(node->left));
    int right = max(0, findMaxPath(node->right));
    mx = max(mx, left+right+node->val);
    return max(left, right) + node->val;
}
int main(){
    Node *root = new Node(1);
    root-> left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    mx = root->val;
    findMaxPath(root);
    cout << mx;
}