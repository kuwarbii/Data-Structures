#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val):val(val), left(nullptr), right(nullptr){};
};
void recursive(Node *node){
    if(node == NULL){
        return;
    }
    cout << node->val << ' ';
    rpretrav(node->left);
    rpretrav(node->right);
}

void iterative(Node* node){
    stack<Node*> st;
    st.push(node);
    while(!st.empty()){
        node = st.top();
        st.pop();
        cout << node->val << ' ';
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
}

void iterrative2(Node* node){
    stack<Node*> st;
    while(true){
        if(node){
            cout << node->val << ' ';
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) return;
            node = st.top();
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
    cout << endl;
    iterative(root);
    cout << endl;
    iterative2(root);
}
