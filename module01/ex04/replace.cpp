#include "replace.hpp"

Replace::Replace(std::string filename, std::string src, std::string dst)
            : _filename (filename), _src (src), _dst (dst)
{
}

Replace::~Replace() {}

bool    Replace::replaceStr()
{
    std::ifstream   input;
    std::ofstream   output;
    std::string     buffer;

    input.open(_filename);
    if (!input.is_open())
    {
        std::cout << "Error: unable to open " << _filename << std::endl;
		return (false);
    }
    output.open(_filename + ".replace");
    while (input.good())
    {
        getline(input, buffer);
        for (size_t i = 0; i < buffer.size(); i++)
        {
           	if (!buffer.compare(i, _src.size(), _src)) 
            {
			    buffer.erase(i, _src.size());
			    buffer.insert(i, _dst);
            }
        }
        output << buffer;
        if (!input.eof())
            output << '\n';
    }
    input.close();
    output.close();
    return (true);
}
