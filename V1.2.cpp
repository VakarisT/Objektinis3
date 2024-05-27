#include "studentas.h"

int main()
{
    std::vector<Student> studVector;
    std::vector<Student> best;
    std::vector<Student> worst;
    int n , choice;

    std::cout << "Student Student0;" << std::endl;
    Student Student0;
    std::cout << "Student0: " << Student0 << std::endl;
    std::cout << "Student Student1(\"Vakaris\", \"Tiunaitis\");" << std::endl;
    Student Student1("Vakaris", "Tiunaitis");
    std::cout << "Student1: " << Student1 << std::endl;
    std::cout << "Student Student2(\"Vardas\", \"Pavarde\");" << std::endl;
    Student Student2("Vardas", "Pavarde");
    std::cout << "Student2: " << Student2 << std::endl;
    std::cout << "Student Student3(Student1);" << std::endl;
    Student Student3(Student1);
    std::cout << "Student3: " << Student3 << std::endl;
    std::cout << "Student Student4(std::move(Student2));" << std::endl;
    Student Student4(std::move(Student2));
    std::cout << "Student4: " << Student4 << std::endl;
    std::cout << "Student0 = Student1;" << std::endl;
    Student0 = Student1;
    std::cout << "Student0: " << Student0 << std::endl;
    std::cout << "Student0 = std::move(Student4);" << std::endl;
    Student0 = std::move(Student4);
    std::cout << "Student0: " << Student0 << std::endl;

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
            int hw;
            std::cout << "Studentu skaicius: ";
            std::cin >> n;
            if (n < 1)
                throw std::runtime_error("Klaidinga ivestis");
            if (std::cin.fail())
                CinError();
            std::cout << "Namu darbu skaicius: ";
            std::cin >> hw;
            if (std::cin.fail())
                CinError();
            if (hw < 1)
                throw std::runtime_error("Klaidinga ivestis");
            GenUser(studVector, n, hw);
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
            std::cout << "Pagal ka atrinkti? \n\"1\" - pagal varda/pavarde; \n\"2\" - Pagal vidurki; \n\"3\" - Pagal mediana\n";
            std::cin >> choice;
            if (std::cin.fail())
                CinError();
            if (choice < 1 || choice > 3)
                throw std::runtime_error("Klaidinga ivestis");
            Selection(studVector, choice, best, worst);
        }
        if (choice == 6) {
            std::ofstream fa("Nepazenge" + std::to_string(n) + ".txt");
            Results(fa, worst, "Nepazengusiuju");
            fa.close();
            std::ofstream fb("Pazenge" + std::to_string(n) + ".txt");
            Results(fb, best, "Pazengusiuju");
        }
        if (choice == 7)
            break;
            system("pause");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

    return 0;
}
