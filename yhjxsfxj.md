# 判断圆和矩形是否相交

## 问题

在一个坐标系中，有一个圆和一个矩形，判断圆和矩形是否相交
输入圆心坐标，圆的半径，和矩形中一对对角线中两个点的坐标

## 思路

圆和矩形相交有大概可分为两种情况
情况一：矩形的顶点在圆内，
情况二：矩形的顶点不在圆内，矩形的边和圆相交
判断方法：刚开始想矩形的顶点到圆心的距离小于r就是第一种情况了，后来发现还有一种情圆很大很大以至于矩形在圆里边
刚开始的时候还认为圆心到矩形的每条边的垂直距离小于圆的半径是第二种情况了，后来发现圆心(x, y)不满足 (x1 < x < x2)&&(y1 < y < y2)的时候，圆心到矩形每条边的垂直距离也可能小于半径。所以把这两个判定条件所造成的多出的情况摘出来，然后再判断剩下的情况就行了

## 代码

```C
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

double a, b, xa, ya, xb, yb, r;

double far(double n1, double m1, double n2, double m2)
{
    double ans;
    ans = (n1 - n2) * (n1 - n2) +(m1 - m2) * (m1 - m2);
    ans = sqrt(ans);
    return ans;
}

double max(double x, double y)
{
    if (x > y)
        return x;
    else
        return y;
}

double min(double x, double y)
{
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf", &a, &b, &r, &xa, &ya, &xb, &yb);
        if (
                far(xa, ya, a, b) < r &&
                far(xa, yb, a, b) < r &&
                far(xb, ya, a, b) < r &&
                far(xb, yb, a, b) < r //矩形在圆里面
            )
        {
            printf("NO\n");
            continue;
        }
        else if (
                    far(xa, ya, a, b) > r &&
                    far(xa, yb, a, b) > r &&
                    far(xb, ya, a, b) > r &&
                    far(xb, yb, a, b) > r &&
                    far(xa, ya, xb, ya) > 2*r &&
                    far(xa, ya, xa, yb) > 2*r //圆在矩形里面
                )
        {
            printf("NO\n");
            continue;
        }
        else if (
                    far(xa, ya, a, b) <= r ||
                    far(xa, yb, a, b) <= r ||
                    far(xb, ya, a, b) <= r ||
                    far(xb, yb, a, b) <= r       //顶点在圆内
                )
        {
            printf("YES\n");
            continue;
        }
        else if(
                    (far(xa, b, a, b) <= r && b < max(ya, yb) && b > min(ya, yb))||
                    (far(xb, b, a, b) <= r && b < max(ya, yb) && b > min(ya, yb))||
                    (far(a, ya, a, b) <= r && a < max(xa, xb) && a > min(xa, xb))||
                    (far(a, yb, a, b) <= r && a < max(xa, xb) && a > min(xa, xb))  //顶点不在圆内但是边和圆相交
                )
        {
            printf("YES\n");
            continue;
        }
        else
        {
            printf("NO\n");
            continue;
        }

    }
    return 0;
}
