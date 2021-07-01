#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using std::ostream;
using std::istream;




class Polynomial
{

  public:
    Polynomial();
    Polynomial( int dgr, const double* clist );
    Polynomial( const Polynomial& );
    ~Polynomial();

    int setDegree(int dgr); 
    int getDegree() const;   

    const Polynomial& operator=( const Polynomial& clist);
    bool operator==( const Polynomial& clist) const;




    void printPolynomial( int dgr, const double* clist );


    double operator[]( int index ) const;
    double& operator[]( int index );

  private:
      int    degree;
      double *coefficients; // list of coefficients


};

ostream& operator<<( ostream& , const Polynomial& );
istream& operator>>( istream& , Polynomial& );

#endif