#include<iostream>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include<time.h>
#include<fstream>
using namespace std;
int game(int);
void info();
int main()
{
	string name;
	char o;
	int d;
	cout<<"Welcome to the Word Search Puzzle \n";
	cout<<"Enter Player Name  -  ";
	getline(cin,name);
	cout<<endl;
	cout<<" Press 1 for Easy difficulty \n Press 2 for Hard difficulty \n";
	cin>>d;
	int highscore;
	int score;
	do
	{
		system("cls");
		cout<<"";
		info();
		score=score+game(d);
		cout<<" \n Your Current Score : "<<score<<endl; 
		cout<<"\n If you like to play the game again press y \n If not press n \n";
		cin>>o;
		cout<<endl;
	}while(o!='n');
	{
		system("cls");
	cout<<name<<" Your Final Score  : "<<score;
	//for reading and writing the high score
	ifstream read;
	read.open("highscore.txt");
	if(read.is_open())
	{
		while(!read.eof())
		{
			read>>highscore;
		}
	}
	read.close();
	ofstream write;
	write.open("highscore.txt");
	if(write.is_open ())
	{
		if(score>highscore)
		{
			cout<<"\nyou got the highest score\n";
			highscore=score;
		}
		write<<highscore;
	}
	write.close();
	cout<<"\n the highscore is :"<<highscore;
	
	}
	int exit;
	cin>>exit;
	
}
int game(int u)
{
	int l;
	if(u==1)
	{l=5;}
	else
	{l=10;}
	string output;
	srand(time(0));
    string j[1000];
	ifstream read;
	read.open("dir.txt");
	for(int k=0;k<1000;k++)
	{
		if(read.is_open())
		{		
			read>>j[k];	
		}
	}
	read.close();


	char b[l][l];
	char  b1[l][l];
	for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            char c;
            int r;
            r= rand() % 26;   // generate a random number
            c= 'a' + r;   // Convert  a character from a-z
			//b[i][j]='-'; 
			 b1[i][j]=c;         
             b[i][j]=c;
        }
    }
    // randomly taking words to insert in the puzzle
	int index=rand()%1000;
	output=j[index];
	int le;
	if(u==1)
	{
	    le=j[index].length();
		while(le<3 ,le>5)
		{
			index=rand()%1000;
		}
	}
	else
	{
		le=j[index].length();
		while(le<3 , le>10)
		{
			index=rand()%1000;
		}
	}
		
	
     output=j[index];
	//insertion of words
	int h=rand()%4;
	
	int f=(l+1)-le;
	int dl=(l-le)+1;
	if(h==0)
	{
		int row=rand()%l;
        int col=rand()%f;
        for(int i=0;j[index][i]!='\0';i++,col++)
        {
            b[row][col]=j[index][i];
            b1[row][col]='*';
        }
	}
	if(h==1)
	{
		int row=rand()%f;
        int col=rand()%l;
        for(int i=0;j[index][i]!='\0';i++,row++)
        {
            b[row][col]=j[index][i];
             b1[row][col]='*';
    	}
	}
	if(h==2)
	{
		int row=rand()%l;
        int col=rand()%f;
        col=col+(le-1);
        for(int i=0;j[index][i]!='\0';i++,col--)
        {
            b[row][col]=j[index][i];
             b1[row][col]='*';
        }
	}
		if(h==3)
	{
		int row=rand()%f;
        int col=rand()%l;
         row=row+(le-1);
        for(int i=0;j[index][i]!='\0';i++,row--)
        {
            b[row][col]=j[index][i];
             b1[row][col]='*';
    	}
	}
	
	 for(int i=0;i<l;i++)
    {
    	cout<<"        ";
        for(int j=0;j<l;j++)
        {
          cout<<"|"<<b[i][j];
          
        }
        cout<<"|"<<endl;
    }
    //win condition
	string guess;
	cout<<"  the word you found  "<<endl<<"\t";
	cin>>guess;
	  if(guess==j[index])
    {
        cout<<" \n Congratulations ! You have Found the Hidden word  "<<endl<<endl;
        return 1;
    }
    else
    {
        cout<<" Sorry ! Your guessed word is incorrect "<<endl<<endl;
        cout<<"\n the correst word is "<<output<<endl<<endl;
         for(int i=0;i<l;i++)
   			 {
    			cout<<"        ";
        		for(int j=0;j<l;j++)
        			{
          				cout<<"|"<<b1[i][j];
         	 
       				 }
       			 cout<<"|"<<endl;
   			 }
        return 0;
    }			
											
							
}
void info()
{
	cout<<" Find the Hidden word           "<<endl;
	
}
