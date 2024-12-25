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
    vector<int> largestValues(TreeNode* root) {
         vector<int> result;
        if (!root) {
            return result; // Return an empty vector for an empty tree
        }
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN; // Initialize the maximum value for the current level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                maxVal = max(maxVal, current->val); // Update maxVal

                if (current->left) {
                    q.push(current->left);
                }

                if (current->right) {
                    q.push(current->right);
                }
            }
            
            result.push_back(maxVal); // Add the maximum value for the current level to the result vector
        }
        
        return result;
    }
};
