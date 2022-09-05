#include <iostream>
using namespace std;

class ComplexNumbers {
    private:
    int real;
    int imaginary;
    public:
    ComplexNumbers(int r,int i){
        real = r;
        imaginary = i;
    }
    
    void print(){
        cout<<real<<" + i"<<imaginary<<endl;
    }
    
    void plus(ComplexNumbers c){
        real+=c.real;
        imaginary+=c.imaginary;
    }
    // Done using operator overloading
    ComplexNumbers operator+(ComplexNumbers const &c)const {
        int r = real+c.real;
        int i = imaginary+c.imaginary;
        ComplexNumbers result = ComplexNumbers(r,i);
        return result;
    }
    void multiply(ComplexNumbers c){
        int r = (real*c.real) - (imaginary*c.imaginary);
        int i = (real*c.imaginary) + (imaginary*c.real);
        real = r;
        imaginary = i;
    }
    // Done using operator overloading
    ComplexNumbers operator*(ComplexNumbers const &c) const{
        int r = (real*c.real) - (imaginary*c.imaginary);
        int i = (real*c.imaginary) + (imaginary*c.real);
        return ComplexNumbers(r,i); 
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}