#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
using namespace filesystem;

string formRemoveFilename(string filePath) {
    string temp_str = "Temp";
    cout<<filePath.find("Temp")+temp_str.size()+1<<" ; "<<filePath[filePath.find("Temp")+temp_str.size()+1]<<endl;
    int dist = filePath.size()-1 - filePath.find("Temp")+temp_str.size()+1;
    string formed_str = filePath.substr(filePath.find("Temp")+temp_str.size()+1, dist);
    return formed_str;
}

int main() {
    string str_directoryPath = "C:/Users/Uncle_Shrimp/AppData/Local/Temp";
    path directoryPath = str_directoryPath;
    for (const auto& entry :
        directory_iterator(directoryPath)) {
        


        if (filesystem::is_regular_file(entry.path())) {
            try {
                // Output the path of the file or subdirectory
                cout << "File: " << entry.path() << endl;
                string path_string_u8 = entry.path().u8string();
                cout<<formRemoveFilename(path_string_u8)<<endl<<endl;
                string filename = formRemoveFilename(path_string_u8);
                int result = remove(filename);
                // Attempt to remove the file
                filesystem::remove(filename);
                std::cout << "Deleted: " << entry.path() << std::endl;
            } catch (const filesystem::filesystem_error& e) {
                std::cerr << "Error deleting " << entry.path() << ": " << e.what() << std::endl;
            }
        }
    }
}