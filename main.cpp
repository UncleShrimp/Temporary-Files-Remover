#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
using namespace filesystem;

string formRemoveFilename(string filePath) {
    string temp_str = "Temp";
    cout<<endl<<filePath.find("Temp")+2<<" ; "<<filePath[filePath.find("Temp")+temp_str.size()+1]<<endl;
    return "";
}

int main() {
    string str_directoryPath = "C:/Users/Uncle_Shrimp/AppData/Local/Temp";
    path directoryPath = str_directoryPath;
    for (const auto& entry :
            directory_iterator(directoryPath)) {
        // Output the path of the file or subdirectory
        cout << "File: " << entry.path() << endl;
        string path_string_u8 = entry.path().u8string();
        formRemoveFilename(path_string_u8);
    }
}