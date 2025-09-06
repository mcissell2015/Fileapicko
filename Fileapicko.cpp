#include <iostream>
#include <fstream>
#include <string>

class Fileapicko {
public:
    Fileapicko(const std::string& filename) : filename_(filename) {}

    bool createFile() {
        std::ofstream outfile(filename_);
        if (outfile.is_open()) {
            outfile.close();
            std::cout << "File created successfully: " << filename_ << std::endl;
            return true;
        } else {
            std::cerr << "Unable to create file: " << filename_ << std::endl;
            return false;
        }
    }

    bool writeFile(const std::string& content) {
        std::ofstream outfile(filename_);
        if (outfile.is_open()) {
            outfile << content << std::endl;
            outfile.close();
            std::cout << "Content written to file: " << filename_ << std::endl;
            return true;
        } else {
            std::cerr << "Unable to open file for writing: " << filename_ << std::endl;
            return false;
        }
    }

private:
    std::string filename_;
};

int main() {
    std::string filename;
    std::cout << "Enter the desired filename: ";
    std::cin >> filename;

    Fileapicko myFile(filename);

    if (myFile.createFile()) {
        myFile.writeFile("This is some content for the file.");
    }

    return 0;
}