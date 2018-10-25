#include <iostream>
#include "Set.h"

int main() {
    int elements1[] = {-2, -1, 0, 1, 2};
    int elements2[] = {0, 1, 2, 4, 10};
    Set set1(elements1, 5);
    Set set2(elements2, 5);
    Set set3;
    cout << set1 + set2 << endl;
    cout << set1 << endl;
    cout << set2 << endl;
    cout << set3 << endl;
    cout << (set1 == set2) << endl;
    cout << (set1 != set2) << endl;
    cout << (set1 > set2) << endl;
    cout << (set1 >= set2) << endl;
    cout << (set1 < set2) << endl;
    cout << (set1 <= set2) << endl;
    cout << (set1 > set3) << endl;

    return 0;
}