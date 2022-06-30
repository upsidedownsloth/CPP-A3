/* CIT235777 
Jitampa Phongphaew
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
// Add the preprocessor required for file handling.

const int MAXREVIEWS = 12;
const int MAXMOVIES = 42;


class Movie {
	std::string movieName;
	std::string dirFirstName;
	std::string dirLastName;
	std::string genre;
public:
	int yearOfRelease;
	// You will have to write the function definitions for these functions.
	void setMN(std::string);
	void setFN(std::string);
	void setLN(std::string);
	void setG(std::string);
	void setYear(int);
	std::string getMN() { return movieName; };
	std::string getFN() { return dirFirstName; };
	std::string getLN() { return dirLastName; };
	std::string getG() { return genre; };
	int getYear() { return yearOfRelease; };
	Movie();
	~Movie() {};
};

class Review : public Movie {
public:
	int ticketsSold;
	std::string classification;
	void setClass(string);
	void setTickSold(int);
	string getClass() { return classification; }
	double reviewsArr[MAXREVIEWS];
	// You will need to write the function definition for these functions
	double calcAvg();
	double totalTicSold();
	Review();
	~Review() {};
};

// Function Prototypes
// You can modify the parameters of these functions.
void outputScreen(Review*);  // Used to created required console output
void outputFile(Review*); // Used to create required textfile output.

int main() {
	Review MovObj[MAXMOVIES];
	int tempYear, tempTicSold;
	string tempMN, tempG, tempFirst, tempLast, tempClass;
	/*
		Add any additional parameters you might require here.
		Open the Movie_2021v2.txt file.
		Exit the program elegantly, if file not found.
	*/
	//year of release, movie name, number of tickets sold, movie classification, 
	//Directors’ first name, Directors’ last name, movie genre and then 12 reviews.
	ifstream inFile("movies_V2.txt");
	if (!inFile) {
		cout << "Cannot open file.";
		return 0;
	}
	for (int i = 0; i < MAXMOVIES; i++) {
		inFile >> tempYear >> tempMN >> tempTicSold >> tempClass >> tempFirst >> tempLast >> tempG;
		MovObj[i].setYear(tempYear);
		MovObj[i].setMN(tempMN);
		MovObj[i].setTickSold(tempTicSold);
		MovObj[i].setClass(tempClass);
		MovObj[i].setFN(tempFirst);
		MovObj[i].setLN(tempLast);
		MovObj[i].setG(tempG);
		for (int j = 0; j < MAXREVIEWS; j++) {
			inFile >> MovObj[i].reviewsArr[j];
		}
	}
	// Input data from the file into my array of objects: MovObj
	

	// Output to the screen
	outputScreen(MovObj);

	// Output to the text file
	outputFile(MovObj);

	// Don't forget to close your file.
	inFile.close();
	return 0;
}
// Function Definitions of all Movie class members
// You will need to add your other Class function definitions here.
Movie::Movie() {
	// must initialise all Movie attributes.
	movieName = "\0";
	dirFirstName = "\0";
	dirLastName = "\0";
	genre = "\0";
	yearOfRelease = 0;
}

void Movie::setMN(string inMN) {
	movieName = inMN;
}
void Movie::setFN(string inFirst) {
	dirFirstName = inFirst;
}
void Movie::setLN(string inLast) {
	dirLastName = inLast;
}
void Movie::setG(string inGenre) {
	genre = inGenre;
}
void Movie::setYear(int inYear) {
	yearOfRelease = inYear;
}



// Function Definitions of all Review class members
// You will need to add your other Review function definitions here.
Review::Review() {
	// must initialise all Review attributes.
	// Hint.  Use a loop for the array.
	ticketsSold = 0;
	classification = "\0";
	for (int i = 0; i < MAXREVIEWS; i++) {
		reviewsArr[i] = 0;
	}
}

void Review::setClass(string inClass) {
	classification = inClass;
}

void Review::setTickSold(int inTic) {
	ticketsSold = inTic;
}

double Review::totalTicSold() {
	return ticketsSold * 17.50;
}

double Review::calcAvg() {
	// Write the code to calculate the average of the values in the
	// reviewsArr array.
	// Hint.  Create a temp variable to store and add all
	// the variables in the array.  Use a loop.
	// Don't forget to divide by the number of elements in the array.
	double average{};
	for (int i = 0; i < MAXREVIEWS; i++) {
		average += reviewsArr[i];
	}
	average /= MAXREVIEWS;

	return average;
}
// Functions that aren't specifically part of a class
void outputScreen(Review* ObjRev) {

	/*
	  You will need to create a menu that asks what genre the client would like to see the movies for.
	  The options are Action, Adventure, Animation, Comedy, Drama, Horror, Romance, Thriller and Sci-fi.
	  The user should be able to enter q, to quit without it outputting anything.
	  Any other value is wrong, and you should exit.

	  Output the values to the console.
	*/
	int genreSelected{};
	string tempGenre, tempName;
	bool found{ false };
	cout << "Select a Genre from the following menu:\n";
	cout << "[1] Action \n" << "[2] Adventure \n" << "[3] Animation \n" << "[4] Comedy\n" << "[5] Drama\n" << "[6] Horror\n" << "[7] Romance \n" << "[8] Thriller\n" << "[9] Sci-fi\n\n" << "Press [q] to quit. ";
	cin >> genreSelected;
	switch (genreSelected)
	{
	case 1:
		tempGenre = "Action";
		break;
	case 2:
		tempGenre = "Adventure";
		break;
	case 3:
		tempGenre = "Animation";
		break;
	case 4:
		tempGenre = "Comedy";
		break;
	case 5:
		tempGenre = "Drama";
		break;
	case 6:
		tempGenre = "Horror";
		break;
	case 7:
		tempGenre = "Romance";
		break;
	case 8:
		tempGenre = "Thriller";
		break;
	case 9:
		tempGenre = "Sci-fi";
		break;
	default:
		break;
	}

	for (int i = 0; i < MAXMOVIES; i++) {
		if (ObjRev[i].getG() == tempGenre) {
			found = true;
		}
	}
	if (found) {
		cout << setfill('*') << setw(100) << "\n";
		cout << setfill(' ');
		cout << left << setw(30) << "Movie Name" << setw(25) << "Directed by" << setw(10) << "Rating: " << "Ticket Sales: \n";
		cout << setfill('*') << setw(100) << "\n";
		cout << setfill(' ') << "\n";
		for (int i = 0; i < MAXMOVIES; i++) {
			if (ObjRev[i].getG() == tempGenre) {
				tempName = ObjRev[i].getFN() + " " + ObjRev[i].getLN();
				cout << left << setw(30) << ObjRev[i].getMN() << setw(25) << tempName << setw(10) << ObjRev[i].getClass() << fixed << setprecision(2) << "$" << ObjRev[i].totalTicSold() << "\n";
			}
		}
	}
	else {
		cout << "Genre not found";
	}
}
void outputFile(Review* ObjRev) {
	/*
		Open your output.txt file and output the required values.
		You will need to call to your calcAvg() here.
		Don't forget to close your file.
	*/
	ofstream outFile("output.txt");
	if (!outFile) {
		cout << "Cannot create file";
	}
	outFile << left << setw(35) << "Movie: " << "Average Review: \n";
	
	for (int i = 0; i < MAXMOVIES; i++) {
		outFile << left << setw(35) << ObjRev[i].getMN() << ": " <<fixed << setprecision(1) <<  ObjRev[i].calcAvg() << "\n";
	}

	outFile.close();
}