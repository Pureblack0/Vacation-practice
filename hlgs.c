/*海伦公式S=根号下p(p-a)(p-b)(p-c) 公式中a，b，c分别为三角形三边长，p为半周长，S为三角形的面积*/
#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,p,s;
	printf("请输入三角形三边的边长(两边之和大于第三边或两边之和小于第三边):");
	scanf("%f%f%f",&a,&b,&c);
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("三角形面积为%.2f\n",s);
	return 0;
}