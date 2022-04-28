# include "samples.h"

using namespace Mathplus;
using namespace std;


int main()
{
	clock_t ts = clock();
	int ret = Sample1_IntAdd();
	cout << "Time: " << (clock() - ts + 0.00) / CLOCKS_PER_SEC << endl;
	return ret;
}