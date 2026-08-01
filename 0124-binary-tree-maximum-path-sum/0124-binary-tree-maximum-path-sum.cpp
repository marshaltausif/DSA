class Solution {
public:

    // Returns the maximum downward path sum starting from root
    int maxDown(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = maxDown(root->left);
        int right = maxDown(root->right);

        // Ignore negative contributions
        left = max(0, left);
        right = max(0, right);

        return root->val + max(left, right);
    }

    // Brute-force: computes answer for every node
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return INT_MIN;

        int left = maxDown(root->left);
        int right = maxDown(root->right);

        left = max(0, left);
        right = max(0, right);

        // Path passing through current node
        int current = left + root->val + right;

        // Best answer in left subtree
        int leftAns = maxPathSum(root->left);

        // Best answer in right subtree
        int rightAns = maxPathSum(root->right);

        return max(current, max(leftAns, rightAns));
    }
};