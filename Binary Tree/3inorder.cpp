#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val):val(val){};
};
void recursive(Node* node){
    if(node == nullptr){
        return;
    }
    rinord(node->left);
    cout << node->val << " ";
    rinord(node->right);
}

void iterative(Node* nodee){
    stack<Node*> st;
    Node* node = nodee;
    while(true){
        if(node){
            st.push(node);
            node = node -> left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            cout << node->val << " ";
            st.pop();
            
            node = node -> right;
            
        }
    }
}
int main(){
    Node *root = new Node(1);
    root-> left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    recursive(root);
    cout << '\n';
    iterative(root);
}
