/*基本思路
在每一次的排序中选出最小（或最大）的数，将其放在数组最前端，然后在后面的数中重复此步骤，最终达到排序的目的.
算法描述
将存于数组首位数与后面的数依次比较,将其中的较小的数放到数组放到数组首位
将除存于第二位的数视作首位,重复第一步的操作
以此类推*/
# include<stdio.h>
void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
int main()
{
    int i, j, n, t;
    int a[100];
    scanf("%d", &n);//输入要排序的数组元素个数
    getchar();
    for(i=0;i<n;i++)
    scanf("%d", &a[i]);//遍历数组
    for(i=0;i<n-1;i++)//从首位开始,注意:最后一个数由于已经被动和前面所有数进行了比较,故不需要再主动比较
    {
        int min=i;
        for(j=i+1;j<n;j++)//依次和后面的数比较找出最小的数
            if(a[j]<a[min])
            min=j;
        if(min != i)//如果最小的数不是首位,则交换
        swap(&a[min],&a[i]);
    }
    for(i=0;i<n;i++)
    printf("%d ", a[i]);
}