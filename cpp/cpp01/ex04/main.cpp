#include <fstream>
#include <string>
#include <iostream>
#include <iterator>

int main(int ac, char **av)
{    
    if (ac != 4)
    {
        std::cout << "Error: missing arguments" << std::endl;
        return 1;
    }

    std::string filename;
    std::string changed_filename;
    std::string s1;
    std::string s2;
    
    filename = av[1];
    changed_filename = av[1];
    changed_filename.append(".replace");
    s1 = av[2];
    s2 = av[3];
    
    if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << "Couldn't open input file." << std::endl;
        return 1;
    }

    std::string content = std::string(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );

    std::string res;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        res += content.substr(pos, found - pos);
        res += s2;
        pos = found + s1.size();
    }
    res += content.substr(pos);

    std::ofstream output_file(changed_filename.c_str());
    if (!output_file)
    {
        std::cout << "Couldn't create output file." << std::endl;
        return 1;
    }
    output_file << res;
    std::cout << res;
    return 0;
}