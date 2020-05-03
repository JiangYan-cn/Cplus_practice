/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>
#include<math.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<Windows.h>

using namespace std;
*/

/*
struct GCP
{
	int ID;
	double x, y, z;
};

bool read_the_file(const char* file1,GCP**gcp,int *nGCP)
{
	if (*gcp)delete[] * gcp;
	*gcp = nullptr;
	*nGCP = 0;
	FILE *fp=nullptr;
	errno_t err = fopen_s(&fp, file1, "rt");
	if (!fp)
	{
		printf("Cannot open the file %s\n",file1);
		return false;
	}
	fscanf_s(fp, "%d\n",nGCP);
	if (*nGCP)
	{
		(*gcp) = new GCP[*nGCP];
		for (int i = 0; i < *nGCP; i++)
		{
			fscanf_s(fp, "%d % lf %lf %lf\n", &(*gcp)[i].ID, &(*gcp)[i].x, &(*gcp)[i].y, &(*gcp)[i].z);
		}
	}
	fclose(fp);
	return true;
}

bool write_the_file(const char*file2,GCP *gcp,int nGCP)
{
	FILE *fp;
	errno_t err = fopen_s(&fp, file2, "wb");
	if (!fp)
	{
		printf("Cannot write the file %s\n",file2);
		return false;
	}
	fwrite(&nGCP, sizeof(int), 1, fp);
	fwrite(gcp, sizeof(gcp), nGCP, fp);
	fclose(fp);
	return true;
}

void main()
{
	GCP *M=nullptr;
	int nGCP = 0;
	char f1[] = "C:\\C语言文件\\practice";
	char f2[] = "C:\\C语言文件\\class2";
	if (read_the_file(f1, &M, &nGCP))
	{
		write_the_file(f2, M, nGCP);
	}
	if (M)delete[]M;
	system("pause");
}
*/

/*
#include <stdio.h>
#include <memory.h>

typedef struct tagMyDate {
	unsigned int year, month, date;
}MyDate, *MyDatePtr;

const int DaysInMonth[] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool IsLeapYear(unsigned int year) {
	return (((0 == year % 4) && (0 != year % 100)) || (0 == year % 400)) ? true : false;
}

int GetSign(int value) {
	if (value < 0) return -1;
	else if (value > 0) return 1;
	return 0;
}

int CompareDate(MyDatePtr t1, MyDatePtr t2) {
	int symbol = GetSign(t1->year - t2->year);
	if (symbol == 0) {
		symbol = GetSign(t1->month - t2->month);
		if (symbol == 0) {
			symbol = GetSign(t1->date - t2->date);
		}
	}
	return symbol;
}

MyDatePtr InputNewDate() {
	MyDatePtr t = new MyDate;
	printf("Please enter a date(xxxx/xx/xx): ");
	scanf("%d/%d/%d", &t->year, &t->month, &t->date);
	return t;
}

int GetDaysFromTheYear(MyDate& t) {
	const int* pDays = (IsLeapYear(t.year)) ? DaysInMonth + 13 : DaysInMonth;

	int days;
	for (int i = 1; i < t.month; i++) {
		days += pDays[i];
	}
	days += t.date;

	return days - 1;
}

int GetDifferentDays(MyDatePtr t1, MyDatePtr t2) {
	int sign = CompareDate(t1, t2);
	if (sign = 0) return 0;

	MyDatePtr ref, tar;
	if (sign < 0) { ref = t1; tar = t2; }
	else { ref = t2; tar = t1; }

	int days = GetDaysFromTheYear(*tar) - GetDaysFromTheYear(*ref);
	for (int i = ref->year; i < tar->year; i++) {
		int n = (IsLeapYear(i)) ? 366 : 365;
		days += n;
	}

	return sign * days;
}

void main() {
	printf("Compare two input date.\n");
	MyDatePtr t1 = InputNewDate();
	MyDatePtr t2 = InputNewDate();
	printf("%d\n", GetDifferentDays(t1, t2));
	if (t1) delete[] t1;
	if (t2) delete[] t2;
}
*/

/*
void make_dir(char A[])
{
	int n = strlen(A);
	int i = n - 1;
	for (; i > 0; i--)
	{
		if (A[i] == '\\')
		{
			break;
		}
	}

	if (i == 0)
	{
		return ;
	}

	char new_dir[256];
	memcpy(new_dir, A, i * sizeof(char));
	new_dir[i] = '\0';
	make_dir(new_dir);
	_mkdir(A);
}

void main()
{
	char directory[] = "C:\\C语言文件\\计算机满绩\\笔试满分";
	make_dir(directory);
	system("pause");
}
*/

/*
int ReplaceInFile(char strSearch[], char strReplace[], char strSrcFile[], char strTarFile[])
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, strSrcFile, "rt");
	if (!fp)
	{
		printf("Error: Can not open file %s!\n", strSrcFile);
		return 0;
	}
	int nFinds = 0;
	int nChar = strlen(strSearch);
	while (!feof(fp))
	{
		char strLine[256] = { 0 };
		fgets(strLine, _countof(strLine), fp);
		char* str = strstr((char *)strLine, strSearch);
		while (str != nullptr)
		{
			nFinds++;
			memcpy(str, strReplace, nChar * sizeof(char));
			int nLasts = strlen(str);
			if (nLasts > nChar)
			{
				str += nChar;
			}
			else
			{
				break;
			}
			str = strstr(str, strSearch);
		}
	}
	FILE*in = nullptr, *out = nullptr;
	errno_t err1 = fopen_s(&in, strSrcFile, "rt");
	errno_t err2 = fopen_s(&out, strTarFile, "rt");
	char ch, infile[9999] = "\0", outfile[9999] = "\0";
	if (err1 == NULL)
	{
		printf("Cannot open infile.\n");
		return 0;
	}
	if (err2 == NULL)
	{
		printf("Cannot open infile.\n");
		return 0;
	}
	while (!feof(in))
	{
		fputc(fgetc(in), out);
	}
	fclose(in);
	fclose(out);
	fclose(fp);
	return nFinds;
}

void main() {
	char strSearch[] = "double";
	char strReplace[] = "float";
	char strSrcFile[] = "C:\\C语言文件\\C语言期末考试练习题\\参考答案\\Photo.cpp";
	char strTarFile[] = "C:\\C语言文件\\C语言期末考试练习题\\参考答案\\Photo-new.cpp";
	int nFind = ReplaceInFile(strSrcFile, strTarFile, strSearch, strReplace);
	printf("Total %d find and replace!\n", nFind);
	system("pause");
}






int ReplaceInLine(FILE *fpSrc, FILE*fpTar, const char *strSearch, const char *strReplace)
{
	char*Line = new char[256];
	fgets(Line, 256, fpSrc);
	int LenLine = strlen(Line), LenSearch = strlen(strSearch);
	int n = 0, nFind = 0;
	for (n = 0; n < LenLine; n++)
	{
		int t = 0;
		for (int i = 0; i < LenSearch; i++)
		{
			if (*(Line + n + i) == *(strSearch + i))
			{
				t++;
			}
		}
		if (t == LenSearch)
		{
			nFind++;
			fputs(strReplace, fpTar);
			n += LenSearch - 1;
		}
		else
		{
			fputc(*(Line + n), fpTar);
		}
	}
	return nFind;
}

int ReplaceInFile(const char *strSrcFile, const char *strTarFile, const char *strSearch, const char *strReplace)
{
	FILE*fpSrc, *fpTar;
	fopen_s(&fpSrc, strSrcFile, "r");
	if (!fpSrc)
	{
		return -1;
	}
	fopen_s(&fpTar, strTarFile, "w");
	if (!fpTar)
	{
		return -2;
	}
	int n = 0;
	while (!feof(fpSrc))
	{
		n += ReplaceInLine(fpSrc, fpTar, strSearch, strReplace);
	}
	fclose(fpSrc);
	fclose(fpTar);
	return n;
}

void main() {
	char strSearch[] = "double";
	char strReplace[] = "float";
	char strSrcFile[] = "C:\\C语言文件\\C语言期末考试练习题\\参考答案\\Photo.cpp";
	char strTarFile[] = "C:\\C语言文件\\C语言期末考试练习题\\参考答案\\Photo-new.cpp";
	int nFind = ReplaceInFile(strSrcFile, strTarFile, strSearch, strReplace);
	printf("Total %d find and replace!\n", nFind);
	system("pause");
}
*/

/*
程序功能：自定义字符串的比较函数strcmp。
自己写一个strcmp函数，实现两个字符串的比较：
int strcmp(const char *s1,const char *s2)，如果s1与s2完全相同，则返回值为0;
如果s1不等于s2,返回它们二者第一个不同字符的ASCII码差值(s1减去s2对应位置上的
字符ASCII码之差。
例如：若在in.txt中内容如下：
Hello Happy
Happy Hello
Happy Happyy
Happy Happy
则out.txt中内容应为：
4
-4
-121
0
请在Begin和End之间完善程序，注意:不要删除注释语句。
*/

/*
#include <fstream>
using namespace std;
ifstream infile("in.txt", ios::in);
ofstream outfile("out.txt", ios::out);
begin
int strcmp(char *str1, char *str2)
{
	int m = strlen(str1), n = strlen(str2);
	int s = (m <= n) ? (m) : (n);
	for (int i = 0; i < s; i++)
	{
		if (*str1 != *str2)
		{
			return *str2 - *str1;
		}
		str1++;
		str2++;
	}
	return 0;
}
end
int main()
{
	char str1[100], str2[100];
	while (infile >> str1 >> str2)
		outfile << strcmp(str1, str2) << endl;

	infile.close();
	outfile.close();
	return 0;
}
*/

/*
程序功能：5个球中取3种不同颜色的球。
口袋中有红、黄、蓝、白、黑5种颜色的球若干。每次从口袋中任意依次取出3个球，
问得到3种不同颜色的球的可能取法，输出每种排列的情况。要求用枚举结构实现，
输出时按照红、黄、蓝、白、黑的顺序，每行各项之间用制表位隔开，每输出
一种情况后换行。结果输出到文件out.txt中。
如：out.txt中内容应为：
1	red	yellow	blue
2	red	yellow	white
3	red	yellow	black
……
60	black	white	blue
请在Begin和End之间完善程序，注意：不要删除Begin和End语句。
*/

/*
#include <fstream>
using namespace std;
ofstream outfile("C:\\C语言文件\\out.txt", ios::out);
enum color
{
	red,yellow,blue,white,black
};
char COLOR[5][10] = { "red","yellow","blue","white","black" };
int main()
{
	int x, y, z;
	int n = 0;
	for (x = red; x <= black; x++)
	{
		for (y = red; y <= black; y++)
		{
			for (z = red; z <= black; z++)
			{
				if (x != y && y != z && z != x)
				{
					n++;
					outfile << n << '\t' << COLOR[x] << '\t' << COLOR[y] << '\t' << COLOR[z] << endl;
				}
			}
		}
	}
	outfile.close();
	system("pause");
	return 0;
}
*/

/*
编程实现字符串的替换：
编写函数Replace(char * strSource, char * strFind, char * strReplace)
完成将字符串strSource中所包含的子字符串strFind全部用另外一个字符串
strReplace替换。
从输入文件in.txt中读入一行包含空格的字符串，再读入一个要查找的字符串和
替换的字符串，将原字符串替换后的结果输出到文件out.txt中。
例如：若in.txt中内容为：
three boys have three pencils in three pencilcases.
three
four
则文件out.txt中内容应为：
four boys have four pencils in four pencilcases.
请在Begin和End之间完善程序。注意：不要删除注释语句。
*/

/*
#include <fstream>
using namespace std;
ifstream infile("in.txt", ios::in);
ofstream outfile("out.txt", ios::out);

void Replace(char * strSource, char * strFind, char * strReplace)
{
	char *p = strSource;
	char *q = p;
	char word[50];
	int i = 0;
	while (*q != 0)
	{
		while (*q != ' ') //提取一个单词
		{
			if (*q == 0) break;//若是句子的最后一个单词
			word[i] = *q;
			q++; i++;
		}
		word[i] = '\0';
		if (strcmp(word, strFind) == 0)    //找到待替换的单词则替换
		{
			char temp[100];
			strcpy(temp, strReplace);
			strcat(temp, q);
			strcpy(p, temp);
			q = q + strlen(strReplace) - strlen(strFind); //指针还原在下一个待查找单词前


		}
		if (*q == 0) break; //若字符串结束
		q++; i = 0; p = q;
	}

}

int main()
{
	char str1[100];
	char strF[50];
	char strR[50];
	infile.getline(str1, 100);   //读入一行带空格的字符串，以换行结束
	infile >> strF >> strR;

	Replace(str1, strF, strR);
	outfile << str1 << endl;
	return 0;
}
*/

/*
#include <iostream>
static void fn();//声明静态函数
int main()
{
	fn();
	fn();
	fn();
	system("pause");
}
void fn()//定义静态函数
{
	int n = 10;
	printf("%d", n);
}
*/

/*
#include <stdio.h>
int fun(void)
{
	static int count = 10; // 此语句只在函数第一次调用时执行，后续函数调用此变量的初始值为上次调用后的值，每次调用后存储空间不释放
	return count--;
}
int count = 1;
int main(void)
{
	printf("global\t\tlocal static\n");
	for (; count <= 10; ++count)
	{
		printf("\t\t\t%d\n", count);
		printf("%d\t\t%d\n", count, fun());
		printf("\t\t\t%d\n\n", count);
	}
	return 0;
}
*/

/*
int main()
{
	printf("Please give a value:\n");
	int l, m, n, sum = 0;
	scanf_s("%d", &m);
	l = m;
	while (m >= 1)
	{
		n = m % 10;
		sum += (n*n*n);
		m /= 10;
	}
	printf("I want something just like this:\n%d -> %d \n", l, sum);
	system("pause");
}
*/

/*
void main()
{
	int n, J = 0, max = 0;
	float ave, sum = 0;
	printf("We'll make an array.\nNow firstly let's give it a size(n):\nHow many integers it contains\n");
	scanf_s("%d", &n);
	int *a = new int[n];
	printf("Now let's give each one a value.\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (a[i] > max)
		{
			max = a[i];
			J = 1;
			continue;
		}
		else if (a[i] == max)
		{
			J++;
		}
	}
	ave = sum / n;
	printf("ave\tmax\tJ\n");
	printf("%g\t%d\t%d\n", ave, max, J);
	system("pause");
}
*/

/*
void main()
{
	char S[999] = "\0";
	printf("Please input a string:\n");
	gets_s(S);
	char *p = &S[0], cmax = *p;
	int max = 1, len_a = 0, len_b = 0, len_star = 0;
	if (*p == 'a')
	{
		len_a++;
	}
	else if (*p == 'b')
	{
		len_b++;
	}
	else if (*p == '*')
	{
		len_star++;
	}
	p++;
	while (*p!='\0')
	{
		if (*p != *(p - 1))
		{
			if (*p == 'a')
			{
				len_a = 1;
			}
			else if (*p == 'b')
			{
				len_b = 1;
			}
			else if (*p == '*')
			{
				len_star = 1;
			}
		}
		else if (*p == *(p - 1))
		{
			if (*p == 'a')
			{
				len_a++;
				if (len_a > max)
				{
					max = len_a;
					cmax = 'a';
				}
			}
			else if (*p == 'b')
			{
				len_b++;
				if (len_b > max)
				{
					max = len_b;
					cmax = 'b';
				}
			}
			else if (*p == '*')
			{
				len_star++;
				if (len_star > max)
				{
					max = len_star;
					cmax = '*';
				}
			}
		}
		p++;
	}
	if (cmax == 0)
	{
		printf("ERROR!");
	}
	else
	{
		printf("%d,%c\n", max, cmax);
	}
	system("pause");
}
*/

/*
void main()
{
	int len_1, len_2, n;
	printf("Firstly make sure the size of two strings.\nPlease give two values, so each of them can has a value:\n");
	scanf_s("%d%d", &len_1, &len_2);
	char *s1 = new char[len_1];
	char *s2 = new char[len_2];
	printf("Input the first string:\n");
	scanf_s("%s", s1, len_1);
	printf("Input the second string:\n");
	scanf_s("%s", s2, len_2);
	char *p = s1, *q = s2;
	n = strlen(s2);
	*(q + n) = '\0';
	while (*p != '\0')
	{
		p++;
	}
	*p = ' ';
	p++;
	while (*q != '\0')
	{
		*p = *q;
		p++, q++;
	}
	*p = '\0';
	printf("The first string has been changed into:\n%s\n", s1);
	system("pause");
}
*/

/*
void main()
{
	int n, m, x = 1;
	printf("数组大小最大容量m为:\n");
	scanf_s("%d", &m);
	int *A = new int[m];
	printf("下面分别赋值:\n");
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &A[i]);
	}
	int *a = A;
	n = m;
	while (x < n)
	{
		if (*(a + x) == *(a + x - 1))
		{
			for (int j = x; j < n - 1; j++)
			{
				*(a + j) = *(a + j + 1);
			}
			n--;
		}
		else
		{
			x++;
		}
	}
	*(a + n) = '\0';
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	system("pause");
}
*/

/*
void main()
{
	int m, n, x, y = 0;
	printf("分别输入m和n的值：\n");
	scanf_s("%d%d", &m, &n);
	int *A = new int[m*n];
	printf("下面依次输入数组的元素:\n");
	for (int i = 0; i < m*n; i++)
	{
		scanf_s("%d", &A[i]);
	}
	int max, r, c, i, j;
	for (r = 0; r < m; r++)
	{
		i = r;
		j = 0;
		max = A[r*n + j];
		for (c = 0; c < n; c++)
		{
			if (A[r*n + c] > max)
			{
				max = A[r*n + c];
				i = r;
				j = c;
			}
		}

		for (x = 0; x < m; x++)
		{
			if (A[x*n + j] < max)
			{
				break;
			}
		}
		if (x == m)
		{
			printf("存在鞍点: A[%d][%d]\n", i, j);
		}
		else
		{
			y++;
		}
	}
	if (y == m)
	{
		printf("没有鞍点\n");
	}
	if (A)delete[]A;
	system("pause");
}
*/

/*
程序功能：编程查找学生信息。
依次读入10个学生的基本信息，包括：
学号，姓名 ，性别，年龄，成绩 。
然后再读入一个学号，在已有信息中查找 ，若找到则输出学生基本信息,
中间用制表位隔开，最后换行；若找不到，则输出
"未找到该学生信息！" 。
例如：若输入内容为：
120003 胡兰 女 19 98
120004 包宏伟 男 20 91.2
120005 赵云 男 18 96
120006 齐飞扬 女 19 83.4
120007 唐李生 男 18 88.6
120008 苏解放 男 21 78.4
120009 杜学江 男 17 80.5
120010 吉祥 男 19 87.3
120011 倪冬声 男 17 75.9
120012 刘康锋 女 22 87.1
120006
则输出应为：
120006	齐飞扬	19	女	83.4
*/

/*
struct stu
{
	long sno;
	char name[10];
	char sex[5];
	int age;
	float scores;
}S[10];
void main()
{
	printf("请输入10名学生的基本信息:\n学号\t姓名\t性别\t年龄\t分数\n");
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%ld\t%s\t%s\t%d\t%f", &S[i].sno, S[i].name,20, S[i].sex,20, &S[i].age, &S[i].scores);
	}
	printf("\n");
	printf("请输入相关学号以查找相关信息:\n");
	int n, x;
	scanf_s("%d", &n);
	for (x = 0; x < 10; x++)
	{
		if (n == S[x].sno)
		{
			printf("学号\t姓名\t性别\t年龄\t分数\n%d\t%s\t%s\t%d\t%g\n", S[x].sno, S[x].name, S[x].sex, S[x].age, S[x].scores);
			break;
		}
	}
	if (x == 10 && n != S[9].sno)
	{
		printf("未找到该学生信息!\n");
	}
	system("pause");
}
*/

/*
#include<iostream>
using namespace std;
int main()
{
	char str[] = "ABCD", *p = str;
	printf("%c\n",*p);
	printf("%s\n", p);
	cout << p;
	printf("\n");
	system("pause");
}
*/

/*
#include <iostream>
using namespace std;

void fun(int *a, int *b)
{
	int *k;
	k = a;
	a = b;
	b = k;
}
void main()
{
	int a = 3, b = 6, *x = &a, *y = &b;
	int i = 1, j = 9, *m = &i, *n = &j;
	fun(x, y);
	fun(&i, &j);
	cout << a << " " << b << "\t" << *x << " " << *y;
	printf("\n");
	cout << *m << " " << *n << "\t" << i << " " << j;
	printf("\n");
	system("pause");
}
*/

/*
#include <iostream>
using namespace std;

struct ord
{
	int x, y;
}dt[2] = { 11,12,13,14 };
int main()
{
	ord *p = dt;
	cout << ++p->x << ',';
	cout << ++p->y << "\n";
	cout << p << "\n";
	cout << ++p << "\n";
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

void main()
{
	static int hot = 200;
	int  &rad = hot;
	hot = hot + 100;
	cout << rad << endl;
	system("pause");
}*/

/*
void main()
{
	int a, b, c;
	for (int i = 1; i < 100; i++)
	{
		for (int j = 1; j < 100; j++)
		{
			for (int k = 3; k < 100; k += 3)
			{
				if ((i + j + k == 100) && (i * 5 + j * 3 + k / 3 == 100))
				{
					a = i;
					b = j;
					c = k;
				}
			}
		}
	}
	printf("鸡翁有%d只，鸡母有%d只，鸡雏有%d只\n", a, b, c);
	system("pause");
}
*/

/*
void main()
{
	printf("数字字符串(不超过四位:)");
	int x = 0;
	char s[5] = "\0", *p = s;
	gets_s(s);
	char c = *p;
	while (c!='\0')
	{
		x = x * 10 + c - '0';
		p++;
		c = *p;
	}
	printf("转化为数字:%d\n", x);
	system("pause");
}
*/

/*
struct PT
{
	double x, y, z;
};
PT fun(PT *p, int sum)
{
	double X = 0, Y = 0, Z = 0;
	for (int i = 0; i < sum; i++)
	{
		X += (p+i)->x;
		Y += (p+i)->y;
		Z += (p+i)->z;
	}
	X /= sum, Y /= sum, Z /= sum;
	PT GC = { X,Y,Z };
	return GC;
}
void main()
{
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void main()
{
	char C;
	cout << "请输入一个大写字母：" << endl;
	cin >> C;
	if (C >= 'A'&&C <= 'Z')
	{
		C += 32;
		cout << "大写字母对应的小写字母为:" << C << endl;
	}
	else
	{
		cout << "请输入合乎要求的大写字母" << endl;
	}
	system("pause");
}
*/

/*
void main()
{
	int value1, value2, value3;
	cout << "请输入两个整数:" << endl;
	cin >> value1 >> value2;
	value3 = value1 + value2 - value1 % value2;
	cout << "依题意，得：" << value3 << endl;
	system("pause");
}
*/

/*
void main()
{
	int A[20], x = -1;
	cout << "请输入20个数字：" << endl;
	for (int i = 0; i < 20; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 20; i++)
	{
		if (A[i] == 100)
		{
			x = i + 1;
			break;
		}
	}
	if (x != -1)
	{
		cout << "整数100已经找到，它最初是第" << x << "个输入的。" << endl;
	}
	else
	{
		cout << "未能发现目标（滑稽）!" << endl;
	}
	system("pause");
}
*/

/*
void main()
{
	int i = 10;
	auto_ptr<int> ap1(new int(4)), ap2;
	ap2 = ap1;
	cout << *ap2;
	cout << *ap1 << endl;
	char *c;
	shared_ptr<char> sc;
	sc = c;
	sc = new char(10);
	system("pause");
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
int MaxSubseqSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i]; // 向右累加
		if (ThisSum > MaxSum)
			MaxSum = ThisSum; // 发现更大和则更新当前结果
		else if (ThisSum < 0) // 如果当前子列和为负
			ThisSum = 0; // 则不可能使后面的部分和增大，抛弃之
	}
	return MaxSum;
}
*/

/*
#include<stdio.h>
void f(int n, int *dt)
{
	int dp;
	if (n < 2)
	{
		return;
	}
	if (dt[0] > dt[1])
	{
		dp = dt[0];
		dt[0] = dt[1];
		dt[1] = dp;
	}
	f(n - 1, dt + 1);
}
void main()
{
	int d[10] = { 35,13,21,3,15 }, i;
	for (i = 0; i < 5; i++)
	{
		f(5 - i, d);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", d[i]);
	}
	getchar();
}
*/

/*
#include  <stdio.h>
#pragma warning (disable:4996)
double  fun(double x[], int n)
{
	int i, k = 0;
	double avg = 0.0, sum = 0.0;
	for (i = 0; i < n; i++)
		avg += x[i];

	avg /= n;
	for (i = 0; i < n; i++)
		if (x[i] > avg)
		{

			sum += x[i];
			k++;
		}

	return  sum / k;
}
void main()
{
	double score[12] = { 50,60,70,80,90,100,55,65,75,85,95,99 };
	double aa;
	aa = fun(score, 12);
	printf("%f\n", aa);
}
*/

/*
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
void fun(char *s1, char *s2, char *s3)
{
	int i, j;

	for (i = 0, j = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++, j = j + 2)
	{
		s3[j] = s1[i];
		s3[j + 1] = s2[i];
	}
	if (s2[i] != '\0')
	{
		for (; s2[i] != '\0'; i++, j++)

			s3[j] = s2[i];
	}
	else if (s1[i] != '\0')
	{
		for (; s1[i] != '\0'; i++, j++)
			s3[j] = s1[i];
	}

	s3[j] = '\0';
}
void main()
{
	char s1[128], s2[128], s3[255];
	printf("Please input string1:");
	gets_s(s1);
	printf("Please input string2:");
	gets_s(s2);
	fun(s1, s2, s3);
	printf("string:%s\n", s3);
}
*/

/*
#include<stdio.h>
#pragma warning (disable:4996)
int fun(int n, int result[])
{
	int x = 0;
	for (int i = 1000; i <= n; i++)
	{
		int t = i, a = 0;
		do
		{
			a += (t % 10)*(t % 10)*(t % 10)*(t % 10);
			t /= 10;
		} while (t > 0);
		if (a == i)
		{
			x++;
			result[x - 1] = i;
		}
	}
	return x;
}
void main()
{
	int result[10], n, i;
	void NONO(int result[], int n);
	n = fun(9999, result);
	for (i = 0; i < n; i++) printf("%d\n", result[i]);
	NONO(result, n);
}

void NONO(int result[], int n)
{
	FILE *fp;
	int i;

	fp = fopen("out.dat", "w");
	fprintf(fp, "%d\n", n);
	for (i = 0; i < n; i++) fprintf(fp, "%d\n", result[i]);
	fclose(fp);
}
*/

/*
#include<iostream>

using namespace std;

extern int x = 0;

int f1(int y)
{
	return x * y;
}

int *f2(int a, int b = 1)
{
	int t = a * b;
	return &t;
}

void main()
{
	int i = 10;
	const char r = 10;
	int &lr = i;
	int &rr = i;
	rr = lr;
	int &a = (int&)r, *p;


	const char *c = "nonconst";
	char pc1[9] = "dukang";
	char pc2[9] = "dukang";
	char pc3[9] = "dukang";
	char pc4[9] = "dukang";
	pc1[2] = 't';
	pc2[2] = 't';
	pc3[2] = 't';
	pc4[2] = 't';





	cout << f1(3);
	cout << f2(2, 3);
	getchar();
}
*/

/*
bool is_island(bool A[], int a, int b, int n);

void main()
{
	int n, sum = 0;
	cout << "请输入矩阵的阶:" << endl;
	cin >> n;
	cout << "请按顺序输入矩阵的各个元素：" << endl;
	bool *p = new bool[n*n];
	for (int i = 0; i < n*n; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i < n - 1; i++)//可写成i=1,i<n，这样可减少多余的运算，帮计算机减负;j同理
	{
		//int x, y;可推出一维数组中元素A[q]转化成的二维数组中B[i][j]的位置来大大减少算法复杂度！
		for (int j = 1; j < n - 1; j++)
		{
			if (!*(p+i + j * n))
			{
				sum += is_island(p, i, j, n);
			}
		}
	}
	cout << "小岛的面积是" << sum << endl;
	if (p) delete[]p;
	system("pause");
}

bool is_island(bool A[],int a, int b, int n)
{
	int m = 0;
	for (int i = a + (b-1) * n; i >= 0; i -= n)//up
	{
		if (A[i])
		{
			m++;
			break;
		}
	}
	if (!m)
	{
		return 0;
	}
	for (int i = a + b * n - 1; i >= b*n; i --)//left
	{
		if (A[i])
		{
			m++;
			break;
		}
	}
	if (!(m-1))
	{
		return 0;
	}
	for (int i = a + b * n + 1; i<(b+1)*n;i++)//right
	{
		if (A[i])
		{
			m++;
			break;
		}
	}
	if (!(m - 2))
	{
		return 0;
	}
	for (int i = a + (b+1) * n; i <n*n; i+=n)//down
	{
		if (A[i])
		{
			m++;
			break;
		}
	}
	if (!(m - 3))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
*/

/*用递归求点到直线的距离
double distance(double x1, double x2, double y1, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double pointlength(double x1, double x2, double x3, double y1, double y2, double y3)
{
	double d1 = distance(x1, (x2 + x3) / 2, y1, (y2 + y3) / 2), d2 = distance(x1, x2, y1, y2), d3 = distance(x1, x3, y1, y3);
	if (d2 > d3)
	{
		x2 = (x2 + x3) / 2;
		y2 = (y2 + y3) / 2;
	}
	else if(d2 < d3)
	{
		x3 = (x2 + x3) / 2;
		y3 = (y2 + y3) / 2;
	}
	else
	{
		return d1;
	}
	if (fabs(d2 - d3) < 1e-10)  return d1;
	return pointlength(x1, x2, x3, y1, y2, y3);

}
void main()
{
	double x1, x2, x3, y1, y2, y3, length;
	cout << "输入点A的坐标: ";
	cin >> x1 >> y1;
	cout << "输入点B的坐标: ";
	cin >> x2 >> y2;
	cout << "输入点C的坐标: ";
	cin >> x3 >> y3;
	length = pointlength(x1, x2, x3, y1, y2, y3);
	cout << "输出长度为: ";
	cout << length << endl;
	system("pause");
}
*/

/*
class Point
{
private:
	int x, y;
public:
	Point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
		cout << "Point constructor: " << x << ", " << y << endl;
	}
	Point(Point &p)
	{
		x = p.x;
		y = p.y;
		cout << "Point copy constructor: " << x << ", " << y << endl;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
};

class Line
{
private:
	Point start, end;
public:
	Line(Point pstart, Point pend) : start(pstart), end(pend)
	{
		cout << "Line constructor" << endl;
	}
	float GetDistance()
	{
		double x = double(end.getX() - start.getX());
		double y = double(end.getY() - start.getY());
		return (float)sqrt(x * x + y * y);
	}
};

void main()
{
	Point p1(10, 20), p2(100, 200);
	Line line(p1, p2);
	cout << "The distance is: " << line.GetDistance() << endl;
	system("pause");
}
*/

/*
void main()
{
	cout <<"\a"
		<< endl;
	system("pause");
}
*/

/*
int fun(char a, char *s)
{
	int temp;
	temp = a;
	a = *s;
	*s = temp;
	return a;
}

void main()
{
	char a = '3', b = '6', c;
	c = fun(a, &b);
	printf("%c,%c,%c\n", a, b, c);
	system("pause");
}
*/

/*
int gcd(int x, int y)
{
	while (x != y)
	{
		if (x > y)
		{
			x -= y;
		}
		else
		{
			y -= x;
		}
	}
	return x;
}

void main()
{
	int a, b, c, m;
	cin >> a >> b >> c;
	m = (a*b) / gcd(a, b);
	cout << (m*c) / gcd(m, c);
	system("pause");
}
*/

/*
void fun(int n, int *dt)
{
	int tp;
	if (n < 2)
	{
		return;
	}
	if (dt[0] > dt[1])
	{
		tp = dt[0];
		dt[0] = dt[1];
		dt[1] = tp;
	}
	fun(n - 1, dt + 1);
}

void main()
{
	int d[10] = { 35,13,21,3,15 }, i;
	for (i = 0; i < 4; i++)
	{
		fun(5 - i, d);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", d[i]);
	}
	system("pause");
}
*/

/*

class Point;//必须声明类Point，类Dist的定义中用到了Point

class Dist//定义类Dist
{
public:
	float GetDistance(Point, Point);//成员友元函数
};

class Point//定义类Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y) {};
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	friend float GetDistance(Point, Point);//友元声明，友元是一个一般函数
	friend float Dist::GetDistance(Point, Point);//友元函数是类Dist的成员函数
private:
	int x, y;
};

float GetDistance(Point p1, Point p2)//一般友元函数的定义
{
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return (float)sqrt(x*x + y * y);
}

float Dist::GetDistance(Point p1, Point p2)//成员友元函数的定义
{
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return (float)sqrt(x*x + y * y);
}

void main()
{
	Point p1(10, 20), p2(100, 200);
	cout << "The distance is: " << GetDistance(p1, p2) << endl;//调用一般友元函数
	Dist d;
	cout << "The distance is: " << d.GetDistance(p1, p2) << endl;//调用成员友元函数
	system("pause");
}
*/

/*
class A;//前向引用声明：声明类A，类B的定义用到了类A

class B//定义类B
{
public:
	void BMemberFun(A&);
};

class A//定义类A
{
	friend B;//类B是类A的友元类
private:
	int a, b;
public:
	A(int x = 0, int y = 0)
	{
		a = x, b = y;
	}
	void display()
	{
		cout << "a= " << a << ", " << "b= " << b << endl;
	}
};

void B::BMemberFun(A& objA)//定义友元类B的成员函数，使用引用作为参数
{
	objA.b = 20;//修改类A的私有对象b
}

void main()
{
	A a;
	a.display();
	B b;
	b.BMemberFun(a);
	a.display();
	system("pause");
}
*/

/*
class Point//定义基类，表示点
{
private://私有成员x, y在派生类中不可见
	int x, y;//表示点的x, y坐标
public:
	void setPoint(int a, int b)//设置坐标
	{
		x = a, y = b;
	}
	int getX()//取得x坐标
	{
		return x;
	}
	int getY()//取得y坐标
	{
		return y;
	}
};

class Circle :public Point//定义派生类，表示圆
{
private:
	int radius;//表示圆的半径
public:
	void setRadius(int r)//设置半径
	{
		radius = r;
	}
	int getRadius()//取得半径
	{
		return radius;
	}
	int getUpperLeftX()//取得外接正方形左上方的x坐标
	{
		return getX() - radius;
	}
	int getUpperLeftY()//取得外接正方形左上方的y坐标
	{
		return getY() + radius;
	}
};

void main()
{
	Circle c;
	c.setPoint(200, 250);//共有派生类的对象可以直接访问基类Point的公有成员
	c.setRadius(100);
	cout << "X= " << c.getX()
		<< ", Y= " << c.getY()
		<< ", Radius= " << c.getRadius()
		<< endl;
	cout << " UpperLeft X = " << c.getUpperLeftX()
		<< ", UpperLeft Y = " << c.getUpperLeftY()
		<< endl;
	system("pause");
}
*/

/*
class A
{
public:
	void show()
	{
		cout << "A::show\n";
	}
};

class B :public A
{
public:
	void show()
	{
		cout << "B::show\n";
	}
	void display()
	{
		show();
	}
};

void main()
{
	A a;
	B b;
	a.show();
	b.show();
	b.display();
	system("pause");
}
*/

/*
class Point
{
public:
	Point(int,int);
	~Point();

protected:
	int x, y;
};

class Circle :public Point
{
public:
	Circle(int a = 0, int b = 0, int r = 0) : Point(a, b)
	{
		radius = r;
		cout << "Circle constructor: "
			<< x << ','
			<< y << ','
			<< radius << endl;
	}
	~Circle ()
	{
		cout << "Circle destructor: "
			<< x << ','
			<< y << ','
			<< radius << endl;
	}
protected:
	int radius;
};

class Cylinder:public Circle
{
public:
	Cylinder(int a = 0, int b = 0, int r = 0, int h = 0) :Circle(a, b, r)
	{
		height = h;
		cout << "Cylinder constructor: "
			<< x << ','
			<< y << ','
			<< radius << ','
			<< height << endl;
	}
	~Cylinder()
	{
		cout << "Cylinder destructor: "
			<< x << ','
			<< y << ','
			<< radius << ','
			<< height << endl;
	}
protected:
	int height;
};

Point::Point(int a=0,int b=0)
{
	x = a, y = b;
	cout << "Point constructor: " << x << ',' << y << endl;
}

Point::~Point()
{
	cout << "Point destructor: " << x << ',' << y << endl;
	Sleep(4000);
}

void main()
{
	Cylinder cylinder(400, 300, 200, 100);
}
*/

/*
class BaseA//定义基类
{
protected:
	int a;
public:
	void setA(int x)
	{
		a = x;
	}
};

class BaseB//定义基类
{
protected:
	int b;
public:
	void setB(int x)
	{
		b = x;
	}
};

class MultiDeri :public BaseA, public BaseB//定义多继承的派生类
{
public:
	int getAB()
	{
		return a + b;//可以直接访问基类中protected属性成员
	}
};

void main()
{
	MultiDeri md;//声明派生类的对象
	md.setA(30);//调用从基类BaseA继承而来的成员函数
	md.setB(70);//调用从基类BaseB继承而来的成员函数
	cout << "a+b= " << md.getAB() << endl;//调用派生类MultiDeri自定义的成员函数
	system("pause");
}
*/

/*
class Base1
{
private:
	int a;
public:
	Base1(int x)
	{
		a = x;
		cout << "Base1 Constructor !" << endl;
	}
	int geta()
	{
		return a;
	}
};

class Base2
{
private:
	int b;
public:
	Base2(int x)
	{
		b = x;
		cout << "Base2 Constructor !" << endl;
	}
	int getb()
	{
		return b;
	}
};

class Deri :public Base1, public Base2
{
private:
	int c;
public:
	Deri(int x, int y, int z) :Base2(z), Base1(y)
	{
		c = x;
		cout << "Derived Constructor !" << endl;
	}
	void show()
	{
		cout << geta() << ' ' << getb() << ' ' << c << endl;
	}
};

void main()
{
	Deri obj(1, 2, 3);
	obj.show();
	system("pause");
}
*/

/*
class Base1
{
protected:
	int a;
public:
	void set(int x)
	{
		a = x;
	}
};

class Base2
{
protected:
	int a;
public:
	void set(int x)
	{
		a = a + x;
	}
};

class MultiDeri :public Base1, public Base2
{
public:
	int get1()
	{
		return Base1::a;
	}
	int get2()
	{
		return Base2::a;
	}
};

void main()
{
	MultiDeri md;
	md.Base1::set(30);
	md.Base2::set(70);
	system("pause");
}
*/

/*
class A
{
public:
	int a;
};

class B :public A
{
public:
	int b;
};

class C :public A
{
public:
	int c;
};

class D :public B, public C
{
public:
	int d;
};

void main()
{
	D d1;
	d1.B::a = 10;
	system("pause");
}
*/

/*
class A
{
private:
	int a;
public:
	A(int x)
	{
		a = x;
		cout << "A constructor: " << a << endl;
	}
};

class B1 : virtual public A
{
private:
	int b1;
public:
	B1(int x, int y) :A(x)
	{
		b1 = y;
		cout << "B1 constructor: " << b1 << endl;
	}
};

class B2 : virtual public A
{
private:
	int b2;
public:
	B2(int x, int y) : A(x)
	{
		b2 = y;
		cout << "B2 constructor: " << b2 << endl;
	}
};

class C : public B1, public B2//A是B1和B2的虚基类，B1和B2是C的直接基类，C是派生类
{
private:
	int c;
public:
	C(int x, int y, int z, int w) : B1(x, y), B2(x, z), A(x)//显式指定虚基类A的构造函数
	//直接调用虚基类A，而非向上传递调用
	{
		c = w;
		cout << "C constructor: " << c << endl;
	}
};

void main()
{
	C *pc = new C(1, 2, 3, 4);
	delete pc;
	system("pause");
}
*/

/*
void get_put()
{
	char ch;
	ch = getchar();
	if (ch != '\n')
	{
		get_put();
	}
	if (ch != '\n')
	{
		putchar(ch);
	}
}

void main()
{
	get_put();
	system("pause");
}
*/

/*
struct S
{
	char name[10];
};

void main()
{
	S s1, s2;
	strcpy_s(s1.name, "1\0");
	strcpy_s(s2.name, "ABC");
	s1 = s2;
	cout << s1.name << endl;
	system("pause");
}
*/

/*
void NONO()// 本函数用于打开文件，输入数据，调用函数，输出数据，关闭文件
{
	FILE *in, *out;
	int i, n; char s[81];
	in = fopen("in.dat", "r");
	out = fopen("out.dat", "w");
	for (i = 0; i < 10; i++) {
		fscanf(in, "%s", s);
		fscanf(in, "%d", &n);
		fun(s, n);
		fprintf(out, "%s\n", s);
	}
	fclose(in);
	fclose(out);
}
*/

/*
void  fun(char *a, int  n)
{
	char *b = a;
	int len = 0,count = 0;
	while (*(b++))
	{
		len++;
	}
	b--;
	while (*(--b) == '*')
	{
		count++;
	}
	if (n > 0 && n < count)
	{
		a += len;
		*(a - n) = '\0';
		return;
	}
	else
	{
		return;
	}
}

void main()
{
	char  s[81];  int  n;
	cout<<"Enter a string:\n";
	cin >> s;
	cout<<"Enter n :  ";
	cin>>n;
	fun(s, n);
	cout<<"The string after deleted:\n";
	cout<<s;
	system("pause");
}
*/

/*标答

void  fun(char *a, int  n)
{
	int i = 0, k = 0;
	char *p, *t;
	p = t = a;
	while (*(t++));
	t--;
	while (*(t--)=='*')
	{
		k++;
	}
	if (k > n)
	{
		while (*(p++)&&p < t + n + 1)
		{
			a[i] = *p;
			i++;
		}
		a[i] = '\0';
	}
}

void main()
{
	char  s[81];  int  n;
	cout << "Enter a string:\n";
	cin >> s;
	cout << "Enter n :  ";
	cin >> n;
	fun(s, n);
	cout << "The string after deleted:\n";
	cout << s;
	system("pause");
}

*/

/*
void main()
{
	int a, b, c;
	a = b = c = 0;
	a = (b = 3) = 1;

	cout << a << endl << b << endl << c << endl;
	cout << .2E0 << endl;
	system("pause");
}
*/

/*
int change(int * data)
{
	return (*data)++;
}

void main()
{
	int a = 8, b;
	b = (a >> 2) % 2;
	cout << a << endl << b << endl;
	system("pause");
}
*/

/*
void main()
{
	char a[] = "THIS", b[] = "OK", *c = b;
	cout << strlen(a) << ','
		<< sizeof(a) << ','
		<< strlen(c) << ','
		<< sizeof(c) << endl;
	system("pause");
}
*/

/*冒泡排序算法
void main()
{
	system("color f0");
	int a[10], i, j, t;
	printf("Input 10 numbers: \n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("\n");
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
}
*/

/*选择排序算法
void main()
{
	int a[10], i, j, k, x;
	printf("Input 10 numbers:\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("\n");
	for (i = 0; i < 9; i++)
	{
		k = i;
		for (j = i + 1; j < 10; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		if (i!=k)
		{
			x = a[i];
			a[i] = a[k];
			a[k] = x;
		}
	}
	printf("the sorted numbers:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
}
*/

/*
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define N 10

int fun(char *s)
{
	int i, j = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
		{
			j++;
		}
	}
	return j;
}

void main()
{
	system("color f0");
	//FILE *wf;
	char line[80] = { 0 };
	int num = 0;
	printf("Enter a string:\n");
	gets_s(line);
	num = fun(line);
	printf("The number of the word is:%d\n\n", num);
	//found
	//wf = fopen("out.dat", "w");
	//fprintf(wf, "%d", fun("a big car"));
	//fclose(wf);
	//found
	system("pause");
}
*/

/*
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define N 10

typedef struct ss
{
	char num[10];
	int s;
}STU;

void fun(STU a[], STU *s)
{
	int i;
	*s = a[0];
	for (i = 0; i < N; i++)
	{
		if (s->s > a[i].s)
		{
			*s = a[i];
		}
	}
}

void main()
{
	system("color f0");
	STU a[N] = {
		{"A01",81},{"A02",89},{"A03",66},{"A04",87},{"A05",77},
	{"A06",90},{"A07",79},{"A08",61},{"A09",80},{"A10",71}
	}, m;
	int i;
	printf("***** The original data *****\n");
	for (i = 0; i < N; i++)
	{
		printf("No = %s Mark = %d\n", a[i].num, a[i].s);
	}
	fun(a, &m);
	printf("***** The result *****\n");
	printf("The lowest : %s,%d\n", m.num, m.s);
	system("pause");
}
*/

/*
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

void fun(int a[][N], int m)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			a[i][j] *= m;
		}
	}
}

void main()
{
	system("color f0");
	int a[N][N], m, i, j;
	printf("*** The array***\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			a[i][j] = rand() % 20;
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	m = rand() % 4;
	printf("m=%4d\n", m);
	fun(a, m);
	printf("THE RESULT\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
}
*/

/*
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define N 5

double fun(int w[][N])
{
	int x, y, z = 0;
	double sum = 0;
	for (x = 0; x < N; x++)
	{
		for (y = 0; y < N; y++)
		{
			if ((x == 0) || (x == N - 1) || (y == 0) || (y == N - 1))
			{
				sum += (double)w[x][y];
				z++;
			}
		}
	}
	return sum / z;
}

void main()
{
	system("color f0");
	int a[N][N] = { 0,1,2,7,9,1,9,7,4,5,2,3,8,3,1,4,5,6,8,2,5,9,1,4,1 };
	int i, j;
	double s;
	system("cls");
	printf("***The array***\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	s = fun(a);
	printf("***The result***\n");
	printf("The sum is: %lf\n", s);
	system("pause");
}
*/

/*
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

float fun(float h)
{
	if (h > 0)
	{
		int temp = (int)(1000 * h + 5) / 10;
		return (float)temp / 100.0;
	}
	else
	{
		return 0;
	}
}

void main()
{
	system("color f0");
	float a;
	printf("Enter a: ");
	scanf_s("%f", &a);
	printf("The original data is: ");
	printf("%f\n\n", a);
	printf("The resul: %f\n", fun(a));
	system("pause");
}
*/

/*
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void fun(int array[3][3])
{
	int t;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			t = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = t;
		}
	}
}

void main()
{
	system("color f0");
	int i, j;
	int array[3][3] = {
		{100,200,300},{400,500,600},{700,800,900}
	};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%7d", array[i][j]);
		}
		printf("\n");
	}
	fun(array);
	printf("Converted array:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%7d ", array[i][j]);
		}
		printf("\n");
	}
	system("pause");
}
*/

/*
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int fun(int lim, int aa[MAX])
{
	int i, j, k = 0;
	for (i = 2; i <= lim; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j >= i)
		{
			aa[k++] = i;
		}
	}
	return k;
}

void main()
{
	system("color f0");
	int limit, i, sum;
	int aa[MAX];
	printf("请输入一个整数:");
	scanf_s("%d", &limit);
	sum = fun(limit, aa);
	for (i = 0; i < sum; i++)
	{
		if (i % 10 == 0 && i != 0)//每行输出10个数
		{
			printf("\n");
		}
		printf("%5d", aa[i]);
	}
	system("pause");
}
*/

/*
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *fun(char(*a)[81], int num, char *max)
{
	max = a[0];
	for (int i = 1; i < num; i++)
	{
		if (strlen(max) < strlen(a[i]))
		{
			max = a[i];
		}
	}
	return max;
}

void main()
{
	system("color f0");
	char ss[10][81], *ps = NULL;
	char s[3][81] = {
		"abcd","deg","diegns"
	}, *p = NULL;
	int i = 0, n;
	printf("请输入若干个字符串:");
	gets_s(ss[i]);
	puts(ss[i]);
	while (!strcmp(ss[i], "****") == 0)
	{
		i++;
		gets_s(ss[i]);
		puts(ss[i]);
	}
	n = i;
	ps = fun(ss, n, ps);
	printf("\nmax=%s\n", ps);
	system("pause");
}
*/

/*
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>

//void fun(char *str)
//{
	//char *p1 = str;
	//while (*(p1)!=' '&&*(p1+1)!='\0')
	//{
		//if (*(p1 + 1) == ' ')
		//{
			//char *p2 = p1;
			//while (*(p2 + 2) != '\0')
			//{
				//*(p2 + 1) = *(p2 + 2);
				//p2++;
			//}
			//*(++p2) = '\0';
		//}
		//p1++;
	//}
//}

void fun(char *str)
{
	int i = 0;
	char *p = str;
	while (*p)
	{
		if (*p != ' ')
		{
			str[i++] = *p;
		}
		p++;
	}
	str[i] = '\0';
}

void main()
{
	system("color f0");
	char str[81];
	char Msg[] = "Input a string:";
	int n;
	printf(Msg);
	gets_s(str);
	puts(str);
	fun(str);
	printf("*** str: %s\n", str);
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class A
{
private:
	int a;
public:
	void setA(int i)
	{
		a = i;
	}
	void showA()
	{
		cout << "a=" << a << endl;
	}
};

class B
{
private:
	int b;
public:
	void setB(int i)
	{
		b = i;
	}
	void showB()
	{
		cout << "b=" << b << endl;
	}
};

void main()
{
	system("color f0");

	A a, *pa;
	B b, *pb;
	pa = &a;
	pa->setA(100);
	pa->showA();
	pb = (B*)pa;
	pb->setB(200);
	pb->showB();

	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class A
{
public:
	virtual void show();
};

class B
	:public A
{
public:
	void show();
};

void A::show()
{
	cout << "A::show\n";
}

void B::show()
{
	cout << "B::show\n";
}

void main()
{
	system("color f0");

	A a, *pa;
	B b;
	pa = &a;
	pa->show();
	pa = &b;
	pa->show();//没有virtual则输出A::show

	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base ::constructor\n";
	}
	virtual	~Base()
	{
		cout << "Base::destructor\n";
	}
};

class Derived
	:public Base
{
public:
	Derived()
	{
		cout << "Derived::constructor\n";
	}
	~Derived()
	{
		cout << "Derived:destructor\n";
	}
};

void main()
{
	system("color f0");

	Base *pBase = new Derived;
	//...
	delete pBase;

	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class CShape
{
protected:
	double s;
public:
	CShape()
	{
		s = 0;
	}
	virtual double area() = 0;
};

class CCircle
	:public CShape
{
private:
	double r;
public:
	CCircle(double x)
	{
		r = x;
	}
	double area()
	{
		s = 3.14159*r*r;
		return s;
	}
};

void main()
{
	system("color f0");
	CShape *pCShape;
	CCircle circle(45);
	pCShape = &circle;
	cout << "area=" << pCShape->area() << endl;
	system("pause");
}
*/

/*
class CShape
{
protected:
	double s;
private:
	CShape()
	{
		s = 0;
	}
	virtual ~CShape() = 0;
	virtual double area()
	{
		return s;
	}
};

CShape::~CShape(){}
*/

/*
#include<iostream>

using namespace std;

class Box
{
private:
	int height, width, depth;
public:
	Box()
	{
		height = 0;
		width = 0;
		depth = 0;
	}
	Box(int ht, int wd, int dp)
	{
		height = ht;
		width = wd;
		depth = dp;
	}
	int volume()
	{
		return height * width*depth;
	}
};

void main()
{
	system("color f0");
	Box box1;
	Box box2(10, 15, 20);
	cout << "volume1=" << box1.volume()
		<< ", volume2=" << box2.volume()
		<< endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class Test
{
public:
	void print()const;
	void print();
};

void Test::print()const
{
	cout << "const print!" << endl;
}

void Test::print()
{
	cout << "print!" << endl;
}

void main()
{
	system("color f0");
	const Test a;
	a.print();
	Test b;
	b.print();
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class Complex
{
public:
	float r, i;
	Complex(float x = 0, float y = 0)
	{
		r = x, i = y;
	}
};

Complex operator+(Complex c1, Complex c2)
{
	Complex temp;
	temp.r = c1.r + c2.r;
	temp.i = c1.i + c2.i;
	return temp;
}

void main()
{
	system("color f0");
	Complex complex1(3.56f, 3.8f), complex2(12.8f, -5.2f);
	Complex complex;
	complex = complex1 + complex2;
	if (complex.i > 0)
	{
		cout << complex.r << '+ '
			<< complex.i << 'i'
			<< endl;
	}
	else if (complex.i < 0)
	{
		cout << complex.r << complex.i << 'i' << endl;
	}
	else
	{
		cout << complex.r << endl;
	}
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class Complex
{
private:
	float r, i;
public:
	Complex(float x = 0, float y = 0)
	{
		r = x, i = y;
	}
	Complex operator+(Complex);
	void display()
	{
		if (i < 0)
		{
			cout << r << '+ '
				<< i << 'i'
				<< endl;
		}
		else if (i < 0)
		{
			cout << r
				<< i << 'i'
				<< endl;
		}
		else
		{
			cout << r << endl;
		}
	}
};

Complex Complex::operator+(Complex other)
{
	Complex temp;
	temp.r = this->r + other.r;
	temp.i = this->i + other.i;
	return temp;
}

void main()
{
	system("color f0");
	Complex complex1(3.56f, 3.8f), complex2(12.8f, -5.2f);
	Complex complex;
	complex = complex1 + complex2;
	complex.display();
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class Counter
{
private:
	int value;
public:
	Counter()
	{
		value = 0;
	}
	Counter operator++();
	Counter operator++(int);
	void display()
	{
		cout << "the value is " << value << endl;
	}
};

Counter Counter::operator++()
{
	value++;
	return *this;
}

Counter Counter::operator++(int i)
{
	Counter temp;
	temp.value = value++;
	return temp;
}

void main()
{
	system("color f0");
	Counter obj1, obj2;
	//obj2 = obj1++;
	obj2 = obj1.operator++(0);
	obj1.display();
	obj2.display();
	//obj2 = ++obj1;
	obj2 = obj1.operator++();
	obj1.display();
	obj2.display();
	system("pause");
}
*/

/*
#include<iostream>
#include<cstdlib>
#include<Windows.h>

using namespace std;

class Integer
{
private:
	int *array;
	int len;
public:
	Integer(int size)
	{
		len = size;
		array = new int[size];
	}
	int & operator[](int i);
	~Integer()
	{
		delete[]array;
	}
};

int &Integer::operator[](int i)
{
	if (i<0 || i>len - 1)
	{
		cout << "error: leap the pale!" << endl;
		Sleep(3000);
		exit(1);
	}
	return array[i];
}

void main()
{
	system("color f0");
	Integer arr(10);
	int i;
	for (i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
		cout << arr[i] << ' ';
	}
	cout << endl;
	cout << arr[i] << endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

template<class T>

T abs(T val)
{
	return  (val<0) ? -val : val;
}

void main()
{
	system("color f0");
	int i = 100;
	cout << abs(i) << endl;
	long l = -12345L;
	cout << abs(l) << endl;
	float f = -125.78F;
	cout << abs(f) << endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

template<class T1,class T2>

T1 Max(T1 x, T2 y)
{
	return (x >= y) ? x : (T1)y;
}

void main()
{
	int i = 100;
	float f = 127.25F;
	cout << Max(i, f) << endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

template<class T1,class T2>

class MyTemClass
{
private:
	T1 x;
	T2 y;
public:
	MyTemClass(T1 a, T2 b)
	{
		x = a;
		y = b;
	}
	void ShowMax()
	{
		cout << "MaxMember=" << ((x >= y) ? x : y) << endl;
	}
};

void main()
{
	system("color f0");
	int a = 100;
	float b = 123.45F;
	MyTemClass<int, float> mt(a, b);
	mt.ShowMax();
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class A
{
public:
	virtual void f1() {};
};

class B
	:public A
{
public:
	void f1() {};
};

void main()
{
	A *pAA = new A;
	A *pAB = new B;
	B *pB1 = dynamic_cast<B*>(pAA);
	B *pB2 = dynamic_cast<B*>(pAB);
	cout << "pB1=" << pB1 << ", pB2=" << pB2 << endl;
	system("pause");
}
*/

/*
#include<typeinfo.h>
#include<iostream>

using namespace std;

class Base
{
	virtual void fun(){}
};

class Derived
	:public Base
{

};

void main()
{
	Derived deri;
	Derived *pDeri = &deri;
	Base *pBase = &deri;
	cout << typeid(pDeri).name() << endl;
	cout << typeid(*pDeri).name() << endl;
	cout << typeid(pBase).name() << endl;
	cout << typeid(*pBase).name() << endl;
	cout << typeid(deri).name() << endl;
	int i = 12345;
	cout << typeid(i).name() << endl;
	if (typeid(i) != typeid(float))
	{
		cout << "Type of i is not float." << endl;
	}
	if (typeid(i) == typeid(int))
	{
		cout << "Type of i is int." << endl;
	}
	if (typeid(i) == typeid(123))
	{
		cout << "Type of i is int." << endl;
	}
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class TDshape
{
protected:
	double s;
public:
	TDshape()
	{
		s = 0;
	}
	virtual double area() = 0;
	virtual void printName() = 0;
};

class Triangle
	:public TDshape
{
private:
	double width, height;
public:
	Triangle(double a, double h) :width(a), height(h) {};
	double area()
	{
		s = width * height / 2;
		return s;
	}
	void printName()
	{
		cout << "Triangle";
	}
	void getWidth()
	{
		cout << "The width of the triangle is "
			<< width << '.'
			<< endl;
	}
	void setWidth()
	{
		cout << "Please give the width a value: ";
		cin >> width;
	}
};

class Rectangle
	:public TDshape
{
private:
	double width, height;
public:
	Rectangle(double a, double b)
	{
		width = a, height = b;
	}
	double area()
	{
		s = width * height;
		return s;
	}
	void printName()
	{
		cout << "Rectangle";
	}
	void getHeight()
	{
		cout << "The height of the rectangle is "
			<< height << endl;
	}
	void setHeight()
	{
		cout << "Please give a value to the height: ";
		cin >> height;
	}
};

void main()
{
	system("color f0");
	TDshape *pTDshape1, *pTDshape2;
	Triangle tri(10, 10);
	pTDshape1 = &tri;
	cout << "The area of the ";
	pTDshape1->printName();
	cout << " is " << pTDshape1->area()
		<< endl;
	Rectangle rec(20, 20);
	pTDshape2 = &rec;
	cout << "The area of the ";
	pTDshape2->printName();
	cout << " is " << pTDshape2->area()
		<< endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<string>

using namespace std;

class Person
{
protected:
	string name;
	string id;
	int age;
	string sex;
public:
	Person(string na, string id, int age, string sex)
		:name(na), id(id), age(age), sex(sex) {};
	virtual float getPay() = 0;
	virtual void print()
	{
		cout << "name: " << name << '\n'
			<< "id: " << id << '\n'
			<< "age: " << age << '\n'
			<< "sex: " << sex << endl;
	}
};

class Boss
	:public Person
{
private:
	float time;
public:
	Boss(string na, string id, int age, string sex, float time)
		:Person(na, id, age, sex), time(time){}
	float getPay()
	{
		return time * 150000;
	}
	void print()
	{
		Person::print();
		cout << "time: " << time << " y\n"
			<< "salary: " << getPay()
			<< endl;
	}
	void get_time()
	{
		cout << "time: " << time << " y" << endl;
	}
	void get_salary()
	{
		cout << "salary: " << getPay() << endl;
	}
};

class Employee
	:public Person
{
private:
	float basic, prize, time;
public:
	Employee(string na, string id, int age, string sex, float time, float basic, float prize)
		:Person(na, id, age, sex), time(time), basic(basic), prize(prize) {}
	float getPay()
	{
		return time * (basic + prize);
	}
	void print()
	{
		Person::print();
		cout << "time: " << time << " month(s)\n"
			<< "basic salary: " << basic << '\n'
			<< "prize: " << prize << endl;
	}
	void get_time()
	{
		cout << "time: " << time << " month(s)\n";
	}
	void get_basic()
	{
		cout << "basic salary: " << basic << '\n';
	}
	void get_prize()
	{
		cout << "prize: " << prize << endl;
	}
};

class HourlyWoker
	:public Person
{
private:
	float time, price;
public:
	HourlyWoker(string na, string id, int age, string sex, float time, float price)
		:Person(na, id, age, sex), time(time), price(price) {};
	float getPay()
	{
		return time * price;
	}
	void print()
	{
		Person::print();
		cout << "time: " << time << " h\n"
			<< "price: " << price << endl;
	}
	void get_time()
	{
		cout << "time: " << time << " h\n";
	}
	void get_price()
	{
		cout << "price: " << price << endl;
	}
};

class CommWoker
	:public Person
{
private:
	float basic, profit, time;
public:
	CommWoker(string na, string id, int age, string sex, float time, float basic, float profit)
		:Person(na, id, age, sex), time(time), basic(basic), profit(profit) {}
	float getPay()
	{
		return time * (basic + (0.05)*profit);
	}
	void print()
	{
		Person::print();
		cout << "time: " << time << " month(s)\n"
			<< "basic salary: " << basic << '\n'
			<< "profit: " << profit << endl;
	}
	void get_time()
	{
		cout << "time: " << time << " month(s)\n";
	}
	void get_basic()
	{
		cout << "basic salary: " << basic << '\n';
	}
	void get_profit()
	{
		cout << "profit: " << profit << endl;
	}
};
*/

/*
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class CShp
{
protected:

public:
	virtual void get_shape() = 0;
	virtual void get_preserved() = 0;
	virtual void get_read() = 0;
};

class CPt
	:public virtual CShp
{
protected:
	double m_x, m_y;
	int m_ID;
public:
	CPt() {};
	CPt(double x, double y, int i) :m_x(x), m_y(y), m_ID(i) {};
	void get_shape()
	{
		cout << "point" << endl;
	}
	void get_preserved()
	{
		ofstream outfile("out.txt", ios::out);
		CPt point;
		cout << "Please input values of x, y, id." << endl;
		cin >> point.m_x >> point.m_y >> point.m_ID;
		outfile << "point" << endl
			<< "m_x: " << point.m_x
			<< "\tm_y: " << point.m_y
			<< "\tm_ID: " << point.m_ID;
		outfile.close();
	}
	void get_read()
	{
		ifstream infile("in.txt", ios::in);
		CPt point;
		string str;
		infile >> str;
		infile >> point.m_x >> point.m_y >> point.m_ID;
		infile.close();
	}
};

class CLn
	:public virtual CShp
{
protected:
	CPt *m_linePts;
	int numPts, m_ID;
public:
	CLn() {};
	CLn(CPt *p, int n, int id) :m_linePts(p), numPts(n), m_ID(id) {};
	void get_shape()
	{
		cout << "line" << endl;
	}
	void get_preserved()
	{
		ofstream outfile("out.txt", ios::out);
		CLn line;
		int n, id;
		cout << "Please give a value to numPts: ";
		cin >> n;
		CPt *point = new CPt[n];
		line(point, n, id);
		outfile << "line" << endl
			<< "m_linePts: " << line.m_linePts
			<< "\tnumPts: " << line.numPts
			<< "\tm_ID: " << line.m_ID;
		outfile.close();
	}
	void get_read()
	{
		ifstream infile("in.txt", ios::in);
		CLn line;
		string str;
		infile >> str;
		line.m_linePts->get_read();
		infile>> line.numPts >> line.m_ID;
		infile.close();
	}
};

class CShDB
	:public CPt, public CLn
{
protected:

};
*/

/*
#include<iostream>

using namespace std;

struct A
{
	int i;
	char c;
};

void main()
{
	int num = 1;
	char *p1 = (char *)malloc(sizeof(char));
	for (; ; num++)
	{
		cout << "测试" << num << "开始" << endl;
		p1 = (char *)malloc(sizeof(char) * num * (1 << 20) * 10);
		if (!p1)
		{
			break;
		}
		free(p1);
	}
	cout << "系统的内存大约为: " << num * 10 << "M" << endl;


	num = 1;
	double *p2 = (double *)malloc(sizeof(double));
	for (; ; num++)
	{
		cout << "测试" << num << "开始" << endl;
		p2 = (double *)malloc(sizeof(double) * num * (1 << 20) * 10);
		if (!p2)
		{
			break;
		}
		free(p2);
	}
	cout << "系统的内存大约为: " << num * 80 << "M" << endl;


	num = 1;
	A *p3 = (A *)malloc(sizeof(A));
	for (; ; num++)
	{
		cout << "测试" << num << "开始" << endl;
		p3 = (A *)malloc(sizeof(A) * num * (1 << 20) * 10);
		if (!p3)
		{
			break;
		}
		free(p3);
	}
	cout << "系统的内存大约为: " << num * 50 << "M" << endl;


	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class Caculator
{
private:
	unsigned int count;
public:
	Caculator operator++()
	{
		count++;
		return *this;
	}
	Caculator operator++(int i)
	{
		Caculator C;
		C.count = count++;
		return C;
	}
	Caculator operator--()
	{
		count--;
		return *this;
	}
	Caculator operator--(int i)
	{
		Caculator C;
		C.count = count--;
		return C;
	}
	Caculator operator+(Caculator C)
	{
		Caculator CC;
		CC.count = count + C.count;
		return CC;
	}
};
*/

/*
#include<iostream>

using namespace std;

void main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void main()
{
	int num = 1;
	char *p1 = (char *)malloc(sizeof(char) * num * (1 << 120) * 10);
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class TwoCoord
{
private:
	double x, y;
public:
	TwoCoord()
	{
		x = y = 0;
	}
	TwoCoord(double x,double y):x(x),y(y){}
	friend double get_distance(TwoCoord t1, TwoCoord t2);
	friend ostream &operator<<(ostream &os, TwoCoord &t);
	friend istream &operator>>(istream &is, TwoCoord &t);
	TwoCoord operator+(TwoCoord t1)
	{
		TwoCoord t2;
		t2.x = x + t1.x;
		t2.y = y + t1.y;
		return t2;
	}
	TwoCoord operator-(TwoCoord t1)
	{
		TwoCoord t2;
		t2.x = x - t1.x;
		t2.y = y - t1.y;
		return t2;
	}
};

double get_distance(TwoCoord t1, TwoCoord t2)
{
	TwoCoord t3 = t1 - t2;
	return sqrt((t3.x)*(t3.x) + (t3.y)*(t3.y));
}

ostream &operator<<(ostream &os, TwoCoord &t)
{
	os << "x = " << t.x
		<< "\ty = " << t.y
		<< endl;
	return os;
}

istream &operator>>(istream &is, TwoCoord &t)
{
	cout << "请输入二维坐标(x,y): " << endl;
	is >> t.x >> t.y;
	return is;
}

void main()
{
	TwoCoord t1, t2(1, 2), t3(2, 1), t4, t5, t6;
	t4 = t2 + t3;
	cout << t4 << endl;
	t5 = t2 - t3;
	cout << t5 << endl;
	cin >> t1 >> t6;
	cout << endl;
	cout << get_distance(t1, t6) << endl;
	cout << endl;
	cout << t1 << t6;
	system("pause");
}
*/

/*
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main()
{
	ofstream outfile("C:\\C语言文件\\student.dat", ios::out);
	string name;
	char id[8];
	int math, eng, computer;
	cout << "输入姓名:\t";
	cin >> name;
	cout << "输入身份证号:\t";
	cin >> id;
	cout << "输入数学成绩:\t";
	cin >> math;
	cout << "输入英语成绩:\t";
	cin >> eng;
	cout << "输入计算机成绩:\t";
	cin >> computer;
	outfile << name << " " << id << " "
		<< math << " " << eng << " " << computer << " "
		<< endl;
	outfile.close();
	system("pause");
}
*/

/*
#include<iostream>
#include"Stack.h"

using namespace std;

void main()
{
	Stack s1;
	s1.Push(1);
	s1.Push(12);
	s1.Push(32);
	int x1 = s1.Pop();
	int x2 = s1.Pop();
	int x3 = s1.Pop();
	cout << x1 << "\t"
		<< x2 << '\t'
		<< x3 << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class CShp
{
public:
	virtual void get_shape() = 0;
	virtual void get_preserved() = 0;
	virtual void get_read() = 0;
};

class CPt
	:public virtual CShp
{
protected:
	double m_x, m_y;
	int m_ID;
public:
	CPt() {};
	CPt(double x, double y, int i) :m_x(x), m_y(y), m_ID(i) {};
	void get_shape()
	{
		cout << "point" << endl;
	}
	void get_preserved()
	{
		ofstream outfile("out.txt", ios::out);
		CPt point;
		cout << "Please input values of x, y, id." << endl;
		cin >> point.m_x >> point.m_y >> point.m_ID;
		outfile << "point" << endl
			<< "m_x: " << point.m_x
			<< "\tm_y: " << point.m_y
			<< "\tm_ID: " << point.m_ID;
		outfile.close();
	}
	void get_read()
	{
		ifstream infile("in.txt", ios::in);
		CPt point;
		string str;
		infile >> str;
		infile >> point.m_x >> point.m_y >> point.m_ID;
		infile.close();
	}
};

class CLn
	:public virtual CShp
{
protected:
	CPt *m_linePts;
	int numPts, m_ID;
public:
	CLn() {};
	CLn(int n, int id, CPt *p) : numPts(n), m_ID(id), m_linePts(p) {};
	void get_shape()
	{
		cout << "line" << endl;
	}
	void get_preserved()
	{
		ofstream outfile("out.txt", ios::out);
		int n, id;
		cout << "Please give a value to numPts: ";
		cin >> n;
		CPt *point = new CPt[n];
		CLn line(n, id, point);
		outfile << "line" << endl
			<< "\tnumPts: " << line.numPts
			<< "\tm_ID: " << line.m_ID
			<< "m_linePts: " << line.m_linePts;
		outfile.close();
	}
	void get_read()
	{
		ifstream infile("in.txt", ios::in);
		CLn line;
		string str;
		infile >> str;
		infile >> line.numPts >> line.m_ID;
		line.m_linePts->get_read();
		infile.close();
	}
};

template<class T>
class CShpDB
{
public:
	int count;
	CShp *p = new CShp[count];
	T * Create(string str)
	{
		if (str == "point")
		{
			CPt *p;
			T = CPt;
			return p;
		}
		else if (str == "line")
		{
			CLn *p;
			T = CLn;
			return p;
		}
		else
		{
			int *p;
			T = int;
			return p;
		}
	}
	void Save(string str)
	{
		if (str == "point")
		{
			CPt::get_preserved();
		}
		else if (str == "line")
		{
			CLn::get_preserved();
		}
	}
	void Read(string str)
	{
		if (str == "point")
		{
			CPt::get_read();
		}
		else if (str == "line")
		{
			CLn::get_read();
		}
	}
};
*/

/*
#include<iostream>

using namespace std;

#define N 80

int fun(const char *str)
{
	char *p, *q;
	p = (char*)str;
	q = (char*)str;
	while (*(++q)) {};
	q--;
	for (; q >= p; )
	{
		if (*(p++) == *(q--))
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

void main()
{
	char s[N];
	const char *test[] = { "1234321","123421","123321","abcdCBA" };
	cout << "Enter a string:" << endl;
	gets_s(s);
	cout << endl << endl;
	puts(s);
	if (fun(s))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		if (fun(test[i]))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

#define M 3
#define N 5

void fun(int(*a)[N], int k)
{
	int i, j, p, temp;
	for (p = 1; p <= k; p++)
	{
		for (i = 0; i < M; i++)
		{
			temp = a[i][0];
			for (j = 0; j < N - 1; j++)
			{
				a[i][j] = a[i][j + 1];
			}
			a[i][N - 1] = temp;
		}
	}
}

void main()
{
	system("color f0");
	int x[M][N] = {
		{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}
	}, i, j;
	cout << "The array before moving:" << endl << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << "\t" << x[i][j];
		}
		cout << endl;
	}
	fun(x, 2);
	cout << "The array after moving:" << endl << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << "\t" << x[i][j];
		}
		cout << endl;
	}
	system("pause");
}
*/

/*
#include<conio.h>
#include<iostream>

using namespace std;

#define M 10

int a[M][M] = { 0 };

void fun(int **a, int m)
{

}

void main()
{
	system("color f0");
	int i, j, n;
	cout << "Enter n: ";
	cin >> n;
	fun(a, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << '\t' << a[i][j];
		}
		cout << endl;
	}
	system("pause");
}
*/

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class Operation
{
private:
	double A, B;
public:
	double GetA() const { return A; }
	double GetB() const { return B; }
	void SetA(double x) { A = x; }
	void SetB(double y) { B = y; }
	double virtual GetResult() { return 0; }
	Operation() :A(0), B(0) {}
};

class Add : public Operation
{
public:
	double GetResult()
	{
		return GetA() + GetB();
	}
};

class Sub : public Operation
{
public:
	double GetResult()
	{
		return GetA() - GetB();
	}
};

class Mul : public Operation
{
public:
	double GetResult()
	{
		return GetA()*GetB();
	}
};

class Div : public Operation
{
public:
	double GetResult()
	{
		return GetA() / GetB();
	}
};

class SimpleFactory
{
public:
	static Operation * CreateOpeartor(char ch)
	{
		Operation * p = NULL;
		switch (ch)
		{
		case '+':
			p = new Add();
			break;
		case '-':
			p = new Sub();
			break;
		case '*':
			p = new Mul();
			break;
		case '/':
			p = new Div();
			break;
		}
		return p;
	}
};

int main(int argc, char *argv[])
{
	double A = 0;
	double B = 0;
	char ch = '\0';
	cin >> A >> ch >> B;

	tr1::shared_ptr<Operation> op(SimpleFactory::CreateOpeartor(ch));
	op->SetA(A);
	op->SetB(B);
	cout << op->GetResult() << endl;
}
*/

/*
#include<iostream>

using namespace std;

template<class T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

template<>
char *max<char *>(char *a, char *b)
{
	return (strcmp(a, b) >= 0) ? a : b;
}

void main()
{
	system("color f0");
	float c = 5.1, d = 3.2;
	cout << "2, 3.2 的最大值是: " << max(3, 2) << endl;
	cout << "a, c 的最大值是: " << max('a', 'c') << endl;
	cout << " \"xbv\", \"xyce\" 的最大值是: " << max("xbv", "xyce") << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<string>

using namespace std;

const int Size = 5;

template<class T>
class Array
{
private:
	T a[Size];
public:
	Array()
	{
		for (int i = 0; i < Size; i++)
		{
			a[i] = 0;
		}
	}
	T &operator[](int i);
	void sort();
};

template<class T>
T &Array<T>::operator[](int i)
{
	if (i<0 || i>Size - 1)
	{
		cout << "\n数组下标越界!" << endl;
		exit(1);
	}
	return a[i];
}

template<class T>
void Array<T>::sort()
{
	for (int i = 0; i < Size; i++)
	{
		int p = i;

		for (int j = i + 1; j < Size; j++)
		{
			if (a[p] < a[j])
			{
				p = j;
			}
		}
		T t = a[p];
		a[p] = a[i];
		a[i] = t;
	}
}

template<>
void Array<char *>::sort()
{
	for (int i = 0; i < Size; i++)
	{
		int p = i;
		for (int j = i + 1; j < Size; j++)
		{
			if (strcmp(a[p], a[i]) < 0)
			{
				p = j;
			}
		}
		char * t = a[p];
		a[p] = a[i];
		a[i] = t;
	}
}

void main()
{
	system("color f0");
	Array<int> a1;
	Array<char * > b1;
	a1[0] = 1;
	a1[1] = 23;
	a1[2] = 6;
	a1.sort();
	for (int i = 0; i < 5; i++)
	{
		cout << a1[i] << "\t";
	}
	cout << endl;
	b1[0] = "x1";
	b1[1] = "ya";
	b1[2] = "ad";
	b1[3] = "be";
	b1[4] = "bc";
	b1.sort();
	for (int i = 0; i < 5; i++)
	{
		cout << b1[i] << "\t";
	}
	cout << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<vector>//向量头文件

using namespace std;

void display(vector<int> &v)
{
	while (!v.empty())
	{
		cout << v.back() << "\t";//输出向量的尾部元素
		v.pop_back();//删除向量尾部元素
	}
	cout << endl;
}

void main()
{
	int a[] = { 1,2,3,4,5,6 };
	vector<int> v1, v2;//定义只有0个元素的向量v1, v2
vector<int> v3(a, a + 6);//定义向量v3,并用a数组初始化该向量
vector<int> v4(6);//定义具有6个元素的向量v4
v1.push_back(10);//在v1向量的尾部加入元素10
v1.push_back(11);
v1.push_back(12);
v1.insert(v1.begin(), 30);//将30插入到v1向量的最前面
v2 = v1;//将v1赋值给v2，v2与v1具有相同的元素
v3.assign(3, 10);//将v3的前3个元素都设置为10//
cout << "v1: ";
display(v1);//用数组的方式访问向量元素//
cout << "v2: ";
display(v2);
cout << "v3: ";
display(v3);
v4[0] = 10;
v4[1] = 20;
v4[2] = 30;
v4[3] = 40;
cout << "v4: ";
for (int i = 0; i < 6; i++)
{
	cout << v4[i] << '\t';
}
cout << endl;
v4.resize(10);//重置向量v4的大小，已有元素不受影响
cout << "v4: ";
display(v4);
system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void main()
{
	cout << "1-before try block..." << endl;
	try
	{
		cout << "2-Inside try block..." << endl;
		throw 10;
		cout << "3-After throw ..." << endl;
	}
	catch (int i)
	{
		cout << "4-In catch block1 ... exception..errcode is.." << i << endl;
	}
	catch (char *s)
	{
		cout << "5-In catch block2 ... exception..errcode is.." << s << endl;
	}
	cout << "6-After Catch..." << endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void temperature(int t)
{
	try
	{
		if (t==100)
		{
			throw"沸点! ";
		}
		else if (t==0)
		{
			throw"冰点! ";
		}
		else
		{
			//cout << "the temperature is OK..." << endl;
			throw "the temperature is OK...";
		}
	}
	//catch (int x)
	//{
	//	cout << "temperature=" << x << endl;
	//}
	catch (char *s)
	{
		cout << "wrong"<< endl;
	}
}

void main()
{
	temperature(0);
	temperature(10);
	temperature(100);
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void Errhandler(int n)throw()
{
	try
	{
		if (n == 1)
		{
			throw n;
		}
		if (n==2)
		{
			throw "dx";
		}
		if (n==3)
		{
			throw 1.1;
		}
	}
	catch (...)
	{
		cout << "catch an exception..." << endl;
	}
}

void main()
{
	Errhandler(1);
	Errhandler(2);
	Errhandler(3);
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void Errhandler(int n)throw()
{
	try
	{
		if (n==1)
		{
			throw n;
		}
		cout << "all is ok..." << endl;
	}
	catch (int n)
	{
		cout << "catch an int exception inside..." << n << endl;
		throw;
	}
}

void main()
{
	try
	{
		Errhandler(1);
	}
	catch (int x)
	{
		cout << "catch int an exception in main..." << x << endl;
	}
	cout << "...End..." << endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void fc()
{
	try
	{
		throw"help...";
	}
	catch (int x)
	{
		cout << "in fc...int handler" << endl;

	}
	try
	{
		cout << "no error handle..." << endl;
	}
	catch(char *px)
	{
		cout << "in fc....char*handler" << endl;
	}
}

void fb()
{
	int *q = new int[10];
	try
	{
		fc();
		cout << "return from fc()" << endl;
	}
	catch (...)
	{
		delete[]q;
		throw;
	}
}
void fa()
{
	char *p = new char[10];
	try
	{
		fb();
		cout << "return from fb()" << endl;
	}
	catch (...)
	{
		delete[]p;
		throw;
	}
}

void main()
{
	try
	{
		fa();
		cout << "return from fa" << endl;
	}
	catch (...)
	{
		cout << "in main" << endl;
		cout << "End" << endl;
	}
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

class A
{
public:
	A(int i = 0) :a(i) {};
	~A()
	{
		cout << "in A destructor..." << endl;
	}
private:
	int a;
};

class B
{
public:
	B(int k)
	{
		cout << "int B constructor..." << endl;
		for (int i = 0; i < 10; i++)
		{
			pb[i] = new double[2<<25];
			if (pb[i] == 0)
			{
				throw i;
			}
			else
			{
				cout << "Allocated 2<<27 doubles in pb[" << i << "]" << endl;
			}
		}
	}
private:
	A obj[3];
	double *pb[10];
};

void main()
{
	try
	{
		B b(2);
	}
	catch (int e)
	{
		cout << "catch an exception when allocated pb[" << e << "]" << endl;
	}
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

const int MAX = 3;

class FULL{};

class EMPTY{};

class Stack
{
public:
	void push(int a);
	int pop();
	Stack()
	{
		top = -1;
	}
private:
	int s[MAX];
	int top;
};

void Stack::push(int a)
{
	if (top>=MAX-1)
	{
		throw FULL();
	}
	s[++top] = a;
}

int Stack::pop()
{
	if (top<0)
	{
		throw EMPTY();
	}
	return s[top--];
}

void main()
{
	Stack s;
	try
	{
		s.push(10);
		s.push(20);
		s.push(30);
		//s.push(40);
		cout << "stack(0)= " << s.pop() << endl;
		cout << "stack(1)= " << s.pop() << endl;
		cout << "stack(2)= " << s.pop() << endl;
		cout << "stack(3)= " << s.pop() << endl;
	}
	catch (FULL)
	{
		cout << "Exception: Stack Full" << endl;
	}
	catch (EMPTY)
	{
		cout << "Exception: Stack Empty" << endl;
	}
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

const int MAX = 3;

class Full
{
public:
	Full(int i) :a(i) {};
	int getValue()
	{
		return a;
	}

private:
	int a;
};

class Empty{};

class Stack
{
public:
	Stack()
	{
		top = -1;
	}
	void push(int a)
	{
		if (top>=MAX-1)
		{
			throw Full(a);
		}
		s[++top] = a;
	}
	int pop()
	{
		if (top<0)
		{
			throw Empty();
		}
		return s[top--];
	}

private:
	int s[MAX];
	int top;
};

void main()
{
	Stack s;
	try
	{
		s.push(10);
		s.push(20);
		s.push(30);
		s.push(40);
	}
	catch (Full e)
	{
		cout << "Exception: Stack Full..." << endl
			<< "The value not push in stack: " << e.getValue() << endl;
	}
	system("pause");
}
*/

/*
#include<iostream>
#include<vector>//向量头文件

using namespace std;

void display(vector<int> &v)
{
	while (!v.empty())
	{
		cout << v.back() << "\t";//输出向量的尾部元素
		v.pop_back();//删除向量尾部元素
	}
	cout << endl;
}

void main()
{
	int a[] = { 1,2,3,4,5,6 };
	vector<int> v1, v2;//定义只有0个元素的向量v1, v2
	vector<int> v3(a, a + 6);//定义向量v3,并用a数组初始化该向量
	vector<int> v4(6);//定义具有6个元素的向量v4
	v1.push_back(10);//在v1向量的尾部加入元素10
	v1.push_back(11);
	v1.push_back(12);
	v1.insert(v1.begin(), 30);//将30插入到v1向量的最前面
	v2 = v1;//将v1赋值给v2，v2与v1具有相同的元素
	v3.assign(3, 10);//将v3的前3个元素都设置为10//
	cout << "v1: ";
	display(v1);//用数组的方式访问向量元素//
	cout << "v2: ";
	display(v2);
	cout << "v3: ";
	display(v3);
	v4[0] = 10;
	v4[1] = 20;
	v4[2] = 30;
	v4[3] = 40;
	cout << "v4: ";
	for (int i = 0; i < 6; i++)
	{
		cout << v4[i] << '\t';
	}
	cout << endl;
	v4.resize(10);//重置向量v4的大小，已有元素不受影响
	cout << "v4: ";
	display(v4);
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

template<class T, int num>
T max(T a[])
{
	T mid = a[0];
	for (int i = 0; i < num; i++) {
		if (mid < a[i])mid = a[i];
	}
	return mid;
}
template<int num>
char* max(char* a[])
{
	char*mid; mid = a[0];
	for (int i = 0; i < num; i++) {
		if (strcmp(mid, a[i]) < 0)//若 mid 小于a[i]返回负数
			mid = a[i];
	}
	return mid;
}

void main()
{
	int a[10] = { 6,3,4,8,94,24,4,44,8,-7 };
	char *pp[5];

	for (int i = 0; i < 5; i++) {
		pp[i] = new char[10];
		cin >> pp[i];
	}

	int maxi = max<int, 10>(a);
	char *maxch = max<5>(pp);

	cout << maxi << endl << maxch << endl;
	delete[]*pp;
	system("pause");
}
*/

/*
#include<iostream>
#include<stack>

using namespace std;

void main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.top() << "\t";
	s.pop();
	s.top() = 100;
	s.push(50);
	s.push(60);
	s.pop();
	while (!s.empty())
	{
		cout << s.top() << "\t";
		s.pop();
	}
	cout << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<string>

using namespace std;

void main()
{
	string s1 = "中华人民共和国成立了";
	string s2 = "中国人民从此站起来了!";
	string s3, s4, s5;
	s3 = s1 + ", " + s2;
	int n = s1.find_first_of("人民");
	if (n != string::npos)
	{
		cout << "人民在s1中的位置: " << n << endl;
	}
	else
	{
		cout << "在s1中没有该子串! ";
	}
	s4 = s1.substr(4, 10);
	cout << "s1= " << s1 << endl;
	cout << "s2= " << s2 << endl;
	cout << "s3= " << s3 << endl;
	cout << "s4= " << s4 << endl;
	if (s1>s2)
	{
		cout << "s1>s2 = true" << endl;
	}
	else
	{
		cout << "s1>s2 = false" << endl;
	}
	s3.replace(s3.find("从此"), 4, "从1949年");
	cout << "s3 after replace= " << s3 << endl;
	s3.insert(s3.find("站"), "10月");
	cout << "s3 after insert= " << s3 << endl;
	system("pause");
}
*/

/*
//链表迭代器应用举例

#include<iostream>
#include<list>

using namespace std;

void main()
{
	int i;
	list<int> L1, L2, L3(10);
	list<int>::iterator iter;//定义迭代器iter
	int a1[] = { 100,90,80,70,60 };
	int a2[] = { 30,40,50,60,60,60,80 };
	for (i = 0; i < 5; i++)
	{
		L1.push_back(a1[i]);
	}
	for (i = 0; i < 7; i++)
	{
		L2.push_front(a2[i]);
	}
	for (iter = L1.begin(); iter != L1.end(); iter++)
	{
		cout << *iter << '\t';
	}
	cout << endl;
	int sum = 0;
	//通过迭代器反向输出L2的所有元素
	for (iter = --L2.end(); iter != L2.begin(); iter--)
	{
		cout << *iter << '\t';
		sum += *iter;//计算L2所有链表节点的总和
	}
	cout << "\nL2.sum=" << sum << endl;
	int data = 0;
	//通过迭代器修改L3链表的内容
	for (iter  = L3.begin();iter!=L3.end() ;iter++)
	{
		*iter = data += 10;
	}
	for (iter=L3.begin();iter!=L3.end();iter++)
	{
		cout << *iter << '\t';
	}
	cout << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<string>
#include<set>

using namespace std;

void main()
{
	int a1[] = { -2,0,30,12,6,7,12,10,9,10 };
	set<int, greater<int >>set1(a1, a1 + 7);
	set<int, greater<int>>::iterator p1;
	set1.insert(12);//向集合插入元素
	set1.insert(12);
	set1.insert(4);
	for ( p1 = set1.begin(); p1 !=set1.end() ; p1++)
	{
		cout << *p1 << " ";//输出集合中的内容,是从大到小的
	}
	cout << endl;
	string a2[] = 
	{ 
		"杜明","王为","张青山","李大海","黄明洁","刘一","张三","林富海","王小二","张青山" 
	};
	multiset<string>set2(a2, a2 + 10);//定义字符串的multiset集合,默认排序从小到大
	multiset<string>::iterator p2;
	set2.insert("杜明");
	set2.insert("李则");
	for ( p2 = set2.begin(); p2 !=set2.end() ; p2++)
	{
		cout << *p2 << " ";//输出集合内容
	}
	cout << endl;
	string sname;
	cout << "输入要查找的姓名: ";
	cin >> sname;//输入要在集合中查找的姓名
	p2 = set2.begin();
	bool s = false;//s用于判定找到姓名与否
	while (p2!=set2.end())
	{
		if (sname==*p2)//如果找到就输出姓名
		{
			cout << *p2 << endl;
			s = true;
		}
		p2++;
	}
	if (!s)
	{
		cout << sname << "不在集合中!" << endl;//如果没有找到就给出提示
	}
	system("pause");
}
*/

/*
#include<iostream>
#include<string>
#include<map>

using namespace std;

void main()
{
	string name[] = { "张大年","刘明海","李煜" };//雇员姓名
	double salary[] = { 1200,2000,1450 };//雇员工资
	map<string, double>sal;//用映射存储姓名和工资
	map<string, double>::iterator p;//定义映射的迭代器
	for (int i = 0; i < 3; i++)
	{
		sal.insert(make_pair(name[i], salary[i]));//将姓名/工资加入映射
	}
	sal["tom"] = 3400;//通过下标运算加入map元素
	sal["bob"] = 2000;
	for (p = sal.begin(); p != sal.end(); p++)
	{
		cout << p->first << '\t' << p->second << endl;//输出元素的键和值
	}
	string person;
	cout << "输入查找人员的姓名: ";
	cin >> person;
	for (p = sal.begin(); p != sal.end(); p++)//据姓名查工资，找到就输出
	{
		if (p->first == person)
		{
			cout << p->second << endl;
		}
	}
	system("pause");
}
*/

/*
#include<iostream>
#include<string>
#include<map>

using namespace std;

void main()
{
	multimap<string, string>dict;
	multimap<string, string>::iterator p;
	string eng[] = { "polt","gorge","cliff","berg","precipice","tract" };
	string che[] = { "小块地","地点","峡谷","悬崖","冰山","一片,区域" };
	for (int i = 0; i < 6; i++)
	{
		dict.insert(make_pair(eng[i], che[i]));
	}
	dict.insert(make_pair(string("tract"), string("地带")));
	dict.insert(make_pair(string("precipice"), string("危险的处境")));
	for (p=dict.begin();p!=dict.end();p++)
	{
		cout << p->first << '\t' << p->second << endl;
	}
	string word;
	cout << "请输入要查找的英文单词: ";
	cin >> word;
	for (p = dict.begin(); p != dict.end(); p++)
	{
		if (p->first==word)
		{
			cout << p->second << endl;
		}
	}
	cout << "请输入要查找的中文单词: ";
	cin >> word;
	for (p = dict.begin(); p != dict.end(); p++)
	{
		if (p->second==word)
		{
			cout << p->first << endl;
		}
	}
	system("pause");
}
*/

/*
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void main()
{
	int arr[] = { 100,200,300,400,500,500,600,700,800,900,1000 };
	int *ptr;
	ptr = find(arr, arr + 9, 400);//查找400在arr数组中的地址
	cout << "数据在数组中的下标是: "
		<< ptr - arr << endl;//find返回地址
	list<int>L1;//定义链表L1
	int a1[] = { 30,40,50,60,60,60,80 };
	for (int i = 0; i < 7; i++)
	{
		L1.push_back(a1[i]);//将a1数组加入到L1链表中
	}
	list<int>::iterator pos;
	pos = find(L1.begin(), L1.end(), 80);
	if (pos!=L1.end())
	{
		cout << "L1链表中存在数据元素: "
			<< *pos;//输出找到的数据
	}
	cout << ", 它是链表中的第 "
		<< distance(L1.begin(), pos) + 1
		<< "个节点!" << endl;//distance计算迭代器与链首元素间隔的元素个数
	int n1 = count(arr, arr + 10, 500);//统计arr数组中500的个数
	int n2 = count(L1.begin(), L1.end(), 60);//统计L1链表中60的个数
	cout << "arr数组中有: " << n1 << "个" << 500 << endl;
	cout << "L1链表中有: " << n2 << "个" << 60 << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

void main()
{
	int a1[] = { 10,20,30,40,50,60,70,80 };
	int a2[] = { 40,50,60 };
	int *ptr;
	ptr = search(a1, a1 + 8, a2, a2 + 3);
	if (ptr==a1+8)
	{
		cout << "no match found\n";
	}
	else
	{
		cout << "a2 match a1 at:" << (ptr - a1) << endl;
	}
	vector<int>v;
	list<int>L;
	for (int i = 0; i < 8; i++)
	{
		v.push_back(a1[i]);
	}
	for (int j = 0; j < 3; j++)
	{
		L.push_back(a2[j]);
	}
	vector<int>::iterator pos;
	pos = search(v.begin(), v.end(), L.begin(), L.end());
	cout << distance(v.begin(), pos) << endl;
	system("pause");
}
*/

//问老师
/*
#include<iostream>
#include<list>//链表头文件

using namespace std;

void main()
{
	int i;
	list<int> L1, L2;
	int a1[] = { 100,90,80,70,60 };
	int a2[] = { 30,40,50,60,60,60,80 };
	for (i = 0; i < 5; i++)
	{
		L1.push_back(a1[i]);//将a1数组加入到L1链表中
	}
	for (i = 0; i < 7; i++)
	{
		L2.push_back(a2[i]);//将数组L2加入到L2链表中
	}
	L1.reverse();//将L1链表倒序
	L1.merge(L2);//将L2合并到链表L1中
	cout << "L1的元素的个数为: " << L1.size() << endl;
	L1.unique();//删除L1中相邻位置的相同元素，只留1个
	while (!L1.empty())
	{
		cout << L1.front() << '\t';//删除L1的链首元素
		L1.pop_front();
	}
	cout << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void main()
{
	int a1[] = { 10,20,30,40,50,60,70 };
	int a2[] = { 40,50,60 };
	int a[10];
	merge(a1, a1 + 7, a2, a2 + 3, a);//将a1、a2合并,结果放在a数组中
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << '\t';
	}
	cout << endl;
	list<int>L1, L2;
	list<int>::iterator pos;//pos迭代器用于输出链表元素
	for (int i = 0; i < 7; i++)
	{
		L1.push_back(a1[i]);//插入L1的链表元素
	}
	for (int j = 0; j < 3; j++)
	{
		L2.push_back(a2[j]);//插入L2的链表元素
	}
	L1.merge(L2);//用list的merge成员合并后的L1、L2
	for ( pos = L1.begin(); pos !=L1.end(); pos++)//用迭代器pos输出合并后的L1
	{
		cout << *pos << '\t';
	}
	cout << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void main()
{
	int a1[] = { 10,20,30,4,50,13,7 };
	int a2[] = { -2,0,30,12,6,7,-9,56,32,78 };
	sort(a1, a1 + 7);
	cout << "a1[]: ";
	for (int i = 0; i < 7; i++)
	{
		cout << a1[i] << '\t';
	}
	cout << endl;
	vector<int> L1;
	vector<int>::iterator pos;
	for (int i = 0; i < 10; i++)
	{
		L1.push_back(a2[i]);
	}
	sort(L1.begin(), L1.end());
	cout << "L2: ";
	for ( pos = L1.begin(); pos !=L1.end() ; pos++)
	{
		cout << *pos << '\t';
	}
	cout << endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void main()
{
	char c; 
	char a[50] = { 0 };
	char s1[100] = { 0 };
	cout << "use get() input char: ";
	while ((c=cin.get())!='\n')
	{
		cout << c;
	}
	cout << endl;
	cout << "use get(a,10) input char: ";
	cin.get(a, 10);
	cout << a << endl;
	cin.ignore(1);
	cout << "use getline(s,10) input char: ";
	cin.getline(s1, 10);
	cout << s1 << endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void main()
{
	char c;
	char a[50] = "this is a string...";
	cout << "use get() input char: ";
	while ((c=cin.get())!='\n')
	{
		cout.put(c);
	}
	cout.put('\n');
	cout.put('t').put('h').put('i').put('s').put('\n');
	cout.write(a, sizeof(a) - 1).put('\n');
	cout << "Look" << "\t here! " << endl;
	system("pause");
}
*/

/*
#include<iostream>

using namespace std;

void main()
{
	char c[30] = "this is a string";
	double d = -1234.8976;
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::left);
	cout << c << "----L1" << endl;
	cout.width(30);
	cout.setf(ios::right);
	cout << c << "----L2" << endl;
	cout.setf(ios::dec | ios::showbase | ios::showpoint);
	cout.width(30);
	cout << d << "----L3" << endl;
	cout.setf(ios::showpoint);
	cout.precision(10);
	cout.width(30);
	cout << d << "----L4" << endl;
	cout.width(30);
	cout.setf(ios::oct, ios::basefield);
	cout << 100 << "----L5" << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<iomanip>

using namespace std;

void main()
{
	char c[30] = "this is a string";
	double d = -1234.8976;
	cout << setw(30) << left << setfill('*') << c << "----L1" << endl;
	cout << setw(30) << right << setfill('*') << c << "----L2" << endl;
	cout << dec << showbase << showpoint << setw(30) << d << "----L3" << endl;
	cout << setw(30) << showpoint << setprecision(10) << d << "----L4" << endl;
	cout << setw(30) << setbase(8) << 10 << "----L5" << endl;
	system("pause");
}
*/

/*
#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	fstream ioFile;
	ioFile.open("C:\\C++文件\\a.dat", ios::out);
	ioFile << "张三" << " " << 76 << " " << 98 << " " << 67 << endl;
	ioFile << "李四" << " " << 89 << " " << 70 << " " << 60 << endl;
	ioFile << "王十" << " " << 91 << " " << 88 << " " << 77 << endl;
	ioFile << "黄二" << " " << 62 << " " << 81 << " " << 75 << endl;
	ioFile << "刘六" << " " << 90 << " " << 78 << " " << 67 << endl;
	ioFile.close();
	ioFile.open("C:\\C++文件\\a.dat", ios::in | ios::binary);
	char name[10];
	int chinese, math, computer;
	cout << "姓名\t" << "英语\t" << "数学\t" << "计算机\t" << "总分" << endl;
	ioFile >> name;
	while (!ioFile.eof())
	{
		ioFile >> chinese >> math >> computer;
		cout << name << "\t" << chinese << "\t"
			<< math << "\t" << computer << "\t"
			<< chinese + math + computer << endl;
		ioFile >> name;
	}
	ioFile.close();
	system("pause");
}
*/

/*
#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	char ch;
	ofstream out("C:\\C++文件\\a.dat", ios::out | ios::binary);
	for (int i = 0; i < 90; i++)
	{
		if (!(i%30))
		{
			out.put('\n');
		}
		out.put(char(i));
		out.put(' ');
	}
	out.close();
	ifstream in("C:\\C++文件\\a.dat", ios::in | ios::binary);
	while (in.get(ch))
	{
		cout << ch;
	}
	in.close();
	system("pause");
}
*/

//待完善
/*
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

//#pragma warning(disable:4996)

using namespace std;

class person
{
public:
	person() {};
	person(char* n, char* perid, int Age, char* Address)
	{
		strcpy_s(name, n);
		strcpy_s(id, perid);
		strcpy_s(addr, Address);
		age = Age;
	}
	void display()
	{
		cout << name << '\t' << id << '\t' << age << '\t' << addr << endl;
	}

private:
	char name[20];
	char id[18];
	int age;
	char addr[20];
};

void main()
{
	vector<person> p;
	vector<person>::iterator pos;
	char ch;
	ofstream outfile("C:\\C++文件\\a.dat", ios::out | ios::binary);
	char Name[20], ID[18], Addr[20];
	int Age;
	cout << "--------输入个人档案--------" << endl << endl;
	do
	{
		cout << "姓名:\t";
		cin >> Name;
		cout << "身份证号:\t";
		cin >> ID;
		cout << "年龄:\t";
		cin >> Age;
		cout << "地址:\t";
		cin >> Addr;
		person s1(Name, ID, Age, Addr);
		outfile.write((char*)&s1, sizeof(s1));
		cout << "Enter another person(y/n)?";
		cin >> ch;
	} while (ch=='y');
	outfile.close();
	ifstream infile("C:\\C++文件\\a.dat", ios::in | ios::binary);
	person s1;
	infile.read((char*)&s1, sizeof(s1));
	while (!infile.eof())
	{
		p.push_back(s1);
		infile.read((char*)&s1, sizeof(s1));
	}
	cout << "\n--------从文件中读出的数据--------" << endl << endl;
	pos = p.begin();
	for ( pos = p.begin(); pos != p.end(); pos++)
	{
		(*pos).display();
	}
	system("pause");
}
*/

//问老师
/*
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Employee
{
public:
	Employee() {};
	Employee(int num,char *Name, int Age, double Salary)
	{
		number = num;
		strcpy_s(name, Name);
		age = Age;
		sal = Salary;
	}
	void display()
	{
		cout << number << '\t' << name << '\t' << age << '\t' << sal << endl;
	}

private:
	int number, age;
	char name[20];
	double sal;
};

void main()
{
	ofstream outfile("Employee.dat", ios::out | ios::binary);
	Employee e1(1, "张三", 23, 2320.0);
	Employee e2(2, "李四", 32, 3210);
	Employee e3(3, "王五", 34, 2220);
	Employee e4(4, "刘六", 27, 1220);
	outfile.write((char*)&e1, sizeof(e1));
	outfile.write((char*)&e2, sizeof(e2));
	outfile.write((char*)&e3, sizeof(e3));
	outfile.write((char*)&e4, sizeof(e4));
	Employee e5(3, "王五", 40, 2220);
	outfile.seekp(2 * sizeof(e1));
	outfile.write((char*)&e5, sizeof(e5));
	outfile.close();
	ifstream infile("Employee.dat", ios::in | ios::binary);
	Employee s1;
	cout << "\n------从文件中读出第三个人的数据------\n\n";
	infile.seekg(2 * sizeof(s1), ios::beg);
	infile.read((char*)&s1, sizeof(s1));
	s1.display();
	cout << "\n-------从文件中读出全部的数据-------\n\n";
	infile.seekg(0, ios::beg);
	infile.read((char*)&s1, sizeof(s1));
	while (!infile.eof())
	{
		s1.display();
		infile.read((char*)&s1, sizeof(s1));
	}
	system("pause");
}
*/

//7-7
/*
#include<iostream>

using namespace std;

template<class T, int n>
T max(T a[])
{
	T maximum = a[0];
	for (int i = 0; i < n; i++)
	{
		if (maximum < a[i])
		{
			maximum = a[i];
		}
	}
	return maximum;
}

template<int n>
char* max(char* a[])
{
	char * maximum;
	maximum = a[0];
	for (int i = 0; i < n; i++) 
	{
		if (strcmp(maximum, a[i]) < 0)
		{
			maximum = a[i];
		}
	}
	return maximum;
}

void main()
{
	int a[10] = { 6,3,4,8,94,24,4,44,8,-7 };
	char *ptr[5];
	for (int i = 0; i < 5; i++) 
	{
		ptr[i] = new char[10];
		cout << "请输入一段长不超过9的字符串" << endl;
		cin >> ptr[i];
	}
	cout << endl;
	int max_int = max<int, 10>(a);
	char *max_str = max<char*, 5>(ptr);
	cout << max_int << endl << max_str << endl;
	for (int i = 0; i < 5; i++)
	{
		if (ptr[i])
		{
			delete[]ptr[i];
		}
	}
	system("pause");
}
*/

//7-6
/*
#include<iostream>

using namespace std;

template<typename T>
void exchange(T t1, T t2)
{
	T t3;
	t3 = t1;
	t1 = t2;
	t2 = t3;
}

template<>
void exchange<char*> (char* s1, char* s2)
{
	char *s3;
	s3 = s1;
	s1 = s2;
	s2 = s3;
}

void main()
{
	int n1 = 10, n2 = 100000;
	char * p1 = (char*)"qwert";
	char * p2 = (char*)"asdfg";
	exchange(n1, n2);
	exchange(p1, p2);
	cout << "n1: " << n1 << "\tn2: " << n2 << endl;
	cout << "p1: " << p1 << "\tp2: " << p2 << endl;
	system("pause");
}
*/

//7-9
/*
#include<iostream>
#include<list>
//#include<algorithm>

using namespace std;

class Woker
{
public:
	Woker() {};
	Woker(char* Name, int Age, double sal) :age(Age), salary(sal)
	{
		strcpy_s(name, Name);
	}
	void SetData(char *Name, int Age, double wage)
	{
		strcpy_s(name, Name);
		age = Age;
		salary = wage;
	}
	void Display()
	{
		cout << "Name:\t" << name << endl
			<< "Age:\t" << age << endl
			<< "salary:\t" << salary << endl;
		cout << endl;
	}
	
private:
	char name[20];
	int age;
	double salary;
};

void main()
{
	//定义2个woker类大小为3个单位的数组
	Woker male[3], female[3];
	//Woker staff[6];
	//分别赋值
	male[1].SetData((char*)"Bob", 18, 2333);
	male[2].SetData((char*)"Gay", 18, 2233);
	male[3].SetData((char*)"Tom", 18, 2223);
	female[1].SetData((char*)"Alice", 18, 2333);
	female[2].SetData((char*)"Alita", 18, 2233);
	female[3].SetData((char*)"Andy", 18, 2223);
	//将两个数组合并
	//merge(male, male + 3, female, female + 3, staff);
	//构造两个woker类的列表
	list<Woker>woker_1st, woker_2nd;
	//构造woker类的迭代器
	list<Woker>::iterator pos;
	//分别向2个链表存入woker类对象
	for (int i = 0; i < 3; i++)
	{
		woker_1st.push_back(male[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		woker_2nd.push_back(female[i]);
	}
	//通过迭代器访问输出各节点对象
	cout << "第一个链表中的对象" << endl;
	for (pos = woker_1st.begin(); pos != woker_1st.end(); pos++)
	{
		(*pos).Display();
	}
	cout << "第二个链表中的对象" << endl;
	for (pos = woker_2nd.begin(); pos != woker_1st.end(); pos++)
	{
		(*pos).Display();
	}
	//将第二个链表合并到第一个链表中
	woker_1st.merge(woker_2nd);
	for (pos = woker_1st.begin(); pos != woker_1st.end(); pos++)
	{
		(*pos).Display();
	}
	cout << endl;
	system("pause");
}
*/

//7-10
/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void main()
{
	int a1[] = { 10,20,30,4,50,13,7 };
	int a2[] = { -2,0,30,12,6,7,-9,56,32,78 };
	vector<int> v1, v2, v;
	vector<int>::iterator pos;
	for (int i = 0; i < 7; i++)
	{
		v1.push_back(a1[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(a2[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	v.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	sort(v.begin(), v.end());
	for (pos = v.begin(); pos != v.end(); pos++)
	{
		cout << (*pos) << ' ';
	}
	system("pause");
}
*/

//冒泡排序
/*
#include<iostream>

using namespace std;

template<class T>
void display(T a[], int num)
{
	for (int i = 0; i < num; i++) 
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

template<class T>
void bubble_sort(T a[], int num)
{
	for (int i = 0; i < num - 1; i++) 
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				T m = a[j];
				a[j] = a[j + 1];
				a[j + 1] = m;
			}
		}
	}

}

void main()
{
	int b[10] = { 10,9,8,7,6,5,4,3,2,1 };
	bubble_sort<int>(b, 10);
	display<int>(b, 10);
	system("pause");
}
*/

//矩阵类模板
//网上的代码
//#include<iostream>
//#include <string.h>
//#include <stdio.h>
//#include <malloc.h>
//#include <assert.h>
//
//using namespace std;
//
//// 矩阵的数据结构
//struct CMatData
//{
//	size_t  nWidth;  // 矩阵宽度
//	size_t  nHeigth; // 矩阵高度
//	long    nRefs;   // 矩阵被引用次数
//	unsigned char *  GetData()
//	{
//		return (unsigned char *)(this + 1);
//	} // 内存地址
//};
//
//#define esp  1e-8 // 约等于零的数
//
//template<class T>
//class CMat
//{
//private:
//	size_t			mWidth;  // 矩阵宽度
//	size_t			mHeigth; // 矩阵高度
//	unsigned char mpData[3]; // 数据地址
//	T			 ** mpRows;  // 矩阵行指针
//	// 申请分配内存
//	void AllocBuffer(size_t w, size_t h)
//	{
//		if (w * h == 0)
//		{
//			return;
//		}
//		else
//		{
//			size_t rowSize = ((sizeof(T) * w + 3) & ~3); // 对齐到4BYTE
//			size_t allocSize = sizeof(CMatData) + rowSize * h;
//			CMatData * p = (CMatData *)malloc(allocSize);
//			mpRows = (T **)malloc(sizeof(T *) * h);
//			if (p == NULL || mpRows == NULL) // 申请失败
//			{
//				Init();
//				if (p)
//				{
//					free(p);
//				}
//				if (mpRows)
//				{
//					free(mpRows);
//				}
//			}
//			else
//			{
//				p->nRefs = 1;
//				mWidth = p->nWidth = w;
//				mHeigth = p->nHeigth = h;
//				mpData = p->GetData();
//				for (size_t i = 0; i < mHeigth; i++)
//				{
//					mpRows[i] = (T *)(mpData + rowSize * i);
//				}
//			}
//		}
//	}
//	// 释放内存
//	static void FreeData(void * p)
//	{
//		free(p);
//	}
//	// 引用释放
//	void Release()
//	{
//		if (mpData == NULL)
//		{
//			return;
//		}
//		CMatData * p = GetData();
//		assert(p->nRefs != 0);
//		// 引用减少1，当引用次数等于0，释放内存
//		if (--p->nRefs <= 0)
//		{
//			FreeData(p);
//		}
//		free(mpRows);
//		Init();
//	}
//	// 引用释放
//	static void Release(CMatData * p)
//	{
//		if (p)
//		{
//			assert(p->nRefs != 0);
//			if (--p->nRefs <= 0)
//			{
//				FreeData(p);
//			}
//		}
//	}
//	// 释放旧数据并申请新的内存空间
//	void AllocBeforeWrite(size_t w, size_t h)
//	{
//		if (mpData)
//		{
//			CMatData * p = GetData();
//			if (p->nRefs > 1 || p->nHeigth != h || p->nWidth != w)
//			{
//				Release();
//				Init();
//			}
//		}
//		if (mpData == NULL)
//		{
//			AllocBuffer(w, h);
//		}
//		assert(GetData()->nRefs == 1);
//	}
//	// 更改数据前脱离引用
//	void CopyBeforWrite()
//	{
//		if (mpData == NULL)
//		{
//			return;
//		}
//		if (GetData()->nRefs <= 1)
//		{
//			return;
//		}
//		CMat tmp(*this);
//		Release();
//		AssignCopy(tmp);
//	}
//
//	template<class T1, class T2>
//	T2 * Copy(T1 * f, T1 * t, T2 * o) const
//	{
//		while (f < t)
//		{
//			*o++ = *f++;
//		}
//		return o;
//	}
//	template<class T1, class V>
//	T1 * Fill(T1 * f, T1 * t, V v) const
//	{
//		while (f < t)
//		{
//			*f++ = v;
//		}
//		return f;
//	}
//
//	// 检测数据有效性
//	inline void Youxiao(size_t w, size_t h) const
//	{
//		if (mpData == NULL || w >= mWidth || h >= mHeigth)
//		{
//			assert(0);
//		}
//	}
//	inline void Youxiao(size_t w) const
//	{
//		if (mpData == NULL || w >= mWidth)
//		{
//			assert(0);
//		}
//	}
//	// 复制矩阵
//	void AssignCopy(const CMat & r)
//	{
//		assert(mpData == NULL);
//		if (r.IsEmpty())
//		{
//			return; // 直接返回
//		}
//		AllocBuffer(r.mWidth, r.mHeigth); // 分配内存
//		for (size_t i = 0; i < mHeigth; i++) // 复制数据
//		{
//			const T * p = r.GetRows(i);
//			Copy(p, p + mWidth, GetRows(i));
//		}
//	}
//	// 引用矩阵
//	void RefCopy(const CMat & r)
//	{
//		assert(mpData == NULL);
//		if (r.IsEmpty())
//		{
//			return; // 直接返回
//		}
//		mpRows = (T **)malloc(sizeof(T *) * r.mHeigth);
//		if (mpRows == NULL)
//		{
//			return; // 内存分配错误
//		}
//		mpData = r.mpData; // 直接复制内存地址
//		mWidth = r.mWidth;
//		mHeigth = r.mHeigth;
//		T ** p = r.mpRows;
//		Copy(p, p + r.mHeigth, mpRows);
//		++GetData()->nRefs; // 引用计数增加1
//	}
//
//protected:
//	// 初始化
//	void Init()
//	{
//		mpData = NULL;
//		mpRows = NULL;
//		mWidth = 0;
//		mHeigth = 0;
//	}
//	// 取得数据实际地址
//	CMatData * GetData() const
//	{
//		if (mpData)
//		{
//			return (CMatData *)mpData - 1;
//		}
//		return NULL;
//	}
//	// 交换a b两行
//	inline void SwapRows(size_t a, size_t b)
//	{
//		Youxiao(a);
//		Youxiao(b);
//		CopyBeforWrite();
//		T * tmp = mpRows[a];
//		mpRows[a] = mpRows[b];
//		mpRows[b] = tmp;
//	}
//	// row[a] += row[b]; b行加a行，结果保存到a行
//	inline void AddRows(size_t a, size_t b)
//	{
//		Youxiao(a);
//		Youxiao(b);
//		CopyBeforWrite();
//		T * pal = mpRows[a];
//		T * pah = pal + mWidth;
//		T * pbl = mpRows[b];
//		while (pal < pah)
//		{
//			*pal++ += *pbl++;
//		}
//	}
//	// row[a] -= row[b]; a行减b行，结果保存到a行
//	inline void SubRows(size_t a, size_t b)
//	{
//		Youxiao(a);
//		Youxiao(b);
//		CopyBeforWrite();
//		T * pal = mpRows[a];
//		T * pah = pal + mWidth;
//		T * pbl = mpRows[b];
//		while (pal < pah)
//		{
//			*pal++ -= *pbl++;
//		}
//	}
//	// row[a] -= row[b] * k; a行减b行乘以常数k，结果保存到a行
//	inline void SubRows(size_t a, size_t b, T k)
//	{
//		Youxiao(a);
//		Youxiao(b);
//		CopyBeforWrite();
//		T * pal = mpRows[a];
//		T * pah = pal + mWidth;
//		T * pbl = mpRows[b];
//		while (pal < pah)
//		{
//			*pal++ -= *pbl++ * k;
//		}
//	}
//	// row[a] *= k;  a行乘以常数k
//	inline void MulRows(size_t a, T k)
//	{
//		Youxiao(a);
//		CopyBeforWrite();
//		T * pal = mpRows[a];
//		T * pah = pal + mWidth;
//		while (pal < pah)
//		{
//			*pal++ *= k;
//		}
//	}
//	// row[a] /= k; a行除以常数k
//	inline void DivRows(size_t a, T k)
//	{
//		Youxiao(a);
//		CopyBeforWrite();
//		k = T(1) / k;
//		MulRows(a, k);
//	}
//public:
//	// 构造、析构函数
//
//	CMat()
//	{
//		Init();
//	}
//	CMat(size_t w, size_t h)
//	{
//		Init();
//		AllocBuffer(w, h);
//		SetData();
//	}
//	CMat(size_t w, size_t h, const T * data)
//	{
//		Init();
//		AllocBuffer(w, h);
//		SetData(data);
//	}
//	CMat(const CMat & r) // 复制构造函数
//	{
//		Init();
//		if (!r.IsEmpty())
//		{
//			if (r.GetData()->nRefs < 1)
//			{
//				AssignCopy(r); // 源数据被锁定，需要复制数据
//			}
//			else
//			{
//				RefCopy(r);
//			}
//		}
//	}
//	virtual ~CMat() //
//	{
//		CMatData * p = GetData();
//		if (p)
//		{
//			if (--p->nRefs <= 0)
//			{
//				FreeData(p);
//			}
//		}
//		if (mpRows) free(mpRows);
//	}
//
//	// 复制函数
//	const CMat & operator=(const CMat & r)
//	{
//		CMatData * p1 = GetData();
//		CMatData * p2 = r.GetData();
//		if (p1 == p2)
//		{
//			mWidth = r.mWidth;
//			mHeigth = r.mHeigth;
//			free(mpRows);
//			mpRows = new T*[mHeigth];
//			for (int i = 0; i < mHeigth; ++i)
//			{
//				mpRows[i] = r.mpRows[i];
//			}
//			return *this;
//		}
//		Release();
//		if (!r.IsEmpty())
//		{
//			if (r.GetData()->nRefs < 1)
//			{
//				AssignCopy(r); // 源数据被锁定，需要复制数据
//			}
//			else
//			{
//				RefCopy(r);
//			}
//		}
//		return *this;
//	}
//
//	// 矩阵运算
//
//	// 矩阵转置
//	inline CMat Transpose() const
//	{
//		CMat t(mHeigth, mWidth); // 建立一个新矩阵
//		size_t i, j;
//		for (j = 0; j < mHeigth; j++)
//		{
//			const T * p = (const T *)mpRows[j];
//			for (i = 0; i < mWidth; i++)
//			{
//				t.At(j, i) = *p++;
//			}
//		}
//		return t;
//	}
//	// 矩阵加法
//	inline CMat Add(const CMat & l) const
//	{
//		if (l.mHeigth != mHeigth || l.mWidth != mWidth)
//		{
//			printf("CMat::Add error 矩阵参数不一致\n");
//			return CMat(); // 参数不一致返回空矩阵
//		}
//		CMat t(mWidth, mHeigth);
//		size_t i;
//		for (i = 0; i < mHeigth; i++)
//		{
//			const T * prl = (const T *)mpRows[i];
//			const T * prh = prl + mWidth;
//			const T * pl = (const T *)l.mpRows[i];
//			T * pt = t.mpRows[i];
//			while (prl < prh)
//			{
//				*pt++ = *prl++ + *pl++;
//			}
//		}
//		return t;
//	}
//	// 矩阵减法
//	inline CMat Sub(const CMat & l) const
//	{
//		if (l.mHeigth != mHeigth || l.mWidth != mWidth)
//		{
//			printf("CMat::Add error 矩阵参数不一致\n");
//			return CMat(); // 参数不一致返回空矩阵
//		}
//		CMat t(mWidth, mHeigth);
//		size_t i;
//		for (i = 0; i < mHeigth; i++)
//		{
//			const T * prl = (const T *)mpRows[i];
//			const T * prh = prl + mWidth;
//			const T * pl = (const T *)l.mpRows[i];
//			T * pt = t.mpRows[i];
//			while (prl < prh)
//			{
//				*pt++ = *prl++ - *pl++;
//			}
//		}
//		return t;
//	}
//	// 矩阵乘以常数
//	inline CMat Mul(const T & k) const
//	{
//		CMat t(mWidth, mHeigth);
//		size_t i;
//		for (i = 0; i < mHeigth; i++)
//		{
//			const T * prl = (const T *)mpRows[i];
//			const T * prh = prl + mWidth;
//			T       * pt = t.mpRows[i];
//			while (prl < prh)
//			{
//				*pt++ = *prl++ * k;
//			}
//		}
//		return t;
//	}
//	// 矩阵除以常数
//	inline CMat Div(const T & k) const
//	{
//		T d = T(1) / k;
//		return Mul(d); // 除以k就相当于乘以 1/k
//	}
//	// 两行的数量积
//	inline T DotRows(size_t a, size_t b) const
//	{
//		T r = 0;
//		T * pal = mpRows[a];
//		T * pah = pal + mWidth;
//		T * pbl = mpRows[b];
//		while (pal < pah)
//		{
//			r += *pal++ * *pbl++;
//		}
//		return r;
//	}
//	// 两个矩阵乘法
//	inline CMat Mul(const CMat & l) const
//	{
//		if (mWidth != l.mHeigth)
//		{
//			printf("CMat::Mul error 矩阵参数不一致\n");
//			return CMat(); // 参数不一致返回空矩阵
//		}
//		size_t i, j, k;
//		CMat t(l.mWidth, mHeigth);
//		const T** plRows = (const T**)l.mpRows;
//		for (i = 0; i < mHeigth; i++)
//		{
//			T       * ptl = t.mpRows[i];
//			const T * pr = (const T *)mpRows[i];
//			for (j = 0; j < l.mWidth; j++)
//			{
//				const T *prl = pr;
//				for (k = 0; k < mWidth; k++)
//				{
//					*ptl += *prl++ * l.At(j, k);
//				}
//				ptl++;
//			}
//		}
//		return t;
//	}
//	// 矩阵乘以单行数据
//	inline T * Mul(T * p) const
//	{
//		CMat l(1, mWidth, p);
//		CMat r = Mul(l);
//		return r.GetList(p, mWidth);
//	}
//	// 高斯消元，用于求解线性方程和求矩阵的逆矩阵
//	inline CMat GaussianElimination() const
//	{
//		if (mWidth <= mHeigth)
//		{
//			return CMat();
//		}
//		bool loop = true;
//		CMat r(*this);
//		size_t i, j, k;
//		for (i = 0; i < r.mHeigth && loop; i++)
//		{
//			size_t pos = i;
//			T max = r.At(i, i);
//			for (k = i + 1; k < r.mHeigth; k++) // 找出最大的数值，减小浮点数计算误差
//			{
//				T y = r.At(k, i);
//				if (y > max)
//				{
//					pos = k; max = y;
//				}
//			}
//			if (i != pos)
//			{
//				r.SwapRows(i, pos); // 交换i行与找到的最大数据行
//			}
//			if (r.Iszero(i, i))
//			{
//				loop = false; break;
//			} // 如果最大的数值为零，无解
//
//			// 使i行第i个元素等于1
//			r.DivRows(i, r.At(i, i));
//			// 主计算循环 j行减去i行乘以j行的第i个元素, 使j行的第i个元素为零
//			for (j = 0; j < r.mHeigth; j++)
//			{
//				if (i != j)
//				{
//					r.SubRows(j, i, r.At(i, j));
//				}
//			}
//		}
//		if (loop == false)
//		{
//			return CMat();
//		}
//		r.Resize(r.mWidth - r.mHeigth, r.mHeigth, r.mHeigth, 0);
//		return r;
//	}
//	// 转换为阶梯形矩阵
//	inline CMat Echelon() const
//	{
//		if (mpData == NULL)
//		{
//			return CMat();
//		}
//		CMat r(*this);
//		bool loop = true;
//		size_t i, j, k;
//		for (i = 0; i < r.mHeigth && loop; i++)
//		{
//			size_t pos = i;
//			T max = r.At(i, i);
//			for (k = i + 1; k < r.mHeigth; k++) // 找出最大的数值，减小浮点数计算误差
//			{
//				T y = r.At(k, i);
//				if (y > max)
//				{
//					pos = k; max = y;
//				}
//			}
//			if (i != pos)
//			{
//				r.SwapRows(i, pos); // 交换i行与找到的最大数据行
//			}
//			// 主计算循环
//			for (j = i + 1; j < r.mHeigth; j++)
//			{
//				r.SubRows(j, i, r.At(i, j) / r.At(i, i));
//			}
//		}
//		if (!loop)
//		{
//			r.Resize(r.mWidth, i, 0, 0);
//		}
//		return r;
//	}
//	// 求行列式的值，为减少计算，1，2，3系列的直接计算
//	inline T Det() const
//	{
//		if (mWidth != mHeigth)
//		{
//			return 0;
//		}
//		switch (mWidth)
//		{
//		case 1:
//			return At(0, 0);
//		case 2:
//			return At(0, 0) * At(1, 1) - At(0, 1) * At(1, 0);
//		case 3:
//			return At(0, 0) * At(1, 1) * At(2, 2) + At(0, 1) * At(1, 2) * At(2, 0) + At(0, 2) * At(1, 0) * At(2, 1)
//				- (At(2, 0) * At(1, 1) * At(0, 2) + At(2, 1) * At(1, 2) * At(0, 0) + At(2, 2) * At(1, 0) * At(0, 1));
//		default:
//		{
//			CMat r = Echelon();
//			if (r.mpData == NULL)
//			{
//				return 0;
//			}
//			if (r.mWidth != r.mHeigth)
//			{
//				return 0;
//			}
//			size_t i;
//			T v = r.At(0, 0);
//			for (i = 1; i < mWidth; i++)
//			{
//				v *= r.At(i, i);
//			}
//			return v;
//		}
//		}
//	}
//	// 求矩阵的逆矩阵
//	inline CMat Inv() const
//	{
//		if (mWidth != mHeigth)
//		{
//			return CMat();
//		}
//		CMat r(2 * mWidth, mWidth); // 扩展矩阵
//		size_t i;
//		for (i = 0; i < mWidth; i++) // 复制数据到扩展矩阵
//		{
//			const T * psl = (const T *)mpRows[i];
//			const T * psh = psl + mWidth;
//			T       * pd = r.mpRows[i];
//			Copy(psl, psh, pd);
//			r.At(mWidth + i, i) = 1;
//		}
//		return r.GaussianElimination(); // 返回扩展矩阵的解
//	}
//	// 矩阵的一个应用：最小二乘法
//	//static T * LeastSquares(T * r, const T * y, const T * x, size_t num, size_t n = 1);
//
//	// 属性
//
//	// 获取分配的矩阵宽度
//	//size_t GetAllocWidth() const;
//	// 获取分配的矩阵高度
//	//size_t GetAllocHeigth() const;
//	// 获取矩阵宽度
//	//size_t GetWidth() const;
//	// 获取矩阵高度
//	//size_t GetHeigth() const;
//	// 判断矩阵是否为空
//	//bool IsEmpty() const;
//	// 取得h行的地址
//	//inline T * GetRows(int h);
//	// 取得矩阵的h行，w列的引用
//	//inline T & At(int w, int h);
//	// 取得h行的地址
//	//inline const T * GetRows(int h) const;
//	// 取得矩阵的h行，w列的引用
//	//inline const T & At(int w, int h) const;
//	// 取得矩阵数据
//	//inline T * GetList(T * p, size_t max) const;
//	// 设置数据
//	int SetData(const T * d = NULL)
//	{
//		assert(mpData);
//		assert(mpRows);
//		if (d) for (size_t i = 0; i < mHeigth; i++)
//		{
//			Copy(d, d + mWidth, mpRows[i]);
//			d += mWidth;
//		}
//		else
//		{
//			for (size_t i = 0; i < mHeigth; i++)
//			{
//				Fill(mpRows[i], mpRows[i] + mWidth, T(0));
//			}
//		}
//		return mHeigth * mWidth;
//	}
//	// 改变矩阵大小
//	inline void Resize(size_t w, size_t h, size_t xOff, size_t yOff)
//	{
//		Youxiao(w + xOff - 1, h + yOff - 1);
//		size_t i;
//		mWidth = w;
//		mHeigth = h;
//		for (i = 0; i < mHeigth; i++)
//		{
//			mpRows[i] = mpRows[i + yOff] + xOff;
//		}
//	}
//
//	inline static bool Eqzero(const T & k)
//	{
//		if ((k < T(0) ? -k : k) < esp)
//		{
//			return true;
//		}
//		return false;
//	}
//	inline bool Iszero(size_t w, size_t h) const
//	{
//		return Eqzero(At(w, h));
//	}
//};

//我的矩阵模板(卑微.jpg)
/*
#include<iostream>

using namespace std;

template<class T, int nNum_row, int nNum_col>
class matrix
{
private:
	T m_ppData[nNum_row * nNum_col];
public:
	matrix()
	{
		for (int i = 0; i < nNum_row; i++)
		{
			for (int j = 0; j < nNum_col; j++)
			{
				*(m_ppData + i * nNum_col + j) = 0;
			}
		}
	}
	void set_row()
	{
		cout << "row = ";
		cin >> nNum_row;
	}
	void set_col()
	{
		cout << "col = ";
		cin >> nNum_col;
	}
	void set_certain(int row, int col, T e)
	{
		*(m_ppData + row * nNum_col + col) = e;
	}
	void set_whole()
	{
		cout << "请为矩阵各元素赋值..." << endl << endl;
		for (int i = 0; i < nNum_row; i++)
		{
			cout << "第" << i + 1 << "行" << endl;
			for (int j = 0; j < nNum_col; j++)
			{
				cout << "第" << j + 1 << "列\t";
				cin >> *(m_ppData + i * nNum_col + j);
			}
			cout << endl;
		}
	}
	int get_row()
	{
		return nNum_row;
	}
	int get_col()
	{
		return nNum_col;
	}
	T get_certain(int row, int col)
	{
		return *(m_ppData + row * nNum_col + col);
	}
	void print()
	{
		for (int i = 0; i < nNum_row; i++)
		{
			for (int j = 0; j < nNum_col; j++)
			{
				cout << this->get_certain(i, j) << '\t';
			}
			cout << endl;
		}
	}
	matrix <T,nNum_col , nNum_row> Transpose()
	{
		matrix<T, nNum_col, nNum_row> obj;
		for (int i = 0; i < nNum_row; i++)
		{
			for (int j = 0; j < nNum_col; j++)
			{
				obj.set_certain(j, i, this->get_certain(i, j));
			}
		}
		return obj;
	}
};

void main()
{
	matrix<int, 3, 3> A, B;
	A.set_whole();
	cout << "下面修改特定行特定列的值" << endl;
	int row, col, num;
	cout << "行数: " << "row = ";
	cin >> row;
	cout << "列数: " << "col = ";
	cin >> col;
	cout << "请为第 " << row << " 行第 " << col << " 列赋值: num = ";
	cin >> num;
	cout << endl;
	A.set_certain(row - 1, col - 1, num);
	A.print();
	cout << endl;
	B = A.Transpose();
	B.print();
	cout << endl;
	system("pause");
}
*/

//void HuffmanCoding_2(HuffmanTree & HT, HuffmanCode & HC, int * w, int n)
//{
//	if (n <= 1)
//	{
//		return;
//	}
//	int i, m = 2 * n - 1;
//	int s1, s2;
//	HuffmanTree p;
//	HT = new HTNode[m + 1];//0号单元未用
//	for (p = HT, i = 1; i <= n; ++i, ++p, ++w)
//	{
//		*p = { *w,0,0,0 };
//	}
//	for (; i <= m; ++i)
//	{
//		*p = { 0,0,0,0 };
//	}
//	for (i = n + 1; i <= m; ++i)//建赫夫曼树
//	{
//
//		Select(HT, i - 1, s1, s2);
//		HT[s1].parent = HT[s2].parent = i;
//		HT[i].lchild = s1;
//		HT[i].rchild = s2;
//		HT[i].weight = HT[s1].weight + HT[s2].weight;
//	}
//	HC = new char*[n + 1];
//	char *cd = new char[n];
//	cd[n - 1] = '\0';
//	int q = m;
//	int cdlen = 0;
//	for (i = 1; i <= m; ++i)
//	{
//		HT[i].weight = 0;
//	}
//	while (q)
//	{
//		if (HT[q].weight == 0)
//		{
//			HT[q].weight = 1;
//			if (HT[q].lchild != 0)
//			{
//				q = HT[q].lchild;
//				cd[cdlen++] = '0';
//			}
//			else if (HT[q].rchild == 0)
//			{
//				HC[q] = new char[cdlen + 1];
//				cd[cdlen] = '\0';
//				strcpy_s(HC[q], cdlen, cd);
//			}
//		}
//		else if (HT[q].weight == 1)
//		{
//			HT[q].weight = 2;
//			if (HT[q].rchild != 0)
//			{
//				q = HT[q].rchild;
//				cd[cdlen++] = '1';
//			}
//		}
//		else
//		{
//			HT[q].weight = 0;
//			q = HT[q].weight;
//			--cdlen;
//		}//else
//	}//While
//}
//
//
//
/////*************在HTree[1...upper]选择parent为0且weight最小的两个节点，其序号分别为s1,s2*********/
////void Select(unsigned int upper, int &s1, int &s2)
////{
////	/*********在HTree[1...upper]中先将最小的挑出来，赋值给s2************************************************************/
////	for (int i = 1; i <= upper; i++) {                      //将s2先赋给左边起第一个parent为0的数
////		if (HT[i].parent == 0) {
////			s2 = i;
////			break;
////		}
////	}
////	for (int i = 1; i <= upper; i++) {                      //找到最小权的s2
////		if (HT[i].parent == 0 && HT[s2].weight > HT[i].weight) {
////			s2 = i;
////		}
////	}
////
////	/*********在HTree[1...upper]中将次小的挑出来，赋值给s1************************************************************/
////	for (int i = upper; i >= 1; i--)                                       //将s2先赋给右边起第一个parent为0的数
////		if (HT[i].parent == 0) {
////			s1 = i;
////			break;
////		}
////	for (int i = upper; i >= 1; i--) {              //找到次小权的s1
////		if (i == s2)i--;                                                //跳过s2
////		if (HT[i].parent == 0 && HT[s1].weight > HT[i].weight && s1 != s2 && i >= 1) {
////			s1 = i;
////		}
////	}
////}

//cout << "节点：" << i << "\tweight: " << HT[i].weight << endl
//<< "\tlchild: " << s1 << "\tweight: " << HT[s1].weight << endl
//<< "\trchild: " << s2 << "\tweight: " << HT[s2].weight << endl;
//	}

//#include<iostream>
//
//using namespace std;
//
//class CShape
//{
//public:
//	CShape(){}
//	virtual ~CShape(){}
//	virtual float GetPerimeter() = 0;
//private:
//
//};
//
//class CRectangle:
//	public CShape
//{
//public:
//	CRectangle():up_left_x(0),up_left_y(0),length(0),width(0){}
//	CRectangle(float point_x,float point_y,float len,float wid):
//		up_left_x(point_x),up_left_y(point_y),length(len),width(wid){}
//	~CRectangle(){}
//	virtual float GetPerimeter()
//	{
//		return 2 * (length + width);
//	}
//private:
//	float up_left_x, up_left_y, length, width;
//};
//
//class CCircle:
//	public CShape
//{
//public:
//	CCircle():center_x(0),center_y(0),radius(0){}
//	CCircle(float point_x,float point_y,float r):
//		center_x(point_x),center_y(point_y),radius(r){}
//	~CCircle(){}
//	virtual float GetPerimeter()
//	{
//		return 2 * 3.14 * radius;
//	}
//private:
//	float center_x, center_y, radius;
//};
//
//void main()
//{
//	CShape *p1 = new CRectangle(0, 0, 100, 100), *p2 = new CCircle(0, 0, 50);
//	cout << "Rectangle: " << p1->GetPerimeter() << endl
//		<< "Circle: " << p2->GetPerimeter() << endl;
//	system("pause");
//}

/*
#include<iostream>
#include<stdio.h>

using namespace std;

bool IsPrimeNumber(int a)
{
	if (a<=1)
	{
		return false;
	}
	for (int i = 2; i <= (int(sqrt(a))); i++)
	{
		if (a%i==0)
		{
			return false;
		}
	}
	return true;
}

void main()
{
	int i = 1, n = 0;
	int PrimeNumber[100] = { 0 };
	for ( i = 1; i < 100; i++)
	{
		if (IsPrimeNumber(i))
		{
			PrimeNumber[n] = i;
			n++;
		}
	}
	for ( i = 0; i < n; i++)
	{
		if (i%5==0)
		{
			printf("\n");
		}
		printf("%2d ", PrimeNumber[i]);
	}
	printf("\n");
	system("pause");
}
*/

//使用C语言对int类数组使用qsort函数
//#include<stdio.h>
//#include<stdlib.h>
//
//int comp(const void*a, const void*b)
//{
//	return *(int*)a - *(int*)b;
//}
//
//int main()
//{
//	int i = 0;
//	int *array;
//	int n;
//	scanf_s("%d", &n);
//	array = (int *)malloc(n * sizeof(int));
//	for (; i < n; i++)
//	{
//		scanf_s("%d", array + i);
//	}
//	qsort(array, n, sizeof(int), comp);
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d\t", array[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//使用C++进行快速排序
//#include <iostream>
//
//using namespace std;
//
//void Qsort(int arr[], int low, int high) {
//	if (high <= low) return;
//	int i = low;
//	int j = high + 1;
//	int key = arr[low];
//	while (true)
//	{
//		//从左向右找比key大的值
//		while (arr[++i] < key)
//		{
//			if (i == high) {
//				break;
//			}
//		}
//		//从右向左找比key小的值
//		while (arr[--j] > key)
//		{
//			if (j == low) {
//				break;
//			}
//		}
//		if (i >= j) break;
//		//交换i,j对应的值
//		int temp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = temp;
//	}
//	//中枢值与j对应值交换
//	int temp = arr[low];
//	arr[low] = arr[j];
//	arr[j] = temp;
//	Qsort(arr, low, j - 1);
//	Qsort(arr, j + 1, high);
//}
//
//void main()
//{
//	int a[] = { 57, 68, 59, 52, 72, 28, 96, 33, 24 };
//	Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);//这里原文第三个参数要减1否则内存越界
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//}

//使用C++进行直接插入排序
//#include<iostream>
//using namespace std;
//void main()
//{
//	int a[] = { 98,76,109,34,67,190,80,12,14,89,1 };
//	int k = sizeof(a) / sizeof(a[0]);
//	int i, j;
//	for (i = 1; i < k; i++)//循环从第2个元素开始
//	{
//		if (a[i] < a[i - 1])
//		{
//			int temp = a[i];
//			for (j = i - 1; j >= 0 && a[j] > temp; j--)
//			{
//				a[j + 1] = a[j];
//			}
//			a[j + 1] = temp;//此处就是a[j+1]=temp;
//		}
//	}
//	for (int f = 0; f < k; f++)
//	{
//		cout << a[f] << "  ";
//	}
//	cout << endl;
//	system("pause");
//}

////用C语言实现堆排序
//#include <stdio.h>
//#include <stdlib.h>
//
//void swap(int* a, int* b)
//{
//	int temp = *b;
//	*b = *a;
//	*a = temp;
//}
//
//void max_heapify(int arr[], int start, int end) 
//{
//	//建立父节点指标和子节点指标
//	int dad = start;
//	int son = dad * 2 + 1;
//	while (son <= end)//若子节点指标在范围内才做比较
//	{
//		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
//		{
//			son++;
//		}
//		if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
//		{
//			return;
//		}
//		else//否则交换父子内容再继续子节点和孙节点比较
//		{ 
//			swap(&arr[dad], &arr[son]);
//			dad = son;
//			son = dad * 2 + 1;
//		}
//	}
//}
//
//void heap_sort(int arr[], int len) 
//{
//	int i;
//	//初始化，i从最后一个父节点开始调整
//	for (i = len / 2 - 1; i >= 0; i--)
//	{
//		max_heapify(arr, i, len - 1);
//	}
//	//先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
//	for (i = len - 1; i > 0; i--) 
//	{
//		swap(&arr[0], &arr[i]);
//		max_heapify(arr, 0, i - 1);
//	}
//}
//
//void main()
//{
//	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
//	int len = (int) sizeof(arr) / sizeof(*arr);
//	heap_sort(arr, len);
//	int i;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//}

////用C++实现堆排序
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void max_heapify(int arr[], int start, int end) 
//{
//	//建立父节点指标和子节点指标
//	int dad = start;
//	int son = dad * 2 + 1;
//	while (son <= end) 
//	{ //若子节点指标在范围内才做比较
//		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
//		{
//			son++;
//		}
//		if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
//		{
//			return;
//		}
//		else 
//		{ //否则交换父子内容再继续子节点和孙节点比较
//			swap(arr[dad], arr[son]);
//			dad = son;
//			son = dad * 2 + 1;
//		}
//	}
//}
//
//void heap_sort(int arr[], int len) 
//{
//	//初始化，i从最後一个父节点开始调整
//	for (int i = len / 2 - 1; i >= 0; i--)
//	{
//		max_heapify(arr, i, len - 1);
//	}
//	//先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
//	for (int i = len - 1; i > 0; i--) 
//	{
//		swap(arr[0], arr[i]);
//		max_heapify(arr, 0, i - 1);
//	}
//}
//
//void main()
//{
//	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
//	int len = (int) sizeof(arr) / sizeof(*arr);
//	heap_sort(arr, len);
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	cout << endl;
//	system("pause");
//}

//#include<iostream>
//using namespace std;
//void main()
//{
//	double a = 22;
//	int i = 0, k = 18;
//	i = (a + k) <= (i + k);
//	cout << i << endl;
//	a = a++;
//	cout << a << endl;
//	i++;
//	cout << i << endl;
//	i = !a;
//	cout << i << endl;
//	system("pause");
//}

//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//void main()
//{
//	char a, b, c, d;
//	scanf("%c%c", &a, &b);
//	c = getchar();
//	d = getchar();
//	printf("%c%c%c%c\n", a, b, c, d);
//	system("pause");
//}

//#include<iostream>
//using namespace std;
//void main()
//{
//	short N, P, K, i, m;
//	cout << "Input (the number of the pages \"N\" (3-100), present page \"P\" (1-N), the number of the print pages \"K\" (1-N)):" << endl;
//	cin >> N >> P >> K;
//	bool printLeftArror = false, printRightArror = false;
//	if ((i = P - K) > 1) 
//	{ 
//		printLeftArror = true;
//		cout << "<< ";
//	}
//	else
//	{
//		i = 1;
//	}
//	if ((m = P + K) < N)
//	{
//		printRightArror = true;
//	}
//	else
//	{
//		m = N;
//	}
//	for (; i <= m; i++) 
//	{
//		if (i == P)
//		{
//			cout << "(" << i << ") ";
//		}
//		else
//		{
//			cout << i << " ";
//		}
//	}
//	if (printRightArror)
//	{
//		cout << ">>";
//	}
//	cout << endl;
//	system("pause");
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define N 3
//#define M 4
//void fun(int(*a)[N], int k)
//{
//	int i, temp;
//	for ( i = 0; i < N; i++)
//	{
//		temp = a[0][i];
//		a[0][i] = a[k][i];
//		a[k][i] = temp;
//	}
//}
//void main()
//{
//	int x[M][N] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} }, i, j;
//	printf("The array before moving:\n\n");
//	for ( i = 0; i < M; i++)
//	{
//		for ( j = 0; j < N; j++)
//		{
//			printf("%3d", x[i][j]);
//		}
//		printf("\n\n");
//	}
//	fun(x, 2);
//	printf("The array after moving:\n\n");
//	for ( i = 0; i < M; i++)
//	{
//		for ( j = 0; j < N; j++)
//		{
//			printf("%3d", x[i][j]);
//		}
//		printf("\n\n");
//	}
//	system("pause");
//}

//#include<string.h>
//#include<stdio.h>
//#include<stdlib.h>
//void fun(char t[])
//{
//	char c;
//	int i, j;
//	for ( i = strlen(t); i; i--)
//	{
//		for ( j = 0; j < i - 1; j++)
//		{
//			if (t[j] > t[j + 1])
//			{
//				c = t[j];
//				t[j] = t[j + 1];
//				t[j + 1] = c;
//			}
//		}
//	}
//}
//void main()
//{
//	char s[81];
//	printf("\nPlease enter a character string :");
//	gets_s(s);
//	printf("\n\nBefore sorting :\n%s", s);
//	fun(s);
//	printf("\nAfter sorting decendingly:\n%s", s);
//	system("pause");
//}

//#include<conio.h>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//void fun(char *ss)
//{
//	int count = 1;
//	while (ss[count])
//	{
//		if (ss[count] >= 'a' && ss[count] <= 'z')
//		{
//			ss[count] += ('A' - 'a');
//		}
//		count += 2;
//	}
//}
//void main()
//{
//	FILE * wf;
//	char tt[81], s[81] = "abc4Efg";
//	system("CLS");
//	printf("\nPlease enter a string within 80 characters:\n");
//	gets_s(tt);
//	printf("\n\nAfter changing, the string\n%s", tt);
//	fun(tt);
//	printf("\nbecomes\n%s\n", tt);
//	errno_t err = fopen_s(&wf, "out.dat", "w");
//	if (!err)
//	{
//		fun(s);
//		fprintf(wf, "%s", s);
//	}
//	fclose(wf);
//	system("pause");
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define M 3
//#define N 5
//void fun(int(*a)[N], int k)
//{
//	int i, j, p, temp;
//	for ( p = 1; p <= k; p++)
//	{
//		for ( i = 0; i < M; i++)
//		{
//			temp = a[i][0];
//			for ( j = 0; j < N - 1; j++)
//			{
//				a[i][j] = a[i][j + 1];
//			}
//			a[i][N - 1] = temp;
//		}
//	}
//}
//void main()
//{
//	int x[M][N] = { {1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5} }, i, j;
//	printf("The array before moving:\n\n");
//	for ( i = 0; i < M; i++)
//	{
//		for ( j = 0; j < N; j++)
//		{
//			printf("%3d", x[i][j]);
//		}
//		printf("\n");
//	}
//	fun(x, 2);
//	printf("The array after moving:\n\n");
//	for ( i = 0; i < M; i++)
//	{
//		for ( j = 0; j < N; j++)
//		{
//			printf("%3d", x[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//}

//#include<conio.h>
//#include<stdio.h>
//#include<stdlib.h>
//#define M 10
//int a[M][M] = { 0 };
//void fun(int (*a)[M], int m)
//{
//	int j, k;
//	for ( j = 0; j < m; j++)
//	{
//		for ( k = 0; k < m; k++)
//		{
//			a[j][k] = (k + 1) * (j + 1);
//		}
//	}
//}
//void main()
//{
//	int i, j, n;
//	printf("Enter n :");
//	scanf_s("%d", &n);
//	fun(a, n);
//	for ( i = 0; i < n; i++)
//	{
//		for ( j = 0; j < n; j++)
//		{
//			printf("%4d", a[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//}

//#include<stdio.h>
//#include<stdlib.h>
//void fun(int a, int b, long *c)
//{
//	*c = 0;
//	int x, y;
//	for (size_t i = 0; i < 4; i++)
//	{
//		if (i%2)
//		{
//			*c = (b % 10) + (*c) * 10;
//			b /= 10;
//		}
//		else
//		{
//			*c = (a % 10) + (*c) * 10;
//			a /= 10;
//		}
//	}
//}
//void main()
//{
//	int a, b;
//	long c;
//	printf("Input a, b:");
//	scanf_s("%d%d", &a, &b);
//	fun(a, b, &c);
//	printf("The result is:%ld\n", c);
//	system("pause");
//}

//使用c语言对int类数组使用qsort函数
//#include<stdio.h>
//#include<stdlib.h>
//
//int comp(const void*a, const void*b)
//{
//	return *(int*)a - *(int*)b;//升序排列
//}
//
//int *fun(int *a, int n)
//{
//	int size = n * (n - 1) / 2, *m = (int *)malloc(size * sizeof(int)), count = 0, i, j;
//	for ( i = 0; i < n - 1; i++)
//	{
//		for ( j = i + 1; j < n; j++)
//		{
//			*(m + count) = a[i] + a[j];
//			count++;
//			if (count >= size)
//			{
//				return m;
//			}
//		}
//	}
//}
//
//void main()
//{
//	int i = 0;
//	int *array_1;
//	int n;
//	scanf_s("%d", &n);
//	array_1 = (int *)malloc(n * sizeof(int));
//	for (; i < n; i++)
//	{
//		scanf_s("%d", array_1 + i);
//	}
//	int m = n * (n - 1) / 2, *array_2;
//	array_2 = (int *)malloc(n * sizeof(int));
//	array_2 = fun(array_1, n);
//	qsort(array_2, m, sizeof(int), comp);
//	for ( i = 0; i < m; i++)
//	{
//		printf("%d\t", array_2[i]);
//	}
//	printf("\n");
//	system("pause");
//}

//#include<stdio.h>
//#define M 3
//#define N 4
//void fun(int(*a)[N])
//{
//	int i = 0, j, find = 0, rmax, c, k;
//	while ((i < M) && (!find))
//	{
//		rmax = a[i][0];
//		c = 0;
//		for (j = 1; j < N; j++)
//		{
//			if (rmax < a[i][j])
//			{
//				rmax = a[i][j];
//				c = j;
//			}
//		}
//		find = 1;
//		k = 0;
//		while (k < M && find)
//		{
//			if (k != i && a[k][c] <= rmax)
//			{
//				find = 0;
//			}
//			k++;
//		}
//		if (find)
//		{
//			printf("find: a[%d][%d] = %d\n", i, c, a[i][c]);
//		}
//		i++;
//	}
//		if (!find)
//		{
//			printf("not found!\n");
//		}
//}
//void main()
//{
//	int x[M][N], i, j;
//	printf("Enter number for array:\n");
//	for ( i = 0; i < M; i++)
//	{
//		for ( j = 0; j < N; j++)
//		{
//			scanf_s("%d", &x[i][j]);
//		}
//	}
//	printf("The array:\n");
//	for ( i = 0; i < M; i++)
//	{
//		for ( j = 0; j < N; j++)
//		{
//			printf("%3d", x[i][j]);
//		}
//		printf("\n\n");
//	}
//	fun(x);
//}

//#include<stdio.h>
//double fun(int m)
//{
//	double y = 1.0;
//	int i;
//	for ( i = 2; i <= m; i++)
//	{
//		y -= 1 / (double)(i * i);
//	}
//	return y;
//}
//void main()
//{
//	int n = 5;
//	printf("\nThe result is %lf\n", fun(n));
//}

//#include<conio.h>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int fun(int score[], int m, int below[])
//{
//	float avg = 0;
//	for (size_t i = 0; i < m; i++)
//	{
//		avg += score[i];
//	}
//	avg /= m;
//	int count = 0;
//	for (size_t i = 0; i < m; i++)
//	{
//		if (score[i] < avg)
//		{
//			below[count] = score[i];
//			count++;
//		}
//	}
//	return count;
//}
//void main()
//{
//	int i, n, below[9];
//	int score[9] = { 10,20,30,40,50,60,70,80,90 };
//	system("CLS");
//	n = fun(score, 9, below);
//	printf("\nBelow the average score are: ");
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d ", below[i]);
//	}
//}

//#include<stdlib.h>
//#include<conio.h>
//#include<stdio.h>
//int fun(int m)
//{
//	int i, k;
//	for ( i = m + 1;; i++)
//	{
//		for ( k = 2; k < i; k++)
//		{
//			if (i % k == 0)
//			{
//				break;
//			}
//		}
//		if (k == i)
//		{
//			return (i);
//		}
//	}
//}
//void main()
//{
//	int n;
//	system("CLS");
//	printf("\nPlease enter n: ");
//	scanf_s("%d", &n);
//	printf("%d\n", fun(n));
//	system("pause");
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#define N 80
//#pragma warning(disable:4996)
//void fun(char *s, int n, char *t)
//{
//	int len, i, j = 0;
//	len = strlen(s);
//	if (n >= len)
//	{
//		strcpy(t, s);
//	}
//	else
//	{
//		for ( i = len - n; i <= len - 1; i++)
//		{
//			t[j++] = s[i];
//		}
//		t[j] = '\0';
//	}
//}
//void main()
//{
//	char s[N], t[N];
//	int n;
//	printf("Enter a string: ");
//	gets_s(s);
//	printf("Enter n: ");
//	scanf_s("%d", &n);
//	fun(s, n, t);
//	printf("The string t: ");
//	puts(t);
//	system("pause");
//}

//#include<conio.h>
//#include<stdlib.h>
//#include<stdio.h>
//#pragma warning(disable:4996)
//void fun(size_t x, int pp[], int *n)
//{
//	*n = 0;
//	for (int i = 1; i <= x; i += 2)
//	{
//		if (x % i == 0)
//		{
//			pp[(*n)++] = i;
//		}
//	}
//}
//void main()
//{
//	int x, aa[1000], n, i;
//	system("CLS");
//	printf("\nPlease enter an integer number:\n");
//	scanf("%d", &x);
//	fun(x, aa, &n);
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d ", aa[i]);
//	}
//	printf("\n");
//}

//#include<stdio.h>
//int fun(char *s)
//{
//	int n = 0, flag = 0;
//	while (*s != '\0')
//	{
//		if (*s != ' ' && flag == 0)
//		{
//			n++;
//			flag = 1;
//		}
//		if (*s == ' ')
//		{
//			flag = 0;
//		}
//		s++;
//	}
//	return n;
//}
//void main()
//{
//	char str[81];
//	int n;
//	printf("\nEnter a line text:\n");
//	gets_s(str);
//	n = fun(str);
//	printf("\nThere are %d words in this text.\n\n", n);
//}

//#include<stdlib.h>
//#include<stdio.h>
//#include<conio.h>
//#define N 20
//int fun(float *s, int n, float *aver)
//{
//	float ave, t = 0.0;
//	int count = 0, k, i;
//	for ( k = 0; k < n; k++)
//	{
//		t += s[k];
//	}
//	ave = t / n;
//	for ( i = 0; i < n; i++)
//	{
//		if (s[i] < ave)
//		{
//			count++;
//		}
//	}
//	*aver = ave;
//	return count;
//}
//void main()
//{
//	float s[30], aver;
//	int m, i;
//	system("CLS");
//	printf("\nPlease enter m: ");
//	scanf_s("%d", &m);
//	printf("\nPlease enter %d mark:\n", m);
//	for ( i = 0; i < m; i++)
//	{
//		scanf_s("%f", s + i);
//	}
//	printf("\nThe number of students: %d\n", fun(s, m, &aver));
//	printf("Ave = %f\n", aver);
//	system("pause");
//}

//#include<stdlib.h>
//#include<stdio.h>
//#include<conio.h>
//int fun(int *s, int t, int *k)
//{
//	*k = 0;
//	for (int i = 1; i < t; i++)
//	{
//		if (s[i] > s[*k])
//		{
//			*k = i;
//		}
//	}
//	return 0;
//}
//void main()
//{
//	int a[10] = { 876, 675, 896, 101, 301, 401, 980 ,431, 451, 777 }, k;
//	system("CLS");
//	fun(a, 10, &k);
//	printf("%d, %d\n", k, a[k]);
//}

//#include<stdio.h>
//int fun(char *s, char *t)
//{
//	int n = 0;
//	while (*s)
//	{
//		if (*s < 97)
//		{
//			*(t + n) = *s;
//			n++;
//		}
//		s++;
//	}
//	*(t + n) = 0;
//	return n;
//}
//void main()
//{
//	char s[81], t[81];
//	int n;
//	printf("\nEnter a string:\n");
//	gets_s(s);
//	n = fun(s, t);
//	printf("\nThere are %d letter which ASCII code is less than 97: %s\n", n, t);
//}

//#include<stdlib.h>
//#include<conio.h>
//#include<stdio.h>
//int fun(float x[], int n)
//{
//	int j, c = 0;
//	float xa = 0.0;
//	for ( j = 0; j < n; j++)
//	{
//		xa += x[j] / n;
//	}
//	printf("ave = %f\n", xa);
//	for ( j = 0; j < n; j++)
//	{
//		if (x[j] >= xa)
//		{
//			c++;
//		}
//	}
//	return c;
//}
//void main()
//{
//	float x[100] = {
//		193.199,195.673,195.757,196.051,196.092,196.596,196.579,196.763
//	};
//	system("CLS");
//	printf("%d\n", fun(x, 8));
//	getchar();
//}

//#include<stdio.h>
//float fun(int m, int n)
//{
//	int i, a, b, c = 1;
//	for ( i = 1; i <= m; i++)
//	{
//		c *= i;
//		if (i == n)
//		{
//			a = c;
//		}
//		else if (i == m - n)
//		{
//			b = c;
//		}
//	}
//	return c / (a * b);
//}
//void main()
//{
//	printf("P = C(12,8) = %f\n", fun(12, 8));
//}

//#include<stdio.h>
//#include<stdlib.h>
//#define N 8
//typedef struct list
//{
//	int data;
//	struct list *next;
//}SLIST;
//SLIST *createlist(char *);
//void outlist(SLIST *);
//int fun(SLIST *h, char ch)
//{
//	SLIST *p;
//	int n = 0;
//	p = h->next;
//	while (p != NULL)
//	{
//		n++;
//		if (p->data == ch)
//		{
//			return n;
//		}
//		else
//		{
//			p = p->next;
//		}
//	}
//	return 0;
//}
//void main()
//{
//	SLIST *head;
//	int k;
//	char ch;
//	char a[N] = { 'm','p','g','a','w','x','r','d' };
//	head = createlist(a);
//	outlist(head);
//	printf("Enter a letter:");
//	scanf_s("%c", &ch);
//	k = fun(head, ch);
//	if (k == 0)
//	{
//		printf("\nNot found!\n");
//	}
//	else
//	{
//		printf("The sequence number is %d\n", k);
//	}
//	system("pause");
//}
//SLIST *createlist(char *a)
//{
//	SLIST *h, *p, *q;
//	int i;
//	h = p = (SLIST *)malloc(sizeof(SLIST));
//	for ( i = 0; i < N; i++)
//	{
//		q = (SLIST *)malloc(sizeof(SLIST));
//		q->data = a[i];
//		p->next = q;
//		p = q;
//	}
//	p->next = 0;
//	return h;
//}
//void outlist(SLIST *h)
//{
//	SLIST *p;
//	p = h->next;
//	if (p == NULL)
//	{
//		printf("\nThe list if NULL!\n");
//	}
//	else
//	{
//		printf("\nHead");
//		do
//		{
//			printf("->%c", p->data);
//			p = p->next;
//		} while (p != NULL);
//		printf("->End\n");
//	}
//}

//#include<string.h>
//#include<stdio.h>
//#include<ctype.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//void fun(char *p)
//{
//	int i, t;
//	char c[80];
//	for ( i = 0, t = 0; p[i]; i++)
//	{
//		if (!isspace(*(p + i)))
//		{
//			c[t++] = p[i];
//		}
//	}
//	c[t] = '\0';
//	strcpy(p, c);
//}
//void main()
//{
//	char c, s[80];
//	int i = 0;
//	printf("Input a string:");
//	c = getchar();
//	while (c != '#')
//	{
//		s[i] = c;
//		i++;
//		c = getchar();
//	}
//	s[i] = '\0';
//	fun(s);
//	puts(s);
//	system("pause");
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#define N 2
//struct KEY	//定义密钥结构体
//{
//	int a, b;
//};
//int gcd(int b, int c)	//求 b 和 c 最大公约数
//{
//	if (c == 0)
//	{
//		return b;
//	}
//	else
//	{
//		return gcd(c, b % c);
//	}
//}
//int inv(int a, int r)	//求 a 对于模 r 的乘逆
//{
//	int sum = 1;
//	while(sum % a)
//	{
//		sum += r;
//	}
//	return (sum / a);
//}
//int ouler(int p, int q)	//求 p * q = n 的欧拉函数值
//{
//	return (p - 1) * (q - 1);
//}
//void RSA_KEY_GET_n(int p, int q, int *n, int *fi)	//求密钥中 n 的值， 并获得其欧拉函数值
//{
//	*n = p * q;
//	*fi = ouler(p, q);
//}
//void RSA_KEY_GET_e(int fi, int *e)	//求公钥中 e 的值，本题中因其值已明确给出而不需要求
//{
//	do
//	{
//		*e = 1 + (int)((double)fi * rand() / (RAND_MAX + 1));
//		if (*e < fi && gcd(fi, *e) == 1)
//		{
//			break;
//		}
//	} while (true);
//}
//void RSA_KEY_GET_d(int e, int fi, int *d)	//求私钥中 d 的值
//{
//	*d = inv(e, fi);
//}
//void RSA_KEY(KEY *pk, KEY *sk, int p, int q)	//获得公钥和私钥
//{
//	int fi;
//	RSA_KEY_GET_n(p, q, &sk->b, &fi);
//	pk->b = sk->b;
//	//RSA_KEY_GET_e(fi, &pk->a);
//	pk->a = 13;	//本题中已明确 e = 3
//	RSA_KEY_GET_d(pk->a, fi, &sk->a);
//}
//void RSA_E(KEY pk, long *M, long *C)	//用公钥加密将要输出的明文
//{
//	for (int i = 0;i < N; i++)
//	{
//		long x = M[i], y;
//		unsigned long long z;
//		z = pow(x, pk.a);
//		y = z % pk.b;
//		C[i] = y;
//	}
//}
//void RSA_D(KEY sk, long *C, long *M)	//用私钥解密获得的密文
//{
//	for (int i = 0; i < N; i++)
//	{
//		long x = C[i], y;
//		unsigned long long z;
//		z = pow(x, sk.a);
//		y = z % sk.b;
//		M[i] = y;
//	}
//}
//void RSA(int p, int q,int e, long *m)	//使用 RSA 算法，并输出公钥、密钥、密文、明文
//{
//	KEY pk, sk;
//	long *ciphertext, *c, *plaintext;
//	ciphertext = c = plaintext = (long *)malloc(sizeof(long) * N);
//	RSA_KEY(&pk, &sk, p, q);
//	pk.a = e;//本题中e已明确
//	printf("公钥（e，n）为（%d ，%d）\n私钥（d，n）为（%d ，%d）\n", pk.a, pk.b, sk.a, sk.b);
//	RSA_E(pk, m, ciphertext);
//	c = ciphertext;
//	printf("密文为：\t");
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d\t", *(c + i));
//	}
//	printf("\n明文为：\t");
//	RSA_D(sk, ciphertext, plaintext);
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d\t", *(plaintext + i));
//	}
//	printf("\n");
//}
//void main()
//{
//	long m[N] = { 15, 11 };
//	printf("Plaintext:\t");
//	//for (int i = 0; i < N; i++)
//	//{
//	//	scanf_s("%ld", &m[i]);
//	//}
//	int p, q, e;
//	printf("\nInput p, q, e:\t");
//	scanf_s("%d%d%ld", &p, &q, &e);
//	RSA(p, q, e, m);
//	system("pause");
//}

//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//void main()
//{
//	ifstream infile("C:\\Users\\蒋彦\\Desktop\\matlab课件\\matlab作业截图\\批注 2019-10-17 191520.png", ios::in | ios::binary);
//	
//	int count = 0;
//	while (!infile.eof())
//	{
//		int t = infile.get();
//		count++;
//		//cout << infile.get() << ' ';
//	}
//	cout << count << endl;
//	
//	infile.close();
//	cout << endl;
//	system("pause");
//}

//#include<stdio.h>
//#include<string.h>
//#pragma warning(disable:4996)
//
//void fun(char *str)
//{
//	char buffer[16];
//	strcpy(buffer, str);
//}
//
//int main()
//{
//	char large_string[256];
//	int i;
//	for ( i = 0; i < 256; i++)
//	{
//		large_string[i] = 'A';
//	}
//	fun(large_string);
//	getchar();
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//void fun(int a)
//{
//	char buffer[5];
//	char *ret;
//	ret = buffer + 12;
//	*ret += 8;
//}
//
//void main()
//{
//	int x;
//	x = 10;
//	fun(7);
//	x = 1;
//	cout << x << endl;
//	system("pause");
//}

//#include<iostream>
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//
//using namespace std;
//using namespace cv;
//
//void main()
//{
//	Mat img;
//	imshow("../data/ik_beijing_c.bmp", img);
//	if (img.empty())
//	{
//		cout << "Error" << endl;
//	}
//	namedWindow("pic");
//	imshow("pic", img);
//	waitKey(0);
//
//	unsigned char * pImg = img.data;
//	int cols = img.cols;
//	int rows = img.rows;
//	int channels = img.channels();
//
//	Mat image_gray;
//	image_gray.create(rows, cols, CV_8UC1);
//	unsigned char *pImg_copy = image_gray.data;
//
//	for (int irow = 0; irow < rows; irow++)
//	{
//		for (int jcol = 0; jcol < cols; jcol++)
//		{
//			unsigned char temp;
//			unsigned char bvalue = pImg[(irow * cols + jcol) * channels];
//			unsigned char gvalue = pImg[(irow * cols + jcol) * channels + 1];
//			unsigned char rvalue = pImg[(irow * cols + jcol) * channels + 2];
//			temp = (rvalue + gvalue + bvalue) / 3;          //这个地方有更好额写法，因为会越界
//
//			pImg_copy[irow * cols + jcol] = temp;
//		}
//	}
//	imshow("Display window", image_gray);
//	//imwrite("../data/ik_beijing_c.tif", image_gray);
//	waitKey(0); // Wait for a keystroke in the window
//
//	system("pause");
//}

//#include<iostream>
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//
//using namespace std;
//using namespace cv;
//
//string str1 = "C:/Users/蒋彦/Desktop/Lena.jpg";
//string str2 = "C:/Users/蒋彦/Desktop/Lena_Gray.jpg";

//void onMouse(int event, int x, int y, int flags, void *param)
//{
//	Mat *im = reinterpret_cast<Mat*>(param);
//	switch (event)
//	{
//	case CV_EVENT_LBUTTONDOWN:
//		cout << "at (" << x << "," << y << ") value is: "
//			<< static_cast<int>(im->at<uchar>(Point(x, y))) << endl;
//	default:
//		break;
//	}
//}
//
//
//void f_1_3()
//{
//	Mat ImageColor = imread(str1,0);
//	//Mat ImageGray = imread(str1, CV_LOAD_IMAGE_GRAYSCALE);
//	namedWindow("color");
//	circle(ImageColor, Point(ImageColor.cols / 2, ImageColor.rows / 2), 50, 0, 3);
//	putText(ImageColor, "This is Lena",
//		Point(ImageColor.cols / 6, 3 * ImageColor.rows / 4),
//		FONT_HERSHEY_PLAIN, 1.4, 255, 2);
//	imshow("color", ImageColor);
//	setMouseCallback("color", onMouse, reinterpret_cast<void*>(&ImageColor));
//	//namedWindow("gray");
//	//imshow("gray", ImageGray);
//	//Mat result;
//	//flip(ImageGray, result, -1);
//	//imshow("flip", result);
//	waitKey();
//	//imwrite(str2, ImageGray);
//}

//void f_1_4()
//{
//	Mat image1(240, 320, CV_8UC1);
//	image1 = 100;
//	namedWindow("Image");
//	imshow("Image", image1);
//	waitKey(0);
//
//	image1.create(200, 200, CV_8UC1);
//	image1 = 200;
//
//	imshow("Image", image1);
//	waitKey(0);
//
//	Mat image2(Size(240, 320), CV_8UC3);
//	image2 = Scalar(0, 0, 255);
//
//	imshow("Image", image2);
//	waitKey(0);
//
//	Mat image3 = imread(str2);
//	Mat image4(image3);
//	image1 = image3;
//
//	image3.copyTo(image2);
//	Mat image5 = image3.clone();
//
//	flip(image3, image3, 1);
//
//	namedWindow("Image 1");
//	namedWindow("Image 2");
//	namedWindow("Image 3");
//	namedWindow("Image 4");
//	namedWindow("Image 5");
//
//	imshow("Image 3", image3);
//	imshow("Image 1", image1);
//	imshow("Image 2", image2);
//	imshow("Image 4", image4);
//	imshow("Image 5", image5);
//	waitKey(0);
//
//	Mat gray(500, 500, CV_8UC1);
//	gray = 50;
//	imshow("Image", gray);
//	waitKey(0);
//
//	image1 = imread(str1, CV_LOAD_IMAGE_GRAYSCALE);
//	image1.convertTo(image2, CV_32F, 1 / 255.0, 0.0);
//	imshow("Image", image2);
//	waitKey(0);
//
//
//}

//void f_1_5()
//{
//	//Ptr<IplImage> iplImage = cvLoadImage("C:/Users/蒋彦/Desktop/family.jpg");
//	//IplImage* iplImage = cvLoadImage("C:/Users/蒋彦/Desktop/family.jpg");
//	//Mat image(iplImage, false);
//	//cvReleaseImage(&iplImage);
//	Mat logo = imread(str2);
//	Mat image = imread("C:/Users/蒋彦/Desktop/BlackMe.jpg",1);
//	//Mat imageROI(image,
//	//	Rect(image.cols - logo.cols, image.rows - logo.rows, logo.cols, logo.rows));
//	Mat imageROI = image(
//		Range(image.rows - logo.rows, image.rows),
//		Range(image.cols - logo.cols, image.cols));
//	Mat mask(logo);
//	logo.copyTo(imageROI, mask);
//	imshow("Image", image);
//	waitKey(0);
//}

//#include<iostream>
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//
//using namespace std;
//using namespace cv;
//
//string str1 = "C:/Users/蒋彦/Desktop/Lena.jpg";
//string str2 = "C:/Users/蒋彦/Desktop/Lena_Gray.jpg";
//
//void salt(Mat image, int n)
//{
//	int i, j;
//	for (int k = 0; k < n; k++)
//	{
//		i = rand() % image.cols;
//		j = rand() % image.rows;
//		if (image.type() == CV_8UC1)
//		{
//			image.at<uchar>(j, i) = 255;
//		}
//		else if (image.type() == CV_8UC3)
//		{
//			//image.at<Vec3b>(j, i) = Vec3b(255, 255, 255);
//			image.at<Vec3b>(j, i)[0] = 255;
//			image.at<Vec3b>(j, i)[1] = 255;
//			image.at<Vec3b>(j, i)[2] = 255;
//		}
//	}
//}
//
//void f_2_2()
//{
//	Mat image = imread(str2);
//	namedWindow("Image1");
//	imshow("Image1", image);
//	waitKey(0);
//	salt(image, 3000);
//	namedWindow("Image2");
//	imshow("Image2", image);
//	waitKey(0);
//}
//
//void colorReduce(const Mat &image, Mat &result, int div = 64)
//{
//	int nl = image.rows;
//	int nc = image.cols * image.channels();
//	for (int j = 0; j < nl; j++)
//	{
//		const uchar* data_in = image.ptr<uchar>(j);
//		uchar* data_out = result.ptr<uchar>(j);
//		for (int i = 0; i < nc; i++)
//		{
//			//data[i] = int(data[i] / div) * div + div / 2;
//			data_out[i] = data_in[i] - data_in[i] % div + div / 2;
//		}
//	}
//}
//
//void f_2_3()
//{
//	Mat img = imread(str2);
//	Mat result;
//	result.create(img.rows, img.cols, img.type());
//	colorReduce(img, result);
//	namedWindow("Image");
//	imshow("Image", img);
//	namedWindow("Result");
//	imshow("Result", result);
//	waitKey(0);
//}
//
//void main()
//{
//	f_2_3();
//	system("pause");
//}

//#include<iostream>
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//
//using namespace std;
//using namespace cv;
//
//string str1 = "C:/Users/蒋彦/Desktop/Lena.jpg";
//string str2 = "C:/Users/蒋彦/Desktop/Lena_Gray.jpg";

//void colorReduce(Mat &image,int div = 64)
//{
//	Mat_<Vec3b>::iterator it = image.begin<Vec3b>();
//	Mat_<Vec3b>::iterator itend = image.end<Vec3b>();
//	for (; it != itend; ++it)
//	{
//		(*it)[0] = ((*it)[0] / div) * div + div / 2;
//		(*it)[1] = ((*it)[1] / div) * div + div / 2;
//		(*it)[2] = ((*it)[2] / div) * div + div / 2;
//	}
//}
//
//void f_2_4()
//{
//	Mat img = imread(str1);
//	//Mat result;
//	//result.create(img.rows, img.cols, img.type());
//	colorReduce(img, 64);
//	namedWindow("Image");
//	imshow("Image", img);
//	//namedWindow("Result");
//	//imshow("Result", result);
//	waitKey(0);
//}

//void sharpen(const Mat &image, Mat &result)
//{
//	result.create(image.size(), image.type());
//	int nchannels = image.channels();
//	for (int j = 1; j < image.rows - 1; j++)
//	{
//		const uchar* previous = image.ptr<uchar>(j - 1);
//		const uchar* current = image.ptr<uchar>(j);
//		const uchar* next = image.ptr<uchar>(j + 1);
//		uchar* output = result.ptr<uchar>(j);
//		for (int i = nchannels; i < (image.cols - 1) * nchannels; i++)
//		{
//			*output++ = saturate_cast<uchar>
//				(5 * current[i] - current[i - nchannels] - current[i + nchannels]
//					- previous[i] - next[i]);
//		}
//	}
//	result.row(0).setTo(Scalar(0));
//	result.row(result.rows - 1).setTo(Scalar(0));
//	result.col(0).setTo(Scalar(0));
//	result.col(result.cols - 1).setTo(Scalar(0));
//}
//
//void sharpen2D(const Mat &image, Mat &result)
//{
//	Mat kernel(3, 3, CV_32F, Scalar(0));
//	kernel.at<float>(1, 1) = 5.0;
//	kernel.at<float>(0, 1) = -1.0;
//	kernel.at<float>(2, 1) = -1.0;
//	kernel.at<float>(1, 0) = -1.0;
//	kernel.at<float>(1, 2) = -1.0;
//	filter2D(image, result, image.depth(), kernel);
//}
//
//void f_2_6()
//{
//	Mat img1 = imread(str2);
//	Mat img2;
//	//sharpen(img1, img2);
//	sharpen2D(img1, img2);
//	imshow("result", img2);
//	waitKey(0);
//}
//
//void main()
//{
//	f_2_6();
//	system("pause");
//}

//#include<iostream>
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//
//using namespace std;
//using namespace cv;
//
//string str1 = "C:/Users/蒋彦/Desktop/Lena.jpg";
//string str2 = "C:/Users/蒋彦/Desktop/Lena_Gray.jpg";
//
//int getColorDistance(const Vec3b& color1, const Vec3b& color2)
//{
//	////	方法1
//	//return abs(color1[0] - color2[0])
//	//	+ abs(color1[1] - color2[1])
//	//	+ abs(color1[2] - color2[2]);
//
//	////	方法2
//	//return static_cast<int>(
//	//	norm<int, 3>(Vec3i(color1[0] - color2[0],
//	//		color1[1] - color2[1],
//	//		color1[2] - color2[2]))
//	//	);
//
//	//	方法3
//	Vec3b dist;
//	absdiff(color1, color2, dist);
//	return sum(dist)[0];
//}
//
//class ColorDetector
//{
//public:
//
//	ColorDetector() :maxDist(250), target(0, 0, 0) {};
//
//	ColorDetector(uchar blue, uchar green, uchar red, int maxDist = 100)
//		:maxDist(maxDist)
//	{
//		setTargetColor(blue, green, red);
//	};
//
//	//~ColorDetector();
//
//	int getDistanceToTargetColor(const Vec3b& color) const
//	{
//		return getColorDistance(color, target);
//	};
//
//	void setColorDistanceThreshold(int distance)
//	{
//		if (distance < 0)
//		{
//			distance = 0;
//		}
//		maxDist = distance;
//	};
//
//	int getColorDistanceThreshold() const
//	{
//		return maxDist;
//	};
//
//	void setTargetColor(uchar blue, uchar green, uchar red)
//	{
//		target = Vec3b(blue, green, red);
//	};
//
//	void setTargetColor(Vec3b color)
//	{
//		target = color;
//	};
//	
//	Vec3b getTargetColor() const
//	{
//		return target;
//	};
//
//	Mat operator()(const Mat& image)
//	{
//		result.create(image.size(), CV_8UC1);
//		Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
//		Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
//		Mat_<uchar>::iterator itout = result.begin<uchar>();
//		for (; it != itend ; it++, itout++)
//		{
//			if (getDistanceToTargetColor(*it) <= maxDist)
//			{
//				*itout = 255;
//			}
//			else
//			{
//				*itout = 0;
//			}
//		}
//		return result;
//	}
//
//	Mat process(Mat& image);
//
//private:
//
//	int maxDist;
//	Vec3b target;
//	Mat result;
//
//};
//
//Mat ColorDetector::process(Mat & image)
//{
//	result.create(image.size(), CV_8UC1);
//
//	////	方法1
//	//Mat_<Vec3b>::const_iterator it = image.begin<Vec3b>();
//	//Mat_<Vec3b>::const_iterator itend = image.end<Vec3b>();
//	//Mat_<uchar>::iterator itout = result.begin<uchar>();
//	//for (; it != itend ; it++, itout++)
//	//{
//	//	if (getDistanceToTargetColor(*it) <= maxDist)
//	//	{
//	//		*itout = 255;
//	//	}
//	//	else
//	//	{
//	//		*itout = 0;
//	//	}
//	//}
//	//return result;
//
//	//	方法2
//	Mat output;
//	absdiff(image, Scalar(target), output);
//	vector<Mat>images;
//	split(output, images);
//	output = images[0] + images[1] + images[2];
//	threshold(output, result, maxDist, 255, THRESH_BINARY_INV);
//	return result;
//}
//
//class ColorDectectController
//{
//public:
//
//	ColorDectectController()
//	{
//		cdetect = new ColorDetector();
//	}
//
//	~ColorDectectController()
//	{
//		delete cdetect;
//	}
//
//	void setColorDistanceThreshold(int distance)
//	{
//		cdetect->setColorDistanceThreshold(distance);
//	}
//
//	int getColorDistanceThreshold() const
//	{
//		return cdetect->getColorDistanceThreshold();
//	}
//
//	void setTargetColor(uchar red, uchar green, uchar blue)
//	{
//		cdetect->setTargetColor(blue, green, red);
//	}
//
//	void getTargetColor(uchar &red, uchar &green, uchar &blue) const
//	{
//		Vec3b color = cdetect->getTargetColor;
//		red = color[2];
//		green = color[1];
//		blue = color[0];
//	}
//
//	bool setInputImage(string filename)
//	{
//		image = imread(filename);
//		return !image.empty();
//	}
//
//	const Mat getInputImage() const
//	{
//		return image;
//	}
//
//	void process()
//	{
//		result = cdetect->process(image);
//	}
//
//	const Mat getLastResult()const
//	{
//		return result;
//	}
//
//private:
//
//	ColorDetector* cdetect;
//	Mat image;
//	Mat result;
//
//};
//
//int main()
//{
//	ColorDetector cdetect;
//
//	Mat image = imread(str1);
//	if (image.empty())
//	{
//		return 0;
//	}
//
//	cdetect.setTargetColor(230, 190, 130);
//
//	namedWindow("result");
//	imshow("result", cdetect.process(image));
//	waitKey(0);
//
//	ColorDetector colordetector(230, 190, 130, 250);
//	Mat result = colordetector(image);
//
//	namedWindow("result2");
//	imshow("result2", result);
//	waitKey(0);
//
//	return 1;
//}

//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core/core.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//
//using namespace std;
//using namespace cv;
//
//string str1 = "C:/Users/蒋彦/Desktop/Lena.jpg";
//string str2 = "C:/Users/蒋彦/Desktop/Lena_Gray.jpg";
//
//class Histogram1D
//{
//public:
//	Histogram1D()
//	{
//		histSize[0] = 256;
//		hranges[0] = 0.0;	//	从0开始（含）
//		hranges[1] = 256.0;	//	到256（不含）
//		ranges[0] = hranges;
//		channels[0] = 0;
//	}
//	
//	Mat getHistogram(const Mat& image)
//	{
//		Mat hist;
//		calcHist(
//			&image,
//			1,			//	仅为一个图像的直方图
//			channels,
//			Mat(),		//	不适用掩码
//			hist,
//			1,			//	这是一维的直方图
//			histSize,
//			ranges
//		);
//		return hist;
//	}
//
//	static Mat getImageOfHistogram(const Mat& hist, int zoom)
//	{
//		double maxVal = 0;
//		double minVal = 0;
//		minMaxLoc(hist, &minVal, &maxVal, 0, 0);
//		int histSize = hist.rows;
//		Mat histImg(histSize * zoom, histSize * zoom, CV_8U, Scalar(255));
//		int hpt = static_cast<int>(0.9 * histSize);
//		for (int h = 0; h < histSize; h++)
//		{
//			float binVal = hist.at<float>(h);
//			if (binVal > 0)
//			{
//				int intensity = static_cast<int>(binVal * hpt / maxVal);
//				line(histImg, Point(h * zoom, histSize * zoom),
//					Point(h * zoom, (histSize - intensity) * zoom),
//					Scalar(0), zoom);
//			}
//		}
//		return histImg;
//	}
//
//	Mat getHistogramImage(const Mat& image, int zoom = 1)
//	{
//		Mat hist = getHistogram(image);
//		return getImageOfHistogram(hist, zoom);
//	}
//
//	//~Histogram1D();
//
//private:
//
//	int histSize[1];
//	float hranges[2];
//	const float* ranges[1];
//	int channels[1];
//
//};
//
//class ColorHistogram
//{
//public:
//	ColorHistogram()
//	{
//		histSize[0] = histSize[1] = histSize[2] = 256;
//		hranges[0] = 0.0;
//		hranges[1] = 256.0;
//		ranges[0] = hranges;
//		ranges[1] = hranges;
//		ranges[2] = hranges;
//		channels[0] = 0;
//		channels[1] = 1;
//		channels[2] = 2;
//	}
//
//	Mat getHistogram(const Mat& image)
//	{
//		Mat hist;
//		hranges[0] = 0.0;
//		hranges[1] = 256.0;
//		channels[0] = 0;
//		channels[1] = 1;
//		channels[2] = 2;
//		calcHist(&image,
//			1,
//			channels,
//			Mat(),
//			hist,
//			3,
//			histSize,
//			ranges
//		);
//		return hist;
//	}
//
//	SparseMat getSparseHistogram(const Mat& image)
//	{
//		SparseMat hist(3, histSize, CV_32F);
//		hranges[0] = 0.0;
//		hranges[1] = 256.0;
//		channels[0] = 0;
//		channels[1] = 1;
//		channels[2] = 2;
//		calcHist(&image,
//			1,
//			channels,
//			Mat(),
//			hist,
//			3,
//			histSize,
//			ranges
//		);
//		return hist;
//	}
//
//	static Mat getImageOfHistogram(const Mat& hist, int zoom)
//	{
//		double maxVal = 0;
//		double minVal = 0;
//		minMaxLoc(hist, &minVal, &maxVal, 0, 0);
//		int histSize = hist.rows;
//		Mat histImg(histSize * zoom, histSize * zoom,
//			CV_8U, Scalar(255, 255, 255));
//		int hpt = static_cast<int>(0.9 * histSize);
//		for (int h = 0; h < histSize; h++)
//		{
//			float binVal = hist.at<float>(h);
//			if (binVal > 0)
//			{
//				int intensity = static_cast<int>(binVal * hpt / maxVal);
//				line(histImg, Point(h * zoom, histSize * zoom),
//					Point(h * zoom, (histSize - intensity) * zoom),
//					Scalar(0, 0, 0), zoom);
//			}
//		}
//		return histImg;
//	}
//
//	Mat getHistogramImage(const Mat& image, int zoom = 1)
//	{
//		Mat hist = getHistogram(image);
//		return getImageOfHistogram(hist, zoom);
//	}
//
//private:
//	int histSize[3];
//	float hranges[2];
//	const float* ranges[3];
//	int channels[3];
//};
//
//newIntensity = lookup[oldIntensity];
//static Mat applyLookUp()
//
//void main()
//{
//	Mat image = imread(str1);
//	ColorHistogram h;
//	Mat histo = h.getHistogram(image);
//	for (int i = 0; i < 256; i++)
//	{
//		for (int j = 0; j < 256; j++)
//		{
//			for (int k = 0; k < 256; k++)
//			{
//				if (*histo.ptr<Vec3b>(i, j, k) != Vec3b(0, 0, 0))
//				{
//					cout << "Value\t" << i << '\t' << j << '\t' << k
//						<< "\t=\t" << *histo.ptr<Vec3b>(i, j, k) << endl;
//				}
//			}
//		}
//	}
//	namedWindow("hist");
//	imshow("hist", h.getHistogramImage(image));
//	waitKey(0);
//	system("pause");
//}

#include<iostream>
#include<opencv2/calib3d/calib3d.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include "practice.h"

using namespace std;
using namespace cv;

Mat fun(Mat& img)
{
	Mat result(img.size(), CV_8UC3);
	Mat_<Vec3b>::iterator itResult = result.begin<Vec3b>();
	Mat_<Vec3b>::iterator itImg = img.begin<Vec3b>();
	Mat_<Vec3b>::iterator itImgEnd = img.end<Vec3b>();
	long  sum = 0;
	for (; itImg != itImgEnd; itImg++)
	{
		sum += (long)(*itImg)[2];
		if ((*itImg)[2] == 0){}
		else
		{
			(*itResult)[0] = (uchar)((*itImg)[0] / sqrt((*itImg)[2]));
			(*itResult)[1] = (uchar)((*itImg)[1] / sqrt((*itImg)[2]));
		}
		(*itResult)[2] = 1;
	}
	uchar red = uchar(sum / (img.rows * img.cols));
	cout << (int)red << endl;
	for (itImg = img.begin<Vec3b>(); itImg != itImgEnd; itImg++)
	{
		(*itResult)[2] = red;
	}
	return result;
}

void main()
{
	string s;
	cout << "请输入路径" << endl;
	cin >> s;
	Mat img1 = imread(s);
	if (img1.empty())
	{
		cout << "图像读入失败" << endl;
		return;
	}
	else if (img1.channels()!=3)
	{
		cout << "img1的channels为 " << img1.channels()
			<< "。输入灰度图像，不可处理" << endl;
		return;
	}
	else
	{
		Mat img2 = fun(img1);
		namedWindow("result");
		imshow("result", img2);
		waitKey(0);
	}
	system("pause");
}
