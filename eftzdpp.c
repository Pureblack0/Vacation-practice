/*二分图：简单来说，如果图中点可以被分为两组，并且使得所有边都跨越组的边界，则这就是一个二分图。
准确地说：把一个图的顶点划分为两个不相交集 U 和V ，使得每一条边都分别连接U、V中的顶点。如果存在
这样的划分，则此图为一个二分图。二分图的一个等价定义是：不含有「含奇数条边的环」的图。
匹配：在图论中，一个「匹配」（matching）是一个边的集合，其中任意两条边都没有公共顶点。
最大匹配：一个图所有匹配中，所含匹配边数最多的匹配，称为这个图的最大匹配。*/
#include<stdio.h>
int e[101][101];  //存放输入，数组元素为1时表示有无向边相连
int match[101];   //match[u]=v 表示顶点u与v之间有无向边相连，初始值为0表示所有顶点之间无连接关系
int book[101];    //标记：某顶点是否已经被访问过，0表示未访问，1表示访问过
int n,m;          //计数：n个顶点，m条边

int dfs(int u)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(book[i]==0&&e[u][i]==1)
		{
			book[i]=1;
			if(match[i]==0 || dfs(match[i]))
			{
				//更新匹配关系
				match[u]=i;
				return 1;
			}

		}
	}
	return 0;
}

int main()
{
	int i,j,t1,t2; //t1,t2：边的两顶点下标
	int sum=0;    //用于计数：匹配数
	scanf("%d %d",&n,&m); 
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&t1,&t2);
		e[t1][t2]=1;
	}

	for(i=1;i<=n;i++) match[i]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) book[j]=0;
		if(dfs(i)) sum++;//寻找增广路，若找到，匹配数加1
	}
	printf("%d",sum);

	getchar();getchar();
	return 0;
}
