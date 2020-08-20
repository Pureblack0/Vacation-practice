/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2*/
/*解题思路
1、快速排序
2、返回中间位置元素*/
int cmp_up(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int majorityElement(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp_up);
    return nums[numsSize / 2];
}

