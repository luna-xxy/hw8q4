#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PIN[] = {1, 2, 3, 4, 7};
const int NUM_DIGITS = 10;
const int LEN_PIN = 5;

void printArray(int arr[], int arrSize);
void generateRandDigits(int numRand[NUM_DIGITS]);
int generateRandPin(int numRand[]);

int main() {

  int secretPin;
  cout << "Please enter your PIN according to the following mapping:\n";

  int numInPIN[NUM_DIGITS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int numRand[NUM_DIGITS];
  
  generateRandDigits(numRand);

  cout << "PIN: ";
  printArray(numInPIN, NUM_DIGITS);
  cout << "NUM: ";
  printArray(numRand, NUM_DIGITS);

  cin >> secretPin;

  if (secretPin == generateRandPin(numRand))
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

void generateRandDigits(int numRand[NUM_DIGITS]){
    for (int i = 0; i < NUM_DIGITS; i++)
      numRand[i] = 1 + (rand() % 3);
}

// couple of feedback:
// 1. naming: arr1 and arr2 are not meaningful enough for this function, and made it hard to understand your code. Just use numInPIN and numRand. 
// 2. The nested for loop is completely unnecessary.
int generateRandPin(int numRand[]){
  int randPin = 0;
  for (int i = 0; i < LEN_PIN; i++){
      randPin = randPin*10 + numRand[PIN[i]];
  }
  return randPin;
}


//need to break down into functions