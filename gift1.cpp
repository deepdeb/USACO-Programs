/*
ID: deb21
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int main()  {
  map<string, int> frnz;
  map<int, string> opp;
  int n, a, b = 1;
  char name[15];
  FILE * fin;
  FILE * fout;
  fin = fopen("gift1.in", "r");
  fout = fopen("gift1.out", "w");
  fscanf(fin, "%d", &n);
  for(int i = 0; i<n; ++i)  {
    fscanf(fin, "%s\n", name);
    frnz[name] = i;
    opp[i] = name;
  }
  int ar[n];
  for(int j = 0; j<n; ++j)
    ar[j] = 0;

  /*
  Now I have a map with key: name and value: number and an
  array with key number (obviously, its an array) and value gift-val
  */
  while(!feof(fin)) {
    char gvr[15], gtr[15];
    fscanf(fin, "%s\n", gvr);
    fscanf(fin, "%d%d\n", &a, &b);
    if(b!=0)  {
      ar[frnz[gvr]] = ar[frnz[gvr]] - a + a%b;
      for(int k = 0; k<b; ++k)  {
        fscanf(fin, "%s\n", gtr);
        ar[frnz[gtr]] += (a/b);
      }
    }
  }
  for(int l = 0; l<n; ++l)
    fprintf(fout, "%s %d\n", opp[l].c_str(), ar[l]);
  fclose(fin);
  fclose(fout);
  return 0;
}
