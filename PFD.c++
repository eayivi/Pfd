/**
 * PFD.c++
 * Sophia Hernandez smh3665
 * Enam Ayivi aea787
 */

#include <iostream>
#include <cassert>
#include <vector>

#include "PFD.h"

using namespace std;

//read
std::vector<std::vector<int> > pfd_read(std::istream& r, int& n, int& m){
    cout << "In function read" << endl;
    r >> n;
    // if(!r)
    //     return false;
    r >> m;
    // if(!r)
    //     return false;
    
    assert(n > 0);
    assert(m > 0);

    cout << "n is " << n << " m is " << m << endl;

    std::vector<std::vector<int> > adj_matrix (n, std::vector<int>(n, 0));

    


    

    int vertex;
    int deps;   // number of dependencies per task as given in rule
    int value;
    while (m > 0){
        //cout << "In first while m =" << m << endl;
        r >> vertex;
        r >> deps;

        while(deps > 0){
        //    cout << "In second while deps =" << deps << endl;
            r >> value;
            adj_matrix[(vertex - 1)].at(value-1) = 1;
            --deps;
        }
        --m; 
    }

    cout << "Printing the matrix" << endl;
    for ( int j = 0; j<n ; j++ ) {
        for( std::vector<int>::iterator it = adj_matrix[j].begin(); it != adj_matrix[j].end(); ++it)
            std::cout << *it << ' ';

        cout << endl;
    }

    return adj_matrix;
}

// ------------
// pfd_eval
// ------------

void pfd_eval (std::vector<std::vector<int> >& A) {


}

// print


// solve
void pfd_solve(istream& r, ostream& w){
    int n; // N tasks
    int m; // M rules
        
    // vector for the stupid solution
    cout << "In function solve" << endl;


    pfd_eval(pfd_read(r, n, m)) ;
}
