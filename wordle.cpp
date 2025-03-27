/**
 * Bonus Description
 * I added all three bonus challenges.
 * Bonus 1: I used ai to generate a file containing 100 words instead of an array
 * Bonus 2: I used a boolean array to set flags for indexes of letters that were used/not used
 * Bonus 3: Saves all streaks, and shows highest streak upon startup
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int WORD_LEN = 5;                                 // size for word length
const int MAX_ATTEMPTS = 5;                             // number of max attempts
int letterCount;                                        // number of correct letters in correct space
int streak;                                             // streak counter

const string GRN = "\033[32m";                          // green for correct letter
const string YLW = "\033[33m";                          // Yellow for correct letter in wrong position
const string RED = "\033[31m";                          // red for incorect letters
const string CLR = "\033[0m";                           // reset color

int getHighestInt(ifstream& file);                      // reads file and returns highest number
void generateWord(char word[]);                         // genrates a random number and reads respective line number from file
void getUserInput(char guess[]);                        // gets 5 letter word from user
bool isInSecret(char guess, char secret[]);             // checks if character is in character array
void compareWords(char guess[], char secret[]);         // compares guess to word in color coded output
void displayLetterBank(char guess[], bool inAlpha[]);   // displays unused words
void resetBank(bool inAlpha[]);                         // resets every index of boolean array to false
void playRound();                                       // simulates 1 game of wordle

int main(){
    ifstream fin;
    fin.open("streak.txt");
    if(fin.fail()){
        cout << "Failure to load streaks" << endl;
    }
    cout << "Welcome to worlde!" << endl << "Can you guess the correct word?" << endl;

    int highestStreak = getHighestInt(fin);
    if (highestStreak > 0){
        cout << "Highest Streak: " << highestStreak << endl;
    }
    fin.close();
    
    ofstream fout;
    fout.open("streak.txt", ios::app);

    if (fout.fail()){
        cout << "Error loading file. Streak will not be saved." << endl;
    }

    char choice = 'y';
    int roundCount = 0;
    while (choice == 'y' || choice == 'Y'){
        ++roundCount;
        cout << endl << "Round: " << roundCount << endl;
        cout << "********************************" << endl;
        playRound();
        cout << "Enter y to play again. Enter any other letter to quit." << endl;
        cin >> choice;
        cin.ignore();
    }
    if (streak > 0){
        fout << streak << endl;
    }
    fout.close();
    return 0;
}
int getHighestInt(ifstream& file){
    int highest = 0;
    int next;
    while (file >> next){
        if (next > highest){
            highest = next;
        }
    }
    return highest;
}
void generateWord(char word[]){
    srand(time(0));
    int randInt = (rand() % 100) + 1;
    ifstream fin;
    fin.open("words.txt");

    if (fin.fail()){
        cout << "Error opening file." << endl;
        exit(1);
    }

    for (int i = 0; i < randInt; i++){
        fin >> word;
    }

    cout << "line number " << randInt << endl;      // ADD COMMENT TO HIDE LINE NUMBER OF WORD IN FILE
    cout << "correct word " << word << endl;        // ADD COMMENT TO HIDE WORD 

    fin.close();
}

void getUserInput(char guess[]){
    cout << "Enter a 5 letter word." << endl;
    cin >> guess;

    while (strlen(guess) != WORD_LEN){
        cout << "Invalid input: guess must be exactly 5 characters" << endl;
        cout << "Enter a 5 letter word." << endl;
        cin >> guess;
    }

}

bool isInSecret(char guess, char secret[]){
    bool in = false;

    for (int i = 0; i < WORD_LEN; i++){
        if(toupper(guess) == toupper(secret[i])){
            in = true;
        } 

    }
    
    return in;
}

void compareWords(char guess[], char secret[]){
    letterCount = 0;

    for(int i = 0; i < WORD_LEN; i++){
        if (toupper(guess[i]) == toupper(secret[i])){
            cout << GRN << guess[i];
            ++letterCount;
        }
        else if (isInSecret(guess[i], secret)){
            cout << YLW << guess[i];
        }
        else {
            cout << RED << guess[i];
        }
    }
    
    cout << CLR << endl;
}

void displayLetterBank(char guess[], bool inAlpha[]){
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < strlen(alpha); i++){
        for (int j = 0; j < WORD_LEN; j++){
            if (tolower(guess[j]) == alpha[i]){
                inAlpha[i] = true;
            }
        }
    }
    
    cout << "Unused letters: ";
    for (int i = 0; i < strlen(alpha); i++){
        if(!inAlpha[i]){
            cout << alpha[i] << " ";
        }
    }
    cout << endl;

}

void resetBank(bool inAlpha[]){
    for (int i = 0; i < 26; i++){
        inAlpha[i] = false;
    }
}

void playRound(){
    bool gameWon = false;
    bool inAlpha[26];
    resetBank(inAlpha);
    int attempts = 0;
    char secret[WORD_LEN + 1];
    generateWord(secret);

    ofstream fout;
    fout.open("streak.txt", ios::app);
    if (fout.fail()){
        cout << "Error loading file. Streak will not be saved." << endl;
    }

    while((!gameWon) && (attempts < MAX_ATTEMPTS)){
        char guess[WORD_LEN + 1];
        getUserInput(guess);
        compareWords(guess, secret);
        displayLetterBank(guess, inAlpha);
        ++attempts;
        if (letterCount == WORD_LEN){
            gameWon = true;
        }
    }
    if (gameWon){
        ++streak;
        cout << GRN << "You win!" << CLR << endl;
        cout << streak << " game win streak!" << endl;
    }
    else {
        if (streak > 0){
            fout << streak << endl;
        }
        streak = 0;
        cout << RED << "yOu LoUsE..." << CLR << endl;
        cout << "Word was: " << secret << endl;
    }
    resetBank(inAlpha);
    fout.close();
}