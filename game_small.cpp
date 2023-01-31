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
	cout<<name<<" Your Final Score  : "<<score;
	ofstream out("score.txt");
	out<<name;
	}
	
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
	string a[20]={"adult","block","world",
					"hello","name","and","the"
							,"same","row","big","code","class"
							,"death","earth","boy","sure",
							"rat","cat","index","broke"};
	char b[l][l];
	for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            char c;
            int r;
            r= rand() % 26;   // generate a random number
            c= 'a' + r;            // Convert to a character from a-z
            b[i][j]=c;
        }
    }
	int index=rand()%20;
	output=a[index];
	int h=rand()%2;
	int f=(l+1)-a[index].length();
	if(h==0)
	{
		int row=rand()%l;
        int col=rand()%f;
        for(int i=0;a[index][i]!='\0';i++,col++)
        {
            b[row][col]=a[index][i];
        }
	}
	else
	{
		int row=rand()%f;
        int col=rand()%l;
        for(int i=0;a[index][i]!='\0';i++,row++)
        {
            b[row][col]=a[index][i];
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
	string guess;
	cout<<"  the word you found  "<<endl<<"\t";
	cin>>guess;
	  if(guess==a[index])
    {
        cout<<" \n Congratulations ! You have Found the Hidden word  "<<endl<<endl;
        return 1;
    }
    else
    {
        cout<<" Sorry ! Your guessed word is incorrect "<<endl<<endl<<endl;
        return 0;
    }			
											
							
}
void info()
{
	cout<<" Find the Hidden word           "<<endl;
	
}