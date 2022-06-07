/*
 * Gaurav Laxmandas
 * Nathani
 */

#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

int approx_match(char *txt_file, char *P, int alpha) {
    int n = strlen(P);
    ifstream fp(txt_file);
    string T;
    getline(fp, T);
    fp.close();

    for(int i=0; i<T.size()-n; i++) {
        int k=0;
        for(int j=i; j<i+n; j++) {
            if (T[j] != P[j-i]) k++;
        }
        if (k <= alpha) return i+1;
    }

    return -1;
}
