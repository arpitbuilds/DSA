/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>>ans;
      if(root==NULL){
        return ans;
      }
         bool flag=1;
      queue<TreeNode*>q;
      q.push(root);
     while(!q.empty()){
        int s=q.size();
        vector<int>lvl(s);
        for(int i=0;i<s;i++){
            TreeNode *node=q.front();
            q.pop();
            int index=(flag)?i:(s-i-1);
            lvl[index]=node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        flag=!flag;
        ans.push_back(lvl);
     }
     return ans;
    }
};

// vector<vector<int>> result;
//         if(root==NULL){
//             return result;
//         }
//         bool flag=true;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){   //tc sc o(n)

//             int size=q.size();
//              vector<int>ans(size);
//             for(int i=0;i<size;i++){
//                 TreeNode*node=q.front();
//                 q.pop();
//                 int index=(flag)?i:(size-i-1);
//                 ans[index]=node->val;
//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                 }

//             }
//             flag=!flag;
//             result.push_back(ans);
//         }
//         return result;