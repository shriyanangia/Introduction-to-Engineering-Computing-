//
// Name: Shriya Nangia 
// Date: Feb5, 2020
// Filename: friendshipCompatibility.cpp
// Description: A program that computes the user's friendship compatibility using the user's input to a series of 6 questions.
// 
// 
//


#include<iostream> 
#include<cmath>

using namespace std;

int main() {
	int totalScore = 0;		//used to store the total score of user 
	int favGenre;			// the user's favourite movie/book genre
	int pet;				// user's preference on owning a pet dog or pet cat
	int tvShow;				// user's opinion on the TV show "Friends" 
	int favCharacter;		// user's favourite character from the show "Friends" (only if he loves the show)
	int adventureTrip;		// if user enjoys going on adventure trips 
	int activity;			// the activity the user would want to try on an adventure trip (if he wants to go on an adventure trip)
	int sports;				// if user enjoys playing sports
	int favSport;			// user's favourite sport (if he enjoys sports) 
	int favBeverage;		// user's favourite non-alcoholic beverage 

	cout << "Hello! Embark on a journey to discover our friendship compatibility. For the questions below, enter the number corresponding to your answer choice." << endl;

	// Prompt user to enter their favourite book/movie genre
	cout << "What is your favourite genre of book or movie?  1.Thriller  2.Romantic Comedy  3.Horror  4.Non-fiction" << endl;
	cin >> favGenre; 
		if (favGenre == 1) {
			totalScore += 50 ;
		}
		else {
			totalScore += 20 ;		//calculate total score and store in totalScore
		}

	// Prompt user to choose between owning a pet dog or cat 	
	cout << "If you had to choose between the two, would you rather have a pet dog or a pet cat?  1.Dog  2.Cat" << endl;
	cin >> pet;
		if (pet == 1) {
			totalScore += 30 ; 
		}
		else {
			totalScore -= 10 ;		//calculate total score and store in totalScore
		}

	// Prompt user for opinion on tv show 'Friends'
	cout << "What do you think of the TV show 'Friends'?  1.Love it  2.It's alright  3.Can't stand it  4.Never watched it" << endl;
	cin >> tvShow;
		// If user loves the show, user will enter nested question
		if (tvShow == 1) {
			totalScore += 100 ; 
			// Prompt user for their favourite character from the show 
			cout << "Who is your favorite character on the show?  1.Chandler Bing  2.Phoebe Buffay  3.Monica Geller  4.Rachel Green  5.Joey Tribbiani  6.Ross Geller" << endl;
			cin >> favCharacter;
				if (favCharacter == 1) {
					totalScore += 50 ;
				}
				else{
					totalScore += 40 ;
				}
		}
		else if (tvShow == 2) {
			totalScore += 50 ;
		}
		else if (tvShow == 4) {
			totalScore -= 10 ;
		}
		else{
			totalScore -= 50 ;		//calculate total score and store in totalScore
		}

	// Prompt user for their opinion on going for adventure trips 	
	cout << "Do you like going on adventure trips/doing thrill seeking activities?  1.YES!  2.No" << endl;
	cin >> adventureTrip;
		// If user would like to go on an adventure trip, user enters nested question 
		if (adventureTrip == 1) {
			totalScore += 100 ;
			//Prompt user for the activity he would be most keen on trying 
			cout << "Which activity would you be most interested in trying?  1.Skydiving  2.Deep-Sea Diving  3.Mountain Hiking/Rock Climbing" << endl;
			cin >> activity;
				if (activity == 2) {
					totalScore += 30 ;
				}
				else{
					totalScore += 20 ;

				}
		}		
		else if (adventureTrip == 2) {
			totalScore -= 50 ;			//calculate total score and store in totalScore
		}

	// Prompt user to enter if he enjoys sports 
	cout << "Do you enjoy playing sports?  1.Yes  2.Nope" << endl;
	cin >> sports;
		//If user enjoys playing sports, user enters nested question
		if (sports == 1){
			totalScore += 50 ;
			// Prompt user for his favourite sport
			cout << "Which sport do you enjoy the most?  1.Football  2.Swimming  3.Ultimate Frisbee  4.Basketball  5.Others" << endl;
			cin >> favSport;
				if (favSport = 2||3) {
					totalScore += 50 ;
				}
				else{
					totalScore += 30 ;
				}
		}
		else if (sports == 2){
			totalScore -= 50 ;			//calculate total score and store in totalScore
		}

	// Prompt user for his favourite non-alcoholic beverage 
	cout << "What is your favourite non-alcoholic drink?  1.Soda  2.Juices/Coolers/Smoothies  3.Water  4.Tea/Coffee" << endl;
	cin >> favBeverage;	
		if (favBeverage == 2){
			totalScore += 50 ; 
		}
		else if (favBeverage == 4){
			totalScore += 40 ;
		}
		else if (favBeverage == 3){
			totalScore += 30 ;
		}
		else{
			totalScore -= 20 ;			//calculate total score and store in totalScore
		}
 
	cout << "Your score is " << totalScore << "!" << endl;
		if (totalScore >= 450){  
		cout << "Wow, you are PERFECTLY matched with me! ^_^ " << endl;
		}
		else if (totalScore >= 150){
		cout << "We’ll probably get along ok :) " << endl;
		}
		else{  
		cout << "You are not likely to become my friend :( " << endl;
		}

return 0;
}






