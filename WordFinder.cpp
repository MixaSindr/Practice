#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const string& a, const string& b) {
    return a.length() > b.length();
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int N(10);
    size_t cnt(0);
    char tmpStr[300];
    string str;
    vector<string> allWords;

    //ofstream  OFile("karenina1.txt");


    /*for (size_t i = 0; i < N; i++) {
         std::cout << i;
         OFile << i;
     }
     OFile.close();
     */

    ifstream IFile("karenina.txt");
    //cout << "\n\n\n ";
    while (!IFile.eof()) {
        IFile >> tmpStr;
        allWords.push_back(tmpStr);
        cnt++;
        //OFile << tmpStr << "\n ";
    }
    
    sort(allWords.begin(), allWords.end(), compare);
    for (int i = 0; i < 3; i++) {
        cout << allWords[i]<<"\n";
    }

    IFile.close();
    //OFile.close();
}