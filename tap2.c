#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

char map[10][12]={
	"***A*A***AA",
	"AA**A**A**A",
	"*AA***A*A*A",
	"*A***A**AA*",
	"*AA*A*A**AA",
	"AA**AA***A*",
	"*A*A***A**A",
	"A**A**A***A",
	"A*A**AA*A*Q",
	"A***AA***AA",
};

int curX=0,curY=0;

 void printfPerson()
 {
	 COORD pos;
	 pos.X=curX;
	 pos.Y=curY;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
 }
 
 
 void printMap()
 {
	 int i,j;
	 for(i=0;i<10;i++)
	 {
		for(j=0;j<12;j++)
		{
		   printf("%c",map[i][j]);
		}
		printf("\n");
	 }
 }
 void move(char dir)
 {
	 switch(dir)
	 {
	 case 'w':
		 curY--;
		 if(curY<0)curY=0;
		 if(map[curY][curX]=='A')curY++;
		 break;
     case 's':
			curY++;
			if(curY>=10) curY=10-1;
			if(map[curY][curX]=='A') curY--;
			break;
		case 'a':
			curX--;
			if(curX<0) curX=0;
			if(map[curY][curX]=='A') curX++;
			break;
		case 'd':
			curX++;
			if(curX>=12) curX=12-1;
			if(map[curY][curX]=='A') curX--;
			break;	
	 }

 }


void main()
{

	char dir;
	while(1)
	{
		system("cls");
		printMap();
		printfPerson();
		dir=getch();
		move(dir);

		if(map[curY][curX]=='Q')
		{
			printf("You are so smart~\n");
			break;
		}
	}
}
