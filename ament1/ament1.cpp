/********************************************PROGRAM HEADER**********************************************/
/*Purpose: To encrypt or decrypt the file Orginal.txt, using ROT or Cryptogram encryption, depending on */
/* user input.                                                                                          */
/*													*/
/*Input: User can change files, Original.txt or CryptoKey.txt, to change output. User only needs to     */
/* follow on-screen instructions to encrypt or decrypt files.                                           */ 
/*													*/
/*Output: Program will change data in the following files:						*/
/* EncryptRot.txt, DecryptRot.txt, EncryptCrypto.txt, DecryptCrypto.txt					*/
/* Files will contain encrypted or decrypted data from file Original.txt                                */
/*													*/
/*Date: 03/01/2016											*/
/*													*/
/*Author: Aaron Brunette										*/
/*													*/
/*Email: brune010@cougars.csusm.edu									*/
/*													*/
/*Class: CS 211												*/													
/********************************************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

//files used
//Original.txt		CryptoKey.txt		EncryptRot.txt		DecryptRot.txt		EncryptCrypto.txt	DecryptCrypto.txt

/****************************************Initialize Classes*********************************************/

class EncryptROT				//Class used for encrypting with ROT
{
	private:
	//Vectors
	vector <string> OriginalIntoVecROT;	//Vector for storing Original.txt for ROT
	vector <string> EncryptUseRot;		//Vector for storing encrypted version of Original.txt
	vector <string> DecryptUseRot;		//Vector for storing decrypted version of Original.txt

	public:
	//Routines
	void ReadToVecROT();			//For reading Original.txt into OriginalIntoVecROT
	void EncryptToVecROT(int);		//For encrypting OriginalIntoVecROT into Vector, result stored in EncryptRot.txt
	void DecryptToVecROT(int);		//For decrypting EncryptUseRot into Vector, result stored in DecryptRot.txt
};

class EncryptCRYPT				//Class used for encrypting with Cryptogram
{
	private:
	//Vectors
	vector <string> OriginalIntoVecCRY;	//Vector for storing Original.txt for Cryptogram
	vector <string> EncryptUseCryp;		//Vector for storing encrypted version of Original.txt
	vector <string> DecryptUseCryp;		//Vector for storing decrypted version of Original.txt
	
	public:
	//Routines
	void ReadToVecC();			//For reading Original.txt into OriginalIntoVecCRY
	void EncryptToVecC(string);		//For encrypting OriginalIntoVecCRY into Vector, result stored in EncryptCrypto.txt	
	void DecryptToVecC(string);		//For decrypting EncryptUseCryp into vector, result stored in DecryptCrypto.txt
};

/*****************************************Class Function Descriptions***********************************/

					//Functions used for ROT//
		      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

/*****************************************************************************************************/
//Purpose: To take Original.txt and store it in vector OriginalIntoVecROT
//Date: 2016.02.28
//Parameters: None
//Variables: word, to store words from Original.txt. rFile, to hold unencrypted text.
/*****************************************************************************************************/
void EncryptROT::ReadToVecROT()
{
	string word;	

	ifstream rFile;
	rFile.open("Original.txt");

	if(rFile)
	{
		while(rFile >> word)
		{
			for(int i = 0; i < word.size(); i++)
			{
				word[i] = tolower(word[i]);
			}
			OriginalIntoVecROT.push_back(word);
		}
	}
	else
		cout << "Error opening file!\n";

	rFile.close();
}

/****************************************************************************************************/
//Purpose: To take Original.txt and encrypt it, then store it in EncryptRot.txt
//Date: 2016.02.28
//Parameters: None
//Variables: word, store unencrypted words from Original.txt vector. eWord, to store encrypted words.
// rFile, to hold encrypted text.
/****************************************************************************************************/
void EncryptROT::EncryptToVecROT(int rot)
{
	string word, eWord; 

	for(int i = 0; i < OriginalIntoVecROT.size(); i++)
	{
		eWord = word = OriginalIntoVecROT[i];
		for(int j = 0; j < word.size(); j++)
		{
			unsigned char e = word[j];		//unsigned char used to avoid overflow into negative values
			if(e < 'a' || e > 'z')
			{
				eWord[j] = e;
			}
			else
			{
				e += rot;
				if(e > 'z')
				{
					e -= 26;
				}
				eWord[j] = e;
			}
		}
		EncryptUseRot.push_back(eWord);
		EncryptUseRot.push_back(" ");
	}

	ofstream rFile;
	rFile.open("EncryptRot.txt");
	if(rFile)
	{
		for(int k = 0; k < EncryptUseRot.size(); k++)
			rFile << EncryptUseRot[k];
	}
	else
		cout << "Error opening file!\n";
}

/******************************************************************************************************/
//Purpose: To take rot encrypted text and decrypt it, then store it in DecryptRot.txt
//Date: 2016.02.28
//Parameters: None
//Variables: word, to hold an encrypted word from the vector. dWord, to hold an decrypted word from the vector.
// rFile, to open encrypted rot text. dFile, to hold decrypted text. rot, to hold rot encryption key.
/******************************************************************************************************/
void EncryptROT::DecryptToVecROT(int rot)
{
	string word, dWord;
	
	ifstream rFile;
	rFile.open("EncryptRot.txt");

	while(rFile >> word)
	{
		EncryptUseRot.push_back(word);
		EncryptUseRot.push_back(" ");
	}

	rFile.close();

	for(int l = 0; l < EncryptUseRot.size(); l++)
	{
		dWord = word = EncryptUseRot[l];
		for(int m = 0; m < word.size(); m++)
		{
			unsigned char d = word[m];
			if(d < 'a' || d > 'z')
			{
				dWord[m] = d;
			}
			else
			{
				d -= rot;
				if(d < 'a')
				{
					d += 26;
				}
				dWord[m] = d;
			}
		}
		DecryptUseRot.push_back(dWord);
	}

	ofstream dFile;
	dFile.open("DecryptRot.txt");

	if(dFile)
	{
		for(int o = 0; o < DecryptUseRot.size(); o++)
			dFile << DecryptUseRot[o];
	}
	else
		cout << "Error opening file!\n";
}

				//Functions used for Cryptogram//
	  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

/*****************************************************************************************************/
//Purpose: To take Original.txt and store it in vector OriginalIntoVecCRY
//Date: 2016.02.28
//Parameters: None
//Variables: word, to store words from Original.txt. cFile, to hold unencrypted text.
/*****************************************************************************************************/
void EncryptCRYPT::ReadToVecC()
{
	string word;

	ifstream cFile;
	cFile.open("Original.txt");
	
	if(cFile)
	{
		while(cFile >> word)
		{
			for(int i = 0; i < word.size(); i++)
			{
				word[i] = tolower(word[i]);
			}
			
			OriginalIntoVecCRY.push_back(word);
		}
	}
	else
		cout << "Error opening file!\n";

	cFile.close();
}

/****************************************************************************************************/
//Purpose: To take Original.txt and encrypt it, then store it in EncryptCrypto.txt
//Date: 2016.02.28
//Parameters: None
//Variables: word, store unencrypted words from Original.txt vector. eWord, to store encrypted words.
// xyz, holds the alphabet for reference. cFile, to hold encrypted text.
/****************************************************************************************************/
void EncryptCRYPT::EncryptToVecC(string key)
{
	string word, eWord;
	string xyz = "abcdefghijklmnopqrstuvwxyz";

	for(int z = 0; z < OriginalIntoVecCRY.size(); z++)
	{
		eWord = word = OriginalIntoVecCRY[z];
		for(int j = 0; j < word.size(); j++)
		{
			if(word[j] < 'a' || word[j] > 'z')
			{
				eWord[j] = word[j];
			}
			else
			{
				int findEnc = xyz.find(word[j],0);
				eWord[j] = key[findEnc];
			}			

		}
		EncryptUseCryp.push_back(eWord);
		EncryptUseCryp.push_back(" ");
	}
	ofstream cFile;
	cFile.open("EncryptCrypto.txt");
	if(cFile)
	{
		for(int k = 0; k < EncryptUseCryp.size(); k++)
		{
			cFile << EncryptUseCryp[k];
		}
	}
	else
		cout << "Error opening file!\n";
}

/**************************************************************************************************/
//Purpose: To take cryptogram encrypted text and decrypt it, then store it in DecryptCrypto.txt
//Date: 2016.02.28
//Parameters: key, the variable that stores the cryptogram key
//Variables: word, to hold an encrypted word from the vector. dWord, to hold an decrypted word from the vector.
// xyz, holds the alphabet as reference. dFile, to open encrypted cryptogram text.
// oFile, to hold decrypted text.
/**************************************************************************************************/
void EncryptCRYPT::DecryptToVecC(string key)
{
	string word, dWord;

	ifstream dFile;
	dFile.open("EncryptCrypto.txt");

	while(dFile >> word)
	{
		EncryptUseCryp.push_back(word);
	}

	dFile.close();

	string xyz = "abcdefghijklmnopqrstuvwxyz";

	for(int y = 0; y < EncryptUseCryp.size(); y++)
	{
		dWord = word = EncryptUseCryp[y];
		for(int w = 0; w < word.size(); w++)
		{
			if(word[w] < 'a' || word[w] > 'z')
			{
				dWord[w] = word[w];
			}
			else
			{
				int findDec = key.find(word[w],0);
				dWord[w] = xyz[findDec];
			}
		}
		DecryptUseCryp.push_back(dWord);
		DecryptUseCryp.push_back(" ");
	}

	ofstream oFile;
	oFile.open("DecryptCrypto.txt");
	if(oFile)
	{
		for(int x = 0; x < DecryptUseCryp.size(); x++)
		{
			oFile << DecryptUseCryp[x];
		}
	}
	else
		cout << "Error opening file!\n";
}

/*****************************************Function prototypes*******************************************/

int EncOrDec();
int ChooseEncrypt();
int GetRotEncrypt();
int ChooseDecrypt();
int GetRotDecrypt();
bool Decision();
bool endP();
string getCryptKey();
void invalid();

/**********************************************MAIN*****************************************************/
//Purpose: To encrypt or decrypt Original.txt depending on user input
//Date: 2016.02.26
//Parameters: None
//Variables: Uend, for returning 0 if user wants to end the program.
/*******************************************************************************************************/
int main()
{
	bool Uend = false;

	Uend = Decision();

	if (Uend == true)	//Checking if user wants to end the program
	{
		return 0;
	}
}

/***************************************Function Definitions*******************************************/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/

/******************************************************************************************************/
//Purpose: To use other funtions to display an interactive menu for the user 
// to decide what they would like to do with Original.txt
//Date: 2016.02.27
//Parameters: None
//Variables: eOd, for choosing encryption or decryption. encType, for choosing encryption type. 
// decType, for choosing decryption type. rot, for choosing what the ROT encryption key is.
// pEnd, for returning if the user wants to end the program.
/******************************************************************************************************/ 
bool Decision()
{
	int eOd = 0, encType = 0, decType = 0, rot = 0;
	bool pEnd = false;

	do	//Starts menu
	{
		eOd = EncOrDec();
		switch(eOd)
		{
			case 1 :	//User is encrypting
			{
				do	//Choose what type of encryption the user wants
				{
					encType = ChooseEncrypt();
					switch(encType)
					{
						case 1 :
						{
							rot = GetRotEncrypt();			//get rot key

							//class function to ROT encrypt here
							EncryptROT new_ROTenc;			//initialize new class new_ROTenc
							new_ROTenc.ReadToVecROT();		//call function of EncryptROT
							new_ROTenc.EncryptToVecROT(rot);	//call function of EncryptROT

							cout << "\nOriginal.txt has been encrypted using rot" << rot << ".\n";
							break;
						}
						case 2 :
						{
							cout << "\nYou are encrypting using Cryptogram.\n\n"
							     << "Using cryptogram stored in file CryptoKey.txt\n\n";
							string cryptoStr = getCryptKey();	//get cryptokey

							//class functions to Crypto encrypt here
							EncryptCRYPT new_CRYenc;		//initialize new class new_CRYenc
							new_CRYenc.ReadToVecC();		//call function of EncryptCRYPT
							new_CRYenc.EncryptToVecC(cryptoStr);	//call function of EncryptCRYPT

							cout << "Original.txt has been encrypted using cryptogram.\n";
							break;
						}
						case 3 :
						{
							eOd = 0;
							break;
						}
						case 4 :
						{
							pEnd = endP();
							return pEnd;
						}
						default :
							invalid();	
					}
				} while(!(encType != 1 || encType != 2 || encType != 3 || encType != 4));
				break;
			}
			case 2 :	//User is decrypting
			{
				do		//Choose what type of decryption the user wants
				{
					decType = ChooseDecrypt();
					switch(decType)
					{
						case 1 :
						{
							rot = GetRotDecrypt();			//get rot key

							//class function to ROT decrypt here
							EncryptROT new_ROTenc;			//initialize new class new_ROTenc
							new_ROTenc.DecryptToVecROT(rot);	//call function of EncryptROT

							cout << "\nOriginal.txt has been decrypted using rot" << rot << ".\n";
							break;
						}
						case 2 :
						{
							cout << "\nYou have chosen Cryptogram decryption.\n\n"
 							     << "Using cryptogram stored in file CryptoKey.txt\n";
							string cryptoStr = getCryptKey();	//get cryptokey

							//class functions to CRYPT decrypt here
							EncryptCRYPT new_CRYenc;		//initialize new class new_CRYenc
							new_CRYenc.DecryptToVecC(cryptoStr);	//call function of EncryptCRYPT
							
							cout << "\nOriginal.txt has been decrypted with cryptogram.\n";
							break;
						}
						case 3 :
						{
							eOd = 0;
							break;
						}
						case 4 :
						{
							pEnd = endP();
							return pEnd;
						}
						default :
							invalid();
					}
				}while(!(decType != 1 || decType != 2 || decType != 3 || decType != 4));
				break;
			}
			case 3 :
			{
				pEnd = endP();
				return pEnd;
			}
			default :
				invalid();
		}	


	}while(eOd != 1 || eOd != 2 || eOd != 3);	//infinite loop, user ends program inside loop
}

/**********************************************************************************************************/
//Purpose: To have the user choose between encryption or decryption
//Date: 2016.02.27
//Parameters: None
//Variables: EoD, used to store user input, Returns EoD
/**********************************************************************************************************/
int EncOrDec()
{
	int EoD = 0;
	cout << "\n"
	     << "========================================================\n"
	     << "This program will encrypt or decrypt a file for you.\n"	//Asks user for input
	     << "\tEnter 1 for Encryption.\n"
	     <<	"\tEnter 2 for Decryption.\n"
	     << "\tEnter 3 to end the program.\n"
	     << "Enter: ";
	cin >> EoD;		//user input
	return EoD;
}

/********************************************************************************************************/
//Purpose: To have the user choose what type of encryption they want to use
//Date: 2016.02.27
//Parameters: None
//Variables: chooseEnc, to store the user input, Returns chooseEnc
/********************************************************************************************************/
int ChooseEncrypt()
{
	int chooseEnc = 0;
	cout << "\nYou are encrypting.\n";

	cout << "\nChoose your encryption type.\n"
	     << "\tEnter 1 for ROT encryption.\n"
	     << "\tEnter 2 for Cryptogram encryption.\n"
	     << "\tEnter 3 to jump back one menu.\n"
	     << "\tEnter 4 to end the program.\n"
	     << "Enter: ";
	cin >> chooseEnc;	//user input
	return chooseEnc;
}

/*******************************************************************************************************/
//Purpose: To get the ROT encryption key from the user
//Date: 2016.02.27
//Parameters: None
//Variables: rotEnc, to store the user input, Returns rotEnc
/*******************************************************************************************************/
int GetRotEncrypt()
{
	int rotEnc = 0;
	cout << "\nYou have chosen ROT encryption.\n\n"
	     << "Please enter the ROT encryption key you'd like your file to be encrypted with: ";
	
	cin >> rotEnc;		//user input
	if(rotEnc < 1)
		rotEnc *= -1;	//Invalid input catch, sets to positive if negative
								
	rotEnc = rotEnc % 26;	//Invalid input catch, rounds down to value within 26
	cout << "\nYou are encrypting using rot" << rotEnc << ".\n";
	return rotEnc;
}

/******************************************************************************************************/
//Purpose: To have the user choose what type of decryption they want to use
//Date: 2016.02.27
//Parameters: None
//Variables: chooseDec, to store the user input, Returns chooseDec
/******************************************************************************************************/
int ChooseDecrypt()
{
	int chooseDec = 0;
	cout << "\nYou are decrypting.\n";

	cout << "\nChoose your decryption type.\n"
	     << "\tEnter 1 for ROT decryption.\n"
	     << "\tEnter 2 for Cryptogram decryption.\n"
	     << "\tEnter 3 to jump back one menu.\n"
	     << "\tEnter 4 to end the program.\n"
	     << "Enter: ";
	cin >> chooseDec;	//user input
	return chooseDec;
}

/******************************************************************************************************/
//Purpose: To get the ROT decryption key from the user
//Date: 2016.02.27
//Parameters: None
//Variables: rotDec, to store the ROT value from user, Returns rotDec
/******************************************************************************************************/
int GetRotDecrypt()
{
	int rotDec = 0;
	cout << "\nYou have chosen ROT decryption.\n\n"
	     << "Please enter the ROT decryption key you'd like your file to be encrypted with: ";
	
	cin >> rotDec;		//user input
	if(rotDec < 1)
		rotDec *= -1;	//Invalid input catch, sets to positive if negative
								
	rotDec = rotDec % 26;	//Invalid input catch, rounds down to value within 26
	cout << "\nYou are encrypting using " << rotDec << ".\n";
	return rotDec;
}

/*****************************************************************************************************/
//Purpose: To tell the user the program is ending and ends program.
//Date: 2016.02.27
//Parameters: None
//Variables: Returns true to main
/****************************************************************************************************/
bool endP()
{
	cout << "\nEnding program!\n";
	return true;
}

/***************************************************************************************************/
//Purpose: Retrieve the Cryptogram key from the file, CryptoKey.txt and send it to Decision()
//Date:	2016.02.28
//Parameters: None
//Variables: Ckey, to hold the data in the file, CryptKey to open the file, Returns Ckey
/***************************************************************************************************/
string getCryptKey()
{
	string Ckey;
	ifstream CryptKey;
	CryptKey.open("CryptoKey.txt");

	if(CryptKey)
	{
		CryptKey >> Ckey;
	}
	else
	{
		cout << "\nError opening file!\n";
	}
	return Ckey;
}

/*************************************************************************************************/
//Purpose: Tell user they have enterted an invalid choice.
//Date: 02/26/2016
//Parameters: None
//Variables: None
/************************************************************************************************/
void invalid()
{
	cout << "You have entered an invalid choice.\n";
}
