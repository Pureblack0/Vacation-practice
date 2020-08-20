/*给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
找到所有出现两次的元素。
你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
示例：
输入:
[4,3,2,7,8,2,3,1]
输出:
[2,3]
来源：力扣（LeetCode）*/
/*首先将数组进行一次排序，从大到小或从小到大都行；
申请最大长度的临时变量，也可以是最大长度/2；
遍历数组，当两个数组值相同时，赋值给临时变量，同时返回长度+1；
最后直接返回即可。*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void *p1, const void *p2) {
    if (*(int *)p1 > *(int *)p2) {
        return 1;
    } else if (*(int *)p1 == *(int *)p2) {
        return 0;
    } else {
        return -1;
    }
}

int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int *temp = (int *)malloc(sizeof(int) * numsSize);
    int index = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            temp[index++] = nums[i];
        }
    }

    *returnSize = index;
    return temp;
}

