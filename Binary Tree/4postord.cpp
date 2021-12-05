#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val):val(val){};
};

void repost(Node* node){
    if(node == nullptr){
        return;
    }
    repost(node->left);
    repost(node->right);
    cout << node->val << ' ';
}

void itpost2stack(Node* node){
    stack<Node*> st1, st2;
    st1.push(node);
    while(!st1.empty()){
        node = st1.top();
        st1.pop();
        st2.push(node);
        
        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);
    }
    while(!st2.empty()){
        cout << st2.top()->val << ' ';
        st2.pop();
    }
}

void itpost1stack(Node* node){
    stack<Node*> st;
    Node* curr = node;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            node = st.top()->right;
            if(node == nullptr){
                node = st.top();
                cout << node->val << ' ';
                st.pop();
                while(!st.empty() && node == st.top()->right){
                    node = st.top();
                    st.pop();
                    cout << node->val << " ";
                }
            }
            else{
                curr = node;
            }
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
    repost(root);
    cout << endl;
    itpost2stack(root);
    cout << endl;
    itpost1stack(root);
}