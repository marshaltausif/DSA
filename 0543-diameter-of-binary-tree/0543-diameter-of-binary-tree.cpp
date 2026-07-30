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
    int diam = 0;

    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        diam = max(diam, leftH + rightH);   // diameter check happens HERE, inside height()
        return 1 + max(leftH, rightH);       // height() returns HEIGHT only
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);      // ONE call — this alone visits every node and updates diam
        return diam;        // just return the tracked best
    }
};
