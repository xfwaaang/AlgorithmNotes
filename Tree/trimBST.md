#### 题目描述
给定一个平衡二叉树和上下界L、R，消减BST使得所有节点的值均位于[L, R]之间

#### 代码实现

```
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

```
TreeNode* trimBST(TreeNode* root, int L, int R) 
{
    if(root == NULL)  return NULL;
    
    if(root->val < L)  return trimBST(root->right, L, R);
    if(root->val > R)  return trimBST(root->left, L, R);
    
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    
    return root;
}
```