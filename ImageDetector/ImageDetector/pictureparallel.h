#ifndef _PICTUREPARALLEL_H_
#define _PICTUREPARALLEL_H_

#pragma once

#include "bitmap_image.hpp"
#include <vector>
#include <algorithm>

class PictureParallel
{
public:
	PictureParallel();
	PictureParallel(string path);
	virtual ~PictureParallel();

	void initialize();

	void parsePath(string path);
	void loadPicture();
	void savePicture(string season);
	void savePicture();
	void createHistogram();
	void fillHistogram(unsigned char color, int iter, float &arrScope);
	void normalizeHistogram();

	float* getScope();

	void setName(string name) { _name = name; }
	string getName() { return _name; }

	void setPath(string path) { _path = path; }
	string getPath() { return _path; }

	void setFullPath(string fullPath) { _fullPath = fullPath; }
	string getFullPath() { return _fullPath; }

	void setResultPath(string resultPath = "results/") { _resultPath = resultPath; }
	string getResultPath() { return _resultPath; }

	void setExtension(string extension) { _extension = extension; }
	string getExtension() { return _extension; }

	void setSeason(string season = "none") { _season = season; }
	string getSeason() { return _season; }

	vector<float>* getHistogram() { return _histogram; }

private:
	string _name;
	string _extension;
	string _path;
	string _fullPath;
	string _resultPath;

	string _season;

	bitmap_image _image;

	vector<float> _histogram[3];
};

#endif // _PICTUREPARALLEL_H_