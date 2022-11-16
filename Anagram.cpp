#include <iostream>
#include <algorithm>
#include <fstream>

#include "Anagram.h"

Anagram::Anagram(const std::string& nameOfFile)
    :fileName(nameOfFile)
{
    std::ifstream file;
    file.open(nameOfFile, std::ios::out);

    if(file.good())
    {
        std::cout << "File name is correct" << std::endl;
        readFile();
    }
    else
    {
        std::cout << "ERROR file" << std::endl;;
    }
    file.close();
}

void Anagram::readFile()
{
    std::ifstream file(fileName);

    if(file.is_open())
    {
        std::string line;
        while(getline(file, line))
        {
           addLineFromFileToMap(line+'\n');
        }

        file.close();
    }
}

std::string Anagram::addLineFromFileToMap(std::string line)
{
    std::string oneWord;
    auto point = line.begin();

    while (point != line.end())
    {
        if(*point == ',')
        {
            words.emplace_back(oneWord);
            oneWord.clear();
            ++point;
        }
        if(point != line.end())
        {
            oneWord += *point;
            ++point;
        }
    }
    vectorOfAnagramLines.emplace_back(finder());
    words.clear();

    return oneWord;
}

std::string Anagram::finder()
{
    std::map<int, std::string> mapOfWords;
    mapOfWords[3] = words[0];
    int counter = 4;

    auto findSizeword = std::find_if(std::begin(words), std::end(words), [&counter](std::string str){
            return counter == str.size();
    });


    while(findSizeword != words.end())
    {
        findSizeword = std::find_if(findSizeword, std::end(words), [&counter](std::string str){
        return counter == str.size();
        });

        if(findSizeword == words.end())
        {
            break;
        }
        
        if (areAnagrams(mapOfWords[counter-1], *findSizeword))
        {

            mapOfWords[counter] = *findSizeword;
            findSizeword = words.begin();
            counter++;
        }
        else
        {
            findSizeword = std::find_if(++findSizeword, std::end(words), [&counter](std::string str){
            return counter == str.size();
            });
        }
    }
    addArrowAndCharacter(counter, mapOfWords);

    std::string stringToReturnMapWords;

    for(auto elem : mapOfWords)
    {
        stringToReturnMapWords.append(elem.second);
    }

    return stringToReturnMapWords;
}

bool Anagram::areAnagrams(const std::string &word1,   const std::string &word2)
{
    for(int i = 0; i < word1.size(); i++)
    {
        auto findLetter = std::find(std::begin(word2), std::end(word2), word1[i]);
        if(findLetter == word2.end())
            return false;
    }

    return true;
}

void Anagram::addArrowAndCharacter(const int &counter, std::map<int, std::string>&mapOfWords)
{
    for(auto i = 4; i < counter; i++)
    {
        mapOfWords[i-1].insert(mapOfWords[i-1].length(), characterFinder(mapOfWords[i-1], mapOfWords[i]));
    }
}

std::string Anagram::characterFinder(std::string word1, std::string word2)
{
    for(auto elem : word1)
    {
        word2.erase(std::remove(word2.begin(), word2.end(), elem), word2.end());
    }

    return (" + " + word2 + " -> ");
}

void Anagram::printAllFile() const
{
    for(auto elem : vectorOfAnagramLines)
    {
        std::cout << elem << std::endl;
    }
}

void Anagram::printGivenLine(int givenNumber) const
{
    if(givenNumber > vectorOfAnagramLines.size()-1)
    {
        std::cout << "No line :" << givenNumber << std::endl;
    }
    else
    {
        std::cout << vectorOfAnagramLines[givenNumber] << std::endl;
    }

}
