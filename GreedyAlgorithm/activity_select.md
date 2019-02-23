#### 题目描述
`S={1,2,…,n}`是`n`个活动的集合，活动共用同一资源，同一时间只有一个活动使用  
活动`i`有起始时间`si`，终止时间`fi`，`si <= fi`，表示为`xi=[si，fi]`   
活动`i`和`j`是相容的，若 `sj >= fi 或 si >= fj`  
输入：`S={1, 2, …, n}，xi=[si，fi]，1 <= i <= n`  
输出：`S`的最大相容集合

#### 解题思路
`S`按结束时间排序，`f1 <= f2 <= …. <= fn`  
根据贪心思想，为了选择更多活动，每次选择 `fi` 最小的活动

#### 代码实现
伪代码
```cpp
Greedy-Activity-Selector(S, F)
  n = length(S);
  A = {1};
  j = 1;
  for  i=2  to  n  do
    if si >= fj then
      A = A∪{i}；
      j=i；
  return  A
```