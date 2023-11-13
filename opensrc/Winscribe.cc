#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

// Functions

void pause() { system("pause"); } // Used to pause the system.
void wait(int time) { Sleep(time * 1000); } // Used to pause the program for <..> seconds.

void cls(int delay=0) {  // Clears the screen.
    wait(delay); 
    system("cls"); 
}
void title(string title="[no title]") {  // Used to change title.
    string command = "title " + title;

    system(command.c_str());
}

string ask(string question) { // std::cin but better
    string output;

    cout << question;
    getline(cin, output);

    return output;
}

// Main
int main() {
    int line = 1;

    string text;
    char ch;

    cls();

    string name = ask("* "); cout << "\n";
    title("Winscribe\t* " + name);
    
    while (true) {
        string output = ask(to_string(line) + ". ");
        
        text += output + "\n";
        line ++;


        // Comamnds
        if (output == "\023") { // Key: Ctrl+S; used to save the file
            ofstream file(name); // Make the file

            if (file.is_open()) { // Writing to the file
                file << text;
                file.close();
            } else {
                file << "Error saving file. E001";
                cout << "Cannot save file contents. E001";
            }
        } else if (output == "\004") { // Key: Ctrl+D; used to delete all text
            cls(); cout << "* " << name << "\n";

            text = "";
            line = 1;
        }
    }
}