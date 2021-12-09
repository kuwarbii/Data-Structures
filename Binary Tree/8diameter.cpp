#include<bits/stdc++.h>
using namespace std;
int diameter = 0;
struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){};
};

int findDiameter(Node* node){
    if(node == nullptr) return 0;
    int left = findDiameter(node->left);
    int right = findDiameter(node->right);
    diameter = max(diameter, left + right);
    return max(left, right) + 1;
}
int main(){
    Node *root = new Node(1);
    root-> left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    findDiameter(root);
    cout << diameter << endl;   
}