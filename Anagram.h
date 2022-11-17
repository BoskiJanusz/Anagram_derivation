#include <string>
#include <vector>
#include <map>

// most methods are private to secure important order
class Anagram
{
    std::vector<std::string> words;
    std::vector<std::string> vectorOfAnagramLines;
    const std::string& fileName;
    
    
    std::string finder();
    std::string characterFinder(std::string, std::string);
    std::string addLineFromFileToVector(std::string);
    bool areAnagrams(const std::string&, const std::string&);
    void addArrowAndCharacter(const int&, std::map<int, std::string>&);
    void readFile();
    
public:
    Anagram(const std::string&);
    void printAllFile() const;
    void printGivenLine(int) const;
};