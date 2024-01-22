# Tic-Tac-toe-in-Arduino-Nano

**INTRODUCTION**
Tic-Tac-Toe, also known as "Noughts and Crosses," is a classic two-player game played
on a 3x3 grid. The objective of the game is to be the first to get three of your symbols
(either 'X' or 'O') in a row, column, or diagonal. It is a simple yet engaging game that can
be implemented using Arduino.

**COMPONENTS USED**
Arduino Nano
Description: The Arduino Nano is a compact microcontroller board based on the
ATmega328P. It serves as the brain of the Tic-Tac-Toe game, handling game logic and
interfacing with other components.
Specifications: It features 14 digital input/output pins, 8 analog inputs, a 16 MHz crystal
oscillator, and a mini-USB port for programming and power supply.

Liquid Crystal Display (LCD)
Description: The Liquid Crystal Display (LCD) is used to visually represent the
Tic-Tac-Toe game board and display game-related information.
Specifications: The LCD used in this project is a 20x4 character display with a standard
HD44780 controller. It has four rows and 20 columns.

Push Buttons (9)
Description: Nine push buttons are used as input devices for players to make moves on
the Tic-Tac-Toe board.
Specifications: The buttons are connected to the Arduino's digital pins

**WORKING AND CONNECTIONS**
Working:
● On starting the simulation, you are asked to enter the number of rounds (from 1-3
and each button on the top row correspond to the numbers from 1 to 3)
● Then player 1 (X) starts the game and goes on till either player 1 or player 2 (O)
win or its a draw.
● Similarly, this goes on till the number of rounds come to an end
● In the end, the result is displayed on the LCD with the number of wins of player 1
and player 2 and the winner.

Connections:
Arduino Nano:
Power (VCC and GND): The Arduino Nano is powered by connecting the VCC and
GND (ground) pins to the power supply.
Digital Pins (D2 to D7): These digital pins are used to establish data connections with
the Liquid Crystal Display (LCD). They are connected to the corresponding data pins
(D4 to D7) on the LCD.
Digital Pins (D8 to D10): These digital pins are connected to the push buttons for the top
row of the game board.
Digital Pins (D11 to D13): These digital pins are connected to the push buttons for the
middle row of the game board.
Analog Pins (A0, A1, A2): These analog pins are connected to the push buttons for the
bottom row of the game board.
Liquid Crystal Display (20x4):
Power (VCC and GND): The LCD is powered by connecting the VCC and GND pins to
the power supply.
Control Pins (RS and EN): The RS (Register Select) and EN (Enable) pins are used to
control the LCD. They are connected to the corresponding digital pins (D2 and D3) on
the Arduino Nano.
Data Pins (D4 to D7): These pins are used to send data to the LCD for displaying
characters. They are connected to the corresponding digital pins (D4 to D7) on the
Arduino Nano.
Push Buttons (9):
Each of the nine push buttons represents a cell on the Tic-Tac-Toe game board.
Top Row (D8, D9, D10): These digital pins on the Arduino Nano are connected to the
push buttons in the top row.
Middle Row (D11, D12, D13): These digital pins on the Arduino Nano are connected to
the push buttons in the middle row.
Bottom Row (A0, A1, A2): These analog pins on the Arduino Nano are connected to the
push buttons in the bottom row.
Each button press connects the corresponding button pin to the ground (GND) of the
Arduino, indicating a player's move in that cell.
These connections enable the Arduino Nano to read player inputs from the push
buttons and update the game board displayed on the LCD.
