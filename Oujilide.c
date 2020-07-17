#include <stdio.h>
int main()
{
    int a;                    
    int b;                    
    int r=1;                  // 余数
    printf("输入两个数字：");
    scanf("%d %d",&a,&b);
    while(r!=0){             
        r = a % b;
        a = b;
        b = r;
    }
    printf("最大公约数为：%d\n",a);      
    return 0;
}

