#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>
#include "Sequence.h"

// Критерій: Дробова частина числа
double fractionalPart(double number) {
    return std::fabs(number - static_cast<long long>(number));
}

int main(int argc, char* argv[]) {
    Sequence sequence;
    std::string outputFileName;

    // Обробка аргументів командного рядка
    if (argc > 1) {
        for (int i = 1; i < argc - 1; ++i) {
            sequence.add(std::stod(argv[i]));
        }
        outputFileName = argv[argc - 1];
    } else {
        // Якщо немає аргументів командного рядка, запитуємо ім'я вхідного файлу
        std::string inputFileName;
        std::cout << "Введіть ім'я вхідного файлу: ";
        std::cin >> inputFileName;

        std::ifstream inputFile(inputFileName);
        if (!inputFile) {
            std::cerr << "Не вдалося відкрити вхідний файл!" << std::endl;
            return 1;
        }

        double number;
        while (inputFile >> number) {
            sequence.add(number);
        }

        inputFile.close();

        std::cout << "Введіть ім'я вихідного файлу: ";
        std::cin >> outputFileName;
    }

    // Сортування послідовності на основі дробової частини
    sequence.sort(fractionalPart);

    // Класифікація послідовності
    int good, bad, neutral;
    sequence.classify(good, bad, neutral);

    // Запис результатів у вихідний файл
    sequence.outputToFile(outputFileName);
    sequence.outputClassificationToFile(outputFileName, good, bad, neutral);

    std::cout << "Хороші: " << good << "\nПогані: " << bad << "\nНейтральні: " << neutral << std::endl;

    return 0;
}