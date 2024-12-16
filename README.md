# C++ Quiz Application

This project implements a simple C++ quiz application with user accounts.

## Features:

*   **User Account Creation:**
    *   Creates new user accounts with username, password, and other details.
    *   Stores account information in a file (`accounts.txt`).
*   **User Login:**
    *   Allows users to login with their account number and password.
    *   Verifies login credentials against the stored data.
*   **Quiz Functionality:**
    *   Loads quiz questions from a file (`questions.txt`).
    *   Presents questions to the user with multiple-choice options.
    *   Tracks user's answers and calculates the final score.
    *   Provides feedback on correct and incorrect answers.

## How to Run:

1.  **Compile:**
    *   Save the code as `quiz.cpp`.
    *   Compile using a C++ compiler (like g++):

    ```bash
    g++ quiz.cpp -o quiz
    ```

2.  **Create Questions File:**
    *   Create a file named `questions.txt` with the following format:

    ```
    Question 1|Option 1|Option 2|Option 3|Option 4|Correct Answer Index (1-4)
    Question 2|Option 1|Option 2|Option 3|Option 4|Correct Answer Index (1-4)
    ...
    ```

    *   For example:

    ```
    What is the capital of France?|Paris|London|Berlin|Rome|1
    Who painted the Mona Lisa?|Michelangelo|Leonardo da Vinci|Raphael|Donatello|2
    ```

3.  **Run the Application:**
    *   Execute the compiled program:

    ```bash
    ./quiz
    ```

4.  **Follow On-Screen Instructions:**
    *   Choose from the options:
        *   Create Account
        *   Login and Start Quiz
        *   Exit

## Note:

*   This is a basic implementation and can be further enhanced with features like:
    *   Timer for each question
    *   Different difficulty levels
    *   Leaderboards
    *   More robust input validation
*   The `accounts.txt` file is used for simple storage. For production environments, consider using a database.

## Contributing:

Contributions are welcome! Feel free to fork this repository and submit pull requests with improvements and new features.
