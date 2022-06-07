/* Gaurav Laxmandas Nathani */

#include <iostream>

#include "a5.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cerr << "Give proper inputs\n ./a5 '/path/to/text/file' 'w' 'containment_threshold'\n";
        return -1;
    }

    containment(argv[1], atoi(argv[2]), atof(argv[3]));

    return 0;
}
