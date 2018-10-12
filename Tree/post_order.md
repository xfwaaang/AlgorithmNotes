#### 题目描述

使用非递归的方法输出n叉树的后序遍历  
[590. N-ary Tree Postorder Traversal of LeetCode](https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/)

#### 代码实现

```
struct TreeNode
{
	int val;
	vector<TreeNode*> children;

	TreeNode(){}

	TreeNode(int _val, vector<TreeNode*> _children)
	{
		val = _val;
		children = _children;
	}
};

vector<int> postOrder(TreeNode *root)
{
	if(root == NULL)	return {};

	vector<int> res;
	stack<TreeNode*> stk;
	stk.push(root);

	while(!stk.empty())
	{
		TreeNode *tmp = stk.top();
		stk.pop();
		for(int i=0; i<tmp->children.size(); ++i)
			stk.push(tmp->children[i]);
		res.push_back(tmp->val);
	}

	reverse(res.begin(), res.end());

	return res;
}
```