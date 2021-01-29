#pragma once

class Piece {
public:
    enum PieceType : char { Pawn, Rook, Knight, Bishop, Queen, King };
    enum PieceColor : char { White, Black };

    Piece(PieceType type, PieceColor color);

private:
    PieceType type;
    PieceColor color;
};
