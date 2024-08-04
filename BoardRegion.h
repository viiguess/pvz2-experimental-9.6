#pragma once

#include "GameObject.h"
#include "BoardEntity.h"

#define BOARDREGION_CONSTRUCT_ADDR 0x1062E84 // Edited by jkn
#define BOARDREGION_SETFLAG_ADDR 0x1062EC8 // Edited by jkn
#define BOARDREGION_VFTABLE_ADDR 0x1D0A534 // Edited by jkn
#define BOARDREGION_GETCLASS_ADDR 0x1062994 // Edited by jkn

class BoardRegionLandedEntity {
public:
	SexyVector3 coords;
	BoardEntity* entity;
};

enum BoardRegionFlags {
	region_deepwater = 1,
	region_tidewater = 2,
	region_sky = 4
};

class BoardRegion : public GameObject
{
public:
	int m_flags;
	FRect m_region;
	int unk;

	void SetRegionFlag(int flag) {
		typedef int (*sub1062EC8)(BoardRegion*, int); // Edited by jkn
		((sub1062EC8)getActualOffset(BOARDREGION_SETFLAG_ADDR))(this, flag);
	}

	virtual void Function13() { };
	virtual void OnParticleImpact() { };
	virtual void CanPlantGoHere(int* gridCoords, int plantType, std::vector<int>* reasonsVec) { };
	virtual float GetSinkDistance(float*) { };
	virtual void RunsEveryFrame() { };
};

