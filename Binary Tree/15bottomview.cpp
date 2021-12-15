#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){}
};

vector<int> bottomview(Node* node){
    vector<int> ans;
    if(node == nullptr) return ans;
    queue<pair<int, Node*>>  q;
    map<int, int> nodes;
    q.push({0, node});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int lvl = it.first;
        Node* currNode = it.second;
        nodes[lvl] = currNode -> val;
        if(currNode->left) q.push({lvl-1, currNode->left});
        if(currNode->right) q.push({lvl+1, currNode->right});

    }
    for(auto node: nodes){
        ans.push_back(node.second);
    }
    return ans;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(3);
    root->right = new Node(4);
    vector<int> ans = bottomview(root);
    for(int i: ans) cout << i << ' ';
}