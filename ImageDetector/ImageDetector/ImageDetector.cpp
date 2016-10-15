#include "stdafx.h"
#include "checkerparallel.h"

#include <windows.h>

using namespace std;

int main(void)
{
	omp_set_num_threads(2);
	double start = GetTickCount();
	CheckerParallel checker;
	checker.loadAllPictures();
	checker.checkPictures();

	double finish = GetTickCount();

	cout << finish - start << "\n";
	return 0;
}

