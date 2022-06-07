/*
 * Gaurav Laxmandas
 * Nathani
 */

#include <iostream>
#include <string>
#include <fstream>

#include "a0.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    int a = std::atoi(argv[3]);
    int res;
    res = approx_match(argv[1], argv[2], a);
    cout << res << endl;
    return 0;
}

