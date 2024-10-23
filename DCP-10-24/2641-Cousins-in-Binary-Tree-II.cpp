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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<pair<TreeNode *, int>> q = {{root, root->val}};
        while (!empty(q)) {
            vector<pair<TreeNode *, int>> new_q;
            const int total = accumulate(cbegin(q), cend(q), 0, [](const auto& total, const auto& x) {
                return total + x.first->val;
            });
            for (auto [node, x] : q) {
                node->val = total - x;
                x = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node->left) {
                    new_q.emplace_back(node->left, x);
                }
                if (node->right) {
                    new_q.emplace_back(node->right, x);
                }
            }
            q = move(new_q);
        }
        return root;
    }
};