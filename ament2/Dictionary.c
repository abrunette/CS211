/*********************Program Header*****************************/
/*Purpose: To recieve input from a transaction file and follow  */
/* the commands given by said file.				*/
/*Input: Commands from transaction file: AddW, DeleteW, SearchW */
/* PrintF, SpellCheck, InsertF					*/
/* Also asks user for the name of the transaction file.		*/
/*Output: Outputs whether or not each individual command was    */
/* succesful or not.						*/
/*Date: 2016.03.29						*/
/*Author: Aaron Brunette					*/
/*Etc. Description: This is the .h file that defines all the    */
/* functions described in the .c file of the same name. This    */
/* file reads in from the file of the users choosing and will   */
/* output commands based on the information in the file they    */
/* chose. If the commands are invalid the program will end.     */
/* With valid commands the program will tell the user which     */
/* parts of the commands passed or failed.                      */
/****************************************************************/

#include "Dictionary.h"

bool Dictionary::failure = false;
bool Dictionary::success = true;

Dictionary::Dictionary():maxWordsInDict(10000), maxWordsPerFile(100), totalWordsInDict(0)	//sets default maximums and total for files and dictionary
{
	for(int i = 0; i < 26; i++)
		numOfWordsInFile[i] = 0;	//sets default size of all files to 0
}
	
//------------------------------------------------------------------
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords),maxWordsPerFile(fileMaxWords),totalWordsInDict(0)
{
	for(int i = 0; i < 26; i++)
		numOfWordsInFile[i] = 0;	//sets default size of all files to 0
}

/*********************Routine Header*****************************/
/*Purpose: To append a given word to the end of the respective  */
/* file determined by the first letter of the word.             */
/*Date: 2016.03.17						*/
/*Parameters: The string word, taken from input or a file.	*/
/*Local variables: searchResult is used to determine the result */
/* of the function Search. fileName holds a variable that is    */
/* changed depending on the first letter of the word. fout holds*/
/* the output file.						*/
/****************************************************************/
bool Dictionary::AddAWord(string word)					//takes string of individual word to be added
{
	bool searchResult = false;
	string fileName = "&.txt";
	fileName[0] = toupper(word[0]);      				// replaces the # sign with appropriate letter
	searchResult = SearchForWord(word);

	if(searchResult == false)
		return (Dictionary::failure);				//Word already exists	
	
	ofstream fout;
	fout.open(fileName.data(), ios::app);

	if(totalWordsInDict++ > maxWordsInDict)
		return (Dictionary::failure);				//Too many words in dictionary
	
	if(numOfWordsInFile[fileName[0]-'A']++ > maxWordsPerFile)
		return (Dictionary::failure);				//Too many words in file

	word[0] = tolower(word[0]);

	fout << word << endl;
	totalWordsInDict++;
	numOfWordsInFile[fileName[0]-'A']++;
	fout.close();
	return (Dictionary::success);
}

/*********************Routine Header*****************************/
/*Purpose: To delete a given word from a file using a vector.   */
/*Date: 2016.03.17						*/
/*Parameters: The string word, taken from input or a file.	*/
/*Local variables: searchResult is used to determine the result */
/* of the function Search. fileName holds a variable that is    */
/* changed depending on the first letter of the word. fin holds */
/* the input file. hold is a vector used to find the word that  */
/* needs to be deleted.						*/
/****************************************************************/
bool Dictionary::DeleteAWord(string word)				//takes string of individual word to be deleted
{
	bool searchResult = false;
	string currword;
	string fileName = "&.txt";
	fileName[0] = toupper(word[0]);	
	searchResult = SearchForWord(word);				//searches for word

	if(searchResult == true)
		return (Dictionary::failure);

	fstream fin;
	fin.open(fileName.data());

	vector <string> hold;

	while(fin >> currword)
		hold.push_back(currword);				//store file in vector

	for(int i = 0; i < hold.size(); i++)
	{
		if(hold[i] == word)					//checks if word is in vector
		{
			hold.erase(hold.begin()+i);
			totalWordsInDict--;
			numOfWordsInFile[fileName[0]-'A']--;
			for(int j = 0; j < hold.size(); j++)		//stores vector into file without deleted word
				fin << hold[i];
			fin.close();
			return(Dictionary::success);
		}
	}
}

/*********************Routine Header*****************************/
/*Purpose: To search for a give word in the dictionary.		*/
/*Date: 2016.03.26						*/
/*Parameters: The string word, taken from input or a file.      */
/*Local variables: fileName holds a variable that is changed    */
/* depending on the first letter of the word. currword holds the*/
/* current word the file is on to be compared against word. fin */
/* hold the input file.						*/
/****************************************************************/
bool Dictionary::SearchForWord(string word)				//take string of individual word to be searched
{
	string fileName = "&.txt";
	string currword;
	fileName[0] = toupper(word[0]);
	ifstream fin;
	fin.open(fileName.data());
	
	while(fin >> currword)
	{
		if(word == currword)
			return (Dictionary::failure);
	}
	return (Dictionary::success);
}

/*********************Routine Header*****************************/
/*Purpose: To print out the words in a file of the dictionary.  */
/*Date: 2016.03.26						*/
/*Parameters: The string fileName, taken from the transaction   */
/* file.							*/
/*Local variables: printWord to hold the word that needs to be	*/
/* printed. wordCount to determine if 5 words have been printed */
/* already. fin to hold the input file.				*/
/****************************************************************/
bool Dictionary::PrintAFileInDict(string fileName)			//takes name of file to be printed
{
	string printWord;
	int wordCount = 0;
	ifstream fin;
	fin.open(fileName.data());

	if(!fin)
		return (Dictionary::failure);
	
	cout << endl;
	while (fin >> printWord)
	{
		if(wordCount == 5)					//after 5 words are printed drop down 1 line
		{
			wordCount = 1;
			cout << endl << printWord << " ";
		}
		else
		{
			cout << printWord << " ";
			wordCount++;
		}
	}
	cout << endl;
	return (Dictionary::success);
}

/*********************Routine Header*****************************/
/*Purpose: To check the spelling of one file against the	*/
/* the words in the dictionary.					*/
/*Date: 2016.03.26						*/
/*Parameters: The string fileName, taken from the transaction   */
/* file.							*/
/*Local variables: searchResult is used to determine the result */
/* of the search function. currword tells what word in the file */
/* the file is on. fin holds the input file.			*/
/****************************************************************/
bool Dictionary::SpellChecking(string fileName)				//takes name of file to be spellchecked
{
	bool searchResult = false;
	string currword;
	ifstream fin;
	fin.open(fileName.data());

	if(!fin)
		return (Dictionary::failure);
	cout << "\nThe following words are spelled incorrectly:\n";
	while (fin >> currword)
	{
		for(int i = 0; i < currword.size(); i++)
			currword[i] = tolower(currword[i]);
		searchResult = SearchForWord(currword);			//if word cannot be found output
		if(searchResult == true)
			cout << currword << " ";
	}
	cout << endl;
	return (Dictionary::success);
}

/*********************Routine Header*****************************/
/*Purpose: To insert a group of words from a file into the      */
/* dictionary.							*/
/*Date: 2016.03.26						*/
/*Parameters: The string fileName taken from the transaction    */
/* file.							*/
/*Local variables: currword holds the current word in the file. */
/* fin holds the input file.					*/
/****************************************************************/
bool Dictionary::InsertWordsIntoDict(string fileName)			//takes name of file to be inserted
{
	string currword;
	ifstream fin;
	fin.open(fileName.data());

	if(!fin)
		return (Dictionary::failure);	

	while (fin >> currword)
	{
		for(int i = 0; i < currword.size(); i++)
			currword[i] = tolower(currword[i]);
		AddAWord(currword);					//stores words from file into dictionary
	}
	return (Dictionary::success);
}

/*********************Routine Header*****************************/
/*Purpose: Asks the user which transaction file they will open  */
/* and takes instructions and data that is sent into it's       */
/* respective program depending on the command.			*/
/*Date: 2016.03.26						*/
/*Parameters: None						*/
/*Local variables: fileName to hold the user input for the      */
/* transaction file. result to tell whether the function failed */
/* or succeeded. fin to hold the input file. 			*/
/****************************************************************/
void Dictionary::ProcessTransactionFile()
{
	string fileName, command, data;
	bool result = false;
	cout << "Please enter the name of the transaction file:\t";
	getline(cin, fileName);						//reads in filename from user

	cout << endl;

	ifstream fin;
	fin.open(fileName.data());

	if(!fin)							//checks if file exists
	{
		cout << "That transaction file does not exist!" << endl;
		return;
	}
	
	//output for commands from transaction file
	while(fin >> command >> data)
	{
		if(command == "AddW")
		{
			result = AddAWord(data);
			if(result == false)
				cout << "The word " << data << " was not added successfully!" << endl;
			else
				cout << "The word " << data << " was added successfully!" << endl;
		}
		else if(command == "DeleteW")
		{
			result = DeleteAWord(data);
			if(result == false)
				cout << "The word " << data << " was not deleted successfully!" << endl;
			else
				cout << "The word " << data << " was deleted successfully!" << endl;
		}
		else if(command == "SearchW")
		{
			result = SearchForWord(data);
			if(result == true)
				cout << "The word " << data << " was not found!" << endl;
			else
				cout << "The word " << data << " was found!" << endl;
		}
		else if(command == "PrintF")
		{
			cout << "Printing file " << data  << endl;
			result = PrintAFileInDict(data);
			if(result == false)
				cout << "The file " << data << " could not be opened!" << endl;
			else
				cout << "\nThe file " << data << " was printed!\n" << endl;
		}
		else if(command == "SpellCheck")
		{
			result = SpellChecking(data);
			if(result == false)
				cout << "The file " << data << " could not be opened!" << endl;
			else
				cout << "\nThe file " << data << " was spellchecked successfully!" << endl;
		}
		else if(command == "InsertF")
		{
			result = InsertWordsIntoDict(data);
			if(result == false)
				cout << "The file " << data << " could not be opened!" << endl;
			else
				cout << "The file " << data << " was inserted successfully!" << endl;
		}
		else
		{
			cout << "Invalid command in transaction file!" << endl
			     << "Command was " << command << endl;
		}
	}
}
