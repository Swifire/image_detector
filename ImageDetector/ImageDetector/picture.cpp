#include "stdafx.h"
#include "picture.h"


Picture::Picture() {}

Picture::Picture(string path) 
{
	initialize();
	parsePath(path);
	setSeason();
	setResultPath();
}

void Picture::initialize()
{
	for (int i = 0; i < 3; i++)
	{
		_histogram[i].reserve(10);
	}

	for (int row = 0; row < 3; row++) 
	{
		for (int col = 0; col < 10; col++) 
		{
			_histogram[row].push_back(0);
		}
	}
}

void Picture::parsePath(string path)
{
	vector<string> arrPath;
	string delim("/");
	size_t prev = 0;
	size_t next;
	size_t delta = delim.length();

	_fullPath = path;

	while ((next = path.find(delim, prev)) != string::npos)
	{
		arrPath.push_back(path.substr(prev, next - prev));
		prev = next + delta;
	}

	for (int i = 0; i < arrPath.size(); i++)
	{
		_path += arrPath.at(i) + "/";
	}

	delim = ".";

	next = path.find(delim, prev);

	_name = path.substr(prev, next - prev);

	prev = next + delta;

	_extension = path.substr(prev, next - prev);
}

void Picture::loadPicture()
{
	bitmap_image image(_fullPath);

	unsigned int w = image.width();
	unsigned int h = image.height();

	image.region(0, 0, w, h, _image);

	normalizeHistogram();
}

void Picture::savePicture(string season)
{
	setSeason(season);
	string newPath = _resultPath + _name + "_" + _season + "." + _extension;
	_image.save_image(newPath);
}

void Picture::savePicture()
{
	string newPath = _resultPath + _name + "_" + _season + "." + _extension;
	_image.save_image(newPath);
}

float* getScope()
{
	int maxColors = 255;
	int intervals = 10;
	int step = maxColors / intervals;
	float* arrScope = new float[10];

	for (int i = 0; i < 10; i++)
	{
		arrScope[i] = i * step;
	}

	return arrScope;
}

void Picture::fillHistogram(unsigned char color, int iter, float& arrScope)
{
	float* arrMyScope = &arrScope;

	for (int i = 9; i >= 0; i--)
	{
		if (color >= arrMyScope[i])
		{
			_histogram[iter][i]++;
			break;
		}
	}
}

void Picture::createHistogram()
{
	const unsigned int width = _image.width();
	const unsigned int height = _image.height();
	unsigned char red, green, blue;

	float* arrScope = getScope();

	for (size_t y = 0; y < height; ++y)
	{
		for (size_t x = 0; x < width; ++x)
		{
			_image.get_pixel(x, y, red, green, blue);
			fillHistogram(red, 0, *arrScope);
			fillHistogram(green, 1, *arrScope);
			fillHistogram(blue, 2, *arrScope);
		}
	}
}

void Picture::normalizeHistogram()
{
	createHistogram();

	for (int i = 0; i < 3; i++)
	{
		float max = *max_element(_histogram[i].begin(), _histogram[i].end());
		for (int j = 0; j < 10; j++)
		{
			_histogram[i][j] = _histogram[i][j] / max;
		}
	}
}

Picture::~Picture() {}