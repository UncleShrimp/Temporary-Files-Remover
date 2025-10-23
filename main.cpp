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
        // Output the path of the file or subdirectory
        cout << "File: " << entry.path() << endl;
        string path_string_u8 = entry.path().u8string();
        cout<<formRemoveFilename(path_string_u8)<<endl<<endl;
        string filename = formRemoveFilename(path_string_u8);
        // Attempt to remove the file
        int result = remove(filename);

        if (result == 0) {
            std::cout << "File '" << filename << "' deleted successfully." << std::endl;
        } else {
            std::cerr << "Error deleting file '" << filename << "'. Error code: " << result << std::endl;
            // You can use perror("Error message") to get a more descriptive error message
        }
    }
}