class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    
    bool sym(Node *root1, Node *root2){
        
        if(!root1 || !root2){
            return !root1 && !root2;
        }
        
            
        return root1->data == root2->data && sym(root1->left, root2->right) && sym(root1->right, root2->left);
    }
    
    
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    return sym(root, root);
    }
};
