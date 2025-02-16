# Blackjack Simulator

## Project Description

Blackjack Simulator is a C++ application that simulates the popular card game blackjack. The project uses CMake for build management.

## Features

- **Game Simulation:** The game simulates a classic blackjack match between a single player and the dealer.  
- **Card Drawing:** The player can draw cards to get as close as possible to 21 without exceeding it.  
- **Result Checking:** The application automatically checks the results after each round to determine the winner.  
- **Graphical Interface:** Provides user interaction through a graphical user interface built with Qt.  
- **Error Prevention:** The application includes mechanisms to prevent common errors, such as invalid user input.  
- **Scoreboard:** After finishing a game, the player can save their score in a leaderboard. The game continues until the player loses all points.  

## Classes  

### Card  
- Stores information about a card, such as its rank and suit.  
- Methods:  
  - `Card(const std::string &rank, const std::string &suit)`: Constructor initializing a card.  
  - `int calculateScore() const`: Calculates and returns the card’s point value.  
  - `QLabel* createLabel(QWidget *parent = nullptr, bool isHidden = false) const`: Creates and returns a QLabel representing the card.  

### Deck  
- Stores and manages a deck of cards.  
- Methods:  
  - `Deck()`: Constructor initializing the deck.  
  - `void initializeDeck()`: Initializes the deck of cards.  
  - `Card drawCard()`: Draws a random card from the deck.  

### Dealer  
- A subclass of `Player`, representing the dealer in the game.  
- Methods:  
  - `Dealer()`: Constructor initializing the dealer.  
  - `void revealHiddenCard()`: Reveals the dealer’s hidden card.  

### GameLogic  
- Manages game logic, such as handling game over conditions.  
- Methods:  
  - `static void handleGameOver(int gameResult, int &balance, int &totalWinnings, int bet, QWidget *gameWindow)`: Handles the end of the game.  

### MainWindow  
- The main window of the application.  
- Methods:  
  - `MainWindow(QWidget *parent = nullptr)`: Constructor initializing the main window.  
  - `~MainWindow()`: Destructor.  
  - `void on_PlayButton_clicked()`: Handles the "Play" button click.  
  - `void on_H2PButton_clicked()`: Handles the "H2P" button click.  
  - `void on_LeaderButton_clicked()`: Handles the "Leader" button click.  

### ScoreManager  
- Manages game scores.  
- Methods:  
  - `static QVector<QPair<QString, int>> readScores(const QString &filePath)`: Reads scores from a file.  
  - `static bool writeScore(const QString &filePath, const QString &name, int score)`: Writes a score to a file.  

### BalanceWindow  
- The window managing the player’s balance.  
- Methods:  
  - `BalanceWindow(QWidget *parent = nullptr)`: Constructor initializing the window.  
  - `~BalanceWindow()`: Destructor.  
  - `void StartingBalance()`: Sets the initial balance.  
  - `void setBet(int bet)`: Sets the bet amount.  
  - `int getBet() const`: Returns the bet amount.  
  - `void on_StartBlackjackButton_clicked()`: Handles the "Start Blackjack" button click.  
  - `void handleGameOver(int gameResult)`: Handles the end of the game.  

### Hand  
- Represents a player's or dealer's hand.  
- Methods:  
  - `void addCard(const Card &card)`: Adds a card to the hand.  
  - `int calculateScore() const`: Calculates and returns the total score of the hand.  

### StyledMessageBox  
- Custom-styled message box.  
- Methods:  
  - `StyledMessageBox(QWidget *parent = nullptr)`: Constructor initializing the message box.  
  - `static StyledMessageBox* customCritical(QWidget *parent, const QString &title, const QString &text)`: Creates a custom critical message box.  
  - `static StyledMessageBox* success(QWidget *parent, const QString &title, const QString &text)`: Creates a success message box.  

