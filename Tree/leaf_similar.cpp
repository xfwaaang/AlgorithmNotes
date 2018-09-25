/*
题目描述：
如果两个二叉树的叶子节点从左到右的值序列相等，则称它们为leaf-similar tree
返回两个给定的二叉树是否为leaf-similar tree
*/

#include<vector>
#include<stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};


/*
利用先序遍历求出叶子节点的值序列
再比较输出结果
*/

void preOrder(TreeNode *root, vector<int> &v)
{
	if(root)
	{
		if(root->left == NULL && root->right == NULL)
			v.push_back(root->val);
		preOrder(root->left, v);
		preOrder(root->right, v);
	}
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
	vector<int> a, b;
	preOrder(root1, a);
	preOrder(root2, b);

	if(a == b)	return true;

	return false;
}

/*
利用深度优先搜索解决
*/

int dfs(stack<TreeNode*> &s)
{
	while(true)
	{
		TreeNode *node = s.top();
		s.pop();
		if(node->left)	s.push(node->left);
		if(node->right)	s.push_back(node->right);
		if(!node->left && !node->right)	return node->val;
	}
}

bool leafSimilar_2(TreeNode *root1, TreeNode *root2)
{
	stack<TreeNode*> a, b;
	a.push(root1);
	b.push(root2);

	while(!a.empty() && !a.empty())
	{
		if(dfs(a) != dfs(b))	return false;
	}

	return a.empty() && b.empty();
}