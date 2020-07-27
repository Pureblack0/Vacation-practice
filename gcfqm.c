/*首先我们了解何为求模运算
对于整型数a，b来说，取模运算或者求余运算的方法都是：
1.求整数商： c = a/b;
2.计算模或者余数： r = a - c*b.
求模运算和求余运算在第一步不同: 取余运算在取c的值时，向0 方向舍入(fix()函数)；而取模运算在计算c的值时，向负无穷方向舍入(floor()函数)。
例如计算：-7 Mod 4
那么：a = -7；b = 4；
第一步：求整数商c，如进行求模运算c = -2（向负无穷方向舍入），求余c = -1（向0方向舍入）；
第二步：计算模和余数的公式相同，但因c的值不同，求模时r = 1，求余时r = -3。
对于n^p mod m，当p很大时直接求解是很困难的，但是我们有如下公式可以解决：
N mod m = [N1 mod m * N2 mod m * N3 mod m*…………*Nn mod m]mod m
有了这个公式，求解问题就简单了，n的p次方很容易拆分为几个数相乘的形式。其中采用二分法拆分较为简单高效。
n^p=n^(p/2)*n^(p/2),再继续二分直至p=1*/
#include<stdio.h>
#include<math.h>

int PowMod(int n, int p,int m)
{
	if (p == 1)
	{
		return n % m;
	}
	int temp = pow(n, p/2);// pow(x,y) 函数用来求 x 的 y 次方的值
	int result = (temp*temp) % m;
	if (p % 2 == 1)
	{
		result = (result*n) % m;
	}
	return result;
}

int main()
{
	int n,p,m,sum;
	printf("输入n,p,m:");
	scanf("%d%d%d",&n,&p,&m);
	sum=PowMod(n,p,m);
	printf("模为%d\n",sum);

	return 0;
}
