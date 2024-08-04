#include "pch.h"
#include "AnimationMgr.h"

TimeEvent* MakeTimeEvent(RtWeakPtr<GameObject>* owner, SexyString* eventName) {
	typedef TimeEvent* (*makeTimeEvent)(RtWeakPtr<GameObject>*, SexyString*);
	return ((makeTimeEvent)getActualOffset(0x326D24))(owner, eventName); // Edited by jkn
}

MoveBoard* MakeMoveBoard(float duration, int startX, int endX, int startY, int endY, int curveType) {
	typedef MoveBoard* (*getMoveBoard)(float, int, int, int, int, int);
	return ((getMoveBoard)getActualOffset(0x326CC8))(2.5, startX, endX, startY, endY, 4); // Edited by jkn
}

void GetStartXAndEndX(int type, int& startX, int& endX) {
	typedef void (*getStartAndEnd)(int, int*, int*);
	((getStartAndEnd)getActualOffset(0x665614))(type, &startX, &endX); // Edited by jkn
}

