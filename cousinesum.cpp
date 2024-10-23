 */
class Solution {

    vector<int> levelsum(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        int sum = 0;
        q.push(root);
        q.push(nullptr);

        while (q.size()) {
            TreeNode* root = q.front();
            q.pop();

            if (root == nullptr) {
                res.push_back(sum);
                sum = 0;
                if (q.size())
                    q.push(nullptr);
            } else {
                sum += root->val;

                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }

        return res;
    }

    int bloodsum(TreeNode* p) {
        int sum = 0;

        if (p->left)
            sum += p->left->val;
        if (p->right)
            sum += p->right->val;

        return sum;
    }

    TreeNode* cousinSum(TreeNode* root, TreeNode* perent,
                        vector<int>& levelsums, int level) {

        if (root == nullptr)
            return nullptr;

        TreeNode* newroot = new TreeNode();

        if (perent != nullptr)
            newroot->val = levelsums[level] - bloodsum(perent);

        newroot->left = cousinSum(root->left, root, levelsums, level + 1);
        newroot->right = cousinSum(root->right, root, levelsums, level + 1);

        return newroot;
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {

        if (root->left == nullptr && root->right == nullptr) {
            return new TreeNode(0);
        }

        vector<int> levelsums = levelsum(root);

        return cousinSum(root, nullptr, levelsums, 0);
    }
};