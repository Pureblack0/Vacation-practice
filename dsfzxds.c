/*设点为Q，线段为P1P2：

判断点Q在该线段上的依据是：①（Q - P1）* （P2 - P1）= 0；② Q在以P1P2为对角线的矩形内；

需要同时满足这两个条件，①保证了Q点在直线上；②保证了Q不在线段的延长线或反向延长线上。

 

补充矢量叉积的知识：

设矢量P=（x1，y1），矢量Q=（x2，y1）

P * Q = （x1 * y2） - （x2*y1）*/
#include <stdio.h>

typedef struct point
{
    double x;  //x坐标
    double y;  //y坐标

}point;  //定义点


//判断点是否在线上，在返回1，不在返回0
int onSegement(point p1,point p2,point Q)
{
    double maxx,minx,maxy,miny;

    maxx = p1.x >p2.x ?p1.x :p2.x ;    //矩形的右边长
    minx = p1.x >p2.x ?p2.x :p1.x ;     //矩形的左边长
    maxy = p1.y >p2.y ?p1.y :p2.y ;    //矩形的上边长
    miny = p1.y >p2.y ?p2.y :p1.y ;     //矩形的下边长

    if( ((Q.x -p1.x )*(p2.y -p1.y) == (p2.x -p1.x) *(Q.y -p1.y)) && ( Q.x >= minx && Q.x <= maxx ) && ( Q.y >= miny && Q.y <= maxy))
        return 1;
    else
        return 0;
}
void main()
{
    point P1,P2,Q;

    printf("input the start point  of the line:");
    scanf("%f%f",&P1.x ,&P1.y);
    printf("\n");

    printf("input the end point of the line:");
    scanf("%f%f",&P2.x ,&P2.y );
    printf("\n");

    printf("input the point :");
    scanf("%f%f",&Q.x ,&Q.y );
    printf("\n");

    if( onSegement(P1,P2,Q) )
    {
        printf("point on the line\n");
    }
    else
    {
        printf("point not on the line\n");
    }

}