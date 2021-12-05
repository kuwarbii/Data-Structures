#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int val): val(val){};
};

vector<vector<int>> hard(Node* node){
    vector<vector<int>> v;
    if(node == nullptr) return v;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        int len = q.size();
        vector<int> level;
        for(int i = 0; i < len; i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->val);
        }
        v.push_back(level);
    }
    return v;

}
int main(){
    Node *root = new Node(1);
    root-> left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    const vector<vector<int>> &v = hard(root);
    for(vector<int> a: v){
        for(int i: a){
            cout << i << " ";
        }
        cout <<endl;
    }
}