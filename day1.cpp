#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//input for the day
int x[200];
int size = 0;

void getInput(){
    // Read today's input file
    ifstream file("input/day1.txt");

    // Open file and assign to int array
    if (file.is_open()) {
        string line;
        while(getline(file, line)){
            x[size] = (stoi(line));
            size++;
        }
    }
    file.close();
}

/*
 * Part One for the day
*/
int partOne() {
    int ret; // define return variable
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            
            // check all possible combos for product
            if(x[i] + x[j] == 2020){
                ret = x[i] * x[j];
            }
        }
    }
    return ret;
}

/*
 * Part Twp for the day
*/
int partTwo() {
    int ret;
    for(int i = 0; i <= size - 2; i++){
        for(int j = i+1; j <= size - 1; j++){
            for(int k = j+1; k <= size; k++){

                // Check all tri-products for output
                if(x[i] + x[j] + x[k] == 2020){
                    ret = x[i] * x[j] * x[k];
                }
            }
        }
    }
    return ret;
}

int main() {
    getInput();
    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo();
    return 0;
}