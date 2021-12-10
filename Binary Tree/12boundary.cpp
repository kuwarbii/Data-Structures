#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){};
};

void leftTree(Node* node){
    if(node->left == nullptr && node->right == nullptr) return;
    cout << node->val << ' ';
    if(node->left){
        
        leftTree(node->left);

    } 
    else {
        leftTree(node->right);
    }

}
void leafNodes(Node* node){
    if(node == nullptr) return;
    leafNodes(node->left);
    if(node->left == nullptr && node->right == nullptr) cout << node->val << " ";
    leafNodes(node->right);
}

void rightTree(Node* node){
    stack<Node*> st;
    Node* temp = node->right;
    while(temp){
        
        if(temp->left == nullptr && temp->right == nullptr) break;
        st.push(temp);
        if(temp->right) temp = temp->right;
        else temp = temp -> left;
    }
    
    while(!st.empty()){
        cout << st.top()->val << ' ';
        st.pop();
    }

}
void boundaryTravel(Node* node){
    leftTree(node);
    leafNodes(node);
    rightTree(node);
}
int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    boundaryTravel(root);
}