#include <stdio.h>
#include<stdlib.h>
int main(){
    int a;                    
    int b;                    
    int r=1;                  // ����
    printf("�����������֣�");
    scanf("%d %d",&a,&b);
    while(r!=0){             
        r = a % b;
        a = b;
        b = r;
    }
    printf("���Լ��Ϊ��%d\n",a); 
    system("pause");       
    return 0;
}

