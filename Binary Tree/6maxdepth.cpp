#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val):val(val){};
};
int recursive(Node* node){
    if(node == nullptr) return 0;
    return(max(recursive(node->left), recursive(node->right))) + 1;
}
int iterative(Node* node){ // level order traversal.
    int height = 0;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        height++;
        
        for(int i = 0; i < q.size(); i++){
            node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return height;
}
int main(){
    Node *root = new Node(1);
    root-> left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << recursive(root) << endl;
    cout << iterative(root) << endl;
}