#include <iostream>
#include "map_objects/test.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    Test first = Test(1);
    cout << first.getT() << endl;

    return 0;
}
