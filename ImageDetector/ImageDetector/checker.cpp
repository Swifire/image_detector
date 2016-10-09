#include "stdafx.h"
#include "checker.h"


Checker::Checker()
{
	initialize();
}

void Checker::initialize()
{
	for (int i = 0; i < 3; i++)
	{
		for (int row = 0; row < 4; row++)
		{
			_avgHistogram[i][row].reserve(10);

			for (int col = 0; col < 10; col++)
			{
				_avgHistogram[i][row].push_back(0);
			}
		}
	}
}

string getSeasonByNumber(int num)
{
	string seasonName;

	switch (num)
	{
		case 0:
			seasonName = "autumn";
			break;
		case 1:
			seasonName = "spring";
			break;
		case 2:
			seasonName = "summer";
			break;
		case 3:
			seasonName = "winter";
			break;
		default:
			seasonName = "None";
			break;
	}

	return seasonName;
}

void Checker::loadSeasonPictures()
{
	string pathSeasonPictures[12] =
	{
		"images/autumn_1.bmp", "images/autumn_2.bmp", "images/autumn_3.bmp",
		"images/spring_1.bmp", "images/spring_2.bmp", "images/spring_3.bmp",
		"images/summer_1.bmp", "images/summer_2.bmp", "images/summer_3.bmp",
		"images/winter_1.bmp", "images/winter_2.bmp", "images/winter_3.bmp"
	};

	string seasonName;

	for (int i = 0; i < 4; i++)
	{
		for (int j = i * 3; j < i * 3 + 3; j++)
		{
			_seasonPictures[j] = new Picture(pathSeasonPictures[j]);
			_seasonPictures[j]->loadPicture();

			seasonName = getSeasonByNumber(i);
			_seasonPictures[j]->setSeason(seasonName);
		}
	}
}

void Checker::loadTestPictures()
{
	string pathTestPictures[4] =
	{
		"images/autumn_test_1.bmp",
		"images/spring_test_1.bmp",
		"images/summer_test_1.bmp",
		"images/winter_test_1.bmp"
	};

	for (int i = 0; i < 4; i++)
	{
		_testPictures[i] = new Picture(pathTestPictures[i]);
		_testPictures[i]->loadPicture();
	}
}

void Checker::loadAllPictures()
{
	loadTestPictures();
	loadSeasonPictures();
}

void Checker::saveTestPictures()
{
	for (int i = 0; i < 4; i++)
	{
		_testPictures[i]->savePicture();
	}
}

void Checker::createAVGHistograms()
{
	vector<float>* avg[3];

	for (int i = 0; i < 3; i++)
	{
		avg[i] = new vector<float>(10);
	}

	for (int i = 0; i < 4; i++)
	{
		int iter = 0;
		for (int j = i * 3; j < i * 3 + 3; j++)
		{
			avg[iter] = _seasonPictures[j]->getHistogram();
			iter++;
		}

		for (int row = 0; row < 3; row++)
		{
			for (int d3 = 0; d3 < 10; d3++)
			{
				float sum = avg[0][row][d3] + avg[1][row][d3] + avg[2][row][d3];
				_avgHistogram[row][i][d3] = sum / 3;
			}
		}
	}	
}

int getMinIterator(float* results)
{
	int minIterator = 0;
	float min = results[0];

	for (int i = 1; i < 4; i++)
	{
		if (results[i] < min)
		{
			min = results[i];
			minIterator = i;
		}
	}

	return minIterator;
}

string Checker::compareHistogram(vector<float>* histogram)
{
	float results[4];
	float value = 0.0;
	float color = 0.0;

	for (int col = 0; col < 4; col++)
	{
		color = 0.0;
		for (int row = 0; row < 3; row++)
		{
			value = 0.0;
			for (int d3 = 0; d3 < 10; d3++)
			{
				value += abs(_avgHistogram[row][col][d3] - histogram[row][d3]);
			}
			color += value;
		}
		results[col] = color;
	}

	int minIterator = getMinIterator(results);

	return getSeasonByNumber(minIterator);
}

void Checker::checkPictures()
{
	createAVGHistograms();

	string testSeasonName;

	vector<float>* avg = new vector<float>(10);
	for (int i = 0; i < 4; i++)
	{
		avg = _testPictures[i]->getHistogram();
		testSeasonName = compareHistogram(avg);
		_testPictures[i]->setSeason(testSeasonName);
	}

	saveTestPictures();
}

Checker::~Checker(){}
