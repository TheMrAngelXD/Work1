#include <iostream>
#include <ctime>
using namespace std;

int size;
int rand(const int size, double* values) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        values[i] = rand();
        cout << values[i] << endl;
    }
    return 0;
}
int maximum(const int size, const double* values) {
    double max = values[1];
    for (int i = 0; i < size; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    cout << "max = " << max << endl;
    return 0;
}

int main()
{
    cout << "n = ";
    int size;
    cin >> size;
    if (size <= 0) {
        throw std::out_of_range("Invalid size");
    }
    double* values;
    values = new double[size];
    rand(size, values);
    maximum(size, values);
    if (values != nullptr)
    {
        delete[] values;
        values = nullptr;
    }
    return 0;
}