### Divide and Conquer

  将问题划分为多个子问题求解，分而治之，各个子问题相互独立

#### 设计过程

- Divide：整个问题划分为多个子问题
- Conquer：求解各个子问题（递归调用子问题的算法）
- Combine：合并子问题的解，形成原始问题的解

#### 分析过程

- 建立递归方程

	T(n) = aT(n/b) + D(n) + C(n)  
	- Divide时间复杂度：D(n)
	- Conquer时间复杂度：aT(n/b)
	- Combine时间复杂度：C(n)

- 递归方程求解

#### 算法示例

- [求两个有序数组的中位数](/DivideAndConquer/median.md)
	> [4. Median of Two Sorted Arrays of LeetCode](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

- [POJ3714](/DivideAndConquer/poj3714.md)
	> 有两个含有N个点的集合，求两个集合中距离最小的点对距离  
      [POJ3714](http://poj.org/problem?id=3714)

- [求序列的逆序对个数](/DivideAndConquer/reverse_pair.md)
	> 使用分治方法求整个序列中逆序对个数，并分析算法的时间复杂性  
	  例如：序列(4,3,2)逆序对有(4,3)，(4,2)，(3,2)共3个

- [求若干矩形的轮廓](/DivideAndConquer/outline_of_rec.md)
	> 给定𝑛座建筑物 𝐵[1, 2, … , 𝑛]，每个建筑物 𝐵[𝑖]表示为一个矩形，用三元组𝐵[𝑖]=(𝑎_𝑖,𝑏_𝑖,ℎ_𝑖)表示    
	  其中𝑎_𝑖表示建筑左下顶点，𝑏_𝑖表示建筑的右下顶点，ℎ_𝑖表示建筑的高    
	  请设计一个 𝑂(𝑛log𝑛)的算法求出这𝑛座建筑物的天际轮廓  
	  [218. The Skyline Problem of LeetCode](https://leetcode.com/problems/the-skyline-problem/description/)  
	  todo

- [求无序数组的第k小元素](/DivideAndConquer/find_k_th.md)

- [最大子数组和](/DivideAndConquer/max_subarray.md)


更多示例见: [LeetCodeNotes#dac](https://github.com/xfwangmm/LeetCodeNotes/blob/master/notes/dac.md)
