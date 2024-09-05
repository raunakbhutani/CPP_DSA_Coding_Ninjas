/*
Problem statement
Implement a polynomial class, with the following properties and functions.

Properties :
1. An integer array (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.

2. An integer holding total size of array A.

Functions : 1. Default constructor 2. Copy constructor 3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value

4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.

5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result

6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result

7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.

8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.

Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases
*/



class Polynomial {
public:
  int *degCoeff;
  int capacity;
  Polynomial() {

    degCoeff = new int[10];
    capacity = 10;
    for (int i = 0; i < 10; i++)
      degCoeff[i] = 0;
  }

  Polynomial(Polynomial const &p) {
    
    degCoeff = new int[p.capacity];
    for (int i = 0; i < p.capacity; i++) {
      degCoeff[i] = p.degCoeff[i];
    }
    
    capacity = p.capacity;
  }

  void operator=(Polynomial const &p) {
    
    delete[] degCoeff;
    
    degCoeff = new int[p.capacity];
    
    for (int i = 0; i < p.capacity; i++) {
      degCoeff[i] = p.degCoeff[i];
    }
    
    capacity = p.capacity;
  }

  void setCoefficient(int degree, int coeff) {
    
    if (degree >= capacity) {
      int size = 2 * capacity;
    
      while (size <= degree) {
        size *= 2;
      }
      
      int *newDegCoeff = new int[size];
      
      for (int i = 0; i < size; i++) {
        newDegCoeff[i] = 0;
      }
      
      for (int i = 0; i < capacity; i++) {
        newDegCoeff[i] = degCoeff[i];
      }
      
      capacity = size;
      
      delete[] degCoeff;
      degCoeff = newDegCoeff;
    }
    
    degCoeff[degree] = coeff;
  }

  void print() {
    
    for (int i = 0; i < capacity; i++) {
      if (degCoeff[i] != 0) {
        cout << degCoeff[i] << "x" << i << " ";
      }
    }
    cout << endl;
  }

  Polynomial operator+(Polynomial const &p) {
    
    Polynomial pNew;
    int i = 0, j = 0;
    while (i < this->capacity && j < p.capacity) {
      
      int deg = i;
      int coeff = this->degCoeff[i] + p.degCoeff[j];
      pNew.setCoefficient(deg, coeff);
      i++;
      j++;
    
    }

    while (i < capacity) {

      pNew.setCoefficient(i, degCoeff[i]);
      i++;
    }
    
    while (j < p.capacity) {
      pNew.setCoefficient(j, p.degCoeff[j]);
      j++;
    }
    
    return pNew;
  }

  Polynomial operator-(Polynomial p) {
    
    Polynomial pNew;
    int i = 0, j = 0;
    
    while (i < this->capacity && j < p.capacity) {
      int deg = i;

      int coeff = this->degCoeff[i] - p.degCoeff[j];
      pNew.setCoefficient(deg, coeff);
      i++;
      j++;
    }

    while (i < capacity) {
      pNew.setCoefficient(i, degCoeff[i]);
      i++;
    }
    
    while (j < p.capacity) {
      pNew.setCoefficient(j, (-1 * p.degCoeff[j]));
      j++;
    }
    
    return pNew;
  }

  int getCoefficient(int degree) {
    if (degree >= capacity) {
      return 0;
    }
    
    return degCoeff[degree];
  }

  Polynomial operator*(Polynomial p) {
    
    Polynomial pNew;
    for (int j = 0; j < p.capacity; j++) {
      for (int i = 0; i < capacity; i++) {
        int deg = i + j;
        int coeff = pNew.getCoefficient(deg) + (this->degCoeff[i] * p.degCoeff[j]);
        
        pNew.setCoefficient(deg, coeff);
      }
    }

    return pNew;
  }
};
