/*快速排序算法 的基本思想是：将所要进行排序的数分为左右两个部分，其中一部分的所有数据都比另外一部分的数据小，
然后将所分得的两部分数据进行同样的划分，重复执行以上的划分操作，直到所有要进行排序的数据变为有序为止。*/
#include<stdio.h>

int arr[] = {1,10,2,6,15,25,3,5};

void sort(int left,int right){
    int i,j,temp,k;
    if(left>right){
        return;
    }
    temp = arr[left];
    i = left;
    j = right;
    while(i!=j){
        while(arr[j]>=temp && i<j){
            j--;
        }
        while(arr[i]<=temp && i<j){
            i++;
        }
        if(i!=j){
             k = arr[i];
                    arr[i] = arr[j];
                    arr[j] = k;
        }
    }
    arr[left] = arr[i];
    arr[i] = temp;
    sort(left,i-1);
    sort(i+1,right);
    
}

int main(){
    printf("--快速排序--\n");
    printf("排序前:\n");
    int i;
    for(i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("排序后:\n");
    sort(0,7);
    for(i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}