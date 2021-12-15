#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){}
};
vector<int> topView(Node* node){
    vector<int> ans;
    queue<pair<int, Node*>> q;
    map<int, int> nodes;
    q.push({0, node});
    while(!q.empty()){
        auto top = q.front();
        int x = top.first;
        Node* currNode = top.second;
        q.pop();
        if(nodes.find(x) == nodes.end()){
            nodes[x] = currNode->val;
        }
        if(top.second->left){
            q.push({x-1, currNode->left});
        }
        if(top.second->right){
            q.push({x+1, currNode->right});
        }
    }
    for(auto temp: nodes){
        ans.push_back(temp.second);
    }
    return ans;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> order = topView(root);
    for(int i: order){
        cout << i <<' ';
    }
}