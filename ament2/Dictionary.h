/*********************Program Header*****************************/
/*Purpose: To create variables and methods to be used in the .h */
/* version of this file and compiled and ran by main.           */
/*Author: Aaron Brunette					*/
/*Etc. Description: This is the only class file used by main.   */
/* There are two const ints for holding the maximum number of   */
/* words in the dictionary and files. totalWordsInDict holds the*/
/* number of words contained in the dictionary. numOfWordsInFile*/
/* is the number of files. The two bools are to determine if a  */
/* method failed or not. There are two constructors, a default  */
/* and one that sets the max words. There are a number of       */
/* methods that are called on depending on the commands in the  */
/* transaction file.                                            */
/****************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class Dictionary
{
	private:
		const 	int maxWordsInDict;			//maximum words in dictionary
		const 	int maxWordsPerFile;			//maximum words per file
			int totalWordsInDict;			//number of words in dictionary
			int numOfWordsInFile[26];		//number of files in dictionary
		static	bool failure;				//returned if method failed
		static	bool success;				//returned if method succeeded

	public:
		Dictionary();					//default constructor sets static values to 0
		Dictionary(int dictMaxWords, int fileMaxWords);	//constructor initializes statics to given values
		bool AddAWord(string word);			//adds a word to a file
		bool DeleteAWord(string word);			//deletes a word from a file
		bool SearchForWord(string word);		//searches for a word in a file
		bool PrintAFileInDict(string filename);		//prints a file
		bool SpellChecking(string fileName);		//spell checks a file against dictionary
		bool InsertWordsIntoDict(string fileName);	//inserts file into dictionary
		void ProcessTransactionFile();			//reads user input file for commands that call above methods
};
#endif
