/*一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21*/
int numWays(int n){
    int simp_ways[2] = {1, 1};
    int waysn = 0, way1 = 1, way2 = 1;

    if(n < 2)
    {
        return simp_ways[n];
    }

    for (int i = 2; i <= n; i++)
    {
        waysn = (way1 + way2) % 1000000007;
        way1 = way2;
        way2 = waysn;
    }

    return waysn;
}