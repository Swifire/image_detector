#include "stdafx.h"
#include "picture.h"

using namespace std;

int main(void)
{
	Picture picture1("images/autumn_1.bmp");
	picture1.loadPicture();
	vector<float>* histogram = picture1.getHistogram();

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < histogram[row].size(); col++)
		{
			cout << histogram[row][col] << "  ";
		}
		cout << "\n";
	}
	//picture1.savePicture("autumn");
	return 0;
}

