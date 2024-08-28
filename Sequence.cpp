#include "Sequence.h"

void Sequence::add(double number)
{
    if (size < 100)
    {
        data[size++] = number;
    }
    else
    {
        std::cerr << "Послідовність переповнена!" << std::endl;
    }
}

void Sequence::sort(std::function<double(double)> criteria)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (criteria(data[j]) < criteria(data[j + 1]))
            {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

void Sequence::classify(int &good, int &bad, int &neutral) const
{
    good = bad = neutral = 0;
    for (int i = 0; i < size; ++i)
    {
        if (data[i] > 10)
        { // Приклад: Вважати числа > 10 як "хороші"
            good++;
        }
        else if (data[i] > 0 && data[i] <= 10)
        { // Приклад: Вважати числа між 0 і 10 як "нейтральні"
            neutral++;
        }
        else if (data[i] <= 0)
        { // Приклад: Вважати числа <= 0 як "погані"
            bad++;
        }
    }
}

void Sequence::outputToFile(const std::string &filename) const
{
    std::ofstream outputFile(filename);
    if (!outputFile)
    {
        std::cerr << "Не вдалося відкрити вихідний файл!" << std::endl;
        return;
    }

    outputFile << "Відсортована послідовність: ";
    for (int i = 0; i < size; ++i)
    {
        outputFile << data[i] << " ";
    }
    outputFile.close();
}

void Sequence::outputClassificationToFile(const std::string &filename, int good, int bad, int neutral) const
{
    std::ofstream outputFile(filename, std::ios_base::app);
    if (!outputFile)
    {
        std::cerr << "Не вдалося відкрити вихідний файл!" << std::endl;
        return;
    }

    outputFile << "\nХороші: " << good << "\nПогані: " << bad << "\nНейтральні: " << neutral << std::endl;
    outputFile.close();
}