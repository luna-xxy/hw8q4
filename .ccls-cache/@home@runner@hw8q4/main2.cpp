#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PIN[] = {1, 2, 3, 4, 5};
const int NUM_DIGITS = 10;
const int LEN_PIN = 5;

void printArray(int arr[], int arrSize);
int generateRandPin(int randDigits[]);
void generateRandDigits(int* randDigits);

int main() {

  cout << "Please enter your PIN according to the following mapping:\n";

  int digits[NUM_DIGITS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int randDigits[NUM_DIGITS];
  generateRandDigits(randDigits);
  
  cout << "PIN: ";
  printArray(digits, NUM_DIGITS);
  cout << "NUM: ";
  printArray(randDigits, NUM_DIGITS);

  // generate the expected rand pin
  int randPin = generateRandPin(randDigits);

  int inputRandPin;
  cin >> inputRandPin;

  if (inputRandPin == randPin)
    cout << "Your PIN is correct";
  else
    cout << "Your PIN is not correct";
  
  return 0;
}

void printArray(int arr[], int arrSize){
   for (int i = 0; i < arrSize; i++){
     cout << arr[i] << " ";
   }
  cout << endl;
}

void generateRandDigits(int* randDigits) {
  for (int i = 0; i < NUM_DIGITS; i++){
    randDigits[i] = 1 + (rand() % 3);
  }
}

int generateRandPin(int randDigits[]) {
  int randPin = 0;
  for (int i = 0; i < LEN_PIN; i++){
    randPin = randPin * 10 + randDigits[PIN[i]];
  }
  return randPin;
}

//need to break down into functions