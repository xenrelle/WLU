#include "Board.h"

enum EDifficulty {
	BEGINNER,
	INTERMEDIATE,
	ADVANCED
}

enum SquareType {
	unk0,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Uncovered,
	Flagged,
	unk11,
	Empty
}

Board::Board(EDifficulty difficulty, int width, int height, int mines, uint randSeed, int firstXClickPos, int firstYClickPos, bool b0) {
	//this->vftable = void*;
	this->vftable = void*;
	int r12 = 0; // xor r12d, r12d effectively just zeroes out the register
	this->unk_0x38 = 0; // r12d
	this->unk_0x3C = 0; // r12d
	this->unk_0x38 = 0; // r12d
	this->unk_0x40 = 0x10; // r13d
	this->unk_0x48 = 0; // r12
	this->flagsPlaced = 0; // r12d
	this->timeElapsed = 0; // r12d
	this->revealedSquares = 0; // r12d
	this->revealsAttempted = 0; // r12d
	this->boardTiles = nullptr; // r12
	this->boardMines = nullptr; // r12
	this->unk_0x48 = 0; // r12
	this->difficulty = difficulty;
	this->mines = mines;
	this->height = height;
	this->width = width;
	this->randSeed = randSeed;
	this->firstXClickPos = firstXClickPos;
	this->firstYClickPos = firstYClickPos;

	uint8_t* boardTilePtr = (uint8_t*)malloc(0x18);
	if (boardTilePtr) {
		*(uint32_t*)(boardTilePtr) = 0;
		*(uint32_t*)(boardTilePtr + 0x4) = 0;
		*(uint32_t*)(boardTilePtr + 0x8) = 0x10;
		*(uint64_t*)(boardTilePtr + 0x10) = 0;
	} else {
		boardTilePtr = 0;
	}

	this->boardTiles = boardTilePtr;

	int v11 = 0;
	if (this->width > 0) {
		int v12 = 0;
		do {
			uint8_t* v13 = (uint8_t*)malloc(0x18);
			if (v13) {
				*(uint32_t*)(v13) = 0;
				*(uint32_t*)(v13 + 0x4) = 0;
				*(uint32_t*)(v13 + 0x8) = 0x10;
				*(uint64_t*)(v13 + 0x10) = 0;
			} else {
				v13 = 0;
			}
			Array<IEventListener *>::Add(this->boardTiles, v13);
			for (int i = 0; i < this->height; ++i) {
				Array<enum NodeType>::Add(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 80) + 16i64) + v12), 9i64, v14, v15);
			}
			++v11;
			v12 += 8i64;
		} while (v11 < this->width);
	}
}

void ToXML(void* serialXML) {
	//code here
}
void FromXML(void* XML, const void* XMLNode) {
	//code here
}
void Update(float f0, void* UIBoardCanvas) {
	//code here
}
void FinishAnimations(void* UIBoardCanvas) {
	//code here
}
void StartAlphaAnimation(int i0, int i1, float f0, bool b0) {
	//code here
}
void AttemptReveal(int i0, int i1) {
	//code here
}
unsigned int getSurroundingFlagCount(int x, int y) {
	// REALLY gross machine code translation but i'll clean it up soon
	if (x - 1 > x + 1) {
		return 0;
	}

	int minXRange = x - 1;
	int maxXRange = x + 1;
	int minYRange = y - 1;
	int maxYRange = y + 1;
	unsigned int flagCount = 0;

	__int64 v6 = y;
	__int64 v7 = x - 1;
	__int64 v8 = x;
	int v11;

	do {
		v11 = minYRange;
		for (int i = v6 - 1; v11 <= maxYRange; ++i) {
			if (v7 >= 0 && minXRange < *((int32_t*)this + 4) && i >= 0 && v11 < *((int32_t*)this + 3) && (v7 != v8 || i != v6) && *(int32_t*)(*(int64_t*)(*(int64_t*)(*(int64_t*)(*((int64_t*)this + 10) + 16i64) + 8 * v7) + 16i64) + 4 * i) == 10) {
				++flagCount;
			}
			++v11;
		}
		++minXRange; ++v7;
	} while (minXRange <= maxXRange);

	return flagCount;
}
/*
__int64 __fastcall Board::getSurroundingFlagCount(Board *this, int a2, int a3)
{
  int v3; // er9
  int v4; // esi
  unsigned int v5; // er11
  __int64 v6; // rbp
  __int64 v7; // r10
  __int64 v8; // r14
  int v9; // er12
  int v10; // edi
  int v11; // edx
  __int64 i; // r8

  v3 = a2 - 1;
  v4 = a2 + 1;
  v5 = 0;
  v6 = a3;
  v7 = a2 - 1;
  v8 = a2;
  if ( a2 - 1 <= a2 + 1 )
  {
    v9 = a3 - 1;
    v10 = a3 + 1;
    do
    {
      v11 = v9;
      for ( i = v6 - 1; v11 <= v10; ++i )
      {
        if ( v7 >= 0
          && v3 < *((_DWORD *)this + 4)
          && i >= 0
          && v11 < *((_DWORD *)this + 3)
          && (v7 != v8 || i != v6)
          && *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 10) + 16i64) + 8 * v7) + 16i64) + 4 * i) == 10 )
        {
          ++v5;
        }
        ++v11;
      }
      ++v3;
      ++v7;
    }
    while ( v3 <= v4 );
  }
  return v5;
}
*/
void validateSurroundingFlags(int x, int y) {
	//code here
}
void freeRes() {
	//code here
}
void placeMines(int i0, int i1) {
	//code here
}
void revealAt(int i0, int i1, int i2, int i3, int i4, int i5) {
	//code here
}
void attemptRevealStatus(int i0, int i1) {
	//code here
}
void GetNumTilesActuallyPlayed() {
	//code here
}
void Validate() {
	//code here
}