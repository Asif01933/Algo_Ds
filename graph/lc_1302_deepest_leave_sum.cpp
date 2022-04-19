/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepest=0,sum=0;
    int deepestLeavesSum(TreeNode* root,int deep=0) {
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            if(deep==deepest){
                sum+=root->val;
                
            }
            else if(deep>deepest){
                sum=root->val;
                deepest=deep;
            }
        }
        deepestLeavesSum(root->left,deep+1);
        deepestLeavesSum(root->right,deep+1);
        return sum;
    }
};