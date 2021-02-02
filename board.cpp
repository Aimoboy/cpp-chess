#include "board.h"
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>

Board::Board() {
    SetFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
;}

void Board::SetFEN(std::string fen) {
    if (ValidateFEN(fen))
        throw "Not valid FEN";

    std::reverse(fen.begin(), fen.end());

    int i = 0;
    int pos = 0;
    while (i < (int)fen.size()) {
        if (fen[i] == '/') {
            i++;
            continue;
        }

        switch (fen[i]) {
            case 'p':
                BP += 1L << pos;
                break;
            case 'r':
                BR += 1L << pos;
                break;
            case 'n':
                BN += 1L << pos;
                break;
            case 'b':
                BB += 1L << pos;
                break;
            case 'q':
                BQ += 1L << pos;
                break;
            case 'k':
                BK += 1L << pos;
                break;
            case 'P':
                WP += 1L << pos;
                break;
            case 'R':
                WR += 1L << pos;
                break;
            case 'N':
                WN += 1L << pos;
                break;
            case 'B':
                WB += 1L << pos;
                break;
            case 'Q':
                WQ += 1L << pos;
                break;
            case 'K':
                WK += 1L << pos;
                break;
            default:
                pos += fen[i] - 48 - 1;
                break;
        }

        pos++;
        i++;
    }
}

int Board::ValidateFEN(std::string fen) {
    std::regex re("[prnbqkPRNBQK1-8]+/[prnbqkPRNBQK1-8]+/[prnbqkPRNBQK1-8]+/[prnbqkPRNBQK1-8]+/[prnbqkPRNBQK1-8]+/[prnbqkPRNBQK1-8]+/[prnbqkPRNBQK1-8]+/[prnbqkPRNBQK1-8]+");
    std::cmatch m;

    if (!std::regex_match(&fen[0], m, re))
        return -1;

    int count = 0;
    for (char c : fen) {
        switch (c) {
            case 'p':
            case 'r':
            case 'n':
            case 'b':
            case 'q':
            case 'k':
            case 'P':
            case 'R':
            case 'N':
            case 'B':
            case 'Q':
            case 'K':
                count++;
                break;
            case '/':
                if (count != 8)
                    return -1;
                count = 0;
                break;
            default:
                count += c - 48;
                break;
        }
    }

    if (count != 8)
        return -1;

    return 0;
}

char Board::GetPieceChar(int chr, int num) {
    int pos = num * boardSize + chr;
    unsigned long posNum = 1L << pos;

    if ((BP & posNum) == posNum)
        return 'p';
    if ((BR & posNum) == posNum)
        return 'r';
    if ((BN & posNum) == posNum)
        return 'n';
    if ((BB & posNum) == posNum)
        return 'b';
    if ((BQ & posNum) == posNum)
        return 'q';
    if ((BK & posNum) == posNum)
        return 'k';
    if ((WP & posNum) == posNum)
        return 'P';
    if ((WR & posNum) == posNum)
        return 'R';
    if ((WN & posNum) == posNum)
        return 'N';
    if ((WB & posNum) == posNum)
        return 'B';
    if ((WQ & posNum) == posNum)
        return 'Q';
    if ((WK & posNum) == posNum)
        return 'K';

    return ' ';
}

std::ostream& operator<<(std::ostream& os, Board& board) {
    std::string str = "";

    str += "+---+---+---+---+---+---+---+---+\n";
    for (int i = board.boardSize - 1; i > -1; i--) {
        for (int j = board.boardSize - 1; j > -1; j--) {
            str += "| ";
            str += board.GetPieceChar(j, i);
            str += " ";
        }
        str += "|\n+---+---+---+---+---+---+---+---+\n";
    }

    return std::cout << str;
}
