### Backtracking and Recursive

#### 递归定义

> 一种直接或间接引用自身的定义方法  
> 一个合法的递归定义包括两个部分：基础情况和递归部分  
> 基础情况以直接形式明确列举新事物的若干简单对象，递归部分给出由简单（或较简单）对象定义新对象的条件和方法

#### 递归算法示例

- [逆序输出正整数的各位数](/BacktrackingRecursive/print_digit_reverse.md)
	> 逆序输出正整数的各位数

- [汉诺塔问题](/BacktrackingRecursive/hanoi.md)
	> 假定有三个塔座：x，y，z，在塔座x上有n个直径大小不一的圆盘，它们按直径从大到小依次放在x上。  
	> 现要求将x上的圆盘移动到y上，并保持原样堆放。移动过程需遵循以下规则：  
	>（1）每次只能移动一个圆盘  
	>（2）圆盘可以放在x，y，z中任意一个上  
	>（3）不能将直径较大的圆盘放在较小的圆盘之上  

- [产生所有可能的排列](/BacktrackingRecursive/gen_all_permutation.md)

	> 产生各种可能的排列  
	> 给定n个自然数{0,1,2...，n}，产生所有可能的排列（permutation）

- [分别用递归和迭代算法计算二项式系数](/BacktrackingRecursive/binomial_coefficient.md)
	
	> 写一个递归算法和一个迭代算法计算二项式系数  
	  (x + y)^n = C(0,n) * x^0 * y^n + C(1,n) * x^1 * y^(n-1) + ... +   
	              C(m,n) * x^m * y^(n-m) + ... + C(n,n) * x^n * y^0


#### 回溯算法示例

- [八皇后问题](/BacktrackingRecursive/eight_queens.md)
	> todo

- [括号排列](/BacktrackingRecursive/brackets.md)
	> todo

- [素数环问题]

- [输出不重复数字的所有排列]