/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root,vector<int> & ans ){
        if(!root){
            return;
        }
        solve(root -> left,ans);
        ans.push_back(root -> data);
        solve(root -> right,ans);
    }
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};