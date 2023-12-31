/*CodeStudio solution*/

/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/


bool isIdentical(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1 == NULL || root2 == NULL) return root1==root2;
    return ((root1->data == root2->data) && isIdentical(root1->left, root2->right) && isIdentical(root1->right, root2->left));
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
    return isIdentical(root->left, root->right);
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
class Solution {
public:
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2 == NULL) return root1==root2;
        return ((root1->val == root2->val) && isIdentical(root1->left, root2->right) && isIdentical(root1->right, root2->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isIdentical(root->left, root->right);
    }
};

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
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* runner = curr->left;
                while (runner->right != nullptr) runner = runner->right;
                runner->right = curr->right, curr->right = curr->left, curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
