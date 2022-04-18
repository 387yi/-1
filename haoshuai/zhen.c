#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"
void menu()
{
	printf("***************************\n");
	printf("******* 1.play   0.exit****\n");
	printf("***************************\n");
}
void gam()
{
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };//全部空格
	//初始化棋盘
	//IntBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	do {

		//玩家下棋
		if (shengfu(board, ROW, COL) == 'j')
		{
			Xiaqi(board, ROW, COL);
		}
		//电脑下棋
		if (shengfu(board, ROW, COL) == 'j')
		{
			Dxiaqi(board, ROW, COL);
		}
		if (shengfu(board, ROW, COL) != 'j')
		{
			break;
		}
	} while (1);
	if (shengfu(board, ROW, COL) == '*')
		printf("\n玩家赢\n");
	else if (shengfu(board, ROW, COL) == '#')
		printf("\n电脑赢\n");
	else
		printf("\n平局\n");
	
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：》");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
			gam();
			break; 
			}
			case 0:
			{
				printf("退出游戏\n");
				break;
			}
			default:
			{
				printf("请重新选择\n");
				break;
			}
		}
		if (input == 0)
			break;
	} while (1);
}
int main() 
{
	test();
	return 0;
}
//void arr_pai(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int m = 1;
//		int j = 0;
//		for ( j= 0; j<sz-i-1 ; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int map = arr[j];
// 				arr[j] = arr[j + 1];
//				arr[j + 1] = map;
//				m = 0;
//			}
//		}
//		if (m == 1)
//			break;
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//    arr_pai(arr,sz);
//	while(i<sz)
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}
//	return 0;
//}
//1.循环的方式找到运算规律
//int func2(int n)
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 2;
//	int i = 0;
//	int a1 = 1;
//	int a2 = 2;
//	int a3 = 3;
//	for (i = 3; i <=n; i++)
//	{
//		a3 = a1 + a2;
//		a1 = a2;
//		a2 = a3;
//	}
//	return a3;
//}
// 2.数学的方式
//int func3(int n)
//{
//	int res = 0;
//	for (int i = 0; i <= n / 2; i++)
//	{
//		int fenzi = 1;
//		int fenmu = 1;
//		for (int j = 0; j <i; j++) 
//		{
//			fenzi = (n - i - j) * fenzi;
//			fenmu = (i - j) * fenmu;
//		}
//		res += fenzi / fenmu;
//	}
//	return res;
//}
// 3.递归的方式
//int jieti(int p)
//{
//	if (p == 1)
//	{
//		return 1;
//	}
//	if (p == 2)
//	{
//		return 2;
//	}
//	return jieti(p - 1) + jieti(p - 2);
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int a = 0;
//	printf("多少个台阶\n请输入》");
//	scanf("%d", &a);
//	int laoshu = func2(a);
//	printf("一共有%d个方法", laoshu);
//	return 0;
//}
//二分查找
//int shuzhu(int arr[], int p,int sz)
//{
//	int letf = 0;
//	//int right = (sizeof(arr) / sizeof(arr[0])-2);
//	int right= sz-1;
//	while(letf<=right)
//	{
//		int zhong = (letf + right) / 2;
//		if (arr[zhong]<p)
//		{
//			letf = zhong + 1;
//		}
//		else if (arr[zhong]>p)
//			right = zhong - 1;
//		else
//		{
//			return zhong;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 10;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	//int sz = strlen(arr);
//	int rat = shuzhu(arr, k, sz);
//	if (rat == -1)
//	{
//		printf("找不到数字");
//	}
//	else
//	{
//		printf("找到了，下标是%d", rat);
//	}
//	return 0;
//}
//判断一个数是不是一个素数
//void sushu(int s)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(s); i++)
//	{
//		if (s % i == 0) {
//			printf("%d这不是素数\n",s);
//			break;
//		}
//	}
//	if (i>sqrt(s))
//	{
//		printf("%d是素数\n", s);
//	}
//}
// 闰年的函数
//void year(int s)
//{
//	if ((s % 4 == 0 && s % 100 != 0) || s % 400 == 0)
//		printf("%d是闰年", s);
//	else
//	{
//		printf("%d不是闰年", s);
//	}
//}
//int main()
//{
//	int p = 0;
//	printf("请输入：>");
//	scanf("%d", &p);
//	//sushu(p);素数
//	//year(p);闰年
//	return 0;
//}
////指针变量
//void Swap(int* x, int* y)
//{
//	int tap = 0;
//	tap = *x;
//	*x = *y;
//	*y = tap;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(&a, &b);
//	printf("a=%d,b=%d", a, b);
//	return 0;
//}
//memset函数的使用
//int main()
//{
//	char arr[] = { "hollw world" };
//	!!!!memset(arr, '*', 10);//(目标，替换的东西，个数）!!!!
//	printf("%s\n", arr);
//	return 0;
//}
//system与shotdown的 使用
////int main() {
////	system("shotdown /a");
////}
//int main()
//{
//	char arr[20] = { 0 };
//	system("shutdown /s  /t 10");
//ass:
//	printf("请注意，你的电脑在一分钟内关机，如果输入：我好帅，就取消关机\n请输入:>");
//	scanf("%s", arr);
//	if (strcmp(arr, "我好帅") == 0)
//		system("shutdown /a");
//	else
//		goto ass;
//	return 0;
//}
//void game() {
//	int ps;
//	ps = rand() % 100 - 1;
//	printf("%d", ps);
//	int as;
//	while (1)
//	{
//		printf("请输入:>\n");
//		scanf("%d\n", &as);
//		if (ps< as)
//			printf("猜大了\n");
//		else if(ps > as)
//			printf("猜小了\n");
//		else {
//			printf("猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int ka = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		printf("########################\n###1.继续    2.结束  ###\n########################\n请选择》");
//		
//		scanf("%d", &ka);
//		switch (ka)
//		{
//		case 1:
//			game();
//			break;
//		case 2:
//			printf("结束游戏\n");
//			break;
//		default:
//			printf("输入错误\n");
//			break;
//		}
//		if (ka == 2) {
//			break;
//		}
//	} while (ka);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		int j = 0;
//		for (j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		sqrt开平方
//		if (j > sqrt(i)) {
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//润年
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1000; i <= 2000; i += 4)
//	{
//		if (i % 4 == 0 && i % 100 != 0 || i % 400==0) {
//			printf("%dyear", i);
//			sum++;
//		}
//	}
//	printf("%d", sum);
//}
//密码
//int main()
//{
//	int i = 0;
//	char password[20] = {0};
//	for (i = 0; i < 3; i++) {
//		printf("请输入密码");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)//strcmp检查字符串是否相等，相等返回0，不相等返回比0大的值
//		{
//			printf( "登录成功\n" );
//			break; 
//		}
//		else
//		{
//			printf("输入错误\n");
//		}
//	}
//	if (i==3)
//	{
//		printf("输入密码错误三次，退出程序");
//	}
//}
//int main()
//{
//	char arr1[] = { "welome to bit!!!!!!" };
//	char arr2[] = { "###################" };
//	int left = 0;
//	/*int right = sizeof(arr1) / sizeof(arr1[0]) - 2;*/
//	int right = strlen(arr1) - 1;
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		!!!!!!Sleep(1000);//休息一秒!!!!!
//		!!!!system("cls");//执行系统命令的一个函数-cls-清空屏幕!!!!
//		left++;
//		right--;
//	}
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int right = 0;
//	int left = sizeof(arr) / sizeof(arr[0])-1;
//	while (right <= left)
//	{
//		int mid = (right + left) / 2;
//		if (k > arr[mid])
//			right = mid + 1;
//		else if (k < arr[mid])
//			left = mid - 1;
//		else {
//			printf("找到了%d",mid);
//			break;
//		}
//	}
//	if (right > left)
//	{
//		printf("找不到");
//	}
	//printf("%d\n", sizeof(arr));
//连续阶乘的相加
//int main()
//{
//	int n = 0;
//	int sum = 1;
//	int pa = 0;
//	int i = 1;
//	int j = 1;
//	printf("输入一个数");
//	scanf("%d", &n);
//	int n1 = n;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= n1; j++)
//		{
//	
//				sum *= j;
//		}
//		n1--;
//		pa += sum;
//		sum = 1;
//	}
//	printf("pa=%d\n", pa);
//}
//优化
 //int main()
 //{
	//int n=0;
	//int i=0;
	//int ret=1;
	//int sum=0;
	//scanf("%d",&n);
	//for(i=1;i<=n;i++)
	//{
	//	ret*=i;
	//	sum += ret;
	//}
	//printf("%d\n", sum);
 //}
// 
// 阶乘的计算
//int main()
//{
//	int n = 0;
//	int i = 1;
//	int sum = 1;
//	printf("请输入你想要的计算的阶乘");
//	scanf("%d", &n);
//	printf("%d\n", n);
//	for (i = 1; i <= n; i++)
//	{
//		if (n == 1)
//			printf("%d\n",1);
//		else
//			sum *= i;
//	}
//	printf("sum=%d\n", sum);
//}
//whlie 的使用
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0 '|| ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}
//结构体
//struct Book
//{
//	char name[20];
//	short price;
//};
//int main() {
//	struct Book b1 = { "c语言程序设计",55 }; 
//	strcpy(b1.name, "c++");//strcpy:字符串修改的函数
//	printf("%s\n", b1.name);
//	return 0;
//}