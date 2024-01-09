class Solution
{
public:
    void DFS(TreeNode *root, string &s)
    {
        if (root == nullptr)
            return;
        DFS(root->left, s);
        if (root->left == NULL && root->right == NULL)
            s += to_string(root->val) + "_";
        DFS(root->right, s);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        string s1, s2;
        DFS(root1, s1); // tree 1
        DFS(root2, s2); // tree 2
        return s1 == s2;
    }
};