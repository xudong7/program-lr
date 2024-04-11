// https://leetcode.cn/problems/invert-binary-tree/

// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    TreeNode* dfs(TreeNode* root)
    {
        if(root == nullptr)
            return nullptr;
        TreeNode* temp = new TreeNode;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        dfs(root->left);
        dfs(root->right);
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp = root;
        dfs(temp);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
