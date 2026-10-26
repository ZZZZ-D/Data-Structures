# 字符串匹配
## 朴素匹配
- 用双循环去一个一个匹配
- 实现在`simplicity-algorithm.c`文件中
## KMP匹配
- 基于模式串，来制作next数组
- 模式串`abaabc`-> next数组`-1 0 0 1 1 2`
## 思考
- kmp算法中，next数组的构造匹配时`next[i] = j`,失配时`j =next[j]`