#include <string>
#include <vector>
#include <map>

class Anagram
{
    std::vector<std::string> words;
    std::vector<std::string> vectorOfAnagramLines;
    const std::string& fileName;
    
    
    std::string finder();
    std::string characterFinder(std::string, std::string);
    std::string addLineFromFileToMap(std::string);
    bool areAnagrams(const std::string&, const std::string&);
    void addArrowAndCharacter(const int&, std::map<int, std::string>&);
    void readFile();
    
public:
    Anagram(const std::string&);
    void printAllFile() const;
    void printGivenLine(int) const;
};