#include "FileIter.h"
FileIter::FileIter(string path){
    this->path = path;
}
void FileIter::walk(){
    walk(path);
}
void FileIter::walk(string path){
    auto p = boost::filesystem::path(path);
    walk(p);
}
void FileIter::walk(boost::filesystem::path p){
    try{
        if (exists(p)){
            if (is_regular_file(p)){
                //cout << p << " size is " << file_size(p) << '\n';
                data.push_back(p.string());
            }
            else if (is_directory(p)){
                //cout << p << " is a directory containing:\n";
                for (directory_entry& x : directory_iterator(p)){
                    walk(x.path());
                }
            }
            else
                cout << p << " exists, but is not a regular file or directory\n";
        }
        else
            cout << p << " does not exist\n";
    }
    catch (const filesystem_error& ex){
        cout << ex.what() << '\n';
    }
}
vector<string> FileIter::get_vector(){
    return data;
}