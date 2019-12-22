#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
/**************************************************************************

Copyright:MySelf

Author: cx

Date:2019-12-16

Description:string to vector

Need include file:
#include <string>
#include <vector>
#include <iostream>
Note:The parameter is const char *

**************************************************************************/
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
/**************************************************************************

Copyright:MySelf

Author: cx

Date:2019-12-22

Description:string to vector<string>

Need include file:
#include <string>
#include <vector>
#include <iostream>

NOTE:The parameter is string
**************************************************************************/
bool splitStringToStr(string& strsrc, string& strSplit, vector<string>& vecresult)
{
    string sstr = strsrc;
    if (strsrc.empty())
    {
        return false;
    }
    string::size_type iStarpos = 0;
    string::size_type isplitpos = 0;
    string str;
    isplitpos = strsrc.find(strSplit,iStarpos);
    while(string::npos != isplitpos)
    {
        str = sstr.substr(iStarpos,isplitpos - iStarpos);
        vecresult.push_back(str);
        iStarpos = isplitpos + strSplit.size();
        isplitpos = strsrc.find(strSplit,iStarpos);
    }
    str = strsrc.substr(iStarpos);
    vecresult.push_back(str);
    return true;
}
/**************************************************************************

Copyright:MySelf

Author: cx

Date:2019-12-22

Description:string to int vector<int>

Need include file:
#include <string>
#include <vector>
#include <iostream>

NOTE:The parameter is string
**************************************************************************/
bool splitStringToInt(string &strsrc,string &strSplit,vector<int>& vecresult)
{
        string sstr = strsrc;
        if (strsrc.empty())
        {
                return false;
        }
        string::size_type iStarpos = 0;
        string::size_type isplitpos = 0;
        string str;
        isplitpos = strsrc.find(strSplit,iStarpos);
        while(string::npos != isplitpos)
        {
                str = sstr.substr(iStarpos,isplitpos - iStarpos);
                vecresult.push_back(stringToInt(str));
                iStarpos = isplitpos + strSplit.size();
                isplitpos = strsrc.find(strSplit,iStarpos);
        }
        str = strsrc.substr(iStarpos);
        vecresult.push_back(stringToInt(str));
        return true;
}

/**************************************************************************

Copyright:MySelf

Author: cx

Date:2019-12-22

Description:string to int

Need include file:
#include <string>
#include <iostream>
#include <sstream>
NOTE:The parameter is string
**************************************************************************/
int stringToInt(string str)
{
    int res = 0;
    stringstream ss;
    ss<<str;
    ss>>res;
    return res;
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
