# 表达式求值
## 表达式
- 自然语言为中缀表达式
- 机器语言为后缀表达式
## 枚举
- `enmu 名字
    {内容}；`
- 内容的值从0开始
## 后缀表达式的实现
- 后缀表达式计算实现在文件`suffix.c`
## 补充
1. fgets用法
- fgets(&expr,sizeof(expr),stdbin)
- 整行读取，可以读取换行符“\n”
2. strcspn用法
- strcspn（&expr，“\n”）
- expr内开头连续几个字节不为\n