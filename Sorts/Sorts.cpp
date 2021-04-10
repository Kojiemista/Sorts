#include <vector>
#include <ctime>
using namespace std;

void fillVector(vector <int>& tmpVector, const int &size)
{
	for (int i = 0; i < size; ++i) tmpVector.push_back(rand() % 100);
}

int main()
{
	srand(time(NULL));
	const int size = 10000;
	vector <int> tmpVector;
	fillVector(tmpVector, size);
	return 0;
}
