#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <string>
# include <fstream>

class Replace
{
private:
    std::string     _filename;
    std::string     _src;
    std::string     _dst;

public:
    Replace(std::string filename, std::string src, std::string dst);
    ~Replace();

    bool    replaceStr();
};

#endif
