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
	cout<<"                      # Welcome to Find the word #\n";
	cout<<"Rules-\n 1.If you Find the  Word without hint you will get 10 points\n 2.If you find the word with the hint you will get 5 points";
	cout<<"\n 3.And Obviously if you don't find the word you will receive 0 points \n\n  "<<"\n\n";
	cout<<"Enter Player Name  -  ";
	getline(cin,name);
	cout<<endl;
	system("cls");
	cout<<" So, you are "<<name<<"\n let's see how many words you can find"<<endl<<endl;
	cout<<" Press 1 for Effortless mode \n Press 2 for Effortful mode  \n";
	cin>>d;
    int highscore;
	int score=0;
	do
	{
		system("cls");
		cout<<"";
		info();
		score=score+game(d);
		cout<<" \n Your Current Score : "<<score<<endl; 
		cout<<"\n Wanna try  again press y \n If not press n \n";
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
			cout<<"\n *you got the highest score\n";
			highscore=score;
		}
		write<<highscore;
	}
	write.close();
	cout<<"\n *the highscore is "<<highscore;
	
	}
	return 0;
	
}



//main game
int game(int u)
{
	int l; 
	if(u==1)
	{l=5;}
	else
	{l=10;}
	int index;
	string output;
	srand(time(0));
    string j[949];
	ifstream read;      // for getting the words in the array//528
	read.open("dir.txt");
	for(int k=0;k<949;k++)
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
			//b[i][j]='-'; //cheat
			 b1[i][j]='*';         
             b[i][j]=c;
        }
    }
    // randomly taking words to insert in the puzzle
	
	int le;
	if(u==1)
	{
	    index=rand()%528;
	}
	else
	{
		index=rand()%949;
	}
		
	
     output=j[index];
	 le=j[index].length();     
     
     
	//insertion of words
	int h=rand()%8;
	
	int f=(l+1)-le;
	int dl=(l-le)+1;
	if(h==0)
	{
		int row=rand()%l;
        int col=rand()%f;
        for(int i=0;j[index][i]!='\0';i++,col++)
        {
            b[row][col]=j[index][i];
            b1[row][col]=j[index][i];
        }
	}
	if(h==1)
	{
		int row=rand()%f;
        int col=rand()%l;
        for(int i=0;j[index][i]!='\0';i++,row++)
        {
            b[row][col]=j[index][i];
             b1[row][col]=j[index][i];
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
             b1[row][col]=j[index][i];
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
             b1[row][col]=j[index][i];
    	}
	}
	//for diagonal 
	if(h==4)
	{
		int row=rand()%dl;
		int col=rand()%dl;
		for(int i=0;j[index][i]!='\0';i++,row++,col++)
		{
			 b[row][col]=j[index][i];
             b1[row][col]=j[index][i];
             
		}
	}
		if(h==5)
	{
		int row=rand()%dl;
		int col=rand()%dl;
		col=col+l-dl;
		for(int i=0;j[index][i]!='\0';i++,row++,col--)
		{
			 b[row][col]=j[index][i];
             b1[row][col]=j[index][i];
             
		}
	}
		if(h==6)
	{
		int row=rand()%dl;
		int col=rand()%dl;
		row=row+l-dl;
		for(int i=0;j[index][i]!='\0';i++,row--,col++)
		{
			 b[row][col]=j[index][i];
             b1[row][col]=j[index][i];
             
		}
	}
		if(h==7)
	{
		int row=rand()%dl;
		int col=rand()%dl;
		col=col+l-dl;
		row=row+l-dl;
		for(int i=0;j[index][i]!='\0';i++,row--,col--)
		{
			 b[row][col]=j[index][i];
             b1[row][col]=j[index][i];
             
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
	cout<<"  *If you found the word  write it \n  *if you want hint press 'h'\n  *If you can not found the word press 'l' "<<endl<<"\t";
	cin>>guess;
		if(guess=="h")	
	{
		string hint_guess;
		cout<<"\nHint-\n";
		cout<<"  The length of the word you are finding is "<<le<<endl;
		cout<<"  and it is written ";
				if(h==0||h==2)
				{
					cout<<"Horizontally";
				}
					if(h==1||h==3)
				{
					cout<<"Vertically";
				}
					if(h==4||h==5||h==6||h==7)
				{
					cout<<"Diagonally";
				}
			cout<<endl<<"  \n\n  Did you find the word now ? \n  If you have write it \n  If not ,it's time to give up, press n"<<endl;
			cin>>hint_guess;
					 if(hint_guess==j[index])
		   					 {
		        				cout<<" \n #Congratulations ! You have Found the Hidden word  "<<endl<<endl;
		        					return 5;
		   					 }
   					  if(hint_guess!=j[index])
					    {
					        cout<<" #Sorry ! Your word is incorrect "<<endl<<endl;
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
			
	  if(guess==j[index])
    {
        cout<<" \n Congratulations ! You have Found the Hidden word  "<<endl<<endl;
        return 10;
    }
   if(guess!=j[index]||guess=="l")
    {
        cout<<" Really ! you can't Find it  "<<endl<<endl;
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
	cout<<"   #  Find the Hidden word  #  "<<endl;
	
}
