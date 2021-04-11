#include <vector>
#include <ctime>
using namespace std;

void sortInsert(vector <int>& tmpVector) //Сортировка вставками, эффективена при малом количестве элементов
{
	for (size_t i = 1; i < tmpVector.size(); ++i)
	{
		for (int b = i; b > 0 && tmpVector.at(b) < tmpVector.at(b - 1); --b)
		{
			swap(tmpVector.at(b), tmpVector.at(b - 1));
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void merge(vector <int>& tmpVector, int start, int end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (tmpVector[start] > tmpVector[start + 1])
            swap(tmpVector[start], tmpVector[start + 1]);
        return;
    }
    merge(tmpVector, start, start + (end - start) / 2);
    merge(tmpVector, start + (end - start) / 2, end);
    vector<int> b;
    size_t b1 = start;
    size_t e1 = start + (end - start) / 2;
    size_t b2 = e1;
    while (b.size() < end - start)
    {
        if (b1 >= e1 || (b2 < end && tmpVector[b2] < tmpVector[b1]))
        {
            b.push_back(tmpVector[b2]);
            ++b2;
        }
        else
        {
            b.push_back(tmpVector[b1]);
            ++b1;
        }
    }
    for (size_t i = start; i < end; ++i)
        tmpVector[i] = b[i - start];
}

void sortMerge(vector <int>& tmpVector) //Сортировка слиянием
{
	merge(tmpVector, 0, tmpVector.size());
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fillVector(vector <int>& tmpVector, const int size)
{
	for (int i = 0; i < size; ++i) tmpVector.push_back(rand() % 100);
}

int main()
{
	srand(time(NULL));
	vector <int> tmpVector1, tmpVector2;
	fillVector(tmpVector1, 10);
	fillVector(tmpVector2, 15);
	sortMerge(tmpVector1);
	//sortInsert(tmpVector1);
	//sortInsert(tmpVector2);
	return 0;
}
