#pragma once

#include "picture.h"

class Checker
{
public:
	Checker();
	virtual ~Checker();

	void initialize();

	void loadAllPictures();
	void saveTestPictures();
private:
	void loadSeasonPictures();
	void loadTestPictures();

	Picture* _seasonPictures[12];
	Picture* _testPictures[4];

	vector<float> _avgHistogram[4];
};

