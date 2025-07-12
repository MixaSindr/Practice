#include <iostream>
using namespace std;

long multToPower4(long a) {
    int b;
    b = a * a;
    a = b * b;
    return a;
}
long multToPower6(long a) {
    int b;
    b = a * a;
    a = b * b * b;
    return a;
}
long multToPower7(long a) {
    int b;
    b = a * a;
    a = b * b * b * a;
    return a;
}
long multToPower8(long a) {
    int b;
    b = a * a;
    a = b * b;
    b = a * a;
    return b;
}
long multToPower9(long a) {
    int b;
    b = a * a;
    a = b * b;
    b = a * a * b;
    return b;
}
long multToPower10(long a) {
    int b;
    b = a * a;
    a = b * b;
    b = a * a * b;
    return b;
}
int main()
{

}