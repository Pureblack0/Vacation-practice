/*思路：用一个长度为N+1的数组保存信息（1表示素数，0表示非素数），先假设所有的数都是素数（初始化为1），
从第一个素数2开始，把2的倍数都标记为非素数（置为0），一直到大于N；然后进行下一趟，找到2后面的下一个素
数3，进行同样的处理，直到最后，数组中依然为1的数即为素数。*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 1000
 
int main(void)
{
    int i,j;
    int prime[N+1];
 
    for(i=2;i<=N;i++)
        prime[i]=1;
    for(i=2;i<sqrt(N);i++)
    {
        if(prime[i]==1)
        {
            for(j=2*i;j<=N;j++)
            {
                if(j%i==0)
                    prime[j]=0;
            }
        }
    }
 
    for(i=2;i<N;i++)
    {
        if(prime[i]==1)
        {
            printf("%d\n",i);
        }
    }
    printf("\n");
    return 0;
}