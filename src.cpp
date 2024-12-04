/*
 * Project: Quiz Management System with Console Gaming Center
 * Author: Mostafa Ahmed Lotfy Moghazy
 * Purpose: A multi-functional program to manage quizzes, user scores, and entertainment games.
 * Features:
 * - Admin tools for managing questions and user data using file handling.
 * - User gameplay for quizzes with score tracking.
 * - Entertainment section with Word Guessing, Tic Tac Toe, and Rock-Paper-Scissors.
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <time.h>
#include <windows.h>
using namespace std;
class Question
{
public:
    string questionText;
    char correctAnswer;
    int difficulty;
};
class User
{
public:
    string username;
    int score;
    void entertainment();
    void wordGuessing();
    void ticTacToe();
    void rps();
};
class QuestionManager
{
public:
    QuestionManager();
    ~QuestionManager();
    void loadQuestions();
    void saveQuestions();
    void displayQuestions();
    void addQuestion(const Question &question);
    void deleteQuestion(int index);
    void modifyAnswer(int index, char newAnswer);
    void adminTasks();
    const Question *getQuestions() const
    {
        return questions;
    }
    int getNumQuestions() const
    {
        return numQuestions;
    }

private:
    Question *questions;
    int numQuestions;
    const string questionsFileName = "questions.txt";
};
class UserManager
{
public:
    UserManager();
    ~UserManager();
    void loadUsers();
    void saveUsers();
    void displayDashboard();
    void addUser(const User &user);
    void deleteUser(int index);
    void modifyUserScore(int index, int newScore);
    void adminTasks();
    const User *getUsers() const
    {
        return users;
    }
    int getNumUsers() const
    {
        return numUsers;
    }

private:
    User *users;
    int numUsers;
    const string usersFileName = "users.txt";
};
class QuizGame
{
public:
    QuizGame(QuestionManager &qManager, UserManager &uManager);
    ~QuizGame();
    void run();

private:
    QuestionManager &questionManager;
    UserManager &userManager;
};
void User::entertainment()
{
    cout << "Welcome to the entertainment section, please choose your game :)\n";
    cout << "1. Word Guessing\n";
    cout << "2. Tic Tac Toe\n";
    cout << "3. Rock Paper Scissors\n";
    cout << "4. Back to Main Menu\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        wordGuessing();
        break;
    case 2:
        ticTacToe();
        break;
    case 3:
        rps();
        break;
    case 4:
        cout << "Returning to the main menu.\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
}
void User::wordGuessing()
{
    cout << "Welcome to the Word Guessing Game!\n";
    cout << "Try to guess the word. Here's a hint for you.\n";
    const int maxAttempts = 6;
    string words[] = {"Hadeer", "computer", "algorithm", "java", "cplusplus"};
    string hints[] = {"Greatest Dr in helwan uni", "Electronic device", "Step-by-step solution", "Programming language", "Extension of C language"};
    srand((time(0)));
    int randomIndex = rand() % 5;
    string selectedWord = words[randomIndex];
    string wordHint = hints[randomIndex];
    string guessedWord(selectedWord.length(), '_');
    int attemptsRemaining = maxAttempts;
    cout << "Hint: " << wordHint << "\n";
    while (attemptsRemaining > 0)
    {
        cout << "Word: " << guessedWord << "\n";
        cout << "Attempts remaining: " << attemptsRemaining << "\n";

        char guess;
        cout << "Enter your guess: ";
        cin >> guess;

        bool correctGuess = false;

        for (size_t i = 0; i < selectedWord.length(); ++i)
        {
            if (selectedWord[i] == guess)
            {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }
        if (!correctGuess)
        {
            cout << "Incorrect guess.\n";
            --attemptsRemaining;
        }
        if (guessedWord == selectedWord)
        {
            cout << "Congratulations! You guessed the word: " << selectedWord << "\n";
            return;
        }
    }
    cout << "Sorry, you ran out of attempts. The correct word was: " << selectedWord << "\n";
}
char arr[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'x';
void start();
void play();
char check_winner();
void start()
{
    system("cls");
    cout << " _____________" << endl;
    for (int i = 0; i < 3; i++)
    {

        cout << " |   |   |   |" << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << " | " << arr[i][j];
        }
        cout << " |" << endl;
        cout << " |___|___|___|" << endl;
    }
}
void play()
{
    char pos;
    if (player == 'x')
        player = 'o';
    else
        player = 'x';
    cout << "choose your postion " << player << " ";
    cin >> pos;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == pos)
                arr[i][j] = player;
        }
    }
}
char check_winner()
{
    int y = 0, z = 0, w = 0;
    for (int i = 0; i < 3; i++)
    {
        y = 0;
        z = 0;
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == player)
                y++;
            if (arr[j][i] == player)
                z++;
        }
        if (y == 3 || z == 3)
            return player;
        }
    w = 0;
    for (int j = 0; j < 3; j++)
    {
        if (arr[j][j] == player)
            w++;
    }
    if (w == 3)
        return player;

    w = 0;
    if (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)
        return player;
    return '*';
}
void User::ticTacToe()
{
    char i = '*';
    int count = 0;
    while ((i == '*') && (count < 9))
    {
        start();
        play();
        i = check_winner();
        count++;
    }
    start();
    if (i == player)
        cout << "the winner is " << player << endl;
    else if (i == '*')
        cout << "no winner" << endl;
}
void drawRock()
{
    cout << "    _______\n";
    cout << "---'   ____)\n";
    cout << "      (_____)\n";
    cout << "      (_____)\n";
    cout << "      (____)\n";
    cout << "---.__(___)\n";
}
void drawPaper()
{
    cout << "    _______\n";
    cout << "---'    ____)____\n";
    cout << "           ______)\n";
    cout << "          _______)\n";
    cout << "         _______)\n";
    cout << "---.__________)\n";
}
void drawScissors()
{
    cout << "    _______\n";
    cout << "---'   ____)____\n";
    cout << "          ______)\n";
    cout << "       __________)\n";
    cout << "      (____)\n";
    cout << "---.__(___)\n";
}
void displayChoice(const string &move)
{
    if (move == "Rock")
    {
        drawRock();
    }
    else if (move == "Paper")
    {
        drawPaper();
    }
    else if (move == "Scissors")
    {
        drawScissors();
    }
}
void User::rps()
{
    cout << "Welcome to Rock, Paper, Scissors!\n";
    cout << "Choose your move:\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    int userChoice;
    cout << "Enter your choice (1-3): ";
    cin >> userChoice;
    cout << "You chose:\n";
    if (userChoice < 1 || userChoice > 3)
    {
        cout << "Invalid choice. Please choose a number between 1 and 3.\n";
        return;
    }
    string choices[] = {"Rock", "Paper", "Scissors"};
    string userMove = choices[userChoice - 1];
    srand((time(0)));
    int computerChoice = rand() % 3;
    string computerMove = choices[computerChoice];
    displayChoice(userMove);
    cout << "\nComputer chose:\n";
    displayChoice(computerMove);
    if (userMove == computerMove)
    {
        cout << "It's a tie!\n";
    }
    else if ((userMove == "Rock" && computerMove == "Scissors") ||
             (userMove == "Paper" && computerMove == "Rock") ||
             (userMove == "Scissors" && computerMove == "Paper"))
    {
        cout << "Congratulations! You win!\n";
    }
    else
    {
        cout << "Sorry, you lose. Better luck next time!\n";
    }
}
QuestionManager::QuestionManager() : questions(nullptr), numQuestions(0)
{
}
QuestionManager::~QuestionManager()
{
    delete[] questions;
}
void QuestionManager::loadQuestions()
{
    ifstream file(questionsFileName);
    if (!file.is_open())
    {
        cerr << "Error opening questions file.\n";
        return;
    }

    file >> numQuestions;
    questions = new Question[numQuestions];

    for (int i = 0; i < numQuestions; ++i)
    {
        file.ignore();
        getline(file, questions[i].questionText);

        file >> questions[i].correctAnswer >> questions[i].difficulty;
    }

    file.close();
}
void QuestionManager::saveQuestions()
{
    ofstream file(questionsFileName);
    if (!file.is_open())
    {
        cerr << "Error opening questions file for writing.\n";
        return;
    }

    file << numQuestions << '\n';

    for (int i = 0; i < numQuestions; ++i)
    {
        file << questions[i].questionText << '\n'
             << questions[i].correctAnswer << ' ' << questions[i].difficulty << '\n';
    }

    file.close();
}
void QuestionManager::displayQuestions()
{
    for (int i = 0; i < numQuestions; ++i)
    {
        cout << "Question " << (i + 1) << " (Difficulty: " << questions[i].difficulty << "):\n";
        cout << questions[i].questionText << "\n";
    }
}
void QuestionManager::addQuestion(const Question &question)
{
    Question *newQuestions = new Question[numQuestions + 1];
    for (int i = 0; i < numQuestions; ++i)
    {
        newQuestions[i] = questions[i];
    }
    newQuestions[numQuestions] = question;

    delete[] questions;
    questions = newQuestions;
    ++numQuestions;

    saveQuestions();
}
void QuestionManager::deleteQuestion(int index)
{
    if (index >= 0 && index < numQuestions)
    {
        Question *newQuestions = new Question[numQuestions - 1];
        for (int i = 0, j = 0; i < numQuestions; ++i)
        {
            if (i != index)
            {
                newQuestions[j++] = questions[i];
            }
        }
        delete[] questions;
        questions = newQuestions;
        --numQuestions;

        saveQuestions();
    }
}
void QuestionManager::modifyAnswer(int index, char newAnswer)
{
    if (index >= 0 && index < numQuestions)
    {
        questions[index].correctAnswer = newAnswer;
        saveQuestions();
    }
}
void QuestionManager::adminTasks()
{
    int choice;
    cout << "Admin Tasks Menu:\n";
    cout << "1. Add Question\n";
    cout << "2. Delete Question\n";
    cout << "3. Modify Answer\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Question newQuestion;
        cout << "Enter the question text: ";
        cin.ignore(); // Consume newline left in the buffer
        getline(cin, newQuestion.questionText);
        cout << "Enter the correct answer (a, b, c, or d): ";
        cin >> newQuestion.correctAnswer;
        cout << "Enter the difficulty (an integer value): ";
        cin >> newQuestion.difficulty;
        addQuestion(newQuestion);
        cout << "Question added successfully!\n";
        break;
    }
    case 2:
    {
        int index;
        cout << "Enter the index of the question to delete: ";
        cin >> index;
        deleteQuestion(index - 1); // Adjust index to 0-based
        cout << "Question deleted successfully!\n";
        break;
    }
    case 3:
    {
        int index;
        cout << "Enter the index of the question to modify answer: ";
        cin >> index;
        char newAnswer;
        cout << "Enter the new correct answer (a, b, c, or d): ";
        cin >> newAnswer;
        modifyAnswer(index - 1, newAnswer); // Adjust index to 0-based
        cout << "Answer modified successfully!\n";
        break;
    }
    case 4:
        cout << "Returning to the main menu.\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
}
UserManager::UserManager() : users(nullptr), numUsers(0)
{
}
UserManager::~UserManager()
{
    delete[] users;
}
void UserManager::loadUsers()
{
    ifstream file(usersFileName);
    if (!file.is_open())
    {
        cerr << "Error opening users file.\n";
        return;
    }
    file >> numUsers;
    users = new User[numUsers];

    for (int i = 0; i < numUsers; ++i)
    {
        file >> users[i].username >> users[i].score;
    }
    file.close();
}
void UserManager::saveUsers()
{
    ofstream file(usersFileName);
    if (!file.is_open())
    {
        cerr << "Error opening users file for writing.\n";
        return;
    }

    file << numUsers << '\n';

    for (int i = 0; i < numUsers; ++i)
    {
        file << users[i].username << ' ' << users[i].score << '\n';
    }

    file.close();
}

void UserManager::displayDashboard()
{
    cout << "Username\tScore\n";
    for (int i = 0; i < numUsers; ++i)
    {
        cout << users[i].username << '\t' << users[i].score << '\n';
    }
}
void UserManager::addUser(const User &user)
{
    User *newUsers = new User[numUsers + 1];
    for (int i = 0; i < numUsers; ++i)
    {
        newUsers[i] = users[i];
    }
    newUsers[numUsers] = user;
    delete[] users;
    users = newUsers;
    ++numUsers;
    saveUsers();
}
void UserManager::deleteUser(int index)
{
    if (index >= 0 && index < numUsers)
    {
        User *newUsers = new User[numUsers - 1];
        for (int i = 0, j = 0; i < numUsers; ++i)
        {
            if (i != index)
            {
                newUsers[j++] = users[i];
            }
        }
        delete[] users;
        users = newUsers;
        --numUsers;
        saveUsers();
    }
}
void UserManager::modifyUserScore(int index, int newScore)
{
    if (index >= 0 && index < numUsers)
    {
        users[index].score = newScore;
        saveUsers();
    }
}
void UserManager::adminTasks()
{
    int choice;
    cout << "Admin Tasks Menu:\n";
    cout << "1. Add User\n";
    cout << "2. Delete User\n";
    cout << "3. Modify User Score\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        User newUser;
        cout << "Enter the username: ";
        cin >> newUser.username;

        cout << "Enter the initial score: ";
        cin >> newUser.score;

        addUser(newUser);
        cout << "User added successfully!\n";
        break;
    }
    case 2:
    {
        int index;
        cout << "Enter the index of the user to delete: ";
        cin >> index;
        deleteUser(index - 1); // Adjust index to 0-based
        cout << "User deleted successfully!\n";
        break;
    }
    case 3:
    {
        int index;
        cout << "Enter the index of the user to modify score: ";
        cin >> index;
        int newScore;
        cout << "Enter the new score: ";
        cin >> newScore;
        modifyUserScore(index - 1, newScore); // Adjust index to 0-based
        cout << "User score modified successfully!\n";
        break;
    }
    case 4:
        cout << "Returning to the main menu.\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
}
QuizGame::QuizGame(QuestionManager &qManager, UserManager &uManager)
    : questionManager(qManager), userManager(uManager)
{
}
QuizGame::~QuizGame()
{
}
void QuizGame::run()
{
    char choice;

    do
    {
        cout << "user Menu:\n";
        cout << "1. take a quiz\n";
        cout << "2. Display Dashboard\n";
        cout << "3. entertainment section" << endl;
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case '1':
        {
            string playerName;
            cout << "Enter your username: ";
            cin >> playerName;

            // Find the user with the entered username
            auto userIt = find_if(userManager.getUsers(), userManager.getUsers() + userManager.getNumUsers(),
                                  [playerName](const User &user)
                                  {
                                      return user.username == playerName;
                                  });

            if (userIt == userManager.getUsers() + userManager.getNumUsers())
            {
                cout << "User not found. Please try again.\n";
                break;
            }

            User *currentUser = const_cast<User *>(&(*userIt));

            int score = 0;
            for (int i = 0; i < questionManager.getNumQuestions(); ++i)
            {
                char playerAnswer;
                cout << questionManager.getQuestions()[i].questionText << "\n";
                cout << "a) ";
                cout << "Your answer: ";
                cin >> playerAnswer;
                if (playerAnswer == questionManager.getQuestions()[i].correctAnswer)
                {
                    score += questionManager.getQuestions()[i].difficulty;
                    cout << "Correct! Current score: " << score << "\n";
                }
                else
                {
                    cout << "Incorrect. The correct answer is " << questionManager.getQuestions()[i].correctAnswer << "\n";
                }
            }
            currentUser->score = score;
            userManager.saveUsers();
            cout << "Game Over! Your final score: " << score << "\n";
            break;
        }
        case '2':
            userManager.displayDashboard();
            break;
        case '3':
        {
            User player1;
            player1.entertainment();
            break;
        }
        case '4':
        {
            cout << "Exiting the program. Goodbye!\n";
            break;
        }

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');
}
int main()
{
    system("color 3e");
    HANDLE consoleColor;
    consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

    QuestionManager qManager;
    UserManager uManager;
    uManager.loadUsers();
    uManager.saveUsers();
    qManager.loadQuestions();
    string adminPassword = "admin123"; // Set your admin password here

    cout << "----------------------------------------\n";
    cout << "|      Welcome to the Quiz Program     |\n";
    cout << "----------------------------------------\n";
    string userType;
    do
    {
        cout << "Are you an admin or a user? Enter 'admin' or 'user': ";
        cin >> userType;
    } while (userType != "admin" && userType != "user");

    if (userType == "admin")
    {
        cout << "Enter admin password: ";
        string enteredPassword;
        cin >> enteredPassword;

        if (enteredPassword == adminPassword)
        {
            system("cls");
            system("color 5e");
            cout << "\nAdmin access granted. Performing admin tasks...\n";

            int adminChoice;
            do
            {
                cout << "\nAdmin Menu:\n";
                cout << "1. Admin Tasks Questions\n";
                cout << "2. Admin Tasks Users\n";
                cout << "3. Display Dashboard\n";
                cout << "4. Exit Admin Menu\n";
                cout << "Enter your choice: ";
                cin >> adminChoice;

                switch (adminChoice)
                {
                case 1:
                {
                    system("cls");
                    qManager.adminTasks();
                }
                break;
                case 2:
                {
                    system("cls");
                    uManager.adminTasks();
                }
                break;
                case 3:
                {
                    system("cls");
                    uManager.displayDashboard();
                }
                break;
                case 4:
                {
                    system("cls");
                    cout << "\nExiting Admin Menu.\n";
                }
                break;
                default:
                {
                    system("cls");
                    cout << "Invalid choice. Please try again.\n";
                }
                }
            } while (adminChoice != 4);
        }
        else
        {
            SetConsoleTextAttribute(consoleColor, 4); // Red color for error
            cout << "\nIncorrect password. Exiting program.\n";
        }
    }
    else if (userType == "user")
    {
        User player;
        QuizGame game(qManager, uManager);
        game.run();
    }
    else
    {
        SetConsoleTextAttribute(consoleColor, 4); // Red color for error
        cout << "\nInvalid user type. Exiting program.\n";
    }

    SetConsoleTextAttribute(consoleColor, 7); // Reset to default color
    return 0;
}
