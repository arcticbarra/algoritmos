class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* r) {

        if (r == NULL) {
            return  vector<vector<int>> ();
        }

        vector<vector<int>> ans;
        bool zigZag = true;
        queue<TreeNode*> q;
        q.push(r);

        while(!q.empty()) {

            int qSize = q.size();
            vector<int> level(qSize);

            for(int i = 0; i < qSize; i++) {

                r = q.front();
                q.pop();
                int index = (zigZag) ? i : (qSize - i - 1);
                level[index] = r->val;

                if (r->left != NULL) {
                    q.push(r->left);

                }
                if (r->right != NULL) {
                    q.push(r->right);
                }
            }

            ans.push_back(level);
            zigZag = !zigZag;
        }

        return ans;

        }
};
