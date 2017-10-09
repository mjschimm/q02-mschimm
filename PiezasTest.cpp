/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


TEST(PiezasTest0, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.dropPiece(0), X);
}

TEST(PiezasTest01, SanityCheck)
{
	Piezas board;
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), O);
}

TEST(PiezasTest02, SanityCheck)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_EQ(board.dropPiece(0), X);
}

TEST(PiezasTest03, SanityCheck)
{
	Piezas board;
	board.dropPiece(0); //X
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	ASSERT_EQ(board.dropPiece(0), Blank); //Invalid
}

TEST(PiezasTest04, SanityCheck)
{
	Piezas board;
	board.dropPiece(0); //X
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	board.dropPiece(0); //Invalid
	ASSERT_EQ(board.dropPiece(1), X); //X
}

TEST(PiezasTest05, SanityCheck)
{
	Piezas board;
	board.dropPiece(1); //X
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	board.dropPiece(0); //O
	ASSERT_EQ(board.dropPiece(0), Blank); //Invalid
}

TEST(PiezasTest06, SanityCheck)
{
	Piezas board;
	board.dropPiece(1); //X
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	board.dropPiece(0); //O
	ASSERT_EQ(board.dropPiece(0), Blank); //Invalid
}

TEST(PiezasTest07, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.gameState(), Invalid);
}

TEST(PiezasTest08, SanityCheck)
{
	Piezas board;
	board.dropPiece(0); //X
	board.dropPiece(0); //O
	board.dropPiece(1); //X
	board.dropPiece(0); //O
	board.dropPiece(2); //X
	board.dropPiece(1); //O
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	board.dropPiece(2); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	
	ASSERT_EQ(board.gameState(), X); //Invalid
}

TEST(PiezasTest09, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.dropPiece(-4), Invalid);
}

TEST(PiezasTest10, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.dropPiece(4), Invalid);
}

TEST(PiezasTest11, SanityCheck)
{
	Piezas board;
	board.dropPiece(4);
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(0); //X
	board.dropPiece(2); //O
	board.dropPiece(1); //X
	board.dropPiece(3); //O
	board.dropPiece(3); //X
	board.dropPiece(2); //O
	board.dropPiece(1); //X
	board.dropPiece(2); //O
	board.dropPiece(3); //X
	ASSERT_EQ(board.gameState(), O); //Invalid
}

TEST(PiezasTest12, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(0, 0), Blank);
}

TEST(PiezasTest13, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(4, 0), Invalid);
}

TEST(PiezasTest14, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(0, 4), Invalid);
}

TEST(PiezasTest15, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(-4, 0), Invalid);
}

TEST(PiezasTest16, SanityCheck)
{
	Piezas board;
	ASSERT_EQ(board.pieceAt(0, -1), Invalid);
}

TEST(PiezasTest17, SanityCheck)
{
	Piezas board;
	board.dropPiece(3); //X
	ASSERT_EQ(board.pieceAt(0, 3), X);
}

TEST(PiezasTest18, SanityCheck)
{
	Piezas board;
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	ASSERT_EQ(board.pieceAt(1, 3), O);
}

TEST(PiezasTest19, SanityCheck)
{
	Piezas board;
	board.dropPiece(0); //X
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(1); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(2); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	
	ASSERT_EQ(board.gameState(), Blank); //Invalid
}

TEST(PiezasTest20, SanityCheck)
{
	Piezas board;
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(0); //X
	board.dropPiece(2); //O
	board.dropPiece(0); //X
	board.dropPiece(2); //O
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	board.dropPiece(1); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	
	ASSERT_EQ(board.gameState(), X); //X
}

TEST(PiezasTest21, SanityCheck)
{
	Piezas board;
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(0); //X
	board.dropPiece(2); //O
	board.dropPiece(0); //X
	board.dropPiece(2); //O
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	board.dropPiece(1); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	board.reset();
	ASSERT_EQ(board.gameState(), Invalid); //Invalid
}

TEST(PiezasTest22, SanityCheck)
{
	Piezas board;
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(0); //X
	board.dropPiece(2); //O
	board.dropPiece(0); //X
	board.dropPiece(2); //O
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	board.dropPiece(1); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	board.reset();
	ASSERT_EQ(board.pieceAt(0, 1), Blank); //Invalid
}