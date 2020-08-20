/*假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。
你可以假设数组中不存在重复元素。
示例 1:
输入: [3,4,5,1,2]
输出: 1
示例 2:
输入: [4,5,6,7,0,1,2]
输出: 0
来源：力扣（LeetCode）*/
/*种暴力的解法是搜索整个数组，找到其中的最小元素，这样的时间复杂度是 O(N)O(N) 其中 NN 是给定数组的大小。
一个非常棒的解决该问题的办法是使用二分搜索。在二分搜索中，我们找到区间的中间点并根据某些条件决定去区间左半部分还是右半部分搜索。
算法
找到数组的中间元素 mid。
如果中间元素 > 数组第一个元素，我们需要在 mid 右边搜索变化点。
如果中间元素 < 数组第一个元素，我们需要在 mid 做边搜索变化点。
当我们找到变化点时停止搜索，当以下条件满足任意一个即可：
nums[mid] > nums[mid + 1]，因此 mid+1 是最小值。
nums[mid - 1] > nums[mid]，因此 mid 是最小值。*/
int findMin(int* nums, int numsSize){ 
    int left=0; 
    int right=numsSize-1; 
    while(right>left) 
    { 
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right])
            left=mid+1;
        else
            right=mid;
    }
    return nums[left];
}




