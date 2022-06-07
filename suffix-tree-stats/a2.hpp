/* Gaurav Laxmandas Nathani */

#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

struct Node{
    struct Node *child[6];
    int start;
    int end;
    int suffix;
};

struct Node* create_node() {
    struct Node* new_node = new struct Node();
    for (int i=0; i<6; i++) {
        new_node -> child[i] = NULL;
    }
    new_node -> start = -1;
    new_node -> end = -1;
    new_node -> suffix = -1;
    return new_node;
}

void create_suffix_tree(char *txt_file) {
    ifstream fp(txt_file);
    string T;
    getline(fp, T);
    fp.close();
    int m = T.length();
    int x = 0;
    int y = 0;

    map<char, int> alpha;
    alpha['A'] = 0;
    alpha['C'] = 1;
    alpha['G'] = 2;
    alpha['T'] = 3;
    alpha['N'] = 4;
    alpha['$'] = 5;

    struct Node* root = create_node();
    for (int i=0; i<m; i++) {
        int curr = alpha[T[i]];
        struct Node* leaf = create_node();
        leaf -> end = m-1;
        leaf -> suffix = i;
        if (root -> child[curr] == NULL) {
            leaf -> start = i;
            root -> child[curr] = leaf;
            y++;
        } else {
            struct Node* prev = root;
            struct Node* follow = root -> child[curr];
            int j = i;
            while(true) {
                int a = follow -> start;
                int b = follow -> end;
                int curr_br = a;
                while (a <= b && T[a] == T[j]) {
                    a++;
                    j++;
                }
                if (a == b+1) {
                    int c = alpha[T[j]];
                    if (follow -> child[c] == NULL) {
                        leaf -> start = j;
                        follow -> child[c] = leaf;
                        y++;
                        break;
                    } else {
                        prev = follow;
                        follow = follow -> child[c];
                    }
                } else {
                    struct Node* int_node = create_node();
                    int_node -> start = follow -> start;
                    int_node -> end = a-1;
                    int_node -> child[alpha[T[a]]] = follow;
                    int_node -> child[alpha[T[j]]] = leaf;
                    prev -> child[alpha[T[curr_br]]] = int_node;
                    follow -> start = a;
                    leaf -> start = j;
                    x++;
                    y = y + 2;
                    break;
                }
            }
        }
    }
    cout << x+1 << endl;
    cout << y << endl;
}
