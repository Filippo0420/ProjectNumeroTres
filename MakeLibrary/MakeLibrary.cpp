// MakeLibrary.cpp : Defines the entry point for the application.
//

#include "MakeLibrary.h"

using namespace std;
namespace plt = matplotlibcpp;
int main()
{
	plt::plot({ 1,2,3,4 }, "*");
	plt::show();
	return 0;
}
