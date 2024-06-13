#include "func.h"
#include "vector.h"

int main()
{
    MyVector<Student> studVector;
    MyVector<Student> best;
    int choice , n;

    Student Student0;
    Student Student1("Vakaris", "Tiunaitis");
    Student Student2("Vardas", "Pavarde");
    Student Student3(Student1);
    Student Student4(std::move(Student2));
    Student0 = Student1;
    Student0 = std::move(Student4);
    std::cout << "Sveiki!" << std::endl;
    while (true)
        try
        {
            std::cout << "Programos eigos pasirinkimas:\n\"1\" - Ivedimas ranka\n\"2\" - Generavimas\n\"3\" - Skaitymas is failo\n\"4\" - Generuoti faila\n\"5\" - Atrinkti studentus\n\"6\" - Rezultatu isvedimas\n\"7\" - Vektoriaus testavimas\n\"8\" - Baigti darba\n" << std::endl;
            std::cin >> choice;
            if (std::cin.fail())
                CinError();
            if (choice < 1 || choice > 8)
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
                ReadFile(studVector, n);
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
                std::cout << "Pagal ka atrinkti?\n \"1\" - Pagal vidurki;\n \"2\" - Pagal mediana" << std::endl;
                std::cin >> choice;
                if (std::cin.fail())
                    CinError();
                if (choice < 1 || choice > 2)
                    throw std::runtime_error("Klaidinga ivestis");
                Selection(studVector, best, choice, n);
            }
            if (choice == 6)
                Results(studVector);
            if (choice == 7)
                VectorTest();
            if (choice == 8)
                exit(EXIT_FAILURE);
            system("pause");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

    return 0;
}
