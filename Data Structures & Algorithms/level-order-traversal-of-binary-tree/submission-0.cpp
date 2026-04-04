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
    void traverseLevelOrder(TreeNode* root, int level, vector<vector<int>> &levelOrderTraversal) {
        if(root == NULL) {
            return;
        }

        if(level > levelOrderTraversal.size()) {
            levelOrderTraversal.push_back({root->val});
        }
        else {
            levelOrderTraversal[level-1].push_back(root->val);
        }

        traverseLevelOrder(root->left, level+1, levelOrderTraversal);
        traverseLevelOrder(root->right, level+1, levelOrderTraversal);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;

        traverseLevelOrder(root, 1, levelOrderTraversal);

        return levelOrderTraversal;
    }
};
