#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<dos.h>
#include<string.h>
#include<cstring>
#include <math.h>
#include <conio.h>
#include <string>
#include <graphics.h>
#include <iostream>
using namespace std;
void digit(int x,int y,int d){
    int a=30;
    if(d==0){
       line(x,y,x+a,y);
        line(x+a,y,x+a,y+a);
        line(x+a,y+a,x+a,y+2*a);
        line(x+a,y+2*a,x,y+2*a);
        line(x,y+2*a,x,y+a);
        line(x,y+a,x,y);

    }
    else if(d==1){

        line(x+a,y,x+a,y+a);
        line(x+a,y+a,x+a,y+2*a);

    }
    else if(d==2){
       line(x,y,x+a,y);
        line(x+a,y,x+a,y+a);

        line(x+a,y+2*a,x,y+2*a);
        line(x,y+2*a,x,y+a);

        line(x,y+a,x+a,y+a);
    }
    else if(d==3){
        line(x,y,x+a,y);
        line(x+a,y,x+a,y+a);
        line(x+a,y+a,x+a,y+2*a);
        line(x+a,y+2*a,x,y+2*a);

        line(x,y+a,x+a,y+a);
    }
    else if(d==4){

        line(x+a,y,x+a,y+a);
        line(x+a,y+a,x+a,y+2*a);
;
        line(x,y+a,x,y);
        line(x,y+a,x+a,y+a);
    }
    else if(d==5){
        line(x,y,x+a,y);

        line(x+a,y+a,x+a,y+2*a);
        line(x+a,y+2*a,x,y+2*a);

        line(x,y+a,x,y);
        line(x,y+a,x+a,y+a);
    }
    else if(d==6){
        line(x,y,x+a,y);

        line(x+a,y+a,x+a,y+2*a);
        line(x+a,y+2*a,x,y+2*a);
        line(x,y+2*a,x,y+a);
        line(x,y+a,x,y);
        line(x,y+a,x+a,y+a);
    }
    else if(d==7){
        line(x,y,x+a,y);
        line(x+a,y,x+a,y+a);
        line(x+a,y+a,x+a,y+2*a);

    }
    else if(d==8){
        line(x,y,x+a,y);
        line(x+a,y,x+a,y+a);
        line(x+a,y+a,x+a,y+2*a);
        line(x+a,y+2*a,x,y+2*a);
        line(x,y+2*a,x,y+a);
        line(x,y+a,x,y);
        line(x,y+a,x+a,y+a);
    }
    else if(d==9){
        line(x,y,x+a,y);
        line(x+a,y,x+a,y+a);
        line(x+a,y+a,x+a,y+2*a);
        line(x+a,y+2*a,x,y+2*a);

        line(x,y+a,x,y);
        line(x,y+a,x+a,y+a);
    }
}

void print(char a[8][8])
{
    int w=0,b=0;
 int i,j;
 for(i=0;i<8;i++)
   {
   for (j=0;j<8;j++){
    if(a[i][j]=='W'){
        setfillstyle(1,9);
        bar(i*60+12,j*60+152,i*60+68,j*60+208);
        w++;
    }
    else if(a[i][j]=='B'){
        setfillstyle(1,14);
        bar(i*60+12,j*60+152,i*60+68,j*60+208);
        b++;
    }
   }
        setcolor(15);
      settextjustify(CENTER_TEXT, CENTER_TEXT);
      settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
      moveto(390, 30);
      outtext("turn:");
    //cout<<w<<b<<endl;
    setfillstyle(1,0);
    bar(170,45,340,120);
    setcolor(9);
    digit(175,50,w/10);
    digit(215,50,w%10);
    setcolor(14);
    digit(265,50,b/10);
    digit(305,50,b%10);

  }
}
int test(char a[8][8],int i,int j,int ii,int jj,char ch1,char ch2)
{
  int x=i,y=j;
  x=i+ii; y=j+jj;
  if (x>=0 && x<8 && y>=0 && y<8)
          if (a[x][y]==ch2)
		  {
		  	while (a[x][y]==ch2) { x=x+ii; y=y+jj;}
		    if (x>=0 && x<8 && y>=0 && y<8 && a[x][y]==ch1 )
			 {
			  a[i][j]='O';
			  return 1;
			 }
		  }
	return 0 ;
}
int test3(char a[8][8],int i,int j,int ii,int jj,char ch1,char ch2)
{
  int x=i,y=j;
  x=i+ii; y=j+jj;
  if (x>=0 && x<8 && y>=0 && y<8)
          if (a[x][y]==ch2)
		  {
		  	while (a[x][y]==ch2) { x=x+ii; y=y+jj;}
		    if (x>=0 && x<8 && y>=0 && y<8 && a[x][y]==ch1 )
			 {
			  return 1;
			 }
		  }
	return 0 ;
}

int test2(char a[8][8],int i,int j,int ii,int jj,char ch1,char ch2)
{
    int t=0;
  if (test3(a,i,j,ii,jj,ch1,ch2))
  {
  	int x=i,y=j;
    x=i+ii; y=j+jj;
   	while (a[x][y]!=ch1) {
	   a[x][y]=ch1;
	   x=x+ii;
	    y=y+jj;
	    t++;
	   }
  }
  return t;
}

void white(char a[8][8])
{
	int i,j;
	int x,y;
	for (i=0 ; i<8 ; i++)
	 for (j=0 ; j<8 ; j++)
	   {
	   	if (a[i][j]=='E')
		   {
		     test(a,i,j,1,0,'W','B');
		     test(a,i,j,1,1,'W','B');
		     test(a,i,j,0,1,'W','B');
		     test(a,i,j,-1,0,'W','B');
		     test(a,i,j,0,-1,'W','B');
		     test(a,i,j,-1,-1,'W','B');
		     test(a,i,j,-1,1,'W','B');
		     test(a,i,j,1,-1,'W','B');
		   }
	   }
}
void black(char a[8][8])
{
	int i,j;
	int x,y;
	for (i=0 ; i<8 ; i++)
	 for (j=0 ; j<8 ; j++)
	   {
	   	if (a[i][j]=='E')
		   {
		     test(a,i,j,1,0,'B','W');
		     test(a,i,j,1,1,'B','W');
		     test(a,i,j,0,1,'B','W');
		     test(a,i,j,-1,0,'B','W');
		     test(a,i,j,0,-1,'B','W');
		     test(a,i,j,-1,-1,'B','W');
		     test(a,i,j,-1,1,'B','W');
		     test(a,i,j,1,-1,'B','W');
		   }
	   }
}
void reset(char a[8][8])
{
	int i,j;
	for (i=0 ; i<8 ; i++)
	 for (j=0 ; j<8 ; j++)
	   	if (a[i][j]=='O') a[i][j]='E' ;
}
void play(char a[8][8],int i , int j , char turn)
{
//	cout <<endl<<i<< "  "<<j ;
	a[i][j]=turn;
	if (turn=='W')
	 {
	 	     test2(a,i,j,1,0,'W','B');
		     test2(a,i,j,1,1,'W','B');
		     test2(a,i,j,0,1,'W','B');
		     test2(a,i,j,-1,0,'W','B');
		     test2(a,i,j,0,-1,'W','B');
		     test2(a,i,j,-1,-1,'W','B');
		     test2(a,i,j,-1,1,'W','B');
		     test2(a,i,j,1,-1,'W','B');
	 }
	 else
	 	   {
		     test2(a,i,j,1,0,'B','W');
		     test2(a,i,j,1,1,'B','W');
		     test2(a,i,j,0,1,'B','W');
		     test2(a,i,j,-1,0,'B','W');
		     test2(a,i,j,0,-1,'B','W');
		     test2(a,i,j,-1,-1,'B','W');
		     test2(a,i,j,-1,1,'B','W');
		     test2(a,i,j,1,-1,'B','W');
		   }

}

int canplay(char a[8][8])
{
	int i,j;
	for (i=0 ; i<8 ; i++)
	 for (j=0 ; j<8 ; j++)
	   	if (a[i][j]=='O') return 1 ;
	return 0 ;
}
void read(char a[8][8])
{
int i;
  for ( i=0 ; i<8 ; i++)
	 gets(a[i]);
}
void bestmove(char a[8][8],int pcmove[2]){
    int maxt=0,i,j,i1,j1;
    char b[8][8];
    //cout<<"1st"<<pcmove[0]<<pcmove[1]<<endl;
    for (i=0 ; i<8 ; i++){
	 for (j=0 ; j<8 ; j++){
           for (i1=0 ; i1<8 ; i1++)
                for (j1=0 ; j1<8 ; j1++)
                    b[i1][j1]=a[i1][j1];
	   	if (a[i][j]=='O'){
            int t=0;
            t+=test2(b,i,j,1,0,'B','W');
            t+=test2(b,i,j,1,1,'B','W');
            t+=test2(b,i,j,0,1,'B','W');
            t+=test2(b,i,j,-1,0,'B','W');
            t+=test2(b,i,j,0,-1,'B','W');
            t+=test2(b,i,j,-1,-1,'B','W');
            t+=test2(b,i,j,-1,1,'B','W');
            t+=test2(b,i,j,1,-1,'B','W');
            if(t>maxt){
                maxt=t;
                pcmove[0]=i;
                pcmove[1]=j;
            }
            //cout<<"hi"<<pcmove[0]<<pcmove[1]<<endl;
        }
	 }
    }
}
int main( )
{
    initwindow(510, 650);
    bool pc=false;
    int menu=0;
    while(!kbhit()){
        if(menu<1){
            setfillstyle(1,5);
            bar(75,275,225,375);
            setfillstyle(1,0);
            bar(80,280,220,370);
            setcolor(15);
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            moveto(150,325);
            outtext("PC");
            setfillstyle(1,5);
            bar(285,275,435,375);
            setfillstyle(1,0);
            bar(290,280,430,370);
            setcolor(15);
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            moveto(360, 325);
            outtext("2-player");
            menu++;
            }
        if(ismouseclick(WM_LBUTTONDOWN)){
                int X,Y;
                X=mousex();
                Y=mousey();
                clearmouseclick(WM_LBUTTONDOWN);

        if(X>75 && X<225 && Y>275 && Y<375){
                setfillstyle(1,0);
                bar(0,0,510,650);
            int pcmove[2]={0,0};
                setcolor(7);
                rectangle(10,150,490,630);
                int cellsize=60;
                for(int i=0;i<8;i++){
                    line(10,i*cellsize+150,8*cellsize+10,i*cellsize+150);
                    line(i*cellsize+10,150,i*cellsize+10,8*cellsize+150);
                }
                bool val2=true,nomove=false;
                int end=0;
                int i,j,n,x,y;
                char turn='W';
                char a[8][8]={'E','E','E','E','E','E','E','E',
                              'E','E','E','E','E','E','E','E',
                              'E','E','E','E','E','E','E','E',
                              'E','E','E','B','W','E','E','E',
                              'E','E','E','W','B','E','E','E',
                              'E','E','E','E','E','E','E','E',
                              'E','E','E','E','E','E','E','E',
                              'E','E','E','E','E','E','E','E'};
             reset(a);
             print(a);
            while (!kbhit())
            {   int remain=0;
                for (i=0 ; i<8 ; i++)
                 for (j=0 ; j<8 ; j++)
                    if (a[i][j]=='E')
                       remain++;
                if(nomove || remain==0){
                    //cout<<2<<endl;
                    setfillstyle(1,0);
                    bar(10,10,50,50);
                    setfillstyle(1,0);
                    bar(300,0,492,49);
                    int w=0,b=0;
                    for (i=0 ; i<8 ; i++)
                     for (j=0 ; j<8 ; j++)
                       {
                        if (a[i][j]=='W') w++;
                        if (a[i][j]=='B') b++;
                       }
                     if (b>w){

                                setcolor(15);
                                  settextjustify(CENTER_TEXT, CENTER_TEXT);
                                  settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                                  moveto(110, 30);
                                  outtext("PC won!");

                     }
                     else if (w>b){

                                setcolor(15);
                                  settextjustify(CENTER_TEXT, CENTER_TEXT);
                                  settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                                  moveto(110, 30);
                                  outtext("YOU won!");

                       }

                     else{
                            setcolor(15);
                          settextjustify(CENTER_TEXT, CENTER_TEXT);
                          settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                          moveto(110, 30);
                          outtext("EQUAL");

                     }
                     //cout<<2<<endl;
                     menu=0;
                        break;
                }
                else{

                    if (turn=='W'){
                    setfillstyle(1,9);
                    fillellipse(470,20,15,15);

                 }
                 else{
                    setfillstyle(1,14);
                    fillellipse(470,20,15,15);
                 }
                bool val=true;
              if(ismouseclick(WM_LBUTTONDOWN)){
                x=((mousex()-10)/60);
                y=((mousey()-150)/60);
                    clearmouseclick(WM_LBUTTONDOWN);
            //cout<<x<<y<<endl;
            //system("cls");



                white(a);
                if(a[x][y]!='O'){
                    val=false;
                    setfillstyle(1,0);
                    bar(10,10,50,50);
                    setcolor(4);
                    line(12,12,48,48);
                    line(12,48,48,12);}





                 if(val){
                     end=0;
                        setfillstyle(1,0);
                        bar(10,10,50,50);
                        setcolor(10);
                        line(12,12,40,48);
                        line(40,48,48,40);
                 play(a,x,y,turn);
                 if (turn=='W') turn='B';  else turn='W';}

                reset(a);
                 print(a);
                 setfillstyle(1,0);
                bar(300,0,510,49);
                 val=true;
                 if(turn=='B'){

                 black(a);
                    //print2(a);
                    bestmove(a,pcmove);
                    x=pcmove[0];
                    y=pcmove[1];
                    //cout<<x<<y<<endl;
                    if(a[x][y]!='O'){
                        val=false;
                        }

                     if(val){
                     end=0;

                 play(a,x,y,turn);
                 if (turn=='W') turn='B';  else turn='W';
                     }
                     delay(500);
                     reset(a);
                 print(a);
                 setfillstyle(1,0);
                bar(300,0,510,49);
                 }


                 do{

                 if(turn=='W')
                    white(a);
                 else
                    black(a);
                 if(canplay(a)==0)
                    {
                        //cout<<"change"<<turn<<endl;
                      if (turn=='W') turn='B';  else turn='W';
                     if(end==1){
                        nomove=true;
                        break;
                     }

                     else
                        end=1;

                    }
                    else{
                        end=0;
                    }
                    reset(a);
                 }while(canplay(a)!=0);
                    }
                }
            }

        }
        else if(X>285 && X<435 && Y>275 && Y<375){
                setfillstyle(1,0);
                bar(0,0,510,650);
                setcolor(7);
                rectangle(10,150,490,630);
                int cellsize=60;
                for(int i=0;i<8;i++){
                    line(10,i*cellsize+150,8*cellsize+10,i*cellsize+150);
                    line(i*cellsize+10,150,i*cellsize+10,8*cellsize+150);
                }
                bool val2=true,nomove=false;
                int end=0;
                int i,j,n,x,y;
                char turn='W';
                char a[8][8]={'E','E','E','E','E','E','E','E',
                              'E','E','E','E','E','E','E','E',
                              'E','E','E','E','E','E','E','E',
                              'E','E','E','B','W','E','E','E',
                              'E','E','E','W','B','E','E','E',
                              'E','E','E','E','E','E','E','E',
                              'E','E','E','E','E','E','E','E',
                              'E','E','E','E','E','E','E','E'};
             reset(a);
             print(a);
            while (!kbhit())
            {   int remain=0;
                for (i=0 ; i<8 ; i++)
                 for (j=0 ; j<8 ; j++)
                    if (a[i][j]=='E')
                       remain++;
                if(nomove || remain==0){
                    //cout<<2<<endl;
                    setfillstyle(1,0);
                    bar(10,10,50,50);
                    setfillstyle(1,0);
                    bar(300,0,492,49);
                    int w=0,b=0;
                    for (i=0 ; i<8 ; i++)
                     for (j=0 ; j<8 ; j++)
                       {
                        if (a[i][j]=='W') w++;
                        if (a[i][j]=='B') b++;
                       }
                     if (b>w){
                                setfillstyle(1,14);
                                fillellipse(100,80,30,30);
                                  setcolor(15);
                                  settextjustify(CENTER_TEXT, CENTER_TEXT);
                                  settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                                  moveto(110, 30);
                                  outtext("Winner");
                            }

                     else if (w>b){

                                setfillstyle(1,9);
                                fillellipse(100,80,30,30);
                                setcolor(15);
                                  settextjustify(CENTER_TEXT, CENTER_TEXT);
                                  settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                                  moveto(110, 30);
                                  outtext("winner");

                       }

                     else{
                            setcolor(15);
                          settextjustify(CENTER_TEXT, CENTER_TEXT);
                          settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                          moveto(110, 30);
                          outtext("EQUAL");

                     }
                     menu=0;
                     //cout<<2<<endl;
                        break;
                }
                else{

                    if (turn=='W'){
                    setfillstyle(1,9);
                    fillellipse(470,20,15,15);

                 }
                 else{
                    setfillstyle(1,14);
                    fillellipse(470,20,15,15);
                 }
                bool val=true;
              if(ismouseclick(WM_LBUTTONDOWN)){
                x=((mousex()-10)/60);
                y=((mousey()-150)/60);
                    clearmouseclick(WM_LBUTTONDOWN);
            //cout<<x<<y<<endl;
            //system("cls");


             int flag=0;
             if (turn=='W'){
                white(a);
                if(a[x][y]!='O'){
                    val=false;
                    setfillstyle(1,0);
                    bar(10,10,50,50);
                    setcolor(4);
                    line(12,12,48,48);
                    line(12,48,48,12);}
             }
             else{
                    black(a);
                    if(a[x][y]!='O'){
                        val=false;
                        setfillstyle(1,0);
                        bar(10,10,50,50);
                        setcolor(4);
                        line(12,12,48,48);
                        line(12,48,48,12);}
                 }

                 if(val){
                     end=0;
                        setfillstyle(1,0);
                        bar(10,10,50,50);
                        setcolor(10);
                        line(12,12,40,48);
                        line(40,48,48,40);
                 play(a,x,y,turn);
                 if (turn=='W') turn='B';  else turn='W';
                 }
                reset(a);
                 print(a);
                 do{

                 if(turn=='W')
                    white(a);
                 else
                    black(a);
                 if(canplay(a)==0)
                    {
                        //cout<<"change"<<turn<<endl;
                      if (turn=='W') turn='B';  else turn='W';
                     if(end==1){
                        nomove=true;
                        break;
                     }

                     else
                        end=1;

                    }
                    else{
                        end=0;
                    }
                    reset(a);
                 }while(canplay(a)!=0);
                    }
                }
            }


        }
        else{
            menu=0;

        }
        }
    }
     getch();
 }
