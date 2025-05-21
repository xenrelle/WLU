#ifndef BOARD_H
#define BOARD_H

class Board {
public:
	// info taken from 0x00000001000262D8 in Minesweeper.exe
	uint64_t* vftable; // 0x0
	int32_t mines; // 0x8
	int32_t height; // 0xC
	int32_t width; // 0x10
	int32_t flagsPlaced; // 0x14
	int32_t revealedSquares; // 0x18
	int32_t revealsAttempted; // 0x1C
	int32_t timeElapsed; // 0x20 (?)
	int32_t difficulty; // 0x24
	int32_t firstXClickPos; //0x28
	int32_t firstYClickPos; //0x2C
	uint32_t randSeed; //0x30
	uint32_t unk_0x34;
	uint32_t unk_0x38;
	uint32_t unk_0x3C;
	uint32_t unk_0x40;
	uint32_t unk_0x44;
	uint32_t unk_0x48;
	uint32_t unk_0x4C;
	uint64_t* boardTiles; // 0x50, unknown type but likely a pointer
	uint64_t* boardMines; // 0x58, unknown type but likely a pointer

	Board(EDifficulty difficulty, int width, int height, int mines, uint randSeed, int firstXClickPos, int firstYClickPos, bool b0);

	void ToXML(void* serialXML);
	void FromXML(void* XML, const void* XMLNode);
	void Update(float f0, void* UIBoardCanvas);
	void FinishAnimations(void* UIBoardCanvas);
	void StartAlphaAnimation(int i0, int i1, float f0, bool b0);
	void AttemptReveal(int i0, int i1);
	unsigned int getSurroundingFlagCount(int x, int y);
	void validateSurroundingFlags(int x, int y);
	void freeRes();
	void placeMines(int i0, int i1);
	void revealAt(int i0, int i1, int i2, int i3, int i4, int i5);
	void attemptRevealStatus(int i0, int i1);
	void GetNumTilesActuallyPlayed();
	void Validate();
};

#endif