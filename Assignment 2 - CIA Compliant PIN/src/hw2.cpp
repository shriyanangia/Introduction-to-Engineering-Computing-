//	
// Name: Shriya Nangia 
// Date: Feb 19 2020
// Filename:hw2.cpp
// Description: A program to check if the input PIN is CIA compliant 
//

#include<iostream>
#include<cmath>

using namespace std;

int main() {
	cout << "Enter PIN" << endl;
	int pin = 0;
	cin >> pin;

	int tempPin = 0;
	while (pin != -1){
		// to check that pin is a non-negative input
		int digitNegative; 
		tempPin = pin;
		while (pin < -1){
			cout << "Invalid input. Enter positive integers only." << endl;
			cin >> pin;
		}

		//is pin between 5-7 digits long 
		bool pinLength = false; 
		int count=0;
		pin = tempPin; 	//pin reinitialised to initial pin 
		while (pin>0){
			count += 1;
			pin = pin/10;
			// cout << count << endl;
		}
		if (count>=5 || count<=7){ 
			pinLength = true; 
		} 

		// does pin have same digit in 2 consecutive positions
		bool consecutiveDigits = false;
		int digit1 =0; 
		int digit2 =0;
		pin = tempPin; 
		while (pin>0){
			if (pin>10){
				digit1 = pin%10;
				digit2 = (pin%100)/10;
				if (digit1 == digit2){ 
					consecutiveDigits =  true; 
				}
			}
			pin = pin/10;
		}
	
		// is sum of last 4 digits a multiple of 3 
		int sumOfLastFour = 0;
		int lastDigit;
		bool isSumMultiple = false;
		int round = 0;
		pin = tempPin;
		while (pin>0){
			lastDigit = (pin%10);
			sumOfLastFour += lastDigit;
			round+=1;
			if (round==4){
				if (sumOfLastFour%3 == 0){
					isSumMultiple = true; 
				}
			}
			pin = pin/10;
		//cout<< lastDigit<<endl;
		}

		// n choose k
		int digitn = 0;
		int maxDigitn = 0;
		int digitk; 
		int leftMostEvenDigitk;
		pin = tempPin;
		while(pin>0){
			digitn = pin%10;
			if (digitn>maxDigitn){
				maxDigitn = digitn;
			}
			pin = pin/10;
		}
		leftMostEvenDigitk = digitn;
		//cout << leftMostEvenDigitk << endl;

		int numerator = 1;
		int denominator1 = 1;
		int denominator2 = 1; 

		pin = tempPin;
		for (int i=maxDigitn; i>=1; i--){
			numerator *= i;
		}
		//cout << numerator << endl;
		for (int j=leftMostEvenDigitk; j>=1; j--){
			denominator2 *= j;
		}
		//cout << denominator2 << endl;
		for (int h=(maxDigitn-leftMostEvenDigitk); h>=1; h--){
			denominator1 *= h;
		}
		//cout << denominator1 << endl;

		int nChooseK;
		nChooseK = numerator/(denominator1*denominator2);
		//cout << nChooseK << endl;
		bool factorial=false;
		if (nChooseK%2==0){
			factorial = true;
		}


	

	//if pin is compliant 
	if (pinLength==true && consecutiveDigits==false && isSumMultiple==true && factorial==true){
		cout << "PIN is CIA compliant" << endl;
	}
	//reasons why pin is not compliant 
	else if (pinLength==false){
		cout << "PIN is not CIA compliant. It is not between 5-7 digits in length." << endl;
	
	}
	else if (consecutiveDigits==true){
		cout << "PIN is not CIA compliant. It has the same digit in 2 consecutive positions." << endl;
		
	}
	else if (isSumMultiple == false){
		cout << "PIN is not CIA compliant. The sum of the last 4 digits is not a multiple of 3." << endl;
		
	}
	else if (factorial == false){
		cout << "PIN is not CIA compliant. Expression n choose k cannot be computed with given PIN." << endl;
	}

	cout << "Enter PIN" << endl;
	cin >> pin;

	}


	return 0;
}







