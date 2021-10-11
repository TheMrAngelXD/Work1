#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    double* values;
    int size;
    cout << "n = ";
    cin >> size;

    if (size <= 0) {
        cerr << "Invalid size" << endl;
        return 1;
    }
    values = new double[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        values[i] = rand();
        cout << values[i]<<endl;
        
    }
    int max = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    cout << "max = " << max << endl;

    delete[] values;
    return 0;
}