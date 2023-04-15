# task-2-noammirjani

Chess Game
This is a C++ implementation of a chess game. The game follows standard chess rules, with two players taking turns to move their pieces on a board. The game can be played in a terminal window.

Getting Started
To run the game, you will need to have a C++ compiler installed on your machine. Once you have the compiler installed, clone the repository to your local machine and navigate to the project directory.

To start the game, run the main.cpp file in your terminal or compile the code using your C++ compiler.

Playing the Game
To make a move, you will need to enter the starting and ending coordinates of the piece you want to move. The coordinates should be entered in the following format: a1b3, where a1 is the starting coordinate and b3 is the ending coordinate.

If your move is valid, the game will update the board with your move and switch to the other player's turn. If your move is invalid, you will receive an error message and be prompted to enter a new move.

The game ends when one player puts the other player's king in checkmate. At that point, the winning player will be declared.

Project Structure
The project is structured as follows:

Board.h: This file contains the Board class, which represents the chess board.
Piece.h: This file contains the Piece class, which represents a chess piece.
PieceFactory.h: This file contains the PieceFactory class, which is responsible for creating instances of Piece.
Pawn.h, Knight.h, Bishop.h, Rook.h, Queen.h, King.h: These files contain the classes that represent the different types of chess pieces.
main.cpp: This file contains the main function, which is responsible for running the game.
Acknowledgements
This game was created by [your name here] as part of [course name here] at [university/school name here].