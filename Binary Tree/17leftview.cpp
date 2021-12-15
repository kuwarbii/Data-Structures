#include<bits/stdc++.h>
using namespace std;
// O(h)
struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){}
};

void leftView(Node* node, int lvl, vector<int> &ans){
    if (node == nullptr) return;
    if(lvl == ans.size()) ans.push_back(node->val);
    leftView(node->left, lvl+1, ans);
    leftView(node->left, lvl+1, ans);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    vector<int> ans;
    leftView(root, 0, ans);
    for(int i: ans) cout << i << " ";
}