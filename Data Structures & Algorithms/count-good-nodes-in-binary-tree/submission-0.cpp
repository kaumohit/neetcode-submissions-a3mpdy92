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
    void countGoodNodes(TreeNode* root, int maxVal, int& goodNodeCount) {
        if(root == NULL) {
            return;
        }

        if(root->val >= maxVal) {
            goodNodeCount++;
        }

        countGoodNodes(root->left, max(root->val, maxVal), goodNodeCount);
        countGoodNodes(root->right, max(root->val, maxVal), goodNodeCount);
    }

    int goodNodes(TreeNode* root) {
        int goodNodeCount = 0;

        countGoodNodes(root, INT_MIN, goodNodeCount);

        return goodNodeCount;
    }
};
