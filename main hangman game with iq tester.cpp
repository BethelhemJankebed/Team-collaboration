#include <iostream>// For input and output
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cctype>  // For isalpha()
using namespace std;
//This starts the main function where the program execution begins
int main() {
   // List of words and their corresponding hints
   const char* words[] = {"apple", "banana", "grape", "orange", "mango"};
   const char* hints[] = {
       "A fruit that keeps doctors away.",// Hint for "apple"
       "A long yellow fruit."// Hint for "banana"
       "A small, round, purple or green fruit."// Hint for "grape"
       "A fruit that is also a color."// Hint for "orange"
       "A tropical fruit that is sweet and juicy."// Hint for "mango"
   };
   const int wordCount = 5;// Total number of words in the list
// Seed the random number generator using the current time
   srand(static_cast<unsigned>(time(0)));
// Select a random word and its corresponding hint
   int randomIndex = rand() % wordCount;// Generate a random index
   const char* word = words[randomIndex];// Select the word
   const char* hint = hints[randomIndex];// Select the hint
   int wordLength = 0;//initializing word length

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
// Main game loop: continues until attempts are exhausted or the word is guessed
   while (attemptsLeft > 0) {
 // Display the hangman state based on the number of incorrect guesses
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
// Check if the word has been completely guessed
       bool wordGuessed = true;
       for (int i = 0; i < wordLength; i++) {
           if (!guessed[i]) {
               wordGuessed = false;
               break;
           }
       }
 // If the word is fully guessed, break out of the loop
       if (wordGuessed) break;
      
// Display the current state of the word
   
      cout << "\nAttempts left: " << attemptsLeft << endl;// Show remaining attempts
       cout << "Word: ";
       for (int i = 0; i < wordLength; i++) {
           if (guessed[i]) {// If the letter is guessed
               cout << word[i];
           } else {
               cout << "_";// Display an underscore for unguessed letters
           }
       }
       cout << endl;
// Prompt the player for their guess
       cout << "\nEnter your guess (or type 'hint' for a clue): ";
       string input;
       cin >> input;
// Handle the "hint" option
       if (input == "hint") {
           if (!hintUsed) {
               cout << "Hint: " << hint << endl;// Display the hint
               hintUsed = true;// Mark the hint as used
               attemptsLeft--;// Deduct an attempt for using the hint
               baseIQ -= iqPenaltyPerHint; // Deduct IQ points for using the hint
               cout << "(Using the hint cost you one attempt and " << iqPenaltyPerHint << " IQ points!)" << endl;
           } else {
               cout << "You have already used the hint for this word!" << endl;
           }
           continue;
       }
// Validate input: ensure it's a single alphabetic character
       if (input.length() != 1 || !isalpha(input[0])) {
           cout << "Invalid input! Please enter exactly one letter." << endl;
           continue;
       }
// Process the player's guess
       char guess = tolower(input[0]);// Convert to lowercase for consistency
       bool correctGuess = false;// Flag for correct guess
// Check if the guessed letter exists in the word
       for (int i = 0; i < wordLength; i++) {
           if (word[i] == guess) {
               guessed[i] = true;
               correctGuess = true;
           }
       }

       if (correctGuess) {
           cout << "Good guess!" << endl;// Inform the player of a correct guess
       } else {
           cout << "Wrong guess!" << endl;// Inform the player of a wrong guess
           attemptsLeft--;
           baseIQ -= iqPenaltyPerWrongGuess; // Deduct IQ points for wrong guess
       }
   }
// Display the final hangman state
   cout << "\nFinal Hangman State:\n";
   switch (initialAttempts - attemptsLeft) {
       case 6:
           cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n";
           break;
   }
// Check if the game was won or lost
   bool wordGuessed = true;// Reset wordGuessed flag
   for (int i = 0; i < wordLength; i++) {
       if (!guessed[i]) {// If any letter is not guessed
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

   return 0;// Exit the program
}



