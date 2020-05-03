#include<iostream>
#include<fstream>

using namespace std;

struct Date
{
	char date[30];
	
};

class Money_Rate
{
public:
	Money_Rate();
	~Money_Rate();
	char Country[30];
	char Currency[30];
	char Currency_code[30];
	double Currency_units_per;
	Date Start_date, End_date;

private:

};

Money_Rate::Money_Rate()
{
	strcpy_s(Country, "0");
	strcpy_s(Currency, "0");
	strcpy_s(Currency_code, "0");
	Currency_units_per = 0.0;
	Start_date = { 0 };
	End_date = { 0 };
}

Money_Rate::~Money_Rate()
{
}

ifstream infile("C:\\Users\\蒋彦\\Desktop\\李大鸟憨憨\\exrates.csv", ios::in);
Money_Rate Data_Frame[168];

void Give_Value(char *s, Money_Rate *mr)
{
	int count = 0;
	char *a = s;
	while (*a != '\n' && *a != '\0')
	{
		char *b = new char[30];
		b = a;
		char *c = new char[30];
		c = b;
		for ( ;  *a != ',' && *a != '\n' ; a++)
		{
			*(c++) = *a;
		}
		*c = '\0';
		switch (count)
		{
		case 0:
			strcpy_s(mr->Country, b);
			count++;
			break;
		case 1:
			strcpy_s(mr->Currency, b);
			count++;
			break;
		case 2:
			strcpy_s(mr->Currency_code, b);
			count++;
			break;
		case 3:
			mr->Currency_units_per = atof(b);
			count++;
			break;
		case 4:
			strcpy_s(mr->Start_date.date, b);
			count++;
			break;
		case 5:
			strcpy_s(mr->End_date.date, b);
			count++;
			break;
		default:
			break;
		}
		if (!c)
		{
			delete[]c;
		}
		c = NULL;
		if (!b)
		{
			delete[]b;
		}
		b = NULL;
		a++;
	}
}

//根据国家名字找对应汇率
double search(const char* cntry)
{
	int i = -1;
	while (strcmp(cntry, (Data_Frame[++i].Country))) {};
	return Data_Frame[i].Currency_units_per;
}

//第一问
void f1()
{
	char *frame = new char[100];
	infile.getline(frame, 100);
	delete[]frame;
	frame = NULL;
	int i = 0;
	while (!infile.eof())
	{
		char *str = new char[100];
		infile.getline(str, 100);
		Give_Value(str, &Data_Frame[i]);
		i++;
		delete[]str;
		str = NULL;
	}
	infile.close();
}

//第二问
void f2()
{
	string s1 = "USA", s2 = "China";
	double c1 = search(s1.c_str()), c2 = search(s2.c_str());
	cout << "USA: " << c1 << '\t' << "China: " << c2
		<< '\n' << "USA/China: " << c1 / c2 << endl;
}

//第三问
void f3()
{
	double avg = 0;
	int max, min;
	max = min = 0;
	int i = 0;
	for ( ;	Data_Frame[i].Currency_units_per != 0; i++)
	{
		avg += Data_Frame[i].Currency_units_per;
		if (Data_Frame[min].Currency_units_per > Data_Frame[i].Currency_units_per)
		{
			min = i;
		}
		if (Data_Frame[max].Currency_units_per < Data_Frame[i].Currency_units_per)
		{
			max = i;
		}
	}
	avg /= i;
	cout << i << endl;
	cout << "汇率最大和最小的国家分别为："
		<< Data_Frame[max].Country << '\t' << Data_Frame[min].Country << '\n'
		<< "汇率值的均值为：" << avg << endl;
}

void f4()
{
	double usaRate = search("USA");
	int count = 0;
	int *num = new int[168];
	for (int i = 0; i < 168; i++)
	{
		if (Data_Frame[i].Currency_units_per < usaRate)
		{
			num[count++] = i;
		}
	}
	cout << "比USA小的行有：" << endl;
	for (int j = 0; j < count; j++)
	{
		cout << num[j] << '\t';
	}
	cout << endl;
}

void main()
{
	f1();
	f2();
	f3();
	f4();
	system("pause");
}