#ifndef SEQENCE_H
#define SEQENCE_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>

class Sequence
{
private:
private:
    double data[100];  // Масив для зберігання чисел
    int size;  
    
public:
    Sequence() : size(0) {}
    void add(double number) ;
    void sort(std::function<double(double)> criteria);
    void classify(int& good, int& bad, int& neutral) const;
    void outputToFile(const std::string& filename) const;
    void outputClassificationToFile(const std::string& filename, int good, int bad, int neutral) const;
};

#endif // SEQENCE_H