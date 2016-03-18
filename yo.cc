#include <iostream>
#include <string>
#include <vector>
using namespace std;
void output (vector<string>, int);

int main (int argc, char* argv[]) {
  string word;
  vector<string> v,o;
  int n, counter = 0;
  cin >> n;

  while (1) { //fill vector with words
    cin >> word;
    if (cin.eof()) break;
    if (word.length() > n) {
      v.push_back(word.substr(0,n));
    }
    else {
      v.push_back(word);
    }
  }

  for (int i = 0; i < v.size(); i++) {
    if (v[i].length() == n && counter == 0) {
      cout << v[i] << endl;
    }
    else if (counter + v[i].length() == n) {
      o.push_back(v[i]);
      output(o,n);
      o.clear();
      counter = 0;
    }
    else if (counter + v[i].length() < n) {
      if (counter + v[i].length() + 1 + v[i+1].length() <= n) {
        counter += v[i].length() + 1;
        if (i != v.size()-1) {
          o.push_back(v[i]);
        }
        else {
          o.push_back(v[i]);
          output(o,n);  
          o.clear();
        }
      }
      else {
        o.push_back(v[i]);
        output(o,n);
        o.clear();
        counter = 0;
      }
    }
  }
}

void output (vector<string> o, int n) {
  if (o.size() == 1) { //Special Case
    cout << o[0];
    int fill = n - o[0].length();
    for (int i = 0; i < fill; i++) {
      cout << " ";
    }
  return;
  }
  //Regular Case:
  int charCount = 0;
  for (int i = 0; i < o.size(); i++) {
    charCount += o[i].length();
  }
  int tSpaces = n - charCount;
  int iSpaces = tSpaces /(o.size()-1);
  int eSpaces = tSpaces %(o.size()-1);
  //cout << charCount << " " << tSpaces << " " << iSpaces << " " << eSpaces << " ";
  for (int i = 0; i < o.size()-1; i++) {
    cout << o[i];
    for (int j = 0; j < iSpaces; j++) {
      cout << " ";
    }
    if (eSpaces!=0) {
      cout << " ";
      eSpaces--;
    }
  }
  cout << o[o.size()-1] << endl;
}
