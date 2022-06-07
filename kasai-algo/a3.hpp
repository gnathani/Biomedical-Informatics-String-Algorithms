/* Gaurav Laxmandas Nathani */

#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

void create_lcp(char *txt_file, char *gsa_file, char *out_file) {
    ifstream TXT_file(txt_file);
    string T;
    getline(TXT_file, T);
    TXT_file.close();
    int n = T.length();

    unsigned char bytes[4];
    int index = 0;
    vector<int> gsa;
    ifstream GSA_file(gsa_file, ios::binary);
    while (GSA_file.read((char*)bytes, 4)) {
        index = bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24);
        gsa.push_back(index);
    }
    GSA_file.close();
    
    int n_gsa = gsa.size();
    vector<int> rev(n,-1);
    for (int i=0; i < n_gsa; i++) {
        rev[gsa[i]] = i;
    }

    vector<int> lcp(n_gsa, 0);
    int h = 0;
    for (int i=0 ; i<n; i++) {
        if (rev[i] > 0) {
            int j = gsa[rev[i] - 1];
            while (T[i+h] == T[j+h] && T[i+h]!='$' && T[j+h]!='$')
                h++;
            lcp[rev[i]] = h;
            if (h > 0) h--;
        }
    }

    ofstream OUT_file(out_file, ios::binary);
    for (int i=0; i < n_gsa; i++) {
        OUT_file.put(lcp[i]);
        OUT_file.put(lcp[i] >> 8);
        OUT_file.put(lcp[i] >> 16);
        OUT_file.put(lcp[i] >> 24);
    }
    OUT_file.close();
}
