#include "stdafx.h"
#include "picture.h"


Picture::Picture() {}

Picture::Picture(string path) 
{
	parsePath(path);
}

void Picture::parsePath(string path)
{
	vector<string> arrPath;
	string delim("/");
	size_t prev = 0;
	size_t next;
	size_t delta = delim.length();

	_fullPath = path;

	while ((next = path.find(delim, prev)) != string::npos){
		arrPath.push_back(path.substr(prev, next - prev));
		prev = next + delta;
	}

	for (int i = 0; i < arrPath.size(); i++)
	{
		_path = arrPath.at(i) + "/";
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
}

void Picture::savePicture(string season)
{
	string newPath = _path + _name + "_" + season + "." + _extension;
	_image.save_image(newPath);
}

Picture::~Picture() {}