# 🃏 Symulator Blackjacka

## 📜 Opis Projektu

Symulator Blackjacka to aplikacja w języku C++, która symuluje popularną grę karcianą blackjack. Projekt wykorzystuje CMake do zarządzania budowaniem.

## ✨ Funkcje

- **Symulacja Gry:** Gra symuluje klasyczny mecz blackjacka między jednym graczem a krupierem.  
- **Dobieranie Kart:** Gracz może dobierać karty, aby zbliżyć się jak najbardziej do 21 punktów, nie przekraczając tej wartości.  
- **Sprawdzanie Wyników:** Aplikacja automatycznie sprawdza wyniki po każdej rundzie, aby określić zwycięzcę.  
- **Interfejs Graficzny:** Umożliwia interakcję użytkownika za pomocą interfejsu graficznego zbudowanego w Qt.  
- **Zapobieganie Błędom:** Aplikacja zawiera mechanizmy zapobiegające typowym błędom, takim jak nieprawidłowe dane wejściowe.  
- **Tablica Wyników:** Po zakończeniu gry gracz może zapisać swój wynik w tabeli liderów. Gra trwa, dopóki gracz nie straci wszystkich punktów.  

## 🛠️ Wymagania

- System z zainstalowanym Qt.
- Kompilator zgodny z C++17.
- CMake do zarządzania budowaniem.

## ⚙️ Instalacja

1. Sklonuj repozytorium:
   ```bash
   git clone https://github.com/Mateusz-Latka/Blackjack-Symulator.git
   ```
2. Przejdź do katalogu projektu:
   ```bash
   cd Blackjack-Symulator
   ```
3. Utwórz katalog build:
   ```bash
   mkdir build && cd build
   ```
4. Uruchom CMake:
   ```bash
   cmake ..
   ```
5. Skompiluj:
   ```bash
   make
   ```

## 📖 Użycie

1. Uruchom aplikację:
   ```bash
   ./BlackjackSimulator
   ```

2. Postępuj zgodnie z instrukcjami w interfejsie graficznym.

## 🙌 Wkład

Jeśli znajdziesz jakiekolwiek problemy lub masz sugestie, otwórz zgłoszenie (issue) lub prześlij pull request.

## 📜 Licencja

Ten projekt jest licencjonowany na warunkach licencji MIT - szczegóły znajdziesz w pliku LICENSE.

## 📧 Kontakt

W razie pytań lub uwag skontaktuj się z właścicielem repozytorium.
