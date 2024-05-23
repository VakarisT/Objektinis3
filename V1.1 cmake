// V1.1 cmake.cpp : Defines the entry point for the application.
//

//using namespace std;

#include "studentas.h"

int main()
{
    std::vector<Student> studVector;
    std::vector<Student> best;
    std::vector<Student> worst;
    int choice;
    while (true)
        try
        {
        std::cout << "Programos eigos pasirinkimas:\n\"1\" - Ivedimas ranka\n\"2\" - Generavimas\n\"3\" - Skaitymas is failo\n\"4\" - Generuoti faila\n\"5\" - Atrinkti studentus\n\"6\" - Rezultatu isvedimas\n\"7\" - Baigti darba\n";
            std::cin >> choice;
            if (std::cin.fail())
                CinError();
            if (choice < 1 || choice > 7)
                throw std::runtime_error("Klaidinga ivestis");
            if (choice == 1)
                ReadUser(studVector);
            if (choice == 2)
            {
                int size, hw;
                std::cout << "Studentu skaicius: ";
                std::cin >> size;
                if (size < 1)
                    throw std::runtime_error("Klaidinga ivestis");
                if (std::cin.fail())
                    CinError();
                std::cout << "Namu darbu skaicius: ";
                std::cin >> hw;
                if (std::cin.fail())
                    CinError();
                if (hw < 1)
                    throw std::runtime_error("Klaidinga ivestis");
                GenUser(studVector, size, hw);
            }
            if (choice == 3)
                ReadFile(studVector);
            if (choice == 4)
            {
                int size, hw;
                std::cout << "Studentu skaicius: ";
                std::cin >> size;
                if (std::cin.fail())
                    CinError();
                if (size < 1)
                    throw std::runtime_error("Klaidinga ivestis");
                std::cout << "Namu darbu skaicius: ";
                std::cin >> hw;
                if (std::cin.fail())
                    CinError();
                if (hw < 1)
                    throw std::runtime_error("Klaidinga ivestis");
                GenFile(size, hw);
            }
            if (choice == 5)
            {
                std::cout << "Pagal ka atrinkti? \n\"1\" - pagal varda/pavarde; \n\"2\" - Pagal vidurki; \n\"3\" - Pagal mediana\n";
                std::cin >> choice;
                if (std::cin.fail())
                    CinError();
                if (choice < 1 || choice > 3)
                    throw std::runtime_error("Klaidinga ivestis");
                Selection(studVector, choice, best, worst);
            }
            if (choice == 6)
                Results(studVector);
            if (choice == 7)
                exit(EXIT_FAILURE);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

    return 0;
}
