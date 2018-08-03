#include <stdio.h>

char grid[49];
unsigned number1, number2,ComputerCount=0,PlayerCount=0;

int valid[]={0,2,4,6,14,16,18,20,28,30,32,34,42,44,46,48};

unsigned get_random()
{
	number2 = 36969 * (number2 & 65535) + (number2 >> 16);
	number1 = 18000 * (number1 & 65535) + (number1 >> 16);
	//printf("%u\n",(number2 << 16) + number1);
	return (number2 << 16) + number1;
}

void printGrid()
{

	char ch='a';

	printf("  1 2 3 4\n%c ",ch);
    int i=0;
	for(i=0; i<49; i++)
	{

		if(i!=0 && i%14==0)
		{
			printf("\n");
			ch++;
			printf("%c ",ch);
		}

		else if(i!=0 && i%7==0) printf("\n  ");

		printf("%c",grid[i]); //printf("%d",i);
	}

	printf("\n\n");
}

int BoxWonOrNot(int pos, int type, char player)
{
	int cnt=0;

	if(type==1)
	{
		if(pos<42)
		{
			if(grid[pos+6]=='|' && grid[pos+8]=='|' && grid[pos+14]=='-')
			{
				if(grid[pos+7]==' ')
				{
					cnt++;
					grid[pos+7]=player;
				}
			}
		}

		if(pos>6)
		{
			if(grid[pos-6]=='|' && grid[pos-8]=='|' && grid[pos-14]=='-')
			{
				if(grid[pos-7]==' ')
				{
					cnt++;
					grid[pos-7]=player;
				}
			}
		}
	}

	else
	{
		if((pos%14)!=13)  // right impo
		{
			if(grid[pos-6]=='-' && grid[pos+8]=='-' && grid[pos+2]=='|')
			{
				if(grid[pos+1]==' ')
				{
					cnt++;
					grid[pos+1]=player;
				}
			}
		}

		if((pos%14)!=7)  // left impo
		{
			if(grid[pos-8]=='-' && grid[pos+6]=='-' && grid[pos-2]=='|')
			{
				if(grid[pos-1]==' ')
				{
					cnt++;
					grid[pos-1]=player;
				}
			}
		}
	}

	return cnt;
}

void userInput()
{

	int x,y;
	char ch1,ch2;

	while(1)
	{

		printf("Enter first co-ordinates(i.e c1,c2):");

		while(1)
		{
			scanf("%c",&ch1);

			scanf("%c%d",&ch1,&x);

			if((ch1>='a' && ch1<='d') && (x>=1 && x<=4))
			{
				break;
			}

			else
			{
				printf("Please Enter a character between 'a' to 'd' followed by a number between 1 to 4 : ");
				continue;
			}

		}

		printf("Enter second co-ordinates(i.e c1,c2):");

		while(1)
		{
			scanf("%c",&ch2);

			scanf("%c%d",&ch2,&y);

			if((ch2>='a' && ch2<='d') && (y>=1 && y<=4))
			{
				break;
			}

			else
			{
				printf("Please Enter a character between 'a' to 'd' followed by a number between 1 to 4 : ");
				continue;
			}
		}

		x=(ch1-97)*14+(x-1)*2;
		y=(ch2-97)*14+(y-1)*2;

		if(x==y)
		{
			printf("co-ordinates are same\n");
			continue;
		}

		if(x>y)
		{
			int temp=x;
			x=y;
			y=temp;
		}

		if(!(x+2==y || x+14==y))
		{
			printf("two co-ordinates are not adjecent\n");
			continue;
		}

		if(x+2==y || x+14==y)
		{
			if(x+2==y)
			{
				if(grid[x+1]=='-')
				{
					printf("First Co-ordinate is already filled\n");
					continue;
				}

				else
				{
					grid[x+1]='-';
					PlayerCount+=BoxWonOrNot(x+1,1,'P');
					printGrid();
					break;
				}
			}

			else
			{
				if(grid[x+7]=='|')
				{
					printf("Second Co-ordinate is already filled\n");
					continue;
				}

				else
				{															//printf("\n%d %d\n",x,y);
					grid[x+7]='|';
					PlayerCount+=BoxWonOrNot(x+7,2,'P');
					printGrid();
					break;
				}
			}
		}

	}
}


int extraCheck()
{
	int i,cnt=0,pos=0;

	for(i=1; i<=33; i+=2)
	{

		cnt=0;

		if(grid[i]=='-') cnt++;
		else pos=i;

		if(grid[i+6]=='|') cnt++;
		else pos=i+6;

		if(grid[i+8]=='|') cnt++;
		else pos=i+8;

		if(grid[i+14]=='-') cnt++;
		else pos=i+14;

		if(cnt==3)
		{

			if((pos/7)%2) grid[pos]='|';
			else grid[pos]='-';

			grid[i+7]='C';
			ComputerCount++;

			return 1;
		}

		if(i==5 || i==19) i+=8;
	}

	return -1;

}

int main()
{

	unsigned turn;

    int i=0;
	for(i=0; i<49; i++)
	{
		if((i>=7 && i<=13) || (i>=21 && i<=27) || (i>=35 && i<=41))
		{
			grid[i]=' ';
		}

		else if(i%2==0) grid[i]='.';

		else grid[i]=' ';
	}

	printf("Enter two positive numbers to initialize the random number generator\n");

	randomInput:

		scanf("%u%u",&number1,&number2);
		if(number1==0 || number2==0)
		{
			printf("Enter two positive numbers\n");
			goto randomInput;
		}
		goto startGame;

    startGame:

        turn=get_random()%2;

        if(turn==0)
            printf("Computer will make the first move.\n\n");

        else
            printf("Player will make the first move.\n\n");

        printGrid();

        mainGameLoop:

            if(turn==0)
            {
                printf("Computers Turn : \n");
                int x,y,i;

                computerTurn:

                    if(extraCheck()==1)
                    {
                        printGrid();
                        goto userTurn;
                    }

                    goto mainOuterP;

                        mainOuterP:
                            x=(get_random()%50+get_random()%50)%50;
                            i = 0;
                            mainInnerP:
                                if(valid[i]==x) goto mainOuterQ;
                                i = i+1;
                                if(i<16) goto mainInnerP;
                                goto mainOuterP;

                        mainOuterQ:
                            y=(get_random()%50+get_random()%50)%50;
                            i = 0;
                            mainInnerQ:
                                if(valid[i]==y && x!=y) goto next;
                                i = i+1;
                                if(i<16) goto mainInnerQ;
                                goto mainOuterQ;

                        next:
                            //printf("%d  %d\n",x,y);
                            if(y<x)
                            {
                                    int temp=x;
                                    x=y;
                                    y=temp;
                            }

                            if(x+2==y || x+14==y)  // got correct co-ordinates pair but doesn't know yet even it filled or not.
                            {
                                if(x+2==y)
                                {
                                    if(grid[x+1] == '-')
                                    {
                                        printf("11\n");
                                        goto computerTurn;
                                    }

                                    else
                                    {
                                        grid[x+1]='-';
                                        ComputerCount+=BoxWonOrNot(x+1,1,'C');
                                        printf("12\n");
                                        printGrid();
                                        goto userTurn;
                                    }
                                }
                                else
                                {
                                    if(grid[x+7]=='|')
                                    {
                                        printf("21\n");
                                        goto computerTurn;
                                    }

                                    else
                                    {
                                        grid[x+7]='|';
                                        ComputerCount+=BoxWonOrNot(x+7,2,'C');
                                        printf("22\n");
                                        printGrid();
                                        goto userTurn;
                                    }
                                }
                            }

                userTurn:
                    turn = 1;
                    if(PlayerCount>=5 || ComputerCount>=5)
                        goto exitGame;

            }

            if(turn==1)
            {
                printf("Player Turn : \n");
                userInput();
                turn=0;
                if(PlayerCount>=5 || ComputerCount>=5)
                    goto exitGame;

                goto mainGameLoop;
            }

        exitGame:
            if(ComputerCount>=5)
                printf("Computer won !!\n");

            else
                printf("Congratulation, You won\n");


	return 0;

}
