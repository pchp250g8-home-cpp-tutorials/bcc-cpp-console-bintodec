#include <iostream>
#include <tchar.h>
#include <string>
#include <regex>
#include <math.h>

int _tmain(int argc, _TCHAR* argv[])
{
    const unsigned int nMaxBinDigits = static_cast<unsigned int>(floor(log2(UINT32_MAX)));
    const std::regex oRegEx("^[0-1]+$");
    unsigned int nBinPower = 1;
    unsigned int nBinNum = 0;
    std::string strLine;
    system("cls");
    std::cout << "Input a binary number\r\n";
    std::getline(std::cin, strLine);
    int nStrLen = strLine.length();
    bool bIsRightString = (nStrLen <= nMaxBinDigits ) &&
    	 (std::regex_match(strLine, oRegEx));
    if (!bIsRightString)
    {
        std::cout << "Wrong binary number format!!!\r\n";
        std::cin.get();
        return 0;
    }
    for (int i = 0; i < nStrLen; i++)
    {
        unsigned int nBinDigit = strLine[nStrLen - 1 - i] - '0';
        nBinNum += (nBinDigit * nBinPower);
        nBinPower *= 2;
    }
    std::cout << "The decenary equavalent of the binary number "
        << strLine << " is: " << nBinNum << "\r\n";
    std::cin.get();
    return 0;
}
