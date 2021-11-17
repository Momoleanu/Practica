#include"Header.h"
#include<ctime>

void PrintIntroduction(int Difficulty)
{
	cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room..." << endl;
	cout << "Enter the correct code to continue.." << endl;
	cout << endl;
}

bool PlayGame(int Difficulty,int lives)
{
	PrintIntroduction(Difficulty);

	const int CodeA = rand()%Difficulty+3;
	const int CodeB = rand()%Difficulty+3;
	const int CodeC = rand()%Difficulty+3;

	cout << CodeA << CodeB << CodeC;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	cout << endl;
	cout << "There are 3 numbers in the code" << endl;
	cout << "The codes add-up to: " << CodeSum << endl;
	cout << "The codes multiply-up to:" << CodeProduct << endl;

	int GuessA, GuessB, GuessC;
	cout << "Choice: ";
	cin >> GuessA;
	cin >> GuessB;
	cin >> GuessC;
	cout << endl;

	cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << endl;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;


	if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
	{
		cout << "***Well done agent! You have extracted a file! Keep going!***" << endl;
		return 1;
	}
	else 
		if(lives==0)
	{

		cout << "***You lost! Try again*** ";
		return 0;
	}


}

int main(void)
{
	 srand(time(NULL));
	 int lives = 3;
	 int LevelDifficulty = 1;
	 const int MaxDifficulty = 5;

	 cout << "You have 3 lives! Don't lose them " << endl;
	while (LevelDifficulty<=MaxDifficulty&&(lives!=0))
	{ 
		bool bLevelComplete = PlayGame(LevelDifficulty,lives);
		cin.ignore();
		cin.clear();
		cout << endl;

		if (bLevelComplete==1)
		{
			++LevelDifficulty;
			system("CLS");
		}
		else
		{
			system("CLS");
			--lives;
			cout << "You lost a life! You have " << lives << " remaining! "<<endl;
			
		}
		
	}
	if ((LevelDifficulty == 6))
	{
		if (lives == 3)
		{
			cout << "***Great work agent! You got all the files! Now get out of there! ***" << endl;
			cout << "You won with " << lives << " lives remaining" << endl << "You are a master hacker! " << endl << endl;
		}
		if (lives == 2)
		{
			cout << "***Great work agent! You got all the files! Now get out of there! ***" << endl;
			cout << "You won with " << lives << " lives remaining" << endl << "You are a pro hacker! " << endl << endl;
		}
		if(lives==1)
		{
			cout << "***Great work agent! You got all the files! Now get out of there! ***" << endl;
			cout << "You won with " << lives << " life remaining" << endl << "You are a good hacker! " << endl << endl;
		}

	}
	if (lives == 0)
		cout << "You lost! Try again!" << endl;
	
	return 0;
}
