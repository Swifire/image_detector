#pragma once

#include "picture.h"
#include <cmath>

class Checker
{
public:
	Checker();
	virtual ~Checker();

	void initialize();

	void loadAllPictures();
	void saveTestPictures();

	void createAVGHistograms();

	void checkPictures();
	string compareHistogram(vector<float>* histogram);
private:
	void loadSeasonPictures();
	void loadTestPictures();

	Picture* _seasonPictures[12];
	Picture* _testPictures[4];

	vector<float> _avgHistogram[3][4];
};

