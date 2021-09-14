//  
// Name: Shriya Nangia 
// Date: 04/23/2020
// Filename: hw6.cpp
// Description: A code that implements a story-creation program
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main()
{	
	string filename;   //declaring a string variable to hold the input file name 
	cout << "Welcome to the IEC story creation program!" << endl;
	cout << "Please enter the name of the file that contains the story template:" << endl;
	cin >> filename;   //input desired file name 
    cin.ignore();   // throw away remaining '\n'

	// open file
    ifstream fin(filename.c_str());
    if (fin.fail())
    {
        cerr << "Error opening " << filename << endl;
        return 1;
    }
    
    int numStrings;
    fin >> numStrings;  // read number of strings in file
    fin.ignore();   // throw away remaining '\n'

    
    const int maxStrings = 20;  //number of words/phrases will be an integer ranging from 1 to 20, thus maxStrings = 20
    string promptList[maxStrings];  //declaring array for the prompts 
    string keywordList[maxStrings]; //declaring array for the keywords 

    // read comma-separated list
    //successfully read  in and  store the prompts and template keywords from the input file into the respective arrays 
    for (int i = 0; i < numStrings; i++)
    {
        getline(fin,promptList[i],',');
        fin.ignore();
        getline(fin,keywordList[i]);
    }

    string storyTemplate;   //declaring storyTemplate array
    //read in and store the story template from input file into the storyTemplate array 
    getline(fin, storyTemplate);

    string pleaseEnter[2] = {"Please enter " , ": "};   //declaring a “Please enter” string
    string userInput[maxStrings];   //declaring array to store user inputs for the set of prompts 

    for (int i = 0; i < numStrings; i++)
    {	
    	//outputs to screen the phrase “Please enter” followed by the exact text of the prompt followed by a colon/space (“: ”) to indicate to the user what he/she should enter
        cout << pleaseEnter[0] << promptList[i] << pleaseEnter[1] << endl;
        // obtain user inputs for each prompt
    	getline(cin, userInput[i]);

    }

    for (int i = 0; i < numStrings; i++)
    {
    	while (storyTemplate.find(keywordList[i]) != string::npos)
    	{
            //performs finding of each single keyword till all of one keyword has been found 
    		size_t pos = storyTemplate.find(keywordList[i]);
            // perform replacement
    		storyTemplate.replace(pos, (keywordList[i]).size(), userInput[i]);
    	}
    	
    } 
    cout << storyTemplate << endl;  //output the modified story template 
    fin.close();    // close file
	return 0;
}




