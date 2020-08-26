/*写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1*/
/*此题通过自下向上进行运算可以减少很多重复计算部分，因此可以采用循环方式进行计算。*/
int fib(int n){
    int result[2] = {0, 1};
    if(n < 2)
    {
        return result[n];
    }

    int fib1 = 0;
    int fib2 = 1;
    int fibn = 0;
    for (int i = 2; i <= n; i++)
    {
        fibn = (fib1 + fib2) % 1000000007;
        fib1 = fib2;
        fib2 = fibn;
    }
    return fibn;
}