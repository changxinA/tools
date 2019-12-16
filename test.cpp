#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int Str2Vect(const char* pSrc, std::vector<std::string> &vDest, const char *pSep) {
    if (NULL == pSrc) {
        return -1;
    }

    int iLen = strlen(pSrc);
    if (iLen == 0) {
        return -1;
    }

    char *pTmp = new char[iLen + 1];
    if (pTmp == NULL) {
        return -1;
    }

    memcpy(pTmp, pSrc, iLen);
    pTmp[iLen] = '\0';

    char *pCurr = strtok(pTmp, pSep);
    while (pCurr) {
        vDest.push_back(pCurr);
        pCurr = strtok(NULL, pSep);
    }

    delete[] pTmp;
    return 0;
}
int main()
{
    const char *str="192.168.0.110";
    vector<string> vec;
    const char *split = ".";
    Str2Vect(str, vec, split);
    for (int i =0;i<vec.size(); i++)
    {
        cout<<vec[i]<<endl;
    }
    return 0;
}
