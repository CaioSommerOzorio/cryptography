// Made by: Caio Sommer
// Note: I deeply apologize for the variable names

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

void printVec(vector<string> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i);
    if (i != vec.size()-1) {
      cout << ", ";
    }
    else {
      cout << endl;
    }
  }
}

string findMethod(vector<string> v) {
  //It's short for method I swear!
  string meth;
  bool first = true;
  for (int i = 2; i < v.size(); i++) {
    if (v.at(i) == "-s") {
      break;
    }
    if (v.at(i) != "-m") {
      if (first) {
        first = false;
        meth+=v.at(i);
      }
      else {
        meth+=" "+v.at(i);
      }
    }
  }
  return meth;
}

string vecToStr(vector<string> v, string s) {
  string u;

  for (int i = 0; i < v.size(); i++) {
    if (i != 0) {
      u+=s;
    }
    u+=v.at(i);
  }

  return u;
}

// s: string
// k: key

tuple <vector<string>, vector<string>, bool> flagHandle(vector<string> in) {
  vector<string> s;
  vector<string> k;
  char m;
  bool l = false;
  for (int i = 0; i < in.size(); i++) {
    if (in.at(i) == "-s") {
      m = 's';
    }
    else if (in.at(i) == "-k") {
      m = 'k';
    }
    else if (in.at(i) == "-s") {
      l = true;
    }
    else if (m == 's') {
      s.push_back(in.at(i));
    }
    else if (m == 'k') {
      k.push_back(in.at(i));
    }
  }
  return make_tuple(s, k, l);
}



// Substitution ciphers


// o: original letter
// n: new letter
// s: string to be encoded
// a: alphabet
// c: cipher alphabet
// u: output
// h1: first half of alphabet
// h2: second half of alphabet

string encodeCaesar(int n, string s) {
  string a = "abcdefghijklmnopqrstuvwxyz";
  string c;
  string h2;
  string h1;
  string u;
  char o = a[n];

  // make the cipher alphabet

  for (int i = 0; i < a.length(); i++) {
    h2+=a[i];
    if (a[i] == o) {
      for (int j = i; j < a.length(); j++) {
        h1+=a[j];
      }
      break;
    }
  }
  h2.pop_back();
  c = h1+h2;

  // Encode the string
  for (int i = 0; i < s.length(); i++) {
//`       if (s[i] == ' ') {
//          u+=" ";
//        }
    for (int j = 0; j < a.length(); j++) {
      if (s[i] == a[j]) {
        u+=c[j];
      }
    }
  }

  return u;
}

// Transposition ciphers

// Yet to be made

int main(int argc, char* argv[]) {
  vector<string> args;
  vector<string> str_;
  vector<string> key;
  bool sil;
  string str;
  string mode;
  string method;
  string output;

  for (int i = 1; i < argc; i++) {
    args.push_back(argv[i]);
  }

  mode = argv[1];
  method = findMethod(args);
  tie(str_, key, sil) = flagHandle(args);
  str = vecToStr(str_, " ");
  if (mode == "encrypt" || mode == "en") {
    if (method == "Caesar") {
      output = encodeCaesar(stoi(key.at(0)), str);
      cout << "Encoded using Caesar Cipher with key " << key.at(0) << ": " << endl;
      cout << output << endl;
    }
  }
}
