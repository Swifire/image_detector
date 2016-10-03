#include "stdafx.h"
#include "picture.h"

using namespace std;

int main(void)
{
	Picture picture1("images/autumn_1.bmp");
	picture1.loadPicture();
	picture1.savePicture("autumn");
	return 0;
}

