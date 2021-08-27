class Solution {
public:
    vector<int> ans;
    
    void leftBoundary(Node *root){
        
        if(!root)
            return;
        
        if(root->left || root->right)
            ans.push_back(root->data);
        
        if(root->left){
            leftBoundary(root->left);
        }
        
        else if(root->right){
            leftBoundary(root->right);
        }
    }
    
    void leaves(Node *root){
        if(!root)
            return ;
            
        if(root->left){
            leaves(root->left);
        }
        
        if(!root->left && !root->right)
            ans.push_back(root->data);
            
        if(root->right){
            leaves(root->right);
        }
    }
    
    void rightBoundary(Node *root){
        if(!root)
            return;

        if(root->right){
            rightBoundary(root->right);
            ans.push_back(root->data);
        }
        
        else if(root->left){
            rightBoundary(root->left);
            ans.push_back(root->data);
        }
        
    }

    vector <int> printBoundary(Node *root){
        ans.clear();
        if(!root)
            return ans;
        ans.push_back(root->data);
        leftBoundary(root->left);
        leaves(root);
        rightBoundary(root->right);
        return ans;
    }
};


//edge cases -> skewed trees