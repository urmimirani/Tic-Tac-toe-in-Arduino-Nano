#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //LCD connections
const int buttonPins[9] = {8, 9, 10, 11, 12, 13, A0, A1, A2}; //button pins

//TTT board and current player
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currPlayer = 'X';

int player1Moves = 0;
int player2Moves = 0;
int totalRounds = 0;
int player1Wins = 0;
int player2Wins = 0;
int roundsCompleted = 0;

//drawing TTT board on LCD
void drawBoard() {
  lcd.clear();
  for (int row = 0; row < 3; row++) {
    lcd.setCursor(0, row * 2);
    for (int col = 0; col < 3; col++) {
      lcd.print(board[row][col]);
      if (col < 2) {
        lcd.print(" | ");
      }
    }
  }
}

//check if game is over
bool gameOver() {
  //check rows col and diag for win
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == currPlayer && board[i][1] == currPlayer && board[i][2] == currPlayer) {
      return true;
    }
    if (board[0][i] == currPlayer && board[1][i] == currPlayer && board[2][i] == currPlayer) {
      return true;
    }
  }
  if (board[0][0] == currPlayer && board[1][1] == currPlayer && board[2][2] == currPlayer) {
    return true;
  }
  if (board[0][2] == currPlayer && board[1][1] == currPlayer && board[2][0] == currPlayer) {
    return true;
  }

  return false; //game not over
}

// handle players move
void makeMove(int buttonIndex) {
  int row = buttonIndex / 3;
  int col = buttonIndex % 3;
  if (board[row][col] == ' ') {
    board[row][col] = currPlayer;
    if (currPlayer == 'X') {
      player1Moves++;
    } else {
      player2Moves++;
    }
    drawBoard();
  }
}

void setup() {
  lcd.begin(20, 4); //initialize LCD with 20 col 4 rows
  drawBoard();
  for (int i = 0; i < 9; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  lcd.setCursor(0, 3);
  lcd.print("Enter no of rounds:");
  while (totalRounds == 0) {
    if (digitalRead(buttonPins[0]) == LOW) {
      totalRounds = 1;
      lcd.setCursor(0, 3);
      lcd.print("Number of rounds: 1 ");
      delay(1000); //display selected round for 1 sec
      lcd.setCursor(0, 3);
      lcd.print("                   "); //clear display
    } else if (digitalRead(buttonPins[1]) == LOW) {
      totalRounds = 2;
      lcd.setCursor(0, 3);
      lcd.print("Number of rounds: 2 ");
      delay(1000); 
      lcd.setCursor(0, 3);
      lcd.print("                   "); 
    } else if (digitalRead(buttonPins[2]) == LOW) {
      totalRounds = 3;
      lcd.setCursor(0, 3);
      lcd.print("Number of rounds: 3 ");
      delay(1000); 
      lcd.setCursor(0, 3);
      lcd.print("                   "); 
    }
  }
}

void loop() {
  if (roundsCompleted < totalRounds) {
    for (int i = 0; i < 9; i++) {
      if (digitalRead(buttonPins[i]) == LOW && board[i / 3][i % 3] == ' ') {
        makeMove(i);
        if (gameOver()) {
          lcd.setCursor(0, 3);
          if (currPlayer == 'X') {
            lcd.print("Player 1 (X) wins!");
            player1Wins++;
          } else {
            lcd.print("Player 2 (O) wins!");
            player2Wins++;
          }
          delay(2000); //display result for 2 seconds
          roundsCompleted++;
          resetGame();
        } else if (isDraw()) {
          lcd.setCursor(0, 3);
          lcd.print("Draw!");
          delay(2000); //display result for 2 seconds
          roundsCompleted++;
          resetGame();
        }
        //switch to the other player
        currPlayer = (currPlayer == 'X') ? 'O' : 'X';
      }
    }
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Player 1: ");
    lcd.print(player1Wins);
    lcd.setCursor(0, 1);
    lcd.print("Player 2: ");
    lcd.print(player2Wins);
    lcd.setCursor(0, 2);
    lcd.print("Winner: ");
    if (player1Wins > player2Wins) {
      lcd.print("Player 1");
    } else if (player2Wins > player1Wins) {
      lcd.print("Player 2");
    } else {
      lcd.print("None");
    }
    while (1); //game over
  }
}

//reset board for next round
void resetGame() {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      board[row][col] = ' ';
    }
  }
  player1Moves = 0;
  player2Moves = 0;
  currPlayer = 'X';
  drawBoard();
}

//check for a draw
bool isDraw() {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board[row][col] == ' ') {
        return false; //at least one empty cell, not draw yet
      }
    }
  }
  return true; //all cells filled,a draw
}
