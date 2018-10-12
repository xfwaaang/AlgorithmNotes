#### 题目描述

求n叉树的深度    
[559. Maximum Depth of N-ary Tree of LeetCode](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/)

#### 代码实现

```
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
    int maxDepth(Node* root) {
        if(!root)   return 0;
        
        int h = 1;
        for(auto node : root->children)
            h = max(h, maxDepth(node) + 1);
        
        return h;
    }
};
```