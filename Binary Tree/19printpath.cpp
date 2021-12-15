#include<bits/stdc++.h>
using namespace std; 

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){}
};
vector<int> ans;
bool path(Node* node, int target){
    if(!node) return false;
    ans.push_back(node->val);
    if(node->val == target) return true;
    if(path(node->left, target) || path(node->right, target)) return true;

    ans.pop_back();
    return false;
    
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(4);
    path(root, 4);
    for(int i: ans) cout << i << ' ';
}