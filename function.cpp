#include "Header.h"

//ввод элементов в вектор items
void inputPrices(std::vector<int> &items, size_t sizeVecPrices, std::string &errorIndex, std::string &errorNumNotInt, int &flagErrorIndex, int &flagErrorInt)
{
    auto indexPrices = 0.0;
    std::string tmpErrorIndex, tmpErrorNumNotInt;
    std::stringstream strTmp;
    int tmpFlagErrorIndex = 0, tmpFlagErrorInt = 0;
    while (true) {
        std::cin >> indexPrices;
        if (indexPrices == -1)
            break;
        else if (indexPrices > sizeVecPrices || indexPrices < 0) {
            tmpErrorIndex += std::to_string((int)indexPrices);
            tmpErrorIndex += " ";
            ++tmpFlagErrorIndex;
            continue;
        }
        else if ((int)indexPrices - indexPrices != 0) {
            strTmp << indexPrices;
            tmpErrorNumNotInt += strTmp.str() + " ";
            strTmp.str("");
            ++tmpFlagErrorInt;
            continue;
        }
        else
            items.push_back(indexPrices);
    }
    errorIndex = tmpErrorIndex;
    errorNumNotInt = tmpErrorNumNotInt;
    flagErrorIndex = tmpFlagErrorIndex;
    flagErrorInt = tmpFlagErrorInt;
}

//проверка на ошибку
bool errorChecking(int flagErrorInt, int flagErrorIndex, std::string errorIndex, std::string errorNumNotInt)
{
    if (flagErrorIndex > 0 && flagErrorInt > 0) {
        std::cout << "Input error:\n"
            << "The are no products with such:  " << errorIndex << '\n'
            << "The product number is entered incorrectly: " << errorNumNotInt << '\n'
            << "Continue calculating the cost without taking into account the erroneous data, click - y\n"
            << "If you re-enter the data, click - n\n";
        return 0;
    }
    else if (flagErrorIndex > 0) {
        std::cout << "Input error:\n"
            << "The are no products with such:  " << errorIndex << '\n'
            << "Continue calculating the cost without taking into account the erroneous data, click - y\n"
            << "If you re-enter the data, click - n\n";
        return 0;
    }
    else if (flagErrorIndex > 0) {
        std::cout << "Input error:\n"
            << "The product number is entered incorrectly: " << errorNumNotInt << '\n'
            << "Continue calculating the cost without taking into account the erroneous data, click - y\n"
            << "If you re-enter the data, click - n\n";
        return 0;
    }
    else
        return 1;
}

//Подсчет результата
void score(std::vector<int> &items, std::vector<float> &prices)
{
    float sum = 0;
    for (size_t indexI = 0; indexI < items.size(); ++indexI)
        sum += prices[items[indexI]];
    std::cout << "\nSum = " << sum << std::endl;
}

//Выбор продолжения работы
bool enterActionFlag()
{
    char ch;
    std::cout << "If you want to continue searching except for invalid data, press Y\n"
              << "If you re-enter the data, press N\n";
    while (true) {
        std::cin >> ch;
        if (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') {
            std::cout << "Error. Input error, please re-enter.";
            continue;
        }
        else
            break;
    }
    if (ch == 'y' && ch == 'Y')
        return true;
    else {
        return false;
    }
}
