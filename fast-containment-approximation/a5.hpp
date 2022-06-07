/* Gaurav Laxmandas Nathani */

#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdint>
#include <map>

using namespace std;

unsigned long long int fnv1a(string str); 

void containment(char *txt_file, int w, float tc) {
    ifstream fp(txt_file);
    vector<string> T;
    string temp;
    while (getline(fp, temp)) {
        T.push_back(temp);
    }

    map<unsigned long long int, vector<int> > hashes;
    vector< vector<int> > matches(T.size(), vector<int>(T.size(),0));
    vector<int> d(T.size());
    for (int i=0; i<T.size(); i++) {
        for (int j=0; j<T[i].length()-w+1; j++) {
            string sh(T[i].begin()+j, T[i].begin()+j+w);
            unsigned long long int temp = fnv1a(sh);
            if (temp % 10 == 0) {
                if (hashes.find(temp) == hashes.end()) {
                    hashes[temp].push_back(i);
                    d[i]++;
                } else {
                    vector<int> e;
                    e = hashes[temp];
                    if (e[e.size()-1]!=i) {
                        for (int m=0; m<e.size(); m++) {
                            matches[e[m]][i]++;
                        }
                        hashes[temp].push_back(i);
                        d[i]++;
                    }
                }
            }
        }
    }

    for (int i=0; i<T.size()-1; i++) {
        for (int j=i+1; j<T.size(); j++) {
            float ret = float(matches[i][j])/float((d[i]<d[j]?d[i]:d[j]));
            if (ret>tc) cout << i << " " << j << endl;
        }
    }
}

unsigned long long int fnv1a(string str) {
    unsigned long long hash = 14695981039346656037u;
    for (char const &c: str) {
        hash = hash ^ c;
        hash = hash * 1099511628211;
    }
    return hash;
}
