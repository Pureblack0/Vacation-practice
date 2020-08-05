/*本实例采用二分查找法查找特定关键字的元素。要求用户输入数组长度，也就是有序表的数据长度，
并输入数组元素和査找的关键字。程序输出查找成功与否，以及成功时关键字在数组中的位置。*/
#include <stdio.h>
int binary_search(int key,int a[],int n) //自定义函数binary_search()
{
    int low,high,mid,count=0,count1=0;
    low=0;
    high=n-1;
    while(low<high)    //査找范围不为0时执行循环体语句
    {
        count++;    //count记录査找次数
        mid=(low+high)/2;    //求中间位置
        if(key<a[mid])    //key小于中间值时
            high=mid-1;    //确定左子表范围
        else if(key>a[mid])    //key 大于中间值时
            low=mid+1;    //确定右子表范围
        else if(key==a[mid])    //当key等于中间值时，证明查找成功
        {
            printf("查找成功!\n 查找 %d 次!a[%d]=%d",count,mid,key);    //输出査找次数及所査找元素在数组中的位置
            count1++;    //count1记录查找成功次数
            break;
        }
    }
    if(count1==0)    
        printf("查找失败!");    
    return 0;
}
int main()
{
    int i,key,a[100],n;
    printf("请输入数组的长度：\n");
    scanf("%d",&n);   
    printf("请输入数组元素：\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);   
    printf("请输入你想查找的元素：\n");
    scanf("%d",&key);    
    binary_search(key,a,n);    
    printf("\n");
    return 0;
}