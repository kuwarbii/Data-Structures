#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val): val(val){};
};
void zigZag(Node* node){
    if(node == nullptr) return;
    queue<Node*> q;
    q.push(node);
    int flag = 1;
    while(!q.empty()){
        int size = q.size();
        vector<int> v(size);
        for(int i = 0; i < size; i++){
            node = q.front();
            q.pop();
            int temp = node->val;
            int index = flag? i: size - i - 1; 
            v[index] = temp;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        flag = !flag;
        for(int i: v) cout << i << ' ';
    }
}
int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    zigZag(root);
}