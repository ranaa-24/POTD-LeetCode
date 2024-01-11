class Solution
{
public:
    int maxDiff = -1;
    void calcuDiff(TreeNode *root, TreeNode *child)
    {
        if (!root || !child)
            return;
        int diff = abs(root->val - child->val);
        maxDiff = max(maxDiff, diff);
        calcuDiff(root, child->left);
        calcuDiff(root, child->right);
    }

    void takeEachNode(TreeNode *root)
    {
        if (!root)
            return;

        // for the current root
        calcuDiff(root, root->left);
        calcuDiff(root, root->right);

        // for other roots
        takeEachNode(root->left);
        takeEachNode(root->right);
    }
    int maxAncestorDiff(TreeNode *root)
    {
        takeEachNode(root);
        return maxDiff;
    }
};