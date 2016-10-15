#pragma once

#include "pictureparallel.h"
#include <cmath>

class CheckerParallel
{
public:
	CheckerParallel();
	virtual ~CheckerParallel();

	void initialize();

	void loadAllPictures();
	void saveTestPictures();

	void createAVGHistograms();

	int getMinIterator(float* results);

	string getSeasonByNumber(int num);

	void checkPictures();
	string compareHistogram(vector<float>* histogram);
private:
	void loadSeasonPictures();
	void loadTestPictures();

	PictureParallel* _seasonPictures[12];
	PictureParallel* _testPictures[4];

	vector<float> _avgHistogram[3][4];
};
