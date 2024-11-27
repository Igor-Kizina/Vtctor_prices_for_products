#include "Header.h"

template <typename F>
void printVector(std::vector<F> &vec)
{
    for(size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;
}


int main()
{
    std::vector<float> prices{ 2.34, 55.03, 5.456, 88.44, 15.6, 34.5, 54.45, 56.99, 4.6, 77.77 };
    printVector(prices);
    std::vector<int> items;
    bool flag = true;
    while(flag) {
        std::cout << "Enter the index of the items,"
                  << "To close the input,  enter -1\n";
        std::string errorIndex, errorNumNotInt;
        int flagErrorIndex, flagErrorInt;
        inputPrices(items, prices.size(), errorIndex, errorNumNotInt, flagErrorIndex, flagErrorInt);//Ввод элементов в вектор
        if(errorChecking(flagErrorInt, flagErrorIndex, errorIndex, errorNumNotInt) == 0) {
             if(enterActionFlag() == false)
                score(items, prices);
             else {
                items.erase(items.cbegin(), items.end() - 1); //Обнуляем вектор
                continue;
             }
        }
        else
            score(items, prices);
        flag = false;
    }


    return 0;
}
