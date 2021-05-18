// MoveFolderReadTrain.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <io.h>

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem::v1;

std::vector<std::string> get_files_inDirectory(const std::string&, const std::string&);

int main()
{
    std::ifstream trainFile;

    trainFile.open("C:/Users/warim/Desktop/YOLO_TRAIN/darknet-master/darknet-master/build/darknet/x64/20210305/train.txt", std::ios_base::in);

    std::string oldFolderStr = "C:/Users/warim/Desktop/YOLO_TRAIN/darknet-master/darknet-master/build/darknet/x64/";
    std::string newFolderStr = "C:/Users/warim/Desktop/YOLO_TRAIN/darknet-master/darknet-master/build/darknet/x64/20210308/data/";

    std::string fileLine;

    while (trainFile.peek() != EOF)
    {
        std::getline(trainFile, fileLine);

        fs::rename(oldFolderStr + fileLine, newFolderStr + fileLine.substr(14));
    }
}

// find all matched file in specified directory
// [INPUT]
//   >> const std::string& _path   Search path   ex) c:/directory/
//   >> const std::string& _filter Search filter ex) *.exe or *.*
// [RETURN]
//   >> std::vector<std::string>   All matched file name & extension
std::vector<std::string> get_files_inDirectory(const std::string& _path, const std::string& _filter)
{
    std::string searching = _path + _filter;

    std::vector<std::string> return_;

    _finddata_t fd;
    long handle = _findfirst(searching.c_str(), &fd);  // ���� ���� �� ��� ������ ã�´�.

    if (handle == -1) return return_;

    int result = 0;
    do
    {
        return_.push_back(fd.name);
        result = _findnext(handle, &fd);
    } while (result != -1);

    _findclose(handle);

    return return_;
}