/*猜数字游戏的规则如下：
每轮游戏，系统都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，系统会告诉你，你猜测的数字比系统选出的数字是大了还是小了。
你可以通过调用一个预先定义好的接口 guess(int num) 来获取猜测结果，返回值一共有 3 种可能的情况（-1，1 或 0）：
-1 : 你猜测的数字比系统选出的数字大
 1 : 你猜测的数字比系统选出的数字小
 0 : 恭喜！你猜对了！

示例 :
输入: n = 10, pick = 6
输出: 6
来源：力扣（LeetCode）*/
/*使用二分查找
算法
我们可以直接使用二分查找来找到需要的数字。我们从中间的数字开始，将数字传递到 guessguess 函数里。如果返回 -1, 
说明中间数字比答案大，就查找更小的那一半。类似的，如果返回 1 ，我们查找更大的一半，直到找到答案*/
int guessNumber(int n){
	 int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            if (res == 0)
                return mid;
            else if (res < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
}
