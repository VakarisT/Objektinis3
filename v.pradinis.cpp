#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
const int N = 2;

struct Stud{
string Vard;
string Pavard;
int paz[];
int egz;
float vid;
double med;
};

void Skaityti(Stud & A);
double Median(Stud A, int n);

int main()
{
    Stud A[N];
    for(int i = 0; i < N; i++)
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
    int n , s = 0;
    cout << "Iveskite studento varda: "; cin >> A.Vard;
    cout << "Iveskite studento pavarde: "; cin >> A.Pavard;
    cout << "Kiek pazymiu studentas gavo: "; cin >> n;
    cout << "Iveskite tuos pazymius: ";
    for(int i = 0; i < n; i++)
    {
        cin >> A.paz[i];
        s += A.paz[i];
    }
    cout << "Iveskite egzamino pazymi: "; cin >> A.egz;
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
