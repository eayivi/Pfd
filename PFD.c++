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
void pfd_read(std::vector<std::vector<int> > a, int m){
    int deps;   // number of dependencies per task as given in rule
    while (m > 0){
       --m; 
    }
}

// eval


// print


// solve
bool pfd_solve(istream& r, ostream& w){
    int n; // N tasks
    int m; // M rules
    
    r >> n;
    if(!r)
        return false;
    r >> m;
    if(!r)
        return false;
    
    assert(n > 0);
    assert(m > 0);
    
    // vector for the stupid solution
    std::vector<std::vector<int> > adj_matrix (n, std::vector<int>(n, 0));
    pfd_read(adj_matrix, m);
}
