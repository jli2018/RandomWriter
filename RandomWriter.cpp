/*
	RandomWriter
	Jessica Li
	05/02/16

	File name can be changed on line 24 in method read(). 
	Seed length can be changed on line 119 in method main(), the runner method. 
*/

#include <iostream>
#include <fstream>
//#include <string>
using namespace std;

/*
	Reads the source text file and returns the test. 
	Adds a space after each line because for some reason spaces aren't included after lines
*/
string read()
{
	string line;
	string text;
	//change file below
	ifstream myfile ("Jane_Eyre.txt");
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline (myfile, line);
			text += line + " ";

		}
		myfile.close();
	}
	else cout << "Unable to open file";

	//cout << text << endl;
	return text;
}

/*
	Takes in the source text and a seed length. 
	Chooses a random position for the first seed, using a dowhile loop to ensure the seed is not at the end of the text.
	Finds seed in text, adds all following letters to string nextLetters. Chooses a random position in nextLetters, adds 
	the character at that position to output string returnText. 
	Adds that character to the seed and cuts off the first character of the seed --> this is the new seed. 

*/
string writePoem( string text, int seedLength )
{
	string nextLetters;
	string returnText = "";

	//enters the time, an always changing number, as the seed for random number generation
	 srand(time(NULL));
	 int seedIndex;

	 //creates random number as index for seed, loops if there is not enough text left to make seed
	 do {
		 seedIndex = rand() % text.length();
	 } while (text.length() - (seedIndex + seedLength) < seedLength );

	 string seed = text.substr(seedIndex, seedLength);

	 for ( int i = 0; i < 200; i++ )
	 {
	 	//for testing purposes
	 	//cout << seed << endl;

		 //must clear list of following letters with each new seed
		 nextLetters = "";
		 for ( int i = 0; i < text.length(); i++ )
		 {
			 if ( text.substr(i, seedLength).compare( seed ) == 0 )
			 {
				nextLetters += text.substr( i+seedLength, 1 );
			}
		 }

		 //if the seed is at the end of the text and there are no instances of following characters,
		 //then nextLetters will be empty. The seed will be set to the beginning and the loop will continue. 
		 if ( nextLetters.length() == 0 )
		 {
		 	seed = text.substr( 0, seedLength );
		 	continue;
		 }

		 //chooses random position from nextLetters
		 int temp = rand() % nextLetters.length();
		 //adds randomly chosen character to returnText
		 returnText += nextLetters.substr(temp,1);

		 //below was for old method, ignore
		 //move seed one letter to the right
		 ////seedIndex++;

		 //creates new seed by adding the random character chosen above
		 seed = seed.substr(1) + nextLetters.substr(temp,1);

		 //below was for old method, ignore
		 //has to be less than or equal to, not sure why
		 /*if ( text.length() - seedIndex <= seedLength+1 )
		 {
		 	 seedIndex = 0;
			 cout << "!";
		 }*/
	}

	return returnText;

}

/*
	Main method, also runner method. 
*/
int main()
{
	//the 7 indicates seed length, change it to change seed length
	cout << writePoem( read(), 7 ) << endl;
	return 0;
}




