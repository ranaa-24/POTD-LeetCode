int rangeSumBST(TreeNode *root, int low, int high)
{
    if (!root)
        return 0;
    int sum = 0;
    // go and add left only if root is greater than low, thats means we can find some lower val in left side.
    if (root->val > low)
        sum += rangeSumBST(root->left, low, high);
    if (root->val >= low && root->val <= high)
        sum += root->val;
    // to get greater element go right
    if (root->val < high)
        sum += rangeSumBST(root->right, low, high);

    return sum;
}