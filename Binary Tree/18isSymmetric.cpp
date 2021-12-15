#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){}
};

bool recursive(Node* left, Node* right){
    if(left == nullptr || right == nullptr) return left == right;
    if(left->val != right->val) return false;
    return recursive(left->left, right->right) && recursive(left->right, right->left);
}
bool iterative(Node* node){
    Node* left = node->left;
    Node* right = node->right;
    queue<Node*> nodes;
    nodes.push(left);
    nodes.push(right);
    while(!nodes.empty()){
        Node* leftNode = nodes.front();
        nodes.pop();
        Node* rightNode = nodes.front();
        nodes.pop();
        if(rightNode == nullptr && leftNode == nullptr) continue;
        if(rightNode == nullptr || leftNode == nullptr) return false;
        if(rightNode-> val != leftNode->val) return false;
        nodes.push(leftNode->left);
        nodes.push(rightNode->right);
        nodes.push(leftNode->right);
        nodes.push(rightNode->left);
    }
    return true;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout << recursive(root->left, root->right) << ' ';
    cout << iterative(root);
}