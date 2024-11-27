#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <iostream>
#include <sstream>
#include <vector>
#include <string>


//���� ��������� � ������ items
void inputPrices(std::vector<int> &items, size_t sizeVecPrices, std::string &errorIndex, std::string &errorNumNotInt, int &flagErrorIndex, int &flagErrorInt);
//�������� �� ������
bool errorChecking(int flagErrorInt, int flagErrorIndex, std::string errorIndex, std::string errorNumNotInt);
//�������
void score(std::vector<int> &items, std::vector<float> &prices);
//����� ����������� ������
bool enterActionFlag();

#endif // HEADER_H_INCLUDED
