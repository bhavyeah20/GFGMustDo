class Solution{
    public:
    
    bool sym(Node *root1, Node *root2){
        
        if(!root1 || !root2){
            return !root1 && !root2;
        }
        
            
        return root1->data == root2->data && sym(root1->left, root2->right) && sym(root1->right, root2->left);
    }
    
    
    bool isSymmetric(struct Node* root){
	    return sym(root, root);
    }
};
