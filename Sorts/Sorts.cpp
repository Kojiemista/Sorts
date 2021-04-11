#include <vector>
#include <ctime>
using namespace std;

void sortInsert(vector <int>& tmpVector) //Сортировка вставками, эффективен при малом количестве элементов
{
	for (size_t i = 1; i < tmpVector.size(); ++i)
	{
		for (int b = i; b > 0 && tmpVector.at(b) < tmpVector.at(b - 1); --b)
		{
			swap(tmpVector.at(b), tmpVector.at(b - 1));
		}
	}
}

void sortMerge(vector <int>& tmpVector)
{

}

void fillVector(vector <int>& tmpVector, const int &size)
{
	for (int i = 0; i < size; ++i) tmpVector.push_back(rand() % 100);
}

int main()
{
	srand(time(NULL));
	const int size = 10;
	vector <int> tmpVector1, tmpVector2;
	fillVector(tmpVector1, size);
	fillVector(tmpVector2, size);
	sortInsert(tmpVector1);
	sortInsert(tmpVector2);
	return 0;
}
