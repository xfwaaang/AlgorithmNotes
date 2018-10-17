#### 题目描述

两矩阵 A 和 B，其维数分别是 `p*q` 和 `q*r`，这两个矩阵相乘需进行 `p*q*r` 次乘法  
求 n 个矩阵连乘需要的最少乘法运算次数

#### 分析

3个矩阵相乘 `M1M2M3`，其维数分别为 `10*100，100*5，5*50`

- 可按 `M1(M2M3)` 的方法计算
	- 计算 `M2M3`：`100*5*50 = 25000`
	- 计算 `M1(M2M3)`：`10*100*50 = 50000`
	- 乘法运算总共 `25000 + 50000 = 75000`

- 也可按 `(M1M2)M3` 的方法计算
	- 计算 `M1M2`：`10*100*5 = 5000`
	- 计算 `(M1M)2M3`：`10*5*50 = 2500`
	- 乘法运算总共：`5000 + 2500 = 7500`

结论：不同的计算顺序计算代价不同  

#### 解题思路

令 `M1M2...Mk` 的最小乘法次数为 `m[1,k]`  
`M(k+1)M(k+2)...Mn` 的最小乘法次数为 `m[k+1,n]`  
则 `M1M2...Mn` 的最小乘法次数为 `m[1,k] + m[k+1, n] + r1*ck*cn`
`r1,ck,cn` 分别表示 M1 的行数，Mk 的列数，Mn 的列数  

结论：矩阵连乘问题具有最优子结构，即问题的最优解包括子问题的最优解  

令 `m[i,j]` 表示 `MiM(i+1)...Mj` 的最小乘法次数    
则 `m[1,n]` 表示 `M1M2...Mn` 的最小乘法次数  
在 k 处断开 `m[i,j] = m[i,k] + m[k+1,j] + ri*ck*cj`  
考虑所有的 k，则有  
- `m[i,j] = min(i<=k<j){m[i,k] + m[k+1,j] + ri*ck*cj},  i < j`
- `m[i,j] = 0,  i = j`

<img src="/Assets/matrix_chain_1.png" width="300" height="200" align="left">
<img src="/Assets/matrix_chain_2.png" width="300" height="200" align="right">

#### 代码实现

伪代码
```
Matrix-Chain-Order(r)
	n = length(r)；

	for i=1 to n do
		m[i, i] = 0;

	for x=1 to n-1 do
		for i=1 to n-x do
			j = i + x;
			m[i, j] = ∞;
			for k=i to j-1 do
				q = m[i, k] + m[k+1, j] + ri*ck*cj
				if q<m[i, j] then
					m[i,j]=q;
					s[i,j]=k;

return m and s
```
