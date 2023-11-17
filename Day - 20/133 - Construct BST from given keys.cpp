/*CodeStudio solution*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* helper(vector<int>& nums, int low, int high)
{
    if(low <= high)
    {
        int mid = low + (high-low)/2;
        TreeNode<int>* root = new TreeNode<int>(nums[mid]);
        root->left = helper(nums, low, mid-1);
        root->right = helper(nums, mid+1, high);
        return root;
    }
    return NULL;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return helper(arr, 0, arr.size()-1);
}

/*Leetcode solution*/

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
class Solution
{
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return helper(nums, 0, nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums, int low, int high)
    {
        if(low <= high)
        {
            int mid = low + (high-low)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = helper(nums, low, mid-1);
            root->right = helper(nums, mid+1, high);
            return root;
        }
        return NULL;
    }
};