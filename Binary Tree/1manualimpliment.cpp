#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val);
};
Node::Node(int val):val(val){
    left = nullptr;
    right = NULL;
}
int main(){
    Node* n = new Node(5);
    n->left = new Node(4);
    n->right = new Node(3);
    n->left->left = new Node(2);
    n->left->right = new Node(1);
}