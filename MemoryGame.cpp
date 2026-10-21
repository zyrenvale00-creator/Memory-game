#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	srand(time(0));
	
	char letters[16]
	{
		'A','A','B','B',
		'C','C','D','D',
		'E','E','F','F',
		'G','G','H','H'
	};
	
	char board[4][4];
	bool found[4][4] = {};
	
	//Shuffle letters
	for(int i = 0; i < 16; i++)
	{
		int j = rand() % 16;
		
		char temp = letters[i];
		letters[i] = letters[j];
		letters[j] = temp; 
	}
	
	//Fill the board
	int index = 0;
	
	for(int r = 0; r < 4; r++)
	{
		for(int c = 0; c < 4; c++)
		{
			board[r][c] = letters[index];
			index++;
		}
	}
	
	//Show for 3 seconds
	
	cout<<"==========================\n";
	cout<<"   Memory Matching Game\n";
	cout<<"   Memorize the letters\n";
	cout<<"==========================\n\n";
	
	cout<<"   1 2 3 4\n\n";
	
	for(int r = 0; r < 4; r++)
	{
		cout<<r+1<<" ";
		cout<<" ";
		for (int c = 0; c < 4; c++)
		{
			cout<<board[r][c]<<" ";
		}
		cout<<endl;
	}
	this_thread::sleep_for(chrono::seconds(3));
	system("cls");
	
	int pairs = 0;
	
	while(pairs < 8)
	{
		cout<<"   Memory Matching Game   \n";
		cout<<"==========================\n\n";
		cout<<"   1 2 3 4\n\n";
		
		//Display the board
		
		for(int r = 0; r < 4; r++)
		{
			cout<<r+1<<" ";
			
			for(int c = 0; c < 4; c++)
			{
				if(found[r][c])
				{
					cout<<" "<<board[r][c];
				}
				else
				{	
					cout<<" ";
					cout<<"?";
				}
			}
			cout<<endl;	
		}
		int r1, c1, r2, c2;
		
		cout<<"\nEnter the first row and column: ";
		if(!(cin >>r1>>c1))
		{
			return 0;
		}
		
		cout<<"\nEnter the second row and column: ";
		if(!(cin >>r2>>c2))
		{
			return 0;
		}
		
		//Check user input valid or not
		
		if(r1 < 1 || r1 > 4 || c1 < 1 || c1 > 4 || r2 < 1 || r2 > 4 || c2 < 1 || c2 > 4)
		{
			cout<<"\n\nInvalid Input\n";
			this_thread::sleep_for(chrono::seconds(1));
			system("cls");
			continue;
		}
		
		//Converts inputs into indexes
		
		r1--;
		c1--;
		r2--;
		c2--;
		
		//Chect is the boxes can be selected
		
		if((r1 == r2 && c1 == c2) || 
			found[r1][c1] || found[r2][c2])
		{
			cout<<"\n\nChoose two different positions\n";
			this_thread::sleep_for(chrono::seconds(1));
			system("cls");
			continue;
		}
		
		//Reveal both found leters
        
        found[r1][c1] = true;
        found[r2][c2] = true;
        
        system("cls");
        
        cout<<"Your selected letters\n\n";
        cout<<"   1 2 3 4\n\n";
        
        for(int r = 0; r < 4; r++)
		{
			cout<<r+1<<" ";
			for(int c = 0; c < 4; c++)
			{
				if(found[r][c])
				{
					cout<<" "<<board[r][c];
				}
				else
				{
					cout<<" ";
					cout<<"?";
				}
			}
			cout<<endl;	
		}
		
		//Check for match
		
		if(board[r1][c1] == board[r2][c2])
		{
			cout<<"\nMatch!";
			pairs++;
			cout<<"You have found: "<<pairs<<"/8\n";
			
			this_thread::sleep_for(chrono::seconds(1));
			system("cls");
		}
		else
		{
			cout<<"\nNot match\n";
			
			found[r1][c1] = false;
        	found[r2][c2] = false;
			
			this_thread::sleep_for(chrono::seconds(2));
			system("cls");
			continue;
		}
	}
	
	cout<<"===============================\n";
	cout<<"Congratulations!!!!\n";
	cout<<"I can't believe, how you won!\n";
	cout<<"Now, Get lost!\n";
	cout<<"===============================\n";
	
	system("pause");

	return 0;
}