#### 题目描述
求两个字符串，由一个转成另一个所需的最少编辑次数  
编辑操作包括将一个字符替换成另一个字符、插入一个字符、删除一个字符

#### 解题思路
```
dp[i][j] = dp[i-1][j-1]   str1[i] == str2[j]
dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
```

#### 代码实现
```java
int minDistance(String word1,String word2){
    int m=word1.length();
    int n=word2.length();
    int [][]dp=new int [m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0]=i; //单纯的删除操作
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=i; //单纯的插入操作
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(word1.charAt(i)==word2.charAt(j)){
                dp[i+1][j+1]=dp[i][j];
            }else{
                dp[i+1][j+1]=Math.min(dp[i][j+1],Math.min(dp[i+1][j],dp[i][j]))+1;
            }
        }
    }
    return dp[m][n];
}
```