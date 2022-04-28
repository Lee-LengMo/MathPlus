# include <thread>
# include <iomanip>
# include "samples.h"

using namespace Mathplus;
using namespace std;

static bool SpeedTest_Int_end = false;
static bool SpeedTest_Ull_end = false;

int SpeedTest_Int(Int a, Int b, unsigned int times)
{
	clock_t s = clock();

	for (unsigned int i = 0; i < times; i++)
		Int c = a + b;
	
	cout << "Int Finished! Time:" << (clock() - s + 0.00) / CLOCKS_PER_SEC << endl;
	SpeedTest_Int_end = true;
	return 0;
}

int SpeedTest_Ull(unsigned long long a, unsigned long long b, unsigned int times)
{

	clock_t s = clock();

	for (unsigned int i = 0; i < times; i++)
		unsigned long long c = a + b;

	cout << "Unsigned long long Finished! Time:" << (clock() - s + 0.00) / CLOCKS_PER_SEC << endl;
	SpeedTest_Ull_end = true;
	return 0;
}

int Sample1_IntAdd()
{
	// Simple Add(Int)
	Int a, b, c;
	cin >> a >> b;
	c = (a + b);
	cout << a << " + " << b << " = " << c << endl;
	cout << a << ((a > b) ? " is greater than " : "is not greater than ") << b << endl;
	// Speed test (Int&Unsigned long long)
	setprecision(10);
	thread IntT(SpeedTest_Int, 7389257982374552374, 9420394082384274925, 200000);
	thread UllT(SpeedTest_Ull, 7389257982374552374, 9420394082384274925, 200000);
	IntT.detach();
	UllT.detach();

	while ((!SpeedTest_Int_end)||(!SpeedTest_Ull_end));

	return 0;
}
