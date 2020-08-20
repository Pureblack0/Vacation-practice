/*给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
示例:
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArr(int* a, int aSize, int* returnSize){
    int *arr = NULL;
    int i, temp;
    if (a == NULL || aSize <= 1) {
        *returnSize = 0;
        return a;
    }
    *returnSize = aSize;
    arr = (int *)malloc(sizeof(int) * aSize);
    arr[0] = 1;

    for (i = 1; i < aSize; i++) {
        arr[i] = arr[i - 1] * a[i - 1];
    }

    temp = 1;
    for (i = aSize - 2; i >= 0; i--) {
        temp *= a[i + 1];
        arr[i] *= temp;
    }

    return arr;
}

