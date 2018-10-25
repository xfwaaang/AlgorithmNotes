#### 题目描述

求n叉树的深度    
[559. Maximum Depth of N-ary Tree of LeetCode](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/)

#### 代码实现

```
class Node 
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
```

```
int maxDepth(Node* root) 
{
    if(!root)   return 0;
    
    int h = 1;
    for(auto node : root->children)
        h = max(h, maxDepth(node) + 1);
    
    return h;
}
```

求二叉树的深度
[104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

```
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

递归
```
int maxDepth(TreeNode* root) 
{
    if(root == NULL)    return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int maxDepth(TreeNode *root)
{
    return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}
```

迭代

```
int maxDepth(TreeNode* root) 
{
    if(root == NULL)    return 0;
    
    queue<TreeNode*> help;
    help.push(root);
    int res = 0;
    
    while(!help.empty())
    {
        ++res;
        for(int i=0, n=help.size(); i<n; ++i)
        {
            TreeNode* node = help.front();
            help.pop();
        
            if(node->left)  help.push(node->left);
            if(node->right) help.push(node->right);
        }
    }
    
    return res;
}
```