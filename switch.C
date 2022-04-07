#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	char choice;
	clrscr();
	while(1)
	{
		printf("\nEnter a number : ");
		scanf("%d",&n);
		if(n>=0 && n<10)
		{
		 switch(n)
		 {
			case 0:
			printf("zero");
			break;
			case 1:
			printf("one");
			break;
			case 2:
			printf("two");
			break;
			case 3:
			printf("three");
			break;
			case 4:
			printf("four");
			break;
			case 5:
			printf("five");
			break;
			case 6:
			printf("six");
			break;
			case 7:
			printf("seven");
			break;
			case 8:
			printf("eight");
			break;
			case 9:
			printf("nine");
			break;
		  }
		}
		else
			printf("\nInvalid number");
		printf("\nDo you want to enter more?\nType 'Y' or 'N': ");
		scanf("%c",&choice);
		if(choice=='N' || choice=='n')
		exit();
       }
	getch();
}
