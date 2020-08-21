/*给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
提示：
num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
来源：力扣（LeetCode）*/
/*本题我们只需要对两个大整数模拟「竖式加法」的过程。竖式加法就是我们平常学习生活中常用的对两个整数相加的方法，
回想一下我们在纸上对两个整数相加的操作，是不是将相同数位对齐，从低到高逐位相加，如果当前位和超过 1010，则向高
位进一位？因此我们只要将这个过程用代码写出来即可。
具体实现也不复杂，我们定义两个指针 ii 和 jj 分别指向 \textit{num1}num1 和 \textit{num2}num2 的末尾，即最低位，
同时定义一个变量 \textit{add}add 维护当前是否有进位，然后从末尾到开头逐位相加即可。你可能会想两个数字位数不同
怎么处理，这里我们统一在指针当前下标处于负数的时候返回 00，等价于对位数较短的数字进行了补零操作，这样就可以除去
两个数字位数不同情况的处理，具体可以看下面的代码。*/
char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char* ans = (char*)malloc(sizeof(char) * (fmax(i, j) + 3));
    int len = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans[len++] = '0' + result % 10;
        add = result / 10;
        i--, j--;
    }
    // 计算完以后的答案需要翻转过来
    for (int i = 0; 2 * i < len; i++) {
        int t = ans[i];
        ans[i] = ans[len - i - 1], ans[len - i - 1] = t;
    }
    ans[len++] = 0;
    return ans;
}


