/*插入排序的核心思想是：从头开始，每次头元素作为 “哨兵” 依次和后面的元素
进行比较，（假设从小到大排列）后面大的元素和“哨兵”比较，如果后面的元素比“哨兵”大则交换，每比较一
次，都会从比较位置，向首元素方向进行，因此，该排序算法效率并不高，时间复杂度为O(n2)*/
#include <stdio.h>
//自定义的输出函数
void print(int a[], int n ,int i){
    printf("%d:",i);
    for(int j=0; j<8; j++){
        printf("%d",a[j]);
    }
    printf("\n");
}
//直接插入排序函数
void InsertSort(int a[], int n)
{
    for(int i= 1; i<n; i++){
        if(a[i] < a[i-1]){//若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
            int j= i-1;
            int x = a[i];
            while(j>-1 && x < a[j]){  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;      //插入到正确位置
        }
        print(a,n,i);
    }
}
int main(){
    int a[8] = {3,1,7,5,2,4,9,6};
    InsertSort(a,8);
    return 0;
}