/*
  Filename   : driver.cpp
  Class      : CS328 Spring 2013
  Assignment : Program 2
  Programmer : Kyle jamison
  Date       : 2/17/2013

  This is the driver that reads in the datafile, parses it, and outputs
  the required functionality

*/

#include "quaternion.h"
#include "lnorm.h"
#include <vector>
#include <assert.h>
#include <cstring>
#include <fstream>
#include <string>
#include <stdlib.h>

using std::ifstream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

int main()
{
  vector< Quaternion<float> > testData;

  ifstream dataFile("data.txt");
  if( !dataFile.is_open() )
  {
    cerr << "The datafile couldn't be opened!" << endl;
  }
  else
  {
    string buffer1, num;
    float buffer[3];
    getline(dataFile, buffer1);
    unsigned int index=0;
    while(getline(dataFile, num, ' '))
    {
      if(index>3)
      {
        Quaternion<float> temp(buffer[0], buffer[1], buffer[2], buffer[3]);
        testData.push_back(temp);
        index=1;
        buffer[0] = atoi(num.c_str());
      }
      else
      {
        buffer[index] = atoi(num.c_str());
        index++;
      }
    }
  }

  for(unsigned int i=0; i<testData.size(); i++)
  {
   cout << "h" << i+1 << " : " << testData[i] << endl;
  }

  Lnorm<float> firstNorm;
  float result = firstNorm(testData);

  cout << "\nThe L1 norm of the given input set is: " << result << endl;
  cout << "h1       :  " << (testData[0]) << endl;
  cout << "h2       :  " << (testData[1]) << endl;
  cout << "h1 += h2 :  " << (testData[0]+=testData[1]) << endl;
  cout << "-h1      :  " << (-testData[0]) <<  endl;
  cout << "h1 * h3  :  " << (testData[0]*testData[2]) <<  endl;
  cout << "!h4      :  " << (!testData[3]) <<  endl;
  cout << "h5 ^-1   :  " << (testData[4].inverse()) << endl;

  return 0;
}
