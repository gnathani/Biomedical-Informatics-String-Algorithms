#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main() {
    int gsa[] = {5,4,3,2,1,0};
    ofstream out("gsa", ios::binary);
    for (int i=0; i < (sizeof(gsa)/sizeof(gsa[0])); i++) {
        out.put(gsa[i]);
        out.put(gsa[i] >> 8);
        out.put(gsa[i] >> 16);
        out.put(gsa[i] >> 24);
    }
    out.close();
    return 0;
}
