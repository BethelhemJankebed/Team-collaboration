#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cctype>  // For isalpha()
using namespace std;

int main() {
   const char* words[] = {"apple", "banana", "grape", "orange", "mango"};
   const char* hints[] = {
       "A fruit that keeps doctors away.",
       "A long yellow fruit.",
       "A small, round, purple or green fruit.",
       "A fruit that is also a color.",
       "A tropical fruit that is sweet and juicy."
   };
   const int wordCount = 5;

   srand(static_cast<unsigned>(time(0)));
   int randomIndex = rand() % wordCount;
   const char* word = words[randomIndex];
   const char* hint = hints[randomIndex];
   int wordLength = 0;

   for (wordLength = 0; word[wordLength] != '\0'; wordLength++) {}

   bool guessed[wordLength] = {false};
   int initialAttempts = 6;
   int attemptsLeft = initialAttempts;
   bool hintUsed = false;

   int baseIQ = 100; // Start with a base IQ score
   int iqPenaltyPerHint = 10; // Deduct points for using a hint
   int iqPenaltyPerWrongGuess = 5; // Deduct points for each wrong guess
   int iqBonusForWinning = 20; // Bonus for guessing the word

   cout << "Welcome to Hangman with IQ Scoring!\n";

   while (attemptsLeft > 0) {
       cout << "\nCurrent Hangman State:\n";
       switch (initialAttempts - attemptsLeft) {
           case 0:
               cout << "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n";
               break;
           case 1:
               cout << "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n";
               break;
           case 2:
               cout << "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n";
               break;
           case 3:
               cout << "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n";
               break;
           case 4:
               cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n";
               break;
           case 5:
               cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n";
               break;
           case 6:
               cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n";
               break;
       }

       bool wordGuessed = true;
       for (int i = 0; i < wordLength; i++) {
           if (!guessed[i]) {
               wordGuessed = false;
               break;
           }
       }
       if (wordGuessed) break;

       cout << "\nAttempts left: " << attemptsLeft << endl;
       cout << "Word: ";
       for (int i = 0; i < wordLength; i++) {
           if (guessed[i]) {
               cout << word[i];
           } else {
               cout << "_";
           }
       }
       cout << endl;

       cout << "\nEnter your guess (or type 'hint' for a clue): ";
       string input;
       cin >> input;

       if (input == "hint") {
           if (!hintUsed) {
               cout << "Hint: " << hint << endl;
               hintUsed = true;
               attemptsLeft--;
               baseIQ -= iqPenaltyPerHint; // Deduct IQ points for using the hint
               cout << "(Using the hint cost you one attempt and " << iqPenaltyPerHint << " IQ points!)" << endl;
           } else {
               cout << "You have already used the hint for this word!" << endl;
           }
           continue;
       }

       if (input.length() != 1 || !isalpha(input[0])) {
           cout << "Invalid input! Please enter exactly one letter." << endl;
           continue;
       }

       char guess = tolower(input[0]);
       bool correctGuess = false;

       for (int i = 0; i < wordLength; i++) {
           if (word[i] == guess) {
               guessed[i] = true;
               correctGuess = true;
           }
       }

       if (correctGuess) {
           cout << "Good guess!" << endl;
       } else {
           cout << "Wrong guess!" << endl;
           attemptsLeft--;
           baseIQ -= iqPenaltyPerWrongGuess; // Deduct IQ points for wrong guess
       }
   }

   cout << "\nFinal Hangman State:\n";
   switch (initialAttempts - attemptsLeft) {
       case 6:
           cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n";
           break;
   }

   bool wordGuessed = true;
   for (int i = 0; i < wordLength; i++) {
       if (!guessed[i]) {
           wordGuessed = false;
           break;
       }
   }

   if (wordGuessed) {
       cout << "\nCongratulations! You've guessed the word: " << word << endl;
       baseIQ += iqBonusForWinning; // Bonus for winning the game
   } else {
       cout << "\nSorry, you're out of attempts. The word was: " << word << endl;
   }

   cout << "\nYour IQ Score: " << baseIQ << endl;

   return 0;
}



