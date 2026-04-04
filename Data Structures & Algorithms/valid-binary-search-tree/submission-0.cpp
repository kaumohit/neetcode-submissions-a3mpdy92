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
    vector<int> checkBST(TreeNode* root, bool& isBST) {
        if(root == NULL) {
            return {INT_MAX, INT_MIN};
        }

        vector<int> left = checkBST(root->left, isBST);
        vector<int> right = checkBST(root->right, isBST);

        //cout<<left[0]<<" "<<left[1]<<endl;
        //cout<<right[0]<<" "<<right[1]<<endl;

        if(left[1] >= root->val || right[0] <= root->val) {
            isBST = false;
        }

        return {min(left[0],root->val), max(right[1], root->val)};
    }

    bool isValidBST(TreeNode* root) {
        bool isBST = true;

        checkBST(root, isBST);

        return isBST;
    }
};
