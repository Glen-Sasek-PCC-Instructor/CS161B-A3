//*****************************************************************************
// Author: 
// Assignment:
// Date:
// Description:
// Sources: 
//*****************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

void welcome();

void readScores(double scores[], int &count);

void readDouble(string prompt, double &num);

void calcGrades(double scores[], char grades[], int count);

void printList(double scores[], char grades[], int count);

void sort(double scores[], char grade[], int count);

double median(double scores[], int count); //(***new to this level***)

int main() {

    // Assume the arrays will always contain fewer than 20 values. You must not let the user enter more than 20 values.
    // Assuming max 20 values is intended.
    const int MAX_VALUES = 20; 
    int values_count = 0;

    double scores[MAX_VALUES];
    char grades[MAX_VALUES];

    welcome();

    cout << "Please enter the list of scores (-1 to end input:)" << endl;
    cout << "Valid scores are between 0 and 4 inclusive." << endl;

    readScores(scores, values_count);

    calcGrades(scores, grades, values_count);

    cout << endl;
    cout << "Your stats are as below:" << endl;
    cout << endl;
    cout << "The list of scores and their grades are:" << endl;

    printList(scores, grades, values_count);

    sort(scores, grades, values_count);

    cout << endl;
    cout << "The list sorted by scores in ascending order:" << endl;
    printList(scores, grades, values_count);
    
    cout << endl;
    cout << "The median score is " << setprecision(2) << median(scores, values_count) << endl;
}

void welcome() {
    cout << "Welcome to my Parallel Arrays program!" << endl;
}

// Reads a list of scores from the user. 
//      Use a while loop to do this.
//      A -1 indicates the end of the input and is not stored in the array. 
//
//      Call the readDouble function to do this. 
//
//      You must catch all invalid data such as characters, negative numbers other than -1 etc.
// 
//      The variable count keeps track of the number of scores entered.
// 
//      You must also do validation to make sure that the number is between 0 and 4 inclusive and nothing other than that. 
void readScores(double scores[], int &count) {
    double score = 0;
    const double END_SENTINEL = -1;
    while (score != END_SENTINEL) {
        readDouble(">> ", score);
        if(score == END_SENTINEL) {
            // noop
        } else if (score < 0  || score > 4.0) {
            cout << "Invalid score! Please try again!!" << endl;
            cout << "Valid scores are between 0 and 4 inclusive." << endl;
        } else {
            scores[count] = score;
            count++;
        }
    }
}


// This function should be used any time you read any floats or doubles from the user. 
// Use this function to read the numerical scores from the user.
// It takes a string prompt, outputs it, reads a number from the user, validates and returns the num by reference.
// Write it exactly like the readInt from assignment 1 but 
// declare a double or float instead of an int. See Samplea01.cpp for the readInt function.
void readDouble(string prompt, double &num) {
    do {
        if(!cin) {
            cin.clear();
            cin.get();
            cout << "ERROR ;( 0.0 to 4.0 required" << endl;
        }
        cout << prompt;
        cin >> num;
    } while(!cin);
}

// Use a loop to process each array element and calculate the letter grade for each score.
// Use the table below to assign grades A to F to the corresponding numerical score.

// A   >3.3  <= 4.0    Exceeds
// B   >2.7 <= 3.3     Meets
// C   >1.9 <= 2.7     Approaching
// D   >1.1 <= 1.9     Not Yet
// F   >0.0 <= 1.1     No Evidence
void calcGrades(double scores[], char grades[], int count) {
    for(int i =0; i < count; i++) {
        if(scores[i] >= 3.3) {
            grades[i] = 'A';
        } else if(scores[i] >= 2.7) {
            grades[i] = 'B';
        } else if(scores[i] >= 1.9) {
            grades[i] = 'C';
        } else if(scores[i] >= 1.1) {
            grades[i] = 'D';
        } else {
            grades[i] = 'F';
        }
    }
}

// Go through a for loop and print the scores and the corresponding grades for each item.
void printList(double scores[], char grades[], int count) {

    cout << fixed << setprecision(1);

    for(int i =0; i < count; i++) {
        cout << scores[i] << ' ' << grades[i] << endl;
    }
}

// Sort the arrays using the given sorting algorithm. This is called Selection Sort. 
// Use only this algorithm to sort your list. To see how the Selection Card Sort Algorithm works, watch this video from Virginia Tech.
// Be careful and make sure you sort based on the scores array and swap the corresponding element in 
// the grade array to maintain the correspondence between the two arrays. 
// Meaning if you swap the scores in index 0 and 5, you must also swap the corresponding grades in index 0 and 5.
// Watch this Python Video to help you with the sorting algorithm. Try this Selection Sort Animation by Y. Daniel Liang.

// procedure selection sort
//    list  : array of items
//    count : size of list
//    for i = 0 to count - 1
//    /* set current element as minimum*/
//   	min = i    
//   	/*go through the list and find the smallest element*/
//   	for j = i+1 to count
//      		if list[j] < list[min] then
//         		min = j;
//      		end if
//   	end for
//   	/* swap the minimum element with the current element
// If they are not the same element*/
//   	if min != i  then
//      		swap list[min] and list[i]
//   	end if
//    end for
// end procedure
void sort(double scores[], char grades[], int count) {
    int min = 0;
    for(int i = 0; i < count; i++) {
        min = i;

        for(int j = i+1; j < count; j++) {
            if(scores[j] < scores[min]) {
                min = j;
            }
        }

        if(min != i) {
            double d = scores[min];
            scores[min] = scores[i];
            scores[i] = d;

            char c = grades[min];
            grades[min] = grades[i];
            grades[i] = c;
        }
    }
}

// After sorting, write this function to identify the median score. 
// The median is located in the middle of the array if the array’s size is odd. 
// Otherwise, the median is the average of the middle two values. 
// Return the median to main() and output in main() with two decimal places.
double median(double scores[], int count) {
    if(count %2 == 0) {
       return  (scores[count/2] + scores[count/2 -1]) / 2;
    }

    return scores[count/2];
}