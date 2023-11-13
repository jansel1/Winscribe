#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;
void p() { system("pause"); }
void w(int t) { Sleep(t * 1000); }
void c(int d = 0) { w(d); system("cls"); }
void t(string t = "[no title]") { string c = "title " + t; system(c.c_str()); }
string a(string q) { string o; cout << q; getline(cin, o); return o; }
int main() {
 int l = 1;
 string txt;
 char ch;
 c();
 string n = a("* "); cout << "\n";
 t("Winscribe\t* " + n);
 while (true) {
 string o = a(to_string(l) + ". ");
 txt += o + "\n";
 l++;
 if (o == "\023") {
 ofstream f(n);
 if (f.is_open()) {
 f << txt;
 f.close();
 } else {
 f << "Error saving file. E001";
 cout << "Cannot save file contents. E001";
 }
 } else if (o == "\004") {
 c();
 cout << "* " << n << "\n";
 txt = "";
 l = 1;
 }
 }
 return 0;
}
