#include <iostream>
#include "Anagram.h"

// Anagram class has constructor to get txt file and two public
// methods to print anagrams from given in file elements

int main()
{   
    Anagram anagram("words.txt");
    anagram.printGivenLine(1);

    anagram.printAllFile();
    return 0;
}