
   /**形如2^ n - 1的素数称为梅森尼数。设计求出指数n < 50的所有梅森尼数。
	* *输出格式要求："2^%d-1=%.0lf\n"  "指数n于[2,50]中梅森尼数共有%d个."*/
#include<stdio.h>
#include<math.h>
float isprime(int x) {
	int i = 2;
	for (i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
/*没有else！没有else！没有else！没有else！没有else！*/
    return 1;
}
int main()
{
	int n=2,sum=0;
	double x;
	for (n = 2; n <= 50; n++)
	{
		x = pow(2, n) - 1;
		if (isprime(x))
		{
			sum++;
			printf("2^%d-1=%.0lf\n", n, x);
            /*这里是.0lf,不是.01f*/
		}
	}
	printf("指数n于[2,50]中梅森尼数共有%d个.", sum);
	return 0;
}