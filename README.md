# Team-collaboration
# Hangman Game with IQ Scoring

This is an interactive **Hangman** game implemented in C++ with an added feature of IQ scoring. The game randomly selects a word from a predefined list of fruits, and you need to guess the letters in the word within a limited number of attempts. For each wrong guess, your IQ score decreases, and if you use a hint, you lose more IQ points. If you guess the word correctly, you gain IQ points!

Features

- **Word Selection**: The game randomly selects a word from a list of five fruits: Apple, Banana, Grape, Orange, and Mango.
- **Hangman Drawing**: The game displays the typical Hangman drawing as you make incorrect guesses, progressing through stages.
- **IQ Scoring**: Your IQ score starts at 100 and decreases with every wrong guess and for using a hint. You earn IQ points if you guess the word correctly.
- **Hint Mechanism**: Players can request a hint, which will reveal a clue about the word. Using a hint will cost you one attempt and reduce your IQ score.
- **Game Over Conditions**: The game ends when you either guess the word correctly or run out of attempts.
  
## How to Play

1. The game will randomly choose a fruit word.
2. You will have 6 attempts to guess the word correctly.
3. You can type a letter to guess, or type `hint` to get a clue.
4. Your IQ score will be displayed, and it will decrease for wrong guesses and using hints.
5. If you guess the word correctly, you'll receive an IQ bonus.
6. The game ends when you've either guessed the word or used all attempts.

## IQ Scoring System

- **Base IQ**: 100
- **IQ Deduction for Wrong Guess**: -5 points per wrong guess.
- **IQ Deduction for Using a Hint**: -10 points per hint.
- **IQ Bonus for Winning**: +20 points for correctly guessing the word.

## Requirements

- C++ compiler (e.g., g++)

## How to Run

1. Clone the repository to your local machine.
2. Compile the program with a C++ compiler:
   ```bash
   g++ hangman.cpp -o hangman
   ```
3. Run the game:
   ```bash
   ./hangman
   ```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

