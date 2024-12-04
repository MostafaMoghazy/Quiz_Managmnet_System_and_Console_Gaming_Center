
# Quiz Management System with Games

## Overview
The **Quiz Management System with Games** is a feature-rich C++ application designed to manage quizzes, users, and scores, while also providing engaging mini-games for entertainment. This project demonstrates the use of advanced C++ programming concepts like file handling, dynamic memory allocation, and object-oriented design.

## Features

### Admin Panel
Admins have full control over quiz management and user data:
- **Manage Quiz Questions**:
  - Add, edit, or delete questions.
  - Set question difficulty levels for dynamic scoring.
- **Manage Users**:
  - Add, remove, or update user scores.
- **View Dashboard**:
  - Display a leaderboard of all users and their highest scores.

### User Gameplay
- **Interactive Quiz**:
  - Answer randomly shuffled questions with scores based on difficulty.
  - Persistent score tracking stored in external files.
- **Entertainment Section**:
  - **Word Guessing Game**: Challenge your vocabulary with helpful hints.
  - **Tic Tac Toe**: A classic strategy game against another player.
  - **Rock-Paper-Scissors**: A simple yet exciting game with graphical output.

### Robust File Handling
- **questions.txt**:
  - Stores questions, their correct answers, and difficulty levels.
  - First line specifies the number of questions.
- **users.txt**:
  - Stores usernames and scores.
  - First line specifies the number of users.
  
This approach ensures dynamic memory allocation and efficient data retrieval.

---

## How to Run

1. Clone the repository:
   ```bash
   git clone [repository link]
   ```
2. Navigate to the project directory:
   ```bash
   cd quiz-management-system
   ```
3. Compile the program using a C++ compiler (C++11 or later):
   ```bash
   g++ -std=c++11 -o quiz_app main.cpp
   ```
4. Run the compiled program:
   ```bash
   ./quiz_app
   ```

---

## File Structure
- **`main.cpp`**: The main program file containing all logic for quizzes, user management, and games.
- **`questions.txt`**: 
  - Format: 
    ```
    [Number of Questions]
    [Question Text] [Correct Answer] [Difficulty]
    ```
  - Example:
    ```
    2
    What is the capital of France? a 2
    What is 2+2? b 1
    ```
- **`users.txt`**:
  - Format:
    ```
    [Number of Users]
    [Username] [Score]
    ```
  - Example:
    ```
    2
    John 10
    Doe 15
    ```

---

## Sample Input Files

### Sample `questions.txt`:
```
3
What is the capital of France? a 2
What is 2+2? b 1
Who wrote "To Kill a Mockingbird"? d 3
```

### Sample `users.txt`:
```
3
John 25
Jane 15
Doe 10
```

---

## Notes for Use
- **Admin Credentials**:
  - Username: `admin`
  - Password: `admin123` (modifiable in the code).
- **Dynamic Memory Management**:
  - The number of questions and users is read from the first line of each file to allocate memory dynamically.
- **Entertainment Section**:
  - Games are designed to provide an engaging user experience and are independent of quiz functionalities.

---

## Key Programming Concepts Demonstrated
- **Object-Oriented Programming**:
  - Classes for `User`, `Question`, `QuestionManager`, and `UserManager`.
  - Separation of concerns through encapsulation and modular design.
- **File Handling**:
  - Persistent storage of questions and user data in text files.
- **Dynamic Memory Allocation**:
  - Efficient use of pointers and arrays for flexible data handling.
- **Error Handling**:
  - Validations for file operations and user inputs.
- **Graphical Output**:
  - Basic ASCII graphics for games like Rock-Paper-Scissors.

---

## Contribution
Contributions are highly encouraged! Here’s how you can help:
1. Fork the repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Description of your changes"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a pull request.
