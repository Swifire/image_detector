#include "stdafx.h"
#include "checker.h"

#include <windows.h>

using namespace std;

int main(void)
{
	double start = GetTickCount();

	Checker checker;
	checker.loadAllPictures();
	checker.checkPictures();

	double finish = GetTickCount();

	cout << finish - start << "\n";
	return 0;
}

