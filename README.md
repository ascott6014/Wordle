**Wordle-Inspired C++ Assignment**
==================================

**Objective**
-------------

Your task is to create a **word-guessing game** similar to Wordle. The player will have **five attempts** to guess a randomly selected **five-letter word**. After each guess, the game will provide **color-coded feedback** to help the player figure out the correct word.

* * *

**Game Rules**
--------------

1.  The game will choose a **secret five-letter word**.
2.  The player will **input a five-letter guess**.
3.  The game will provide **color-coded feedback**:
    *   **Green** = Correct letter in the correct position.
    *   **Yellow** = Correct letter, but in the wrong position.
    *   **Red** = Letter is not in the word at all.
4.  The player has **five attempts** to guess the correct word.
5.  If the player guesses correctly, they win.
6.  If they run out of attempts, they lose.

* * *

**Requirements**
----------------

*   Store the **secret word** and the **user’s guess** as **C-strings** (`char arrays`), not `std::string`.
*   Display **color-coded feedback** using **ANSI escape codes** (provided below).
*   Use a **loop** to allow the user multiple attempts.
*   Implement a function to **check if a letter exists in the word**, using the provided function signature.

* * *

**Provided Code**
-----------------

Use the following constants to **color the letters** when displaying results. These strings are called **ANSI Color Codes** they will change the color of your output text for example `"\033[31m"` will make the text red and the code `\033[0m"` will reset the color back to the default. I’ve provided some color constants that you can use instead of remembering the codes.

    const std::string GRN = "\033[32m";  // Green for correct letter in correct position
    const std::string YLW = "\033[33m";  // Yellow for correct letter in wrong position
    const std::string RED = "\033[31m";  // Red for incorrect letters
    const std::string CLR = "\033[0m";   // Reset color
    

They can be use like this:

    std::cout << GRN << "This text will be green\n" << CLR;
    std::cout << RED << "This text will be red\n" << CLR;
    
    int x;
    std::cout << "Enter a number between 1-10 (inclusive): ";
    std::cin >> x;
    
    while (x < 1 || x > 10) {
        // in this code the text "Error:" will be red but the rest will be the default
    	std::cout << RED << "Error:" << CLR << " the number must be between 1-10";
    	
    	std::cout << "Enter a number between 1-10 (inclusive): ";
    	std::cin >> x;
    } 
    

You **must also implement** the following function:

    bool isInSecret(char guess, char secret[]);
    

### **What This Function Should Do:**

*   Check if a **given letter (`guess`)** exists **anywhere** in the **secret word (`secret`)**.
*   Ignore case differences (e.g., `'a'` and `'A'` should be treated the same).
*   Return `true` if the letter is in the word, `false` if it is not.
*   use this in part 3 below. This function is how you’ll determine if a letter should be yellow

Use the following starter code:

    const int WORD_LEN = 5; // use this constant size for word length
    
    const std::string GRN = "\033[32m";  // Green for correct letter in correct position
    const std::string YLW = "\033[33m";  // Yellow for correct letter in wrong position
    const std::string RED = "\033[31m";  // Red for incorrect letters
    const std::string CLR = "\033[0m";   // Reset color
    
    bool isInSecret(char guess, char secret[]);
    
    int main () {
    
    	return 0;
    }
    

* * *

**Instructions**
----------------

### **1\. Store the Secret Word**

*   You will need to **store the secret word** using a **C-string** (`char array`).
*   The secret word must be **exactly five letters** long.
*   Remember to **terminate the C-string properly**.

### **2\. Get User Input**

*   The user will enter a **five-letter guess**.
*   You must store this guess in a **C-string (`char array`)**, ensuring it is exactly five letters.
*   Use `cin.getline()` to **safely read input**.

### **3\. Compare Guess with the Secret Word**

*   Loop through each letter in the guess and compare it to the secret word:
    *   If a letter is in the **correct position**, print it **green**.
    *   If a letter is in the **word but wrong position**, print it **yellow**.
        *   use the `isInSecret()` function to determine if the current character is in the secret
    *   If a letter **is not in the word**, print it **red**.
    *   **HINT:** Since you are looping over each character one at a time you will output each character one at a time. Don’t output the newline until the entire loop is done.

### **4\. Repeat Until Game Ends**

*   The player gets **five attempts** to guess the word.
*   If they guess correctly, display a **win message**.
*   If they **run out of attempts**, display a **game over message**.

* * *

**Bonus Challenges**
--------------------

Once you complete the basic game, try these additional features:

### **Bonus 1: Random Secret Word Selection**

*   Instead of always using the same secret word, **store multiple words in an array**.
*   Choose a random word **when the game starts**.
*   Hint: You will need to use **random number generation** to select a random index

### **Bonus 2: Show Unused Letters**

*   After the **first attempt**, display a list of **letters the user has not tried yet**.
*   These letters should be printed in **white**.
*   Hint: You will need to **track guessed letters** in an array. Would this array be a c-string or just a normal character array?

### **Bonus 3: Streak Counter**

*   Keep track of **how many games in a row** the player wins.
*   Display the **current win streak** at the end of each game.
*   Save this data in a file so you can load/save their streak when you start the game

* * *

**What to Submit**
------------------

*   A **`.cpp` file** with your completed program.
*   If you implemented **bonuses**, include a **short comment** at the top explaining what you added.
*   Make sure your code **compiles and runs without errors** before submitting.

* * *

**Hints**
---------

*   **C-strings (`char arrays`)** require manual handling of null terminators (`'\0'`).
*   The **`<cstring>`** library has functions that may help with string operations.
*   The **`<cstdlib>`** and **`<ctime>`** libraries can help with random number generation.

* * *
