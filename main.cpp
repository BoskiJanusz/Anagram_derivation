#include <iostream>
#include <vector>
#include "Anagram.h"

int main()
{
    std::vector<std::string> words = {"ail", "tennis", "nails", "desk", "aliens", "enine", "sail"};
   
    Anagram anagram("words.txt");
    anagram.printGivenLine(1);

    anagram.printAllFile();
    return 0;
}