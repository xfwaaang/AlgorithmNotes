/*
题目描述：
给定一个n叉树，返回其后序遍历
使用迭代法
*/
#include<vector>
#include<stack>

using namespace std;

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