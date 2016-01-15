/*
ID: deb21
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()  {
  int mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, day[7], pos = 0, n;
  for(int l = 0; l<7; ++l)
    day[l] = 0;
  FILE *fin, *fout;
  fin = fopen("friday.in", "r");
  fout = fopen("friday.out", "w");
  fscanf(fin, "%d", &n);
  for(int i = 0; i<n; ++i)  {
    if((1900+i)%4 == 0)
      if((1900+i)%100 == 0)
        if((1900+i)%400 != 0)
          mon[1] = 28;
        else
          mon[1] = 29;
      else
        mon[1] = 29;
    else
      mon[1] = 28;
    for(int j = 0; j<12; ++j) {
      ++day[pos];
      pos = (pos + mon[j])%7;
    }
  }
  for(int k = 0; k<7; ++k)  {
      fprintf(fout, "%d", day[k]);
      if(k<6)
        fprintf(fout, " ");
  }
  fprintf(fout, "\n");
  return 0;
}
