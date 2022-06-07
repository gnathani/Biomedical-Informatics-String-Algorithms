/* Gaurav Laxmandas Nathani */

#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void bm_horsepool(char *txt_file, char *P) {
    int n = strlen(P);
    ifstream fp(txt_file);
    string T;
    getline(fp, T);
    fp.close();
    int m = T.length();
    int sigma=0;
    int i=0, j=0;

    int occ[95][n+2];
    memset(occ, -1, sizeof(occ));
    for (i=0; i<n; i++) {
        int curr = int(P[i])-32;
        if (occ[curr][n+1]==-1) {
            occ[curr][n+1] = 0;
            sigma++;
        }
        if (occ[curr][n+1]!=-1) {
            int val = occ[curr][n];
            for (j=val+1; j<i+1; j++) {
                occ[curr][j] = val;
            }
        }
        occ[curr][n]=i;
    }
    for (i=0; i<95; i++) {
        int val = occ[i][n];
        for (j=val+1; j<n; j++) {
            occ[i][j]=val;
        }
    }

    for (i=0; i<m; i++) {
        int curr = int(T[i]-32);
        if (occ[curr][n+1]==-1) {
            occ[curr][n+1]=1;
            sigma++;
        } else {
            occ[curr][n+1]+=1;
        }
    }

    int l = 0, p = 0, t = 0, c = n-1;
    int C[n];
    int s = 0,tmp = 0;
    memset(C, 0, sizeof(C));
    for (i=0; i<=m-n; i=i+s) {
        j = n - 1;
        t++;
        while (j>=0 && T[i+j]==P[j] ) {
            t++;
            j--;
        }
        if (j==-1) {
            t--;
            s=1;
        } else {
            C[j]+=1;
            if (C[j] > C[c]) c = j;
            else if (C[j] == C[c] && j>c) c = j;
            tmp = int(T[i+j])-32;
            s = (occ[tmp][j]==-1)?j+1:j-occ[tmp][j];
        }
        if (s==1) l++;
        else p++;
    }

    double Pr = 1;
    for (i=0; i<n; i++) {
        Pr = Pr * (occ[int(P[i])-32][n+1]/(m*1.0));
    }

    cout << m << endl;
    cout << n << endl;
    cout << sigma << endl;
    cout << l << endl;
    cout << p << endl;
    cout << t << endl;
    cout << c+1 << endl;
    cout << fixed << setprecision(6) << Pr << endl;
}
