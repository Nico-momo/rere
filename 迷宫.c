#include<stdio.h>
int n,maze[10][10],a[10][10],num=0,c=0,min=0;
//a数组用来标记该坐标是否被走过 ，并标记是否通 
	//num表示走过的步长
	//min表示最短步长
	//c表示走过的路线，防止路线重复
void lemon(int i,int j)
{
	if(i==n-2 && j==n-2)//函数到达了终点，记录其走过的长度 
	{
		if(c==0) 
		{
			min=num;
		}
		if(num<min)//将走到终点的长度与min来对比 
		{
			min=num;
		}
		c++; 
		return;
	}
	//接着控制方向的走位 
	if(maze[i][j]==0 && a[i][j]==0)//向上走 
	{
		num++; 
		a[i][j]=1;//将走过的方位标记，防止下一次移动重复。 
		lemon(i+1,j);//向上走 
		//如果运行到这里，说明前面所走的路都不通或者已经走到终点退回来，这时候就将所走的方位标记重置，并且走过的步数减1 
		a[i][j]=0;
		num--;
	}
	if(maze[i][j]==0 && a[i][j]==0)//向下走 
	{
	    num++;
		a[i][j]=1; 
		lemon(i-1,j);
		
		a[i][j]=0;
		num--;
	}
	if(maze[i][j]==0 && a[i][j]==0)//向右走 
	{
	    num++; 
		a[i][j]=1; 
		lemon(i,j+1);
		 
		a[i][j]=0;
		num--;
	}
	if(maze[i][j]==0 && a[i][j]==0)//向左走 
	{
	    num++; 
		a[i][j]=1; 
		lemon(i,j-1);//向上走 
		
		a[i][j]=0; 
		num--;
	}
}
int main()
{
	scanf("%d",&n);
	for(int e=0;e<n;e++)//构造迷宫图形 
	{
		for(int f=0;f<n;f++)
		{
			scanf("%d",&maze[e][f]);
		}
	}
	lemon(1,1);//将入口坐标传给函数 
	if(min>0)  
	printf("%d",min);
	else
	printf("No solution");
	
	
}

