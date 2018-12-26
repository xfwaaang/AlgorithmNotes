### Greedy Algorithm

#### 贪心算法要素

##### 基本思想

- 求解最优化问题的算法包含一系列步骤
- 每一步都有一组选择
- 作出在当前看来最好的选择
- 希望通过作出局部最优选择达到全局最优选择
- 贪心算法不一定总产生最优解
- 贪心算法是否产生优化解，需严格证明

##### 产生最优解的条件

- 最优子结构
	- 当一个问题的最优解包含子问题的最优解时，称这个问题具有最优子结构

- 贪心选择性
	- 当一个问题的全局最优解可以通过局部最优解得到，称这个问题具有贪心选择性
	- 证明思路：
	假定首选元素不是贪心选择所要的元素，证明将首元素替换成贪心选择所需元素，依然得到最优解
	数学归纳法证明每一步均可通过贪心选择得到最优解

##### 动态规划方法可用的条件

- 最优子结构
- 子问题重叠性
  
适用贪心算法时，动态规划可能不适用    
适用动态规划时，贪心算法可能不适用

##### 算法示例

- [活动选择问题](/GreedyAlgorithm/activity_select.md)

- [poj2393](/GreedyAlgorithm/poj2393.md)
	> [poj2393](http://poj.org/problem?id=2393)

- [poj1328](/GreedyAlgorithm/poj1328.md)
	> [poj1328](http://poj.org/problem?id=1328)

- [非01背包问题](/GreedyAlgorithm/bag.md)

- [最小化连线的长度](/GreedyAlgorithm/mini_length.md)

- [最大子数组和](/GreedyAlgorithm/max_subarray.md)
	> 在数组（包含至少一个数字）中查找连续的子数组，使其和最大。   

- [任意顺序合并数组](/GreedyAlgorithm/merge_array.md)
	> todo

- [消减数字](/GreedyAlgorithm/remove_digtal.md)
	> todo


