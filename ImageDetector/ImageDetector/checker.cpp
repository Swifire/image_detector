#include "stdafx.h"
#include "checker.h"


Checker::Checker()
{
	initialize();
}

void Checker::initialize()
{
	for (int i = 0; i < 4; i++)
	{
		_avgHistogram[i].reserve(10);
	}

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 10; col++)
		{
			_avgHistogram[row].push_back(0);
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

	string testName;
	 
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

Checker::~Checker(){}
