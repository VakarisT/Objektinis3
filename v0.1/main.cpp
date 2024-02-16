#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
const int N = 5;

struct Stud{
string Vard;
string Pavard;
int* paz;
int egz;
float vid;
float med;
};

void Skaityti(Stud & A);
double Median(Stud A, int n);

int main()
{
    Stud A[N];
    for(int i = 0; i < 2; i++)
        Skaityti(A[i]);
    cout << "Vardas  Pavarde         Galutinis(vid.) / Galutinis(med.)" << endl;
    cout << "---------------------------------------------------------" << endl;
    for(int j = 0; j < N; j++)
    {
        cout << A[j].Vard << '\t' << A[j].Pavard << '\t';
        cout << fixed << setprecision(2) << 0.4 * A[j].vid + 0.6 * A[j].egz << '\t' << '\t' << '\t';
        cout << fixed << setprecision(2) << 0.4 * A[j].vid + 0.6 * A[j].med << '\n';
    }
    return 0;
}
void Skaityti(Stud & A)
{
    int n = 0 , s = 0;
    cout << "Iveskite studento varda: "; cin >> A.Vard;
    cout << "Iveskite studento pavarde: "; cin >> A.Pavard;
    {cout << "Kiek pazymiu studentas gavo: "; cin >> n;}
    if (n == 0 || n > 100)
        exit(EXIT_FAILURE);

    cout << "Iveskite tuos pazymius: ";
    for(int i = 0; i < n; i++)
    {
        cin >> A.paz[i];
        while(A.paz[i] < 0 || A.paz[i] > 10)
        {cout << "Iveskite tinkama pazymi: "; cin >> A.paz[i];}
        s += A.paz[i];
    }
    cout << "Iveskite egzamino pazymi: "; cin >> A.egz;
    while(A.egz < 0 || A.egz > 10)
        {cout << "Iveskite tinkama pazymi: "; cin >> A.egz;}
    A.vid = (float)s / n;
    A.med = Median(A,n);
}
double Median(Stud A, int n)
{
    double m;
    sort(A.paz, A.paz + n);
    if(n % 2 == 0)
        m = (double)A.paz[n / 2];
    m = (double)(A.paz[(n - 1) / 2] + A.paz[n / 2]) / 2.0;
    return m;
}
