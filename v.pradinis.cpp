#include <iostream>
#include <iomanip>

using namespace std;
const int N = 2;

struct Stud{
string Vard;
string Pavard;
int paz[];
int egz;
float vid;
};

void Skaityti(Stud A);

int main()
{
    Stud A[N];
    Skaityti(A);
    return 0;
}
void Skaityti(Stud A)
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
    A.vid = s / n;
}
