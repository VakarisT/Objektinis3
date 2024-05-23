#include "studentas.h"

const std::vector<std::string> nameList{ "Jonas","Amelija","Markas","Sofija","Benas","Liepa","Leonas","Liepa","Storas","Elija" };
const std::vector<std::string> surnameList{ "Syna","Kaminskaite","Kazlauskas","Vanagaite","Petrauskas","Ratkeviciute","Gradauskas","Petreikyte","Apuole","Sadauskaite" };

Student::Student() : hwRes_({ 0 })
{
    name_ = "NeraVardo";
    surname_ = "NeraPavardes";
    exRes_ = 0;
    avg_ = 0.0;
    med_ = 0.0;
}

Student::Student(std::string name, std::string surname) : hwRes_({ 0 })
{
    name_ = name;
    surname_ = surname;
    exRes_ = 0;
    avg_ = 0.0;
    med_ = 0.0;
}
Student::~Student()
{
    hwRes_.clear();
}

double Student::Average()
{
    if (hwRes_Size() > 0)
        return 0.4 * hw_Sum() / hwRes_Size() + 0.6 * get_exRes();
    else
        return 0.6 * get_exRes();
}

double Student::Median()
{
    std::vector<int> hwRes = get_HwRes();
    int size = hwRes_Size();
    if (size % 2 == 0 && size > 0)
        return (hwRes[size / 2 - 1] + hwRes[size / 2]) / 2.0 * 0.4 + 0.6 * get_exRes();
    else if (size % 2 != 0 && size > 0)
        return hwRes[size / 2] * 0.4 + 0.6 * get_exRes();
    else
        return 0.6 * get_exRes();
}

bool compareName(const Student &a, const Student &b)
{
    return a.get_Name() < b.get_Name();
}

bool compareSurname(const Student &a, const Student &b)
{
    return a.get_Surname() < b.get_Surname();
}

bool compareAvg(const Student &a, const Student &b)
{
    return a.get_Avg() < b.get_Avg();
}

bool compareMed(const Student &a, const Student &b)
{
    return a.get_Med() < b.get_Med();
}

int RandGrade()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}

void GenFile(int size, int hw)
{
    std::string fileName = "studentai" + std::to_string(size) + ".txt";
    std::ofstream output(fileName);
    std::stringstream out;

    out << std::left << std::setw(25) << "Vardas" << std::setw(25) << "Pavarde";
    for (int i = 1; i <= hw; i++)
        out << std::left << std::setw(10) << "ND" + std::to_string(i) << " ";
    out << std::left << std::setw(10) << "Egz." << std::endl;
    for (int i = 1; i <= size; i++)
    {
        out << std::left << std::setw(25) << "Vardas" + std::to_string(i) << std::setw(25) << "Pavarde" + std::to_string(i);
        for (int j = 0; j < hw; j++)
            out << std::left << std::setw(10) << RandGrade() << " ";
        out << std::left << std::setw(10) << RandGrade() << std::endl;
    }

    output << out.str();
    out.clear();
    output.close();
    std::cout << "Failas: " << fileName << " sugeneruotas" << std::endl;
}

void ReadFile(std::vector<Student> &studVector)
{
    try
    {
        std::cout << "Kiek studentu norite pamatyti (jei norite pabaigti, irasykite \"0\"): " << std::endl;
        //system("dir *.txt");
        int size;
        //std::string fileName;
        //std::cout << "Irasykite failo pavadinima (jei norite pabaigti, irasykite \"exit\"): ";
        std::cin >> size;
        if (size == 0)
            return;

        std::ifstream input("studentai" + std::to_string(size) + ".txt");
        if (!input.is_open())
            throw std::runtime_error("Nepavyko atidaryti failo! :(");

        const auto start = std::chrono::high_resolution_clock::now();

        Student stud;
        std::string line;
        input.ignore(1000, '\n');
        while (std::getline(input, line))
        {
            std::istringstream iss(line);
            std::string name, surname;
            if (!(iss >> name >> surname))
                throw std::runtime_error("Nepavyko nuskaityti failo! :(");
            stud.set_Name(name);
            stud.set_Surname(surname);
            int hw;
            stud.clear_Hw();
            while (iss >> hw)
                stud.set_Hw(hw);
            if (!stud.hwRes_Empty())
            {
                stud.set_ExRes(stud.hw_Last());
                stud.del_LastHw();
                stud.hw_Sort();
                stud.set_Avg(stud.Average());
                stud.set_Med(stud.Median());
            }
            studVector.push_back(stud);
        }

        input.close();
        std::cout << "Failas sekmingai nuskaitytas :)" << std::endl;
        studVector.shrink_to_fit();
        const auto end = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double> diff = end - start;
        std::cout << "Failo nuskaitymo laikas: " << diff.count() << " sekundes" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Selection(std::vector<Student>& studVector, int choice, std::vector<Student> best, std::vector<Student> worst)
{
    try
    {
        switch (choice) {
        case 1:
            sort(studVector.begin(), studVector.end(),
                [](const Student& a, const Student& b) { return (a.get_Name() < b.get_Name()); });
            break;
        case 2:
            sort(studVector.begin(), studVector.end(),
                [](const Student& a, const  Student& b) { return (a.get_Avg() < b.get_Avg()); });
            break;
        case 3:
            sort(studVector.begin(), studVector.end(),
                [](const Student& a, const Student& b) { return (a.get_Med() < b.get_Med()); });
            break;
        }
        Student st;
        for (int i = 0; i < studVector.size(); i++)
        {
            //Stud st = A.at(i);
            if (studVector.at(i).get_Avg() < 5.0)
            {
                st.set_Name(studVector.at(i).get_Name());
                st.set_Surname(studVector.at(i).get_Surname());
                st.set_Avg(studVector.at(i).get_Avg());
                st.set_Med(studVector.at(i).get_Med());
                worst.push_back(st);
                //st.clear();
            }
            else if (studVector.at(i).get_Avg() >= 5.0)
            {
                st.set_Name(studVector.at(i).get_Name());
                st.set_Surname(studVector.at(i).get_Surname());
                st.set_Avg(studVector.at(i).get_Avg());
                st.set_Med(studVector.at(i).get_Med());
                best.push_back(st);
                //st.clear();
            }
        }
        studVector.clear();
        /*if (choice == 1)
        {
            const auto start = std::chrono::high_resolution_clock::now();
            auto best = std::find_if(studVector.begin(), studVector.end(), [](const Student& stud)
                                     { return stud.get_Avg() >= 5.0; });
            //if (best != studVector.end())
                //studVector.erase(best, studVector.end());
            //else
                //throw std::runtime_error("Nera studento su vidurkiu >= 5.0");
            /*for (int i = 0; i < studVector.size(); i++)
            {
                //Stud st = A.at(i);
                if (studVector.at(i).avg_ < 5.0) {
                    best.push_back(studVector.at(i));
                    //auto it = A.begin() + i;
                }
            }
            while (studVector.front().avg_ < 5.0)
                studVector.pop_front();
            const auto end = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double> diff = end - start;
            std::cout << "Studentu atrankos laikas: " << diff.count() << " sekundes" << std::endl;
        }
        if (choice == 2)
        {
            const auto start = std::chrono::high_resolution_clock::now();
            auto best = std::find_if(studVector.begin(), studVector.end(), [](const Student &stud)
                                     { return stud.get_Med() >= 5.0; });
            if (best != studVector.end())
                studVector.erase(best, studVector.end());
            else
                throw std::runtime_error("Nera studento su mediana >= 5.0");
            const auto end = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double> diff = end - start;
            std::cout << "Studentu atrankos laikas: " << diff.count() << " sekundes" << std::endl;
        }*/
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Results(std::vector<Student> stud)
{
    try
    {
        //std::ofstream fout("")
        if (stud.size() < 1)
            throw std::runtime_error("Nera duomenu vektoriaus masyve!");
        std::cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(15) << "Galutinis (Med.)" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        for (const auto &i : stud)
            std::cout << std::left << std::setw(15) << i.get_Name() << std::setw(15) << i.get_Surname() << std::setw(20) << i.get_Avg() << std::setw(15) << i.get_Med() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void ReadUser(std::vector<Student> &studVector)
{
    try
    {
        Student temp;
        std::string name, surname;
        int hw, ex;

        while (true)
        {
            std::cout << "Vardas (jei norite uzbaigti, spauskite \"exit\"): ";
            std::cin >> name;
            if (name == "exit")
                break;
            std::cout << "Pavarde: ";
            std::cin >> surname;
            temp.set_Name(name);
            temp.set_Surname(surname);
            temp.clear_Hw();
            while (true)
            {
                std::cout << "Namu darbu pazymys (jei norite uzbaigti, spauskite \"-1\"): ";
                std::cin >> hw;
                if (std::cin.fail())
                    throw std::runtime_error("Klaidinga ivestis");
                if (hw < 0)
                    break;
                temp.set_Hw(hw);
            }
            std::cout << "Egzamino pazymys: ";
            std::cin >> ex;
            if (std::cin.fail())
                throw std::runtime_error("Klaidinga ivestis");
            temp.set_ExRes(ex);
            temp.set_Avg(temp.Average());
            temp.set_Med(temp.Median());
            studVector.push_back(temp);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void GenUser(std::vector<Student> &studVector, int size, int hw)
{
    int v, p;
    bool lytis;
    for (int i = 0; i < size; i++)
    {
        Student temp;
        v = RandGrade() - 1;
        lytis = v % 2;
        p = RandGrade() - 1;
        while(lytis != (p % 2))
            p = RandGrade() - 1;
        temp.set_Name(nameList[v]);
        temp.set_Surname(surnameList[p]);
        temp.clear_Hw();
        for (int j = 0; j < hw; j++)
            temp.set_Hw(RandGrade());
        temp.set_ExRes(RandGrade());
        temp.set_Avg(temp.Average());
        temp.set_Med(temp.Median());
        studVector.push_back(temp);
    }
}

void CinError()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw std::runtime_error("Klaidinga ivestis");
}
