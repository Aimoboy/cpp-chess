#pragma once
#include <string>

class Board {
private:
    static const int boardSize = 8;
    unsigned long WP = 0, WR = 0, WN = 0, WB = 0, WQ = 0, WK = 0, BP = 0, BR = 0, BN = 0, BB = 0, BQ = 0, BK = 0;

    void SetFEN(std::string fen);

    int ValidateFEN(std::string fen);

    char GetPieceChar(int chr, int num);

public:
    Board();

    friend std::ostream& operator<<(std::ostream& os, Board& board);
};
