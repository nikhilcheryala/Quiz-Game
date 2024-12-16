#include <bits/stdc++.h>
using namespace std;

class Account {
public:
    string name;
    string username;
    string gender;
    int accountno;
    string password;
};

class Quiz {
    static int accountcounter;
    int score;
    vector<string> questions;
    vector<vector<string>> options;
    vector<int> correctAnswers;

public:
    Account acc;

    Quiz() : score(0) {}

    int accountgenerate() {
        return ++accountcounter;
    }
    void accountcreate() {
        acc.accountno = accountgenerate();
        cin.ignore();
        cout << "Enter the name: ";
        getline(cin, acc.name);
        cout << "Enter the Gender: ";
        cin >> acc.gender;
        cout << "Enter Username: ";
        cin >> acc.username;
        cout << "Enter your Password: ";
        cin >> acc.password;

        ofstream outFile("accounts.txt");
        if (outFile.is_open()) {
            outFile << acc.accountno << ","
                    << acc.name << ","
                    << acc.gender << ","
                    << acc.username << ","
                    << acc.password << endl;
            outFile.close();
        } else {
            cout << "Error opening file for writing!" << endl;
        }

        cout << "Account created successfully! Your account number is: " << acc.accountno << endl;
        cout << "Thanks for creating account, " << acc.username << endl;
    }

    bool login() {
        int enteredAccNo;
        string enteredPassword;

        cout << "Enter your Account Number: ";
        cin >> enteredAccNo;
        cout << "Enter your Password: ";
        cin >> enteredPassword;

        ifstream inFile("accounts.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string accountnoStr, name, gender, username, password;

                getline(ss, accountnoStr, ',');
                getline(ss, name, ',');
                getline(ss, gender, ',');
                getline(ss, username, ',');
                getline(ss, password, ',');

                int fileAccountNo = stoi(accountnoStr);

                if (fileAccountNo == enteredAccNo && password == enteredPassword) {
                    cout << "Login successful! Welcome to the Quiz, " << name << "!" << endl;
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
        } else {
            cout << "Error opening file for reading!" << endl;
        }

        cout << "Invalid Account Number or Password!" << endl;
        return false;
    }

    void loadQuestions(const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cerr << "Error: Could not open questions file!" << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string question, option1, option2, option3, option4, correctOptionStr;

            getline(ss, question, '|');
            getline(ss, option1, '|');
            getline(ss, option2, '|');
            getline(ss, option3, '|');
            getline(ss, option4, '|');
            getline(ss, correctOptionStr, '|');

            questions.push_back(question);
            options.push_back({option1, option2, option3, option4});
            correctAnswers.push_back(stoi(correctOptionStr));
        }
        inFile.close();
    }

    // starting the quiz
    void startQuiz() {
        if (questions.empty()) {
            cout << "No questions available. Please check the questions file." << endl;
            return;
        }

        score = 0;
        for (int i = 0; i < questions.size(); ++i) {
            cout << "Question " << (i + 1) << ": " << questions[i] << endl;
            for (int j = 0; j < options[i].size(); ++j) {
                cout << j + 1 << ". " << options[i][j] << endl;
            }

            int userAnswer;
            cout << "Your answer (1-4): ";
            cin >> userAnswer;

            if (userAnswer == correctAnswers[i]) {
                cout << "Correct!\n" << endl;
                ++score;
            } else {
                cout << "Wrong! The correct answer is: "
                     << correctAnswers[i] << ". " << options[i][correctAnswers[i] - 1] << "\n" << endl;
            }
        }

        cout << "Quiz Over! Your total score: " << score << "/" << questions.size() << endl;
    }
};

int Quiz::accountcounter = 100;

int main() {
    Quiz quiz;
    int choice;

    do {
        cout << "\n1. Create Account\n2. Login and Start Quiz\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                quiz.accountcreate();
                break;
            case 2:
                if (quiz.login()) {
                    quiz.loadQuestions("questions.txt");
                    quiz.startQuiz();
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}