//  
// Name: Shriya Nangia 
// Date: 04/13/2020
// Filename: hw5.cpp
// Description: A program that simulates a shopping cart for College of Engineering hat sales
//

#include <iostream>
#include <fstream>

using namespace std;
//function prototypes 
void printArray(int array[], int len);
void inventoryUpdate(int array1[], int array2[], int len);

int main()
{
	int continueShopping = 0;	//declaring variable that allows user to place 2 or more oders after checking out 
	int userInput = 0;	//declaring variable that hold the user's choice of options (between 1-6) within a single order 
	int purchaseDesignNum = 0;	//declaring variable that holds the design number within the option of adding a design to shopping cart  
	int quantityOfDesign;	//declaring variable that holds the number of hats of a specific design within the option of adding a design to shopping cart
	int removeItem;	//declaring variable that holds the design number within the option of removing a design from shopping cart
	int numOfRemoveItem;	//declaring variable that holds the number of hats of a specific design within the option of removing a design from shopping cart
	int totalPrice = 0;	//keeps track of the toal cost of hats in shopping cart 
	const int SIZE = 12;	//declaring size of array as 12 as there are only 12 available hat designs
	// declare and open input file
	string inputFile = "coeHatDesigns.txt";
	ifstream fin(inputFile.c_str());
	// checking if the files were able to be opened 
	if (fin.fail())
    {
        cerr << "File " << inputFile << " could not be opened." << endl;
        return false;
    }

	int inventory[SIZE];	//declaring an inventory array to store the on-hand quantities for the hat designs,
    int cost[SIZE];	//declaring a cost array to store the prices of hats
    int cart[SIZE];	//declaring a cart array to keep track of the  user’s shopping cart

	for (int i=0; i<SIZE; i++) //entering for loop to ensure all integers in given file are read 
    {
        fin >> inventory[i] >> cost[i];	//reading in from file the given initial hat numbers of each design into the inventary array and their respective costs into the cost array
        
        // checking for error case 
        if (!fin)
        {
            cerr << "Error reading from file." << endl;
            return false;
        }
    }
    
    cout << "Welcome to the College of Engineering hat sale!" << endl;
    while (continueShopping != 2)	//entering while loop 
    {
    	while (userInput != 6)	//ensuring all user inputs excluding 6 are validated 
    	{
    		cout << "What would you like to do?" << endl;
    		cout << "(1) Print the current hat quantity available\n(2) Select available hat design for purchase\n(3) Remove selected design from purchase\n(4) Print shopping cart\n(5) Checkout\n(6) Quit" << endl;	//presenting the 6 options within each order
    		cin >> userInput;	//user option input 

	    	if (userInput==1) //when option 1 is selected by user 
	    	{
	    		cout << "Current hat availability and their respective prices:" << endl;
	    		for (int i=0; i<SIZE; i++)	//prints the current quantity available and price for each of the 12 designs 
	    		{
	    			cout << "Number of design " << (i+1) << "s available: " << inventory[i] << " Price of each hat: " << cost[i] << endl; 
	    		}
	    	}
	    	else if (userInput==2)	//when option 2 is selected by user 
	    	{
    			
				cout << "Which design would u like to purchase. Enter a design number between 1-12." << endl;
				cin >> purchaseDesignNum;	//holds the design number from which the user wants hats added to the shopping cart 
				if ((purchaseDesignNum>=1) and (purchaseDesignNum<=12))	//if design number entered is between 1-12
				{
					cout << "What quantity of selected design would you like to purchase?" << endl; 
					cin >> quantityOfDesign;	//hold the quantity of hats the user wants added to the cart from the above entered design number 
					if (quantityOfDesign<=0)	//ensures order quantities are always greater than 0
					{
						cout << "Error: Order quantity must be greater than 0." << endl;
					}
					else
					{
						while (quantityOfDesign > 0)
    					{
    						if (cart[purchaseDesignNum-1]+quantityOfDesign>inventory[purchaseDesignNum-1])	//ensures availability of number of hats desired by user for above entered hat design 
    						{
    							cout << "Error: Hats available are fewer than entered quantity. Enter a different quantity." << endl;
    							cin >> quantityOfDesign;
    						}
    						else
    						{
    							cart[purchaseDesignNum-1] += quantityOfDesign;	//quantity for item will be updated by adding new quantity to previous quantity for above enterd hat design   
    							totalPrice += (quantityOfDesign * cost[purchaseDesignNum-1]);	//updates the total cost of all hats after specified hats have been added to cart  
    							break;
    						}
    					}
					}	
				}			
				else	//validates user input for numbers not falling between 1-12 
				{
					cout << "Error: Design number entered must be between 1-12" << endl;
				}
    		}
	    	else if (userInput==3)	//allows user to remove selected design from shopping cart  
	    	{
	    		cout << "Items from which design would you like to remove from the shopping cart? Enter a design number between 1-12." << endl; 
	    		cin >> removeItem;	//holds the design number for which the user wants hats remmoved 
	    		if ((removeItem>=1) and (removeItem<=12))	//if design number entered is between 1-12 
	    		{
		    		cout << "How many hats of selected design would you like to remove?" << endl;
		    		cin >> numOfRemoveItem;	//holds the quantity of hats the user wants removed from the above entered design number
		    		while (numOfRemoveItem>=0)
		    		{
		    			if (cart[removeItem-1]<numOfRemoveItem)	//prevents user from removing more hats than the number currently present in the cart for each design
		    			{
		    				cout << "Error: Hats available in cart are fewer than entered quantity. Enter a different quantity" << endl;
		    				cin >> numOfRemoveItem;
		    			}
		    			else
		    			{
		    				cart[removeItem-1] -= numOfRemoveItem;	//updates the cart for the number of hats left of a specific design, after taking into account the number of hats removed 
		    				totalPrice -= (numOfRemoveItem*cost[removeItem-1]);	//updates the total cost of all hats after specified hats have been removed 
		    				break;
		    			}
		    		}
		    		
		    	}
		    	else	//validates user input for design numbers not between 1-12
		    	{
		    		cout << "Error: Design number entered must be between 1-12" << endl;
		    	}
	    		
	    	}
	    	else if (userInput==4)	//when option 4 is selected by user 
	    	{
	    		cout << "Current items in shopping cart: " << endl; 
	    		for (int i = 0; i<SIZE; i++)	//for loop transverses array to print the shopping cart 
	    		{
	    			cout << "Design " << i+1 << ": " << cart[i] << endl;	//displays current quantities for shopping cart 
	    		}

	    		cout << "Total amount: " << totalPrice << endl;	//displays the total amount due by user for all items in shopping cart  
	    	}
	    	else if (userInput==5)	//when option 5 is selected by user 
	    	{
	    		cout << "Shopping cart: " << endl;
	    		for (int i = 0; i<SIZE; i++)	//for loop transverses array to print the shopping cart  
	    		{
	    			cout << "Design " << i+1 << ": " << cart[i] << endl;
	    		}
	    		cout << "Total amount: " << totalPrice << endl;	//prints the total amount the user needs to pay in checkout 	
	    		inventoryUpdate(inventory,cart, 12);	//updates inventory list to reflect the quantity of hats remaining for each design after current purchase
	    		//printArray(inventory,12);	
	    		memset(cart, 0, sizeof(cart));	//resets the shopping cart 
	    		totalPrice = 0;
	    		cout << "Would you like to place another order? \n (1) Yes \n (2) No" << endl;
	    		cin >> continueShopping;	
	    		if (continueShopping==2)	//if user does not want to place another order (setting continueShopping to 2 allows program to break out of outer while loop)
	    		{
	    			cout << "Thank you for shopping with us! Have a good day" << endl;
	    			break;	//break out of inner while loop 
	    		}
	    	}
	    	else	//directs user to enter an option number between 1-6, validating all other user inputs excluding those between 1-6  
	    	{	
	   			cout << "Please enter a number input from 1-6" << endl;
	   		}

	    }
    	if (userInput==6)	//validating the user input of 6 
    	{
    		cout << "Thank you for shopping with us! Have a good day" << endl;
    		continueShopping = 1;	//ensures program will terminate (will not renter while loop)
    		break;	//break out of outer while loop 
    	}

    }

	return 0;	
}

//Definition of function printArray 
//Function prints an array taking 2 parameters - the array and its size 
void printArray(int array[], int len)
{ 
    for (int i = 0; i<len; i++)
    {
        cout << array[i] << endl;
    } 

}

//Definition of function inventoryUpdate
//Function updates the existing inventory array after subtracting hats that have already been bought
void inventoryUpdate(int array1[], int array2[], int len)
{
	for (int i = 0; i<len; i++)
	{
		array1[i] = array1[i] - array2[i];
	}

}





