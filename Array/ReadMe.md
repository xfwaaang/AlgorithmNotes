### Array

- [最大收益](/Array/max_profit.md)

  > 假设您有一个数组，其中第i个元素是第i天给定股票的价格。 
  > 设计一个算法来找到最大的利润。  
  > 1. 您可以根据需要完成尽可能多的交易（即多次买入和卖出一次股票）。  
  > 但是，您不得同时进行多笔交易（即您必须在再次购买之前出售股票）。
  > 2. 您只可以进行一次交易。

- [找到数组中出现一次的元素](/Array/single_number.md)

  > 给定一个整数数组，除了一个元素外，每个元素都会出现两次，
  > 找到那一个。   
  > 注意：时间复杂度O(n)，空间复杂度O(1)

- [两条垂线与X轴所围成最大储水量区域的面积](/Array/max_area.md)

  > 给定n个非负整数a1，a2，...，an，其中每个表示坐标（i，ai）处的点。  
  > 绘制n条垂直线，使得线i的两个端点位于（i，ai）和（i，0）。  
  > 找到两条线，它们与x轴一起形成一个容器，这个容器装水量最多。   
  > 注意：容器不能倾斜

- [具有最大和的子数组](/Array/max_subarray.md)

  > 在具有最大总和的数组（包含至少一个数字）中查找连续的子数组。   
  > 例如，给定数组[-2, 1, -3, 4, -1, 2, 1, -5, 4]  
  > 连续的子阵列[4, -1, 2, 1]具有最大的和为6。   
  > 时间复杂度：O(n)

<!-- - [flip&invert图片矩阵](/Array/flip_and_invert_image.cpp) -->

- [Array Partition I](/Array/array_pair_sum.md)

  > 给定一个2n个整数的数组，你的任务是将这些整数分组为n对整数，  
  > 比如说（a1，b1），（a2，b2），...，（an，bn），  
  > 求所有min(ai， bi)之和的最大值  
  > Input: [1,4,3,2]  
  > Output: 4  
  > Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

- [sort array by parity](/Array/sort_array_by_parity.md)
  > 给定一个非负整数数组A，返回一个由A的所有偶数元素组成的数组，后跟A的所有奇数元素。   
    您可以返回满足此条件的任何答案数组。  
    Input: [3,1,2,4]  
    Output: [2,4,3,1]  
    The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

- [sort array by parity ii](/Array/sort_array_by_parity_ii.md)
  > 给定一个非负整数的数组A，A中的一半整数是奇数，一半是偶数  
    对数组进行排序，使得A[i]为奇数时，i为奇数; A[i]是偶数时，i是偶数  
    [922. Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/description/)

- [Smallest Range I](/Array/smallest_range_i.md)
  > 给定一个整数数组A，对于每个整数A[i]，  
    我们可以选择任何x，其中-K <= x <= K，并将x加到A[i]。   
    得到数组B. 返回B的最大值和B的最小值之差。

- [Reshape the Matrix](/Array/reshape_matrix.md)
  > [566. Reshape the Matrix of LeetCode](https://leetcode.com/problems/reshape-the-matrix/)