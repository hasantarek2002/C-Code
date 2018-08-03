#include <stdio.h>

char grid[49];
unsigned number1, number2,ComputerCount=0,PlayerCount=0;

int valid[]={0,2,4,6,14,16,18,20,28,30,32,34,42,44,46,48};

unsigned get_random()
{
	number2 = 36969 * (number2 & 65535) + (number2 >> 16);
	number1 = 18000 * (number1 & 65535) + (number1 >> 16);
	return (number2 << 16) + number1;
}

void printGrid()
{

	char ch='a';

	printf("  1 2 3 4\n%c ",ch);
    int i=0;

        print:
		if(i!=0 && i%14==0)
		{
			printf("\n");
			ch++;
			printf("%c ",ch);
		}

		else if(i!=0 && i%7==0) printf("\n  ");

		printf("%c",grid[i]);
		i = i+1;
		if(i<49) goto print;

	printf("\n\n");
}

int BoxWonOrNot(int pos, int type, char player)
{
	int cnt=0;

	if(type!=0)             // 0 for '_'      1 for  ' | '
       goto bwn;
		if(pos<42 && grid[pos+6]=='|' && grid[pos+8]=='|' && grid[pos+14]=='-' && grid[pos+7]==' '){
			cnt++;
            grid[pos+7]=player;
		}

		if(pos>6 && grid[pos-6]=='|' && grid[pos-8]=='|' && grid[pos-14]=='-' && grid[pos-7]==' '){
			cnt++;
            grid[pos-7]=player;
		}
		return cnt;

	bwn:
		if((pos%14)!=13 && grid[pos-6]=='-' && grid[pos+8]=='-' && grid[pos+2]=='|' && grid[pos+1]==' '){
			cnt++;
            grid[pos+1]=player;
		}

		if((pos%14)!=7 && grid[pos-8]=='-' && grid[pos+6]=='-' && grid[pos-2]=='|' && grid[pos-1]==' '){
			cnt++;
            grid[pos-1]=player;
		}

	return cnt;
}

void userInput()
{

	int x,y;
	char ch1,ch2;

	UI://while(1)
	//{
        UI1:
            printf("Enter first co-ordinates(i.e c1,c2):");

			scanf("%c",&ch1);
            scanf("%c%d",&ch1,&x);

			if((ch1>='a' && ch1<='d') && (x>=1 && x<=4))
                goto UI2;
                printf("Please Enter a character between 'a' to 'd' followed by a number between 1 to 4 : ");
                goto UI1;

		UI2:
		    printf("Enter second co-ordinates(i.e c1,c2):");

			scanf("%c",&ch2);

			scanf("%c%d",&ch2,&y);

			if((ch1>='a' && ch1<='d') && (x>=1 && x<=4))
                goto UInext;
                printf("Please Enter a character between 'a' to 'd' followed by a number between 1 to 4 : ");
                goto UI2;

        UInext:
		x=(ch1-97)*14+(x-1)*2;
		y=(ch2-97)*14+(y-1)*2;

		if(x==y)
		{
			printf("co-ordinates are same\n");
			goto UI;
		}

		if(x>y)
		{
			int temp=x;
			x=y;
			y=temp;
		}

		if(!(x+2==y || x+14==y))
		{
			printf("two co-ordinates are not adjacent\n");
			goto UI;
		}

		if(x+2==y || x+14==y)
		{
			if(x+2==y)
			{
				if(grid[x+1]=='-')
				{
					printf("First Co-ordinate is already filled\n");
					goto UI;
				}

				else
				{
					grid[x+1]='-';
					PlayerCount+=BoxWonOrNot(x+1,0,'P');
					printGrid();
					goto finish;
				}
			}

			else
			{
				if(grid[x+7]=='|')
				{
					printf("Second Co-ordinate is already filled\n");
					goto UI;
				}

				else
				{
					grid[x+7]='|';
					PlayerCount+=BoxWonOrNot(x+7,1,'P');
					printGrid();
					goto finish;
				}
			}
		}
        goto UI;


    finish : return;
}


int extraCheck()
{
	int i=1,cnt=0,pos=0;


    excheck:
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
		    //printf("in extra 1111\n");
			if((pos/7)%2) grid[pos]='|';
			else grid[pos]='-';

			grid[i+7]='C';
			ComputerCount++;

			int j=8;

			innerLoop:

				if(grid[j]==' ' && grid[j-1]=='|' && grid[j+1]=='|' && grid[j-7]=='-' && grid[j+7]=='-')
				{
				    //printf("in extra 2222\n");
					ComputerCount++;
                    grid[j]='C';
                    return 1;
				}

				if(j==12 || j==26) j+=8;
				j=j+2;
				if(j<=40)
                    goto innerLoop;

			return 1;
		}

		if(i==5 || i==19) i+=8;
		i = i+2;
		if(i<=33) goto excheck;


	return -1;

}

int main()
{

	unsigned turn;
    int x,y,i=0;

    start:
		if(((i>=7 && i<=13) || (i>=21 && i<=27) || (i>=35 && i<=41)) || i%2!=0)
			grid[i]=' ';
        else grid[i]='.';
        i = i+1;
		if(i<49) goto start;

    rg:	printf("Enter two positive numbers to initialize the random number generator\n");

        scanf("%d %d",&number1,&number2);
		if(!(number1==0 || number2==0))
            goto game;
            goto rg;

    game:
        printf("Game starts\n");

        m1:
           printf("computers Turn : \n");
           if(extraCheck()!=1)
           if(PlayerCount>=5 || ComputerCount>=5) goto end;
           //printf("%d\n",ComputerCount);
           goto p;

           printGrid();
           goto Plturn;

        p:
            x=(get_random(number1,number2)%50+get_random(number1,number2)%50)%50;
            i = 0;

            pi:
                if(valid[i]==x) goto q;
                i = i+1;
                if(i<16) goto pi;
                goto p;


        q:y=(get_random(number1,number2)%50+get_random(number1,number2)%50)%50;
            i = 0;

            qi:
                if(valid[i]==y && x!=y) goto next;
                i = i+1;
                if(i<16) goto qi;
                goto q;


        next:
            if(y<x)
            {
                int temp=x;
                x=y;
                y=temp;
            }


            if(x+2==y)
            {
                if(grid[x+1]=='-') goto p;
                else
                {
                    grid[x+1]='-';
                    ComputerCount+=BoxWonOrNot(x+1,0,'C');
                    printGrid();
                    //printf("%d\n",ComputerCount);
                    if(PlayerCount>=5 || ComputerCount>=5) goto end;
                    goto Plturn;
                }
            }

            if(x+14==y)
            {
                if(grid[x+7]=='|') goto p;
                else
                {
                    grid[x+7]='|';
                    ComputerCount+=BoxWonOrNot(x+7,1,'C');
                    printGrid();
                    //printf("%d\n",ComputerCount);
                    if(PlayerCount>=5 || ComputerCount>=5) goto end;
                    goto Plturn;
                }
            }

            goto p;

            Plturn:
               printf("Player Turn : \n");
               userInput();
			   turn=0;
               if(PlayerCount>=5 || ComputerCount>=5) goto end;
			   goto m1;

end:
	if(ComputerCount>=5)
		printf("Computer won !!\n");

	else
		printf("Congratulation, You won\n");

	return 0;
}


