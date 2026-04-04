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
    void levelOrderTraversal(TreeNode* root, int level, vector<int>& rightView) {
        if(root == NULL) {
            return;
        }

        if(level > rightView.size()) {
            rightView.push_back(root->val);
        }
        else {
            rightView[level-1] = root->val;
        }

        levelOrderTraversal(root->left, level+1, rightView);
        levelOrderTraversal(root->right, level+1, rightView);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;

        levelOrderTraversal(root, 1, rightView);

        return rightView;
    }
};
