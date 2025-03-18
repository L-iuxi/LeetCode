#include <iostream>
#include <string.h>
#include <stdio.h>
class Student{
    public: 
    char name[13];
    int age;
    int grade;

    private:
    int secret;
};
int main()
{
Student a;
char n[13];
std::cin >> n;
strcpy(a.name,n);
std::cout << n << std::endl;
}