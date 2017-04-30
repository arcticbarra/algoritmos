class Solution {
public:

    int sumOfLeftLeavesHelper(TreeNode* r, bool left) {
        if (r == NULL) {
            return 0;
        }

        if (r->left == NULL && r->right == NULL) {
            return left ? r->val : 0;
        }

        return sumOfLeftLeavesHelper(r->left,true) + sumOfLeftLeavesHelper(r->right,false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, false);
    }

};
