给定二叉树，返回整棵树的倾斜度。 树节点的倾斜被定义为所有左子树节点值的总和与所有右子树节点值的总和之间的绝对差。  
空节点倾斜0。 整棵树的倾斜度定义为所有节点倾斜的总和。


```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int tilt = 0;
    
    int postorder(TreeNode* root){
        if(!root)   return 0;
        
        int left = postorder(root->left);
        int right = postorder(root->right);
        tilt += abs(left - right);
        
        return left + right + root->val;
    }
    
    
    int findTilt(TreeNode* root) {
        postorder(root);
        return tilt;
    }
};
```