# Tic-Tac-Toe-in-Arduino-Nano

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

● On starting the simulation, you are asked to enter the number of rounds (from 1-3
and each button on the top row correspond to the numbers from 1 to 3)

● Then player 1 (X) starts the game and goes on till either player 1 or player 2 (O)
win or its a draw.

● Similarly, this goes on till the number of rounds come to an end

● In the end, the result is displayed on the LCD with the number of wins of player 1
and player 2 and the winner.

