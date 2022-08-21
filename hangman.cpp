#include<iostream>
#include<cstdlib>
using namespace std;

void instructions();
void playGame();

int main() {
    cout << "Welcome to hangman!" <<endl;
    while (1) {
        cout << endl <<"Menu: 1. Play 2. Instructions 3. Exit" <<endl;
        int choice;
        cin >> choice;
        switch (choice){
            case 1:
                playGame();
                break;
            case 2:
                instructions();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice" <<endl;
                break;
        }
    }

}

void instructions(){
    cout << "**Instructions:**" <<endl;
    cout << "You have 5 chances to guess the complete word" << endl;
    cout << "If you guess the word, you win" << endl;
    cout << "If you didn't guess the word, you lose" << endl;
    cout << "If you guess the wrong letter, you lose one chance" << endl;
    cout << "You can enter only alphabetical characters" << endl;
    cout << "It is just a simple game, Don't take it seriously" << endl;
    cout << "Save the Hangman!!!!" << endl;
    cout << "**Enjoy!**" << endl;
}

void playGame(){
    int turns = 5;
    string guesses = "";
    cout << "*******Lets Begin*******" <<endl;
    string arr[] = {"which", "there", "their", "about", "would", "these", "other", "words", "could", "write", "first", "water", "after", "where", "right", "think", "three", "years", "place", "sound", "great", "again", "still",};
    
    srand(time(0));
    int random = rand() % 20;
    string word = arr[random];
    string hidden = "";
    for (int i = 0; i < word.length(); i++) {
        hidden += "_";
    }
    cout << hidden << endl;
    while (turns > 0) {
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        if (guesses.find(guess) != string::npos) {
            cout << "You already guessed that letter" << endl;
            continue;
        }
        guesses += guess;
        if (word.find(guess) != string::npos) {
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == guess) {
                    hidden[i] = guess;
                }
            }
            cout << hidden << endl;
            if (hidden == word) {
                cout << "You win!" << endl;
                return;
            }
        } else {
            turns--;
            cout << "Wrong guess" << endl;
            cout << "You have " << turns << " turns left" << endl;
        }
        if (turns == 0) {
            cout << "You lose" << endl;
            cout << "The word was " << word << endl;
            return;
        }
    }
}