#include "Libr.h"
#include "Str.h"

void Skaityti(std::vector<Stud>& A);
float Median(Stud A);
void Rusiuoti(std::vector<Stud>& A, int r);

int main()
{
    std::vector<Stud> A;
    int N, r = 0;
    try {
        Skaityti(A);
    }
    catch (std::exception& ex) {
        std::cout << "Tuscia";
    }
    std::cout << A.size() << "\n";
    if (A.size() == 1)
        std::cout << "Nera studentu\n";
    std::cout << "Pagal ka norie rusiuoti?" << '\n';
    std::cout << "Pagal vardus - 1" << '\n';
    std::cout << "Pagal pavardes - 2" << '\n';
    std::cout << "Pagal galutini su vidurkiais - 3" << '\n';
    std::cout << "Pagal galutini su medianomis - 4" << '\n';

    try {
        std::cin >> r;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Blogai ivestas elementas" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Blogai ivestas elementas" << std::endl;
    }

    Rusiuoti(A, r);

    std::ofstream fout("kursiokai.txt");
    fout << "Vardas         Pavarde                  Galutinis(vid.) / Galutinis(med.)" << '\n';
    fout << "-------------------------------------------------------------------------" << '\n';
    for (auto j = A.begin(); j != A.end(); j++)
    {
        fout << j->Vard << std::setw(16) << j->Pavard << std::setw(10) << '\t';
        fout << std::fixed << std::setprecision(2) << j->vid << std::setw(18);
        fout << std::fixed << std::setprecision(2) << j->med << '\n';
    }
    fout.close();
    return 0;
}
void Skaityti(std::vector<Stud>& A)
{
    std::ifstream fin("studentai.txt");
    if (fin.fail()) std::cout << "Nėra failo\n";
    Stud st;
    std::string v;
    int n = 0;
    int p, i, s;
    while (v != "Egz.") {
        fin >> v;
        n++;
    }
    n -= 3;

    while (!fin.eof()) {
        fin >> st.Vard;
        if (st.Vard == "")
            throw std::underflow_error();
        fin >> st.Pavard;
        s = 0;
        for (i = 0; i < n; i++) {
            try {
                fin >> p;
            } catch (std::logic_error& le)
            {std::cout << "Rastas blogas simbolis" << '\n';}
            st.paz.push_back(p);
            s += p;
        }
        try {
            fin >> st.egz;
        } catch (std::out_of_range& ex)
        {std::cout << "Rastas blogas simbolis" << '\n';}

        if (n != 0) {
            st.vid = 0.4 * ((float)s / n) + 0.6 * st.egz;
            st.med = 0.4 * (float)Median(st) + 0.6 * st.egz;
        }
        else {
            st.vid = 0;
            st.med = 0;
        }
        A.push_back(st);
    }
    fin.close();
}
float Median(Stud A)
{
    sort(A.paz.begin(), A.paz.end());
    int n = A.paz.size();
    if (n % 2 == 0)
        return (float)A.paz[n / 2];
    else
        return (float)(A.paz[(n - 1) / 2] + A.paz[n / 2]) / 2.0;
}
void Rusiuoti(std::vector<Stud>& A, int r)
{
    switch (r) {
    case 1:
        sort(A.begin(), A.end(),
            [](const Stud& a, const Stud& b) { return (a.Vard < b.Vard); });
        break;
    case 2:
        sort(A.begin(), A.end(),
            [](const Stud& a, const Stud& b) { return (a.Pavard < b.Pavard); });
        break;
    case 3:
        sort(A.begin(), A.end(),
            [](const Stud& a, const  Stud& b) { return (a.vid < b.vid); });
        break;
    case 4:
        sort(A.begin(), A.end(),
            [](const Stud& a, const Stud& b) { return (a.med < b.med); });
        break;
    }
}
