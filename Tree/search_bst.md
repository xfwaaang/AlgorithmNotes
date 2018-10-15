#### 题目描述
给定二叉搜索树（BST）的根节点和值。您需要在BST中找到节点的值等于给定值的节点  
返回以该节点为根的子树。如果此节点不存在，则应返回NULL

#### 代码实现

[源代码](/Tree/search_bst.cpp)

```
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

/*
recursive
*/
TreeNode* searchBST(TreeNode *root, int val)
{
	if(root == NULL)
		return NULL;

	if(root->val == val)
		return root;
	else if(root->val > val)
		return searchBST(root->left, val);
	else
		return searchBST(root->right, val);
}

/*
iterative
*/
TreeNode* searchBST(TreeNode *root, int val)
{
	while(NULL != root && root->val != val)
		root = root->val > val ? root->left : root->right;

	return root;
}

TreeNode* searchBST(TreeNode *root, int val)
{
	while(root)
	{
		if(root->val > val)
			root = root->left;
		else if(root->val < val)
			root = root->right;
		else
			break;
	}

	return root;
}
```