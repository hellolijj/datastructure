#include <stdio.h>
#define  MaxSize  10

typedef struct           //集合结构体类型
{
	int data[MaxSize];   //存放集合中的元素,其中MaxSsize为常量
	int length;           //存放集合中实际的元素个数
}Set;                    //讲集合结构体类型用一个新的类型名Set表示

/*创建一个集合*/
void createSet(Set& s, int a[], int n)
{
	int i;
	for (i = 0;i < n; i++)
	{
		s.data[i] = a[i];
		s.length = n;
	}
}

/*输出一个集合*/
void dispest(Set s)
{
    int i;
    for (i = 0; i < s.length; i++)
    {
        printf("%d", s.data);
    }
    printf("\n");
}

/*判断一个元素是否在集合中*/
bool inset(Set s, int e)
{
	int i;
	for (i = 0; i < s.length; i++)
	{
		if (s.data[i] == e)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/*求集合的并集*/
void add(Set s1, Set s2, Set s3)
{
	int i;
	for (i = 0; i < s1.length; i++)
	{
		s3.data[i] = s1.data[i];   //将集合1中的所有元素复制到s3中
	}
	s3.length = s1.length;
	for (i = 0; i < s2.length; i++)
	{
		if (!inset(s1, s2.data[i]))   //将s2中不在s1中出现的元素复制到S3中
		{
			s3.data[s3.length] = s2.data[i];
			s3.length++;
		}
	}
}

/*求集合的差集*/
void sub(Set s1, Set s2, Set& s3)
{
	int i;
	s3.length = 0;
	for (i = 0; i < s1.length; i++)        //将s1中没有出现在s2中的元素复制到s3中
	{
		if (!inset(s2, s1.data[i]))
		{
			s3.data[s3.length] = s1.data[i];
			s3.length++;
		}
	}
}

/*求集合的交集*/
void intersection(Set s1, Set s2, Set& s3)
{
	int i;
	s3.length = 0;
	for (i = 0; i < s1.length; i++)  //将s1中出现在s2中的元素复制 到s3中
	{
		if (inset(s2, s1.data[i]))
		{
			s3.data[s3.length] = s1.data[i];
			s3.length++;
		}
	}
}

/*主函数*/
int main()
{
	Set s1, s2, s3, s4, s5;
	int  a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int  b[] = { 2,3,4,5,6,7,8 };
	int n = 5, m = 7;
	createSet(s1, a, n);
	createSet(s1, b, m);
	printf("s1:");
	dispest(s1);
	printf("s2:");
	dispest(s2);
	printf("s3=s1Us2\n");
	add(s1, s2, s3);
	printf("s3:");
	dispest(s3);
	printf("s4=s1-s2\n");
	sub(s1, s2, s4);
	printf("s4:");
	dispest(s4);
	printf("s5=s1Us2\n");
	intersection(s1, s2, s5);
	printf("s5:");
	dispest(s5);
}
