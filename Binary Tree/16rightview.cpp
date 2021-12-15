#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){}
};

void rightView(Node* node, int lvl, vector<int> &ans){
    if (node == nullptr) return;
    if(lvl == ans.size()) ans.push_back(node->val);
    rightView(node->right, lvl+1, ans);
    rightView(node->left, lvl+1, ans);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    vector<int> ans;
    rightView(root, 0, ans);
    for(int i: ans) cout << i << " ";
}