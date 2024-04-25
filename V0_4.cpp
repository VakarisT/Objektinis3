#include "Libr.h"
#include "Str.h"

template<class T>
std::string toString(const T& value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

void Skaityti(std::vector<Stud>& A);
float Median(Stud A);
void Rusiuoti(std::vector<Stud>& A);
void Generuoti(int n, int p);
void Paskirstyti(std::vector<Stud>& A, std::vector<Stud>& A1, std::vector<Stud>& A2);
void Isvesti(std::ofstream& fout, std::vector<Stud>& A);

int main()
{
    std::vector<Stud> A;
    std::vector<Stud> A1;
    std::vector<Stud> A2;
    
    int i , n , p;
    std::cout << "Kiek bus uzduota namu darbu? "; 
    try {
        std::cin >> p;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Blogai ivestas elementas" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Blogai ivestas elementas" << std::endl;
    }
    auto tpr = high_resolution_clock::now();
    for (n = 1000; n <= 10000000; n *= 10)
    {
        Generuoti(n, p);
        auto t1pr = high_resolution_clock::now();
        Skaityti(A);
        Rusiuoti(A);
        Paskirstyti(A, A1, A2);
        std::ofstream fa("Nepazenge" + toString(n) + ".txt");
        Isvesti(fa, A1);
        fa.close();
        std::ofstream fb("Pazenge" + toString(n) + ".txt");
        Isvesti(fb, A2);
        fb.close();
        A1.clear();
        A2.clear();
        auto t1pb = high_resolution_clock::now();
        std::cout << "Bendra trukme: " << double((duration_cast<milliseconds>(t1pb - t1pr)).count()) / 1000.0 << " s\n";
        system("pause");
    }
    auto tpb = high_resolution_clock::now();
    std::cout << "Visos programos atlikimo trukme: " << double((duration_cast<milliseconds>(tpb - tpr)).count()) / 1000.0 << " s\n";
    return 0;
}
void Skaityti(std::vector<Stud>& A)
{
    auto t1 = high_resolution_clock::now();
    std::ifstream fin("Studentai.txt");
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
        fin >> st.Pavard;
        s = 0;
        for (i = 0; i < n; i++) {
            fin >> p;
            st.paz.push_back(p);
            s += p;
        }
        fin >> st.egz;
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
    auto t2 = high_resolution_clock::now();
    std::cout << "Skaitymo trukme: " << double((duration_cast<milliseconds>(t2 - t1)).count()) / 1000.0 << " s\n";
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
void Rusiuoti(std::vector<Stud>& A)
{
    auto t1 = high_resolution_clock::now();
    sort(A.begin(), A.end(),
        [](const Stud& a, const  Stud& b) { return (a.vid < b.vid); });
    auto t2 = high_resolution_clock::now();
    std::cout << "Rusiavimo trukme: " << double((duration_cast<milliseconds>(t2 - t1)).count()) / 1000.0 << " s\n";
}
void Generuoti(int n, int p)
{
    srand(time(NULL));
    std::ofstream fout("Studentai.txt");
    fout << "Vardas" << " " << "Pavarde" << " ";
    for (int i = 0; i < p; i++)
        fout << "ND" << i << " ";
    fout << "Egz." << '\n';
    
    for (int ii = 1; ii <= n; ii++)
    {
        fout << "Vardas" << ii << " " << "Pavarde" << ii << " ";
        for (int iii = 0; iii < p + 1; iii++)
            fout << rand() % 11 << " ";
        fout << '\n';
    }
    fout.close();
}
void Paskirstyti(std::vector<Stud>& A, std::vector<Stud>& A1, std::vector<Stud>& A2)
{
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < A.size(); i++)
    {
        Stud st = A.at(i);
        if (st.vid < 5.0)
            A1.push_back(st);
        else if (st.vid >= 5.0)
            A2.push_back(st);
    }
    A.clear();
    auto t2 = high_resolution_clock::now();
    std::cout << "Paskirstymo trukme: " << double((duration_cast<milliseconds>(t2 - t1)).count()) / 1000.0 << " s\n";
}
void Isvesti(std::ofstream& fout, std::vector<Stud>& A)
{
    auto t1 = high_resolution_clock::now();
    fout << "Vardas         Pavarde                  Galutinis(vid.) / Galutinis(med.)" << '\n';
    fout << "-------------------------------------------------------------------------" << '\n';
    for (auto i = A.begin(); i != A.end(); i++)
    {
        fout << i->Vard << std::setw(16) << i->Pavard << std::setw(10) << '\t';
        fout << std::fixed << std::setprecision(2) << i->vid << std::setw(18);
        fout << std::fixed << std::setprecision(2) << i->med << '\n';
    }
    fout.close();
    auto t2 = high_resolution_clock::now();
    std::cout << "Isvedimo trukme: " << double((duration_cast<milliseconds>(t2 - t1)).count()) / 1000.0 << " s\n";
}