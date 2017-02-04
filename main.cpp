//
//  main.cpp
//  Lexical_Analyzer_p1
//
//  Created by William Pinkston on 2/2/17.
//  Copyright © 2017 Xunil_programming. All rights reserved.
//

#include <iostream>
#include "Analyzer.hpp"
#include <vector>
#include <fstream>

#include <ctype.h>


void ReadFile(std::string filename, std::vector<char>& Input)
{
    std::ifstream inFile(filename.c_str());
    if (inFile.fail())
    {
        return;
    }
    char inChar = inFile.get();
    while (inFile.good())
    {
        Input.push_back(inChar);
        //std::cout << inChar;
        inChar = inFile.get();
    }
    if (inFile.eof())
    {
        Input.push_back('\0');
    }
}


int main(int argc, const char * argv[]) {
//    std::cout << "this\t that\n all them\r things" << std::endl;
//    obviously, \r and \n BOTH will count towards my line count
    
    if (argc < 2)
    {
        std::cout << "Incorrect usage. Expected " << argv[0] << " <filename>" << std::endl;
        return 0;
    }

    
    analyzer parser;
    std::vector<char> Input;
    ReadFile(argv[1],Input);
    parser.run(Input);
    
    
    //read inFile text
    //store it in a vector
    //then pass the vector to the analyzer
    
    return 0;
}






