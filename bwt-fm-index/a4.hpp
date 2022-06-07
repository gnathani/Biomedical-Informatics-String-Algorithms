/* Gaurav Laxmandas Nathani */

#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>
#include <math.h>

using namespace std;

void create_text_match(char *txt_file, char *P) {
    map<char, int> alpha;
    alpha['$'] = 0;
    alpha['A'] = 1;
    alpha['C'] = 2;
    alpha['G'] = 3;
    alpha['N'] = 4;
    alpha['T'] = 5;

    ifstream fp(txt_file);
    string L, temp;
    getline(fp, L);
    getline(fp, temp);
    vector<int> F;
    stringstream sstr_F(temp);
    int val;
    while(sstr_F >> val) F.push_back(val);
    int m = L.length();

    string c;
    getline(fp, c);
    int sp_f = stoi(c);
    
    vector< vector<int> > occ;
    while(getline(fp, temp)) {
        vector<int> t;
        stringstream sstr_t(temp);
        while(sstr_t >> val) t.push_back(val);
        occ.push_back(t);
    }
    fp.close();

    int i = m-2;
    int curr = 0;
    char T[m];
    T[m-1] = '$';
    int a = 0;
    int left, right;
    int count = 0;
    vector<int> next(m);
    int prev = 0;
    while(i>=0) {
        T[i] = L[curr];
        i--;
        a = alpha[L[curr]];
        prev = curr;
        if (curr % sp_f == 0) {
            curr = F[a] + occ[a][curr/sp_f] - 1;
        } else {
            left = floor((curr * 1.0 /sp_f * 1.0) * 1.0);
            right = ceil((curr * 1.0 /sp_f * 1.0) * 1.0);
            int l = left;
            if (right < F.size() && occ[a][left] == occ[a][right]) {
                count = 0;
                left = right+1;
            } else {
                left = left * sp_f + 1;
                right = curr;
            }
            count = 0;
            while (left <= right) {
                if (L[left] == L[curr]) count++;
                left++;
            }
            curr = F[a] + occ[a][l] + count - 1;
        }
        next[prev] = curr;
    }
    for (int i=0; i<m; i++) cout << T[i];
    cout << endl;

    int n = strlen(P);
    i = n-2;
    a = alpha[P[n-1]];
    left = F[a];
    right = (a == 5 ? m-1 : F[a+1]-1);
    cout << right-left+1 << endl;
    vector<int> visit;
    for (int i=left ; i<=right; i++) visit.push_back(i);
    while (i>=0) {
        count = 0;
        vector<int> t;
        for (int j=0; j<visit.size(); j++) {
            curr = visit[j];
            if (L[curr] == P[i]) {
                count++;
                t.push_back(next[curr]);
            }
        }
        visit.assign(t.begin(), t.end());
        cout << count << endl;
        i--;
    }
}
