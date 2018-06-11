#include<stdio.h>
#include<stdlib.h>
int a[8][3] = {
	{ 1,1,1 },
	{ 1,1,0 },
	{ 1,0,1 },
	{ 1,0,0 },
	{ 0,1,1 },
	{ 0,1,0 },
	{ 0,0,1 },
	{ 0,0,0 }
};
int x[8] = { 3,3,3,3,3,3,3,3 };
int y[8];
int z[8];
int bz = 0;
int bzs = 0;
char ch;
void display();
void kh();
void core();
void qz(char c);
void qzs(char c);
void qzss(char c);
void lj(char c);
void ljs(char c);

int hq(int a, int b)//合取
{
	if (a == b&&a == 1)
		return 1;
	else
		return 0;
}

int xq(int a, int b)//析取
{
	if (a == 1 || b == 1)
		return 1;
	else
		return 0;
}

int qf(int a)//取反
{
	if (a == 1)
		return 0;
	else
		return 1;
}

int tj(int a, int b)//条件式
{
	if (a == 1 && b == 0)
		return 0;
	else
		return 1;
}

int xor(int a, int b)//异或
{
	if (a == 1 && b == 0)
		return 1;
	else if (a == 0 && b == 1)
		return 1;
	else
		return 0;
}

void qzs(char c)
{
	if (c == '-')
	{
		bz = 1;
		ch = getchar();
	}
	else if (c == 'p')
	{
		for (int i = 0; i < 8; i++)
			y[i] = a[i][0];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				y[i] = qf(y[i]);
		}
	}
	else if (c == 'q')
	{
		for (int i = 0; i < 8; i++)
			y[i] = a[i][1];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				y[i] = qf(y[i]);
		}
	}
	else if (c == 'r')
	{
		for (int i = 0; i < 8; i++)
			y[i] = a[i][2];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				y[i] = qf(y[i]);
		}
	}
}

void qz(char c)
{
	if (c == '-')
	{
		bz = 1;
		ch = getchar();
	}
	else if (c == 'p')
	{
		for (int i = 0; i < 8; i++)
			x[i] = a[i][0];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				x[i] = qf(x[i]);
			bz = 0;
		}
	}
	else if (c == 'q')
	{
		for (int i = 0; i < 8; i++)
			x[i] = a[i][1];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				x[i] = qf(x[i]);
			bz = 0;
		}
	}
	else if (c == 'r')
	{
		for (int i = 0; i < 8; i++)
			x[i] = a[i][2];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				x[i] = qf(x[i]);
			bz = 0;
		}
	}
}

void qzss(char c)
{
	if (c == '-')
	{
		bz = 1;
		ch = getchar();
	}
	else if (c == 'p')
	{
		for (int i = 0; i < 8; i++)
			z[i] = a[i][0];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				z[i] = qf(z[i]);
		}
	}
	else if (c == 'q')
	{
		for (int i = 0; i < 8; i++)
			z[i] = a[i][1];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				z[i] = qf(z[i]);
		}
	}
	else if (c == 'r')
	{
		for (int i = 0; i < 8; i++)
			z[i] = a[i][2];
		if (bz == 1)
		{
			for (int i = 0; i < 8; i++)
				z[i] = qf(z[i]);
		}
	}
}

void lj(char c)
{

	if (c == '&')
	{
		ch = getchar();
		if (ch == '(')
		{
			bzs = bz;
			bz = 0;
			kh();
			for (int i = 0; i < 8; i++)
			{
				x[i] = xq(x[i], y[i]);
			}

		}
		else
		{
			qzs(ch);
			for (int i = 0; i < 8; i++)
				x[i] = xq(x[i], y[i]);
		}
	}
	else if (c == 'x')
	{

		ch = getchar();
		if (ch == '(')
		{
			bzs = bz;
			bz = 0;

			kh();

			for (int i = 0; i < 8; i++)
			{
				x[i] = hq(x[i], y[i]);
			}
		}
		else
		{
			qzs(ch);
			for (int i = 0; i < 8; i++)
				x[i] = hq(x[i], y[i]);
		}
	}
	else if (c == '>')
	{
		ch = getchar();
		if (ch == '(')
		{
			bzs = bz;
			bz = 0;
			kh();
			for (int i = 0; i < 8; i++)
			{
				x[i] = tj(x[i], y[i]);
			}
		}
		else
		{
			qzs(ch);
			for (int i = 0; i < 8; i++)
				x[i] = tj(x[i], y[i]);
		}
	}
	else if (c == '+')
	{
		ch = getchar();
		if (ch == '(')
		{
			bzs = bz;
			bz = 0;
			kh();
			for (int i = 0; i < 8; i++)
			{
				x[i] = xor (x[i], y[i]);
			}
		}
		else
		{
			qzs(ch);
			for (int i = 0; i < 8; i++)
				x[i] = xor (x[i], y[i]);
		}
	}

}

void ljs(char c)
{

	if (c == '&')
	{
		ch = getchar();
		qzs(ch);
		for (int i = 0; i < 8; i++)
			z[i] = xq(z[i], y[i]);
	}
	else if (c == 'x')
	{
		ch = getchar();
		qzs(ch);
		for (int i = 0; i < 8; i++)
			z[i] = hq(z[i], y[i]);
	}
	else if (c == '>')
	{
		ch = getchar();
		qzs(ch);
		for (int i = 0; i < 8; i++)
			z[i] = tj(z[i], y[i]);
	}
	else if (c == '+')
	{
		ch = getchar();
		qzs(ch);
		for (int i = 0; i < 8; i++)
			z[i] = xor (z[i], y[i]);
	}

}

void kh()
{
	ch = getchar();
	qzss(ch);
	ch = getchar();
	while (ch != ')')
	{
		ljs(ch);
		ch = getchar();
	}
	if (bzs == 1)
	{
		for (int i = 0; i < 8; i++)
			y[i] = qf(z[i]);
		bzs = 0;
	}
	else if (bzs == 0)
	{
		for (int i = 0; i < 8; i++)
			y[i] = z[i];
	}

}

void display()
{
	printf("                ===============================================\n");
	printf("                               p|      q|      r|真值为|\n");
	for (int i = 0; i < 8; i++)
	{
		printf("                               %d|      %d|      %d|   %d  |\n", a[i][0], a[i][1], a[i][2], x[i]);
	}

}

void core()
{

	ch = getchar();
	while (ch != '=')
	{
		if (ch == '-')
		{
			bz = 1;
			ch = getchar();
			continue;
		}
		else if (ch == 'p')
		{
			qz(ch);
			ch = getchar();
			continue;
		}
		else if (ch == 'q')
		{
			qz(ch);
			ch = getchar();
			continue;
		}
		else if (ch == 'r')
		{
			qz(ch);
			ch = getchar();
			continue;
		}
		else if (ch == '(')
		{
			bzs = bz;
			bz = 0;
			kh();
			for (int i = 0; i < 8; i++)
			{
				x[i] = y[i];
			}
			ch = getchar();
			continue;

		}
		else if (ch == '&')
		{

			lj(ch);
			ch = getchar();
			continue;
		}
		else if (ch == 'x')
		{
			lj(ch);
			ch = getchar();
			continue;
		}
		else if (ch == '>')
		{
			lj(ch);
			ch = getchar();
			continue;
		}
		else if (ch == '+')
		{
			lj(ch);
			ch = getchar();
			continue;
		}
	}
	display();
}

void main()
{
	printf("                   ****************************************\n");
	printf("                   **                                    **\n");
	printf("                   **           请输入计算表达式         **\n");
	printf("                   **           (变量为p、q、r)          **\n");
	printf("                   **                                    **\n");
	printf("                   **       取反:-             析取:&    **\n");
	printf("                   **                                    **\n");
	printf("                   **       合取:x             条件:>    **\n");
	printf("                   **                                    **\n");
	printf("                   **       异或:+                       **\n");
	printf("                   **                                    **\n");
	printf("                   **                                    **\n");
	printf("                   ****************************************\n");

	core();
	system("pause");

}
