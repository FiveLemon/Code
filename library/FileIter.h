#ifndef __FILEITER__H_
#define __FILEITER__H_

#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;
class FileIter{
private:
    string path;
    vector<string> data;
public:
    FileIter(string path);
    void walk();
    void walk(string path);
    void walk(boost::filesystem::path p);
    vector<string> get_vector();
};
#endif