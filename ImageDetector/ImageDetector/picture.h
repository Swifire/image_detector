#pragma once

#include "bitmap_image.hpp"
#include <vector>

class Picture
{
public:
	Picture();
	Picture(string path);
	virtual ~Picture();

	void loadPicture();
	void savePicture(string season);
	void parsePath(string path);

	void setName(string name) { _name = name; }
	string getName() { return _name; }

	void setPath(string path) { _path = path; }
	string getPath() { return _path; }

	void setFullPath(string fullPath) { _fullPath = fullPath; }
	string getFullPath() { return _fullPath; }

	void setExtension(string extension) { _extension = extension; }
	string getExtension() { return _extension; }

	vector<int>* getRGB() { return _rgb; }

private:
	string _name;
	string _extension;
	string _path;
	string _fullPath;

	bitmap_image _image;

	vector<int> _rgb[3];
};

