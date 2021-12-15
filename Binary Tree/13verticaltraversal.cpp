#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){};
};
void verticalTraversal(Node* node){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({node, {0, 0}});
    while(!q.empty()){
        auto element = q.front();
        q.pop();
        node = element.first;
        int y = element.second.first, x = element.second.second;
        nodes[y][x].insert(node->val);
        if(node->left) q.push({node->left, {y-1, x+1}});
        if(node->right) q.push({node->right, {y+1, x+1}});
    }
    for(auto p: nodes){
        for(auto q: p.second){
            for(int i: q.second) cout << i << ' ';
        }
    }
}
vector<vector<int>> verticallTraversal(Node* root) {
        queue<pair<Node*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            Node* node = temp.first;
            int y = temp.second.first, x = temp.second.second;
            nodes[y][x].insert(node->val);
            if(node->left) q.push({node->left, {y-1, x+1}});
            if(node->right) q.push({node->right, {y+1, x+1}});
        }
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> v;
            for(auto temp: p.second){
                v.insert(v.end(), temp.second.begin(), temp.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
int main(){
 Node* root = new Node(1);
 root->left = new Node(2);
 root->right = new Node(3);
 verticalTraversal(root);
 vector<vector<int>> v = verticallTraversal(root);
 for(auto i: v) for(int j: i) cout << j << ' ';
}