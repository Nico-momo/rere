#include<stdio.h>
int n,maze[10][10],a[10][10],num=0,c=0,min=0;
//a����������Ǹ������Ƿ��߹� ��������Ƿ�ͨ 
	//num��ʾ�߹��Ĳ���
	//min��ʾ��̲���
	//c��ʾ�߹���·�ߣ���ֹ·���ظ�
void lemon(int i,int j)
{
	if(i==n-2 && j==n-2)//�����������յ㣬��¼���߹��ĳ��� 
	{
		if(c==0) 
		{
			min=num;
		}
		if(num<min)//���ߵ��յ�ĳ�����min���Ա� 
		{
			min=num;
		}
		c++; 
		return;
	}
	//���ſ��Ʒ������λ 
	if(maze[i][j]==0 && a[i][j]==0)//������ 
	{
		num++; 
		a[i][j]=1;//���߹��ķ�λ��ǣ���ֹ��һ���ƶ��ظ��� 
		lemon(i+1,j);//������ 
		//������е����˵��ǰ�����ߵ�·����ͨ�����Ѿ��ߵ��յ��˻�������ʱ��ͽ����ߵķ�λ������ã������߹��Ĳ�����1 
		a[i][j]=0;
		num--;
	}
	if(maze[i][j]==0 && a[i][j]==0)//������ 
	{
	    num++;
		a[i][j]=1; 
		lemon(i-1,j);
		
		a[i][j]=0;
		num--;
	}
	if(maze[i][j]==0 && a[i][j]==0)//������ 
	{
	    num++; 
		a[i][j]=1; 
		lemon(i,j+1);
		 
		a[i][j]=0;
		num--;
	}
	if(maze[i][j]==0 && a[i][j]==0)//������ 
	{
	    num++; 
		a[i][j]=1; 
		lemon(i,j-1);//������ 
		
		a[i][j]=0; 
		num--;
	}
}
int main()
{
	scanf("%d",&n);
	for(int e=0;e<n;e++)//�����Թ�ͼ�� 
	{
		for(int f=0;f<n;f++)
		{
			scanf("%d",&maze[e][f]);
		}
	}
	lemon(1,1);//��������괫������ 
	if(min>0)  
	printf("%d",min);
	else
	printf("No solution");
	
	
}

