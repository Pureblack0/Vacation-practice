/*在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上
(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制: (1) 每次只能移动一个盘子; (2) 盘子只能从柱子顶端滑出移到下一根柱子; 
(3) 盘子只能叠在比它大的盘子上。
完成目标：将n个block块从A搬运到C，求需要移动多少次完成？
约束条件：搬运的过程中每次只能移动一个block块，且不能出现大的block块在小的block块之上。*/
#include <stdio.h>
#include <string.h>
/*
 算法思路：1将 n-1个盘子先放到B座位上
          2.将A座上地剩下的一个盘移动到C盘上
          3、将n-1个盘从B座移动到C座上
*/
//函数声明
void move(char x, char y);
void hannuo(int n,char one ,char two,char three)
{
  if(n==1)move(one, three); //递归截止条件
  else
{
  hannuo(n-1,one ,three,two);//将 n-1个盘子先放到B座位上
  move(one,three);//将A座上地剩下的一个盘移动到C盘上
  hannuo(n-1,two,one,three);//将n-1个盘从B座移动到C座上
 
}
}
void move(char x,char y)
{
 printf("%c--->%c",x,y);
}
 
int main()
{
 int n;
 printf("input your number");
 scanf("%d",&n);
 hannuo(n,'A','B','C');
 return 0;
}
