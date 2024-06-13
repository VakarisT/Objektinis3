V3.0 tyrimas.

## MyVector apžvalga
### push_back()
Prideda nurodytą elemento reikšmę prie konteinerio galo.
```cpp
MyVector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);

std::cout << "MyVector reiksmes:";
for (unsigned int i = 0; i < vec.size(); i++)
    std::cout << ' ' << vec[i];
std::cout << '\n';
```
Rezultatas
```cpp
MyVector reiksmes: 1 2 3

### capacity()
Nurodo dabartinę konteinerio talpą.
```cpp
MyVector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);

std::cout << "MyVector talpa: " << vec.capacity() << std::endl;
```
Rezultatas
```cpp
MyVector talpa: 4
```
### pop_back()
Pašalina paskutinį konteinerio elementą.
```cpp
MyVector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
vec.pop_back();

std::cout << "MyVector reiksmes:";
for (unsigned int i = 0; i < vec.size(); i++)
    std::cout << ' ' << vec[i];
std::cout << '\n';
```
Rezultatas
```cpp
MyVector reiksmes: 1 2
```
### shrink_to_fit()
Sumažina atminties naudojimą atlaisvindamas nenaudojamą atmintį.
```cpp
MyVector<int> vec;
for (unsigned int i = 0; i < 10; i++)
    vec.push_back(i);
    std::cout << "Talpa pries shrink_to_fit: " << vec.capacity() << "\n";
vec.shrink_to_fit();
std::cout << "Talpa po shrink_to_fit: " << vec.capacity() << "\n";
```
Rezultatas
```cpp
Talpa pries shrink_to_fit: 16
Talpa po shrink_to_fit: 10
```
### empty()
Patikrina ar konteineris yra tuščias.
```cpp
MyVector<int> vec;
std::cout << "Ar MyVector tuscias? " << (vec.empty() ? "Taip" : "Ne") << "\n";
```
Rezultatas
```cpp
Ar MyVector tuscias? Taip
```
## Testavimai
- Intel(R) Core(TM) i7-1065G7 CPU @ 1.30GHz
- RAM(8,0 GB)
- KBG40ZNV512G KIOXIA
### Konteinerių užpildymas (v3.0)
| Elementu skaicius | std::vector laikas | MyVector laikas | std::vector atminties perskirstymai | MyVector atminties perskirstymai |
|-------------------|--------------------|-----------------|-------------------------------------|----------------------------------|
| 10000             | 0.000068s           | 0.000041s        | 14                                  | 14                               |
| 100000            | 0.000384s           | 0.000293s        | 17                                  | 17                               |
| 1000000           | 0.002038s           | 0.001965s        | 20                                  | 20                               |
| 10000000          | 0.024393s           | 0.024126s        | 24                                  | 24                               |
| 100000000         | 0.233874s           | 0.227221s        | 27                                  | 27                               |
