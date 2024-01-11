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


//Eficient approach..

class Solution {
public:
    int getDiff(TreeNode* root, int maxi, int mini){
        if(root==nullptr)
            return abs(maxi - mini);
        
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        //find deff in left
        int l = getDiff(root->left, maxi, mini);
        int r = getDiff(root->right, maxi, mini);

        return max(l, r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return getDiff(root, INT_MIN, INT_MAX);
    }
};