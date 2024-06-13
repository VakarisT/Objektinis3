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
