# Blackjack Symulator

## Opis projektu

Blackjack Symulator to aplikacja napisana w języku C++, która symuluje popularną grę karcianą blackjack. Projekt wykorzystuje CMake do zarządzania kompilacją.

## Funkcjonalności

- **Symulacja gry:** Gra symuluje klasyczną rozgrywkę blackjack pomiędzy jednym graczem a dealerem.
- **Dobieranie kart:** Gracz ma możliwość dobierania kart, aby zbliżyć się do wartości 21 bez jej przekroczenia.
- **Sprawdzanie wyniku:** Aplikacja automatycznie sprawdza wyniki po każdej rundzie, określając zwycięzcę.
- **Interfejs graficzny:** Umożliwia interakcję z graczem poprzez graficzny interfejs użytkownika zbudowany przy użyciu Qt.
- **Ochrona przed błędami:** Aplikacja zawiera mechanizmy zapobiegające typowym błędom, takim jak wprowadzenie nieprawidłowych danych przez użytkownika.
- **Tabela wyników:** Po zakończeniu gry gracz może zapisać swój wynik w tabeli wyników. Gra toczy się tak długo, aż gracz nie straci wszystkich punktów.

## Klasy

### Card
- Przechowuje informacje o karcie, takie jak jej rangę i kolor.
- Metody:
  - `Card(const std::string &rank, const std::string &suit)`: Konstruktor inicjalizujący kartę.
  - `int calculateScore() const`: Oblicza i zwraca wartość punktową karty.
  - `QLabel* createLabel(QWidget *parent = nullptr, bool isHidden = false) const`: Tworzy i zwraca QLabel reprezentujący kartę.

### Deck
- Przechowuje talię kart i zarządza nimi.
- Metody:
  - `Deck()`: Konstruktor inicjalizujący talię kart.
  - `void initializeDeck()`: Inicjalizuje talię kart.
  - `Card drawCard()`: Losuje kartę z talii.

### Dealer
- Klasa pochodna klasy `Player`, reprezentująca dealera w grze.
- Metody:
  - `Dealer()`: Konstruktor inicjalizujący dealera.
  - `void revealHiddenCard()`: Odkrywa ukrytą kartę dealera.

### GameLogic
- Zarządza logiką gry, taką jak obsługa końca gry.
- Metody:
  - `static void handleGameOver(int gameResult, int &balance, int &totalWinnings, int bet, QWidget *gameWindow)`: Obsługuje zakończenie gry.

### MainWindow
- Główne okno aplikacji.
- Metody:
  - `MainWindow(QWidget *parent = nullptr)`: Konstruktor inicjalizujący główne okno.
  - `~MainWindow()`: Destruktor.
  - `void on_PlayButton_clicked()`: Obsługuje kliknięcie przycisku "Play".
  - `void on_H2PButton_clicked()`: Obsługuje kliknięcie przycisku "H2P".
  - `void on_LeaderButton_clicked()`: Obsługuje kliknięcie przycisku "Leader".

### ScoreManager
- Zarządza wynikami gry.
- Metody:
  - `static QVector<QPair<QString, int>> readScores(const QString &filePath)`: Odczytuje wyniki z pliku.
  - `static bool writeScore(const QString &filePath, const QString &name, int score)`: Zapisuje wynik do pliku.

### BalanceWindow
- Okno zarządzające balansem gracza.
- Metody:
  - `BalanceWindow(QWidget *parent = nullptr)`: Konstruktor inicjalizujący okno.
  - `~BalanceWindow()`: Destruktor.
  - `void StartingBalance()`: Ustawia początkowy balans.
  - `void setBet(int bet)`: Ustawia zakład.
  - `int getBet() const`: Zwraca wartość zakładu.
  - `void on_StartBlackjackButton_clicked()`: Obsługuje kliknięcie przycisku "Start Blackjack".
  - `void handleGameOver(int gameResult)`: Obsługuje zakończenie gry.

### Hand
- Reprezentuje rękę gracza lub dealera.
- Metody:
  - `void addCard(const Card &card)`: Dodaje kartę do ręki.
  - `int calculateScore() const`: Oblicza i zwraca sumaryczną wartość punktową ręki.

### StyledMessageBox
- Spersonalizowane okno wiadomości.
- Metody:
  - `StyledMessageBox(QWidget *parent = nullptr)`: Konstruktor inicjalizujący okno wiadomości.
  - `static StyledMessageBox* customCritical(QWidget *parent, const QString &title, const QString &text)`: Tworzy niestandardowe okno wiadomości krytycznej.
  - `static StyledMessageBox* success(QWidget *parent, const QString &title, const QString &text)`: Tworzy okno wiadomości sukcesu.

## Instalacja

1. Sklonuj repozytorium:
   ```sh
   git clone https://github.com/Mateusz-Latka/Blackjack-Symulator.git
   cd Blackjack-Symulator
