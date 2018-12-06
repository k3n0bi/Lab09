// main.cpp
// Ben Howe
// COSC 2030
// Lab 09
// December 5, 2018

// Reads the contents of one text file, and outputs a sorted list of the words to another.


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::map;


int main()
{
  string filename;
  string outfilename;
  ifstream infile;
  bool fileread = false;

  map<string, int> tally;
  string line;
  string word;
  while (!fileread)
  {
    cout << "Enter an input filename." << endl;
    cin >> filename;
    infile.open(filename);
    if (!infile)
    {
      cin.clear();
      cin.ignore();
      cout << "file not opened" << endl;
    }
    else
    {
      fileread = true;
    }
  }


  while (infile.eof() != true)
  {
    getline(infile, line); //read a line
    istringstream words(line); //stream the line into a list of words
    while (words >> word) //loop the words
    {
      ++tally[word]; //add to the map
    }

  }

  if (infile.is_open())
  {
    infile.close();
  }


  cout << "Enter an output filename." << endl;
  cin >> outfilename;
  ofstream outfile(outfilename);
  for (map<string, int>::iterator it = tally.begin(); it != tally.end(); ++it)
  {
    for (int i = 0; i < it->second; i++) //repeat the stored word the number of times it was found
    {
      //cout << it->first << endl;
      outfile << it->first << endl;
    }
  }

  if (outfile.is_open())
  {
    outfile.close();
  }

  return 0;
}
