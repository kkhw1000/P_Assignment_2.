#include <stdio.h>
#include <math.h>
int Prime_Between(int n1);	// case 1, case3
int Check_Number_Arms(int n);	//  case 2

int main()
{
	int Select, flag;
	int n1, n2,i,D;	// for	case1, case3

	int n;		// for  case2
	printf("==Menu==================================================================================\n");
	printf("1.Display Prime Numbers Between Intervals Using Fuction.\n");
	printf("2.Check Prime Number or Armstrong Number Using Users-defined Fuction.\n");
	printf("3.Check Whether a Number can be Expressed as Sum of Two Prime Numbers.\n");
	printf("========================================================================================\n");
	printf("Press the Number of Menu:");
	scanf("%d", &Select);
//====================================================================================================case1
	switch (Select)
	{
	case 1:
								//prime numbers flag가 1이면 소수 0이면 소수x
		printf("Press the Two numbers:");
		scanf("%d %d", &n1, &n2);
		D = n1;  //숫자 위치 판결용
		
		(n1 > n2) ? (n1 = n2) && (n2 = D) : 53;
		
		
		for (i = ++n1; i < n2; i++)
			{
				flag = Prime_Between(i);
				
				if (flag == 1) printf("%d ", i);
			}
	    
			
		
		break;
	
//====================================================================================================case2

	case 2:
									//flag 0 이면 둘다 해당x  flag 1 이면 암스트롱 flag 2이면 소수 flag 3이면 암스트롱and 소수
		printf("Press the Number:");
		
		scanf("%d", &n);
		flag=Check_Number_Arms(n)+ Prime_Between(n);
		if (flag == 3)printf("This Number is Armstrong number and Prime number.\n");
			
		
		else if (flag == 2) printf("This Number is Armstrong number.");
		else if (flag ==1) printf("This Number is Prime number.");
		else if(flag == 0) printf("This Number is Not Prime number and Armstrong number.");
		break;
//=======================================================================================================case3		
		
	case 3:
		//3
		printf("Press the Number:");
		scanf("%d", &n);
		flag = 0;
		for (n1 = 2; n1 <= n/2; n1++)
		{
			
			n2 = n - n1;
			if (Prime_Between(n1) == 1)
			{
				if (Prime_Between(n2) == 1)
				{
					printf("%d =%d+%d\n", n, n1, n2);// n1 n2 둘다 소수 일 경우
					flag = 1;
				}
			}
			
			
		}
		if (flag == 0) printf("표현 불가능");
		if (flag == 1) printf("더이상의 계산이 없습니다.");
		break;
	}
	return 0;
}

int Prime_Between(int N)
{

	int flag = 1, j;
	
	if (N == 1) flag = 0;
	
		for (j = 2; j <= N / 2; j++)
		{
			if (N%j == 0)
			{
				flag = 0;
				break;
			}
		}


	return flag;

}

int Check_Number_Arms(int n)
{

	int flag=0 ,OriginN;
	int count = 0, NN = 0;
	float sum=0;
		OriginN = n;
	while(OriginN !=0)
	{	
		
		OriginN /= 10;
		
		count++;
	}

	OriginN =n;
	
	while(OriginN !=0)
	{
		
		NN=OriginN%10; //나머지
		sum =sum+ pow(NN,count);
		OriginN /= 10; //몫
		
		
	}
	if (n == sum)	flag = 2;

return flag;

}
