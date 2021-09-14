//
// Name: Shriya Nangia
// Date: March3 2020
// Filename: hw3.cpp
// Description: A program that reads braille code from a file and writes it to another file in standard English. 
//              It then opens the standard English file and converts it back into binary Braille, writing that into a new file.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	// declare and open input and output files
	ifstream braillefileIN("HW3_Braille.txt");
    ifstream alphabetfileIN("binary_Braille_conv.txt");
	ofstream braillefileOUT("message.txt");
 
    // checking if the files were able to be opened 
	if ( braillefileIN.fail() )
    {
        cout << "File HW3_Braille.txt could not be opened." << endl;
        return -1;
    }
    if ( alphabetfileIN.fail() )
    {
        cout << "File binary_Braille_conv.txt could not be opened." << endl;
        return -1;
    }

	if ( braillefileOUT.fail() )
    {
        cout << "File message.txt could not be opened." << endl;
        return -1;
    }

    int num;    // Declaring variable to be an integer since numbers in HW3_Braille.txt are integers 
    int fixedNum;   //declaring variable to be an integer, since first element in alphabetfileIN is an integer
    char alphabet;  //declaring variable to be a character, since second element in alphabetfileIN is a character
    braillefileIN >> num;   //reading the number from braillefileIN 
    while (!braillefileIN.eof())    //While end-of-file is not reached. Entering while loop
    {
        if (num==999999)    //Checks when a space is encountered in braillefileIN. Each space equals a fixed number,999999.
        {
            cout << " ";    //writes " " to the console 
            braillefileOUT << " ";  //writes " " to the file, braillefileOUT
        }

        for (int h=1; h <= 26; h++) //entering for loop 
        {
            alphabetfileIN >> fixedNum >> alphabet; //reading the given fixed number followed by alphabet it stands for from alphabetfileIN
            if (num == fixedNum)    //checks for a match between the numbers in braillefileIN and fixed numbers in alphabetfileIN 
            { 
                cout << alphabet;   //writes alphabet corresponding to matching number to console  
                braillefileOUT << alphabet; //writes alphabet corresponding to matching number to file,braillefileOUT
            }
        }   //exit for loop 

        alphabetfileIN.seekg(0, ios::beg); //rewinds to begining of alphabetfileIN 
        braillefileIN >> num;   //reads next number in braillefileIN 
    }   //exit while loop 

    //closing all open files 
    braillefileIN.close();
    alphabetfileIN.close();
    braillefileOUT.close();

    //part2

    // declare and open input and output files
    ifstream messagefileIN("message.txt");
    alphabetfileIN.open("binary_Braille_conv.txt");
    ofstream messagefileOUT("message2.txt");

    // checking if the files were able to be opened
    if (messagefileIN.fail()){
        cout << "File message.txt could not be opened." << endl;
        return -1;
    }
    if (alphabetfileIN.fail()){
        cout << "File binary_Braille_conv.txt could not be opened." << endl;
        return -1;
    }
    if (messagefileOUT.fail()){
        cout << "File message2.txt could not be opened." << endl;
        return -1;
    }

    char letter;    // Declaring variable to be a character since elements in "message.txt" are letters
    char space = ' ';   // Declaring variable to be a character since a whitespace is considered a character 
    while(!messagefileIN.eof()) //while end-of-file is not reached, entering while loop 
    {
        if (letter == space)    //Checks when a space is encountered in messagefileIN
        {
            cout << 999999 << " ";  //since each space equals a fixed number,999999 we write 999999 to the console 
            messagefileOUT << 999999 << " ";    //writing 999999 to the file, messagefileOUT 
        }

        for (int j=1; j <= 26; j++) //entering for loop 
        {
            alphabetfileIN >> fixedNum >> alphabet; 
            if (alphabet == letter) //checks for a match between the letters in messagefileIN and fixed alphabets in alphabetfileIN 
            {
                cout << setw(6) << setfill('0');    //to ensure the 0 in 6 digit numbers begining with 0, is written to the console
                cout << fixedNum << " ";    //writes the fixed number corresponding to the matching letter to console      
                messagefileOUT << setw(6) << setfill('0');  //to ensure the 0 in 6 digit numbers begining with 0, is written to messagefileOUT
                messagefileOUT << fixedNum << " ";  //writes the fixed number corresponding to the matching letter to messagefileOUT
            }   
        }   //exiting for loop 

        alphabetfileIN.seekg(0, ios::beg);  //rewinds to begining of alphabetfileIN
        messagefileIN.get(letter);  //reads next letter in messagefileIN 
    }   //exiting while loop 

    //closing all open files 
    messagefileIN.close();
    alphabetfileIN.close();
    messagefileOUT.close();

    return 0;
} 