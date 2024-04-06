// https://leetcode.cn/problems/balanced-binary-tree/solutions/377216/ping-heng-er-cha-shu-by-leetcode-solution

# include<iostream>
# include<bits/stdc++.h>
using namespace std;

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
    // 自顶向下DFS
    int height(TreeNode* root)
    {
        if(!root) return 0;
        // 返回最深高度 同时继续向下 故加1
        else return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        // 保证左子树和右子树平衡
        // 保证左右子树高度不超过1
        else return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution2 {
public:
    // 自底向上DFS
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        // 当前节点左右子树是否差值不超过1 或者是否子树中存在不平衡的情况(存在-1值)
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            // 继续上探 高度加1
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        // 用0或-1来判断平衡
        return height(root) >= 0;
    }
};
