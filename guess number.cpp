#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	// Seed the random number generator
	//int secret_number = rand() % 100 + 1;//a number between one and 100
	//0 to 49 mul by 2 then will even only 0 98 +2 to shift to 2 to 100
	int secret_even_number = (rand() % 50) * 2 + 2;
	int guess_number=0;


	cout << "Manar loves Even numbers so much.\n" ;
	cout<< "She thinks that they are kinder than odd ones, she has chosen one \n";

	
	while (secret_even_number!=guess_number)
	{
		cout << "Enter your guess\n";cin >> guess_number;

		if (guess_number % 2 != 0)
		{
			cout << "It is not from Manar's favorite numbers. Try again.\n";
		}

		else if (secret_even_number < guess_number)
		{
			cout << "Try again ! it is higher\n";
		}
		else if (secret_even_number > guess_number)
		{
			cout << "Try again ! it is smaller\n";
		}
		
		else
		{
			cout << "Congratulations ! you guessed it well .\n";
		}
		
	}
	return 0;

}
