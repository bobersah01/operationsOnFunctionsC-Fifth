//SUBSETS OF A STRING - THE PROGRAM PERFORMED WELL.
#include <iostream>
#include <string>
using namespace std;

//First, we are controlling that the sentence, which is given by user,
//includes duplicated characters or white spaces. If there is any of them, the program displays an error message.
//If there is not any error, the program will successfully gives the substrings of the given sentence.

//If a sentence includes space, it displays invalid sentence message.
bool includeSpace(const string& sentence)
{
	int counter = 0;
	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == ' ')
			return false;
	}
	return true;
}

//If there is a duplicated character, it displays invalid sentence message.
int isDuplicated(const string& sentence)
{
	int counter = 1;
	for (int i = 0; i < sentence.length()-1; i++)
	{
		//counter = 1;
		for (int j = i + 1; j < sentence.length(); j++)
		{
			if (sentence[i] == sentence[j])
				counter += 1;
		}
	}
	return counter;
}

//This function is taking three parameters, first is constant sentence, second is current subset,
//the last one is index. 
void listSubsets(const string& sentence, string currentSubset, int index)
{
	if (index == sentence.length())
	{
		cout << "{ " << currentSubset << " }" << endl;
		return;
	}

	//three parameters: first parameters is used to get sentence.
	//second is used to determine the current subset and update it by increasing index by one.
	listSubsets(sentence, currentSubset + " " + sentence[index], index + 1);
	
	//this is for eliminating the current subset from the string.
	listSubsets(sentence, currentSubset, index + 1);
}

int main()
{
	//We are taking sentence from the user as input.
	string sentence;
	bool space; //to determine whether a sentence includes space or not. 
	int numberOfCounter; //to define the number of characters in a sentence and determine duplicated characters. 

	cout << "Please enter a sentence: " << endl;
	getline(cin,sentence);

	//this function is taking three parameters. At the end, we define the index and in all recursion,
	//we are increasing index by one.

	space = includeSpace(sentence); //must be true for validating.
	//cout << "Result of the function: " << space << endl;

	numberOfCounter = isDuplicated(sentence); //must be equal 1 for validating, if bigger than 1 which means there is a duplicated character.
	//cout << "Counter of the function: " << numberOfCounter << endl;

	if (space && numberOfCounter == 1)
		listSubsets(sentence, "", 0);
	else
		cout << "Invalid Sentence. There is/are duplicated character/s or white space/s." << endl;

	//Additionally, this program will be improved such as user enters a sentence
	//that does not include any duplicated characters or white spaces.

	return 0;
}