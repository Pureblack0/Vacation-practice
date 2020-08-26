# 判断矩形是否包含点

判断点的横坐标是否在矩形横坐标之间，纵坐标是否在矩形纵坐标之间即可。

```C++
//判断一个点是否在矩形内部
#include<cstdio>
#include<iostream>

struct Point
{
 float x;
 float y;
 Point(float x,float y)
 {
  this->x = x;
  this->y = y;
 }
};
// 计算 |p1 p2| X |p1 p|
float GetCross(Point& p1, Point& p2,Point& p)
{
 return (p2.x - p1.x) * (p.y - p1.y) -(p.x - p1.x) * (p2.y - p1.y);
}
//判断点是否在5X5的以原点为左下角的正方形内（便于测试）
bool IsPointInMatrix(Point& p)
{
 Point p1(0,5);
 Point p2(0,0);
 Point p3(5,0);
 Point p4(5,5);

 return GetCross(p1,p2,p) * GetCross(p3,p4,p) >= 0 && GetCross(p2,p3,p) * GetCross(p4,p1,p) >= 0;
 //return false;
}
using namespace std;
int main()
{

 while(true)
 {
  Point testPoint(0,0);
  cout << "enter the point :" << endl;

  cin >> testPoint.x >> testPoint.y;

  cout << "the point is  : "<< testPoint.x << " "<< testPoint.y << endl;

  cout << "the point is " << (IsPointInMatrix(testPoint)? "in the Matrix .": "not in the matrix ." )<< endl;
 }
  
 return 0;
}
