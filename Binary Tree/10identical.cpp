#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){};
};
bool isIdentical(Node* first, Node* second){
    if(first == nullptr || second == nullptr) return first == second;

    return (first->val == second->val && isIdentical(first->left, second->left) && isIdentical(first->right, second->right));
}
int main(){
    Node* a = new Node(1);
    a->left = new Node(2);
    a->right = new Node(3);
    a->left->right = new Node(4);

    Node* b = new Node(1);
    b->left = new Node(2);
    b->right = new Node(3);
    cout << isIdentical(a, b) << endl;
}