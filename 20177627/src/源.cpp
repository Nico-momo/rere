#include<iostream>

using namespace std;
bool sign = false,Check(int n, int key);
int shudu[9][9], DFS(int n), m;
void input(),output();
	/* 主函数 */
	int main()
	{
		cout << "请输入一个数独矩阵，空位以0表示:" << endl;
		cin >> m;
		input();
		DFS(0);
		output();
		system("pause");
	}

/* 读入数独矩阵 */
void input()
{
	char temp[9][9];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp[i][j];
			shudu[i][j] = temp[i][j] - '0';
		}
	}
}

/* 判断key填入n时是否满足条件 */
bool Check(int n, int key)
{
	/* 判断n所在横列是否合法 */
	for (int i = 0; i < m; i++)

	{
		/* j为n竖坐标 */
		int j = n / m;

		if (shudu[j][i] == key) return false;

	}
	/* 判断n所在竖列是否合法 */

	for (int i = 0; i <m; i++)

	{
		/* j为n横坐标 */

		int j = n % m;

		if (shudu [i][j] == key) return false;

	}
	/* 全部合法，返回正确 */

	return true;

}
/* 深搜构造数独*/
int DFS(int n)
{
	if (n > m* m - 1)
	{
		sign = true;
		return 0;
	}
	/* 当前位不为空时跳过 */
	if (shudu[n / m][n % m] != 0)
	{
		DFS(n + 1);
	}
	else
	{
		/* 否则对当前位进行枚举测试 */
		for (int i = 1; i <= m; i++)
		{
			/* 满足条件时填入数字 */
			if (Check(n, i) == true)
			{
				shudu[n / m][n % m] = i;
				DFS(n + 1);
				if (sign == true) 
					return 0;
				shudu[n / m][n % m] = 0;
			}
		}
	}
}
/* 输出数独矩阵 */
void output()
{
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << shudu[i][j] << " ";
		}
		cout << endl;
	}
}