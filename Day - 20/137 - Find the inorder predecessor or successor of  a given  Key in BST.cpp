/*CodeStudio solution*/

/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
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
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void inorder_predecessor(BinaryTreeNode<int>* root,int &pred, int key)
{
    while(root!=NULL)
    {
        if(root->data<key)
        {
            pred=root->data;
            root=root->right;
        }
        else if(root->data>=key)
        {
            root=root->left;
        }
    }
}
void inorder_successor(BinaryTreeNode<int>* root,int &succ, int key)
{
    while(root!=NULL)
    {
        if(root->data>key)
        {
            succ=root->data;
            root=root->left;
        }
        else if(root->data<=key)
        {
            root=root->right;
        }
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.

    int pred=-1;
    int succ=-1;
    
    inorder_predecessor(root,pred,key);
    inorder_successor(root,succ,key);
    
    pair<int,int>ans= {pred,succ};
    return ans;
}


/*GeeksforGeeks solution*/

// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    // Your code goes here
    while(root){
        if(root->key==key){
            Node* temp;
            if(root->left!=NULL){
                temp = root->left;
                while(temp->right){  
                    temp=temp->right;
                }
                pre = temp;  
            }
            if(root->right!=NULL){
                temp = root->right;
                while(temp->left){  
                    temp=temp->left;  
                }
                suc = temp; 
            }
            break;
        }
        if(root->key>key){
            suc=root;
            root=root->left;
        }else{
            pre = root;
            root=root->right;
        }
    }

}
