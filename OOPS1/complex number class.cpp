/*
Problem statement
A ComplexNumber class contains two data members : one is the real part (R) and the other is imaginary (I) (both integers).

Implement the Complex numbers class that contains following functions -

1. constructor
You need to create the appropriate constructor.

2. plus -
This function adds two given complex numbers and updates the first complex number.

e.g.

if C1 = 4 + i5 and C2 = 3 +i1
C1.plus(C2) results in: 
C1 = 7 + i6 and C2 = 3 + i1
3. multiply -
This function multiplies two given complex numbers and updates the first complex number.

e.g.

if C1 = 4 + i5 and C2 = 1 + i2
C1.multiply(C2) results in: 
C1 = -6 + i13 and C2 = 1 + i2
4. print -
This function prints the given complex number in the following format :

a + ib
Note : There is space before and after '+' (plus sign) and no space between 'i' (iota symbol) and b.
  */


/**********
 
Following is the main function we are using internally.
Refer this for completing the ComplexNumbers class.
 
 
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
 
 ************/


class ComplexNumbers {
    private:
		int real;
		int complex;
	
	public:
		ComplexNumbers(int real,int complex){
			
      this->real=real;
			this->complex=complex;
		}

		void print(){
      
			if(complex>0)
			cout<<real<<" + "<<"i"<<complex;
			
      else
			cout<<real<<"-"<<"i"<<-complex;
		
    }

		void plus(ComplexNumbers n2){
			
      int r=real+n2.real;
			int c=complex+n2.complex;
			
			real=r;
			complex=c;
		}

		void multiply(const ComplexNumbers &n2){
			
      int r=(real * n2.real)-(complex * n2.complex);
			int c=(real * n2.complex)+(complex * n2.real);
			
			real = r;
			complex = c;
		}
};
