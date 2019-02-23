#### 题目描述

使用非递归的方法输出n叉树的前序遍历    
[589. N-ary Tree Preorder Traversal of LeetCode](https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/)  

#### 代码实现

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        
        if(!root)   return res;
        
        stack<Node*> help;
        
        help.push(root);
        
        while(!help.empty())
        {
            Node* node = help.top();
            help.pop();
            res.push_back(node->val);
            for(int i=node->children.size()-1; i>=0; --i)
                help.push(node->children[i]);
        }
        
        return res;
    }
};
```