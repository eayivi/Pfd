/**
 * PFD.h
 * Sophia Hernandez smh3665
 * Enam Ayivi 
 */
 
#ifndef PFD_h
#define PFD_h


#include <iostream>
#include <vector>

struct Vertex{
    int number;
    mutable int num_deps;
    std::vector<int> edges_in;

    Vertex(int n, int d, std::vector<int> e) : number(n), num_deps(d){
        std::vector<int> edges_in = e;
    }

    Vertex(int n, int d = 0) : number(n), num_deps(d){
        std::vector<int> edges_in (d, 0);
    }

};

/**
 * pdf_solve
 * @param r, w std:: istream and ostream respectively
 *
 */
void pfd_solve(std::istream&, std::ostream&);


/**
 * pdf_read
 * @param 
 * return std::vector<std::vector<int> >
 */
std::vector<Vertex> pfd_read (std::istream&, int&, int&);

/**
 * pdf_eval
 * @param 
 *
 */
std::vector<int> pfd_eval (std::vector<Vertex>&);

/**
 * pdf_print
 * @param 
 *
 */
 void pfd_print(std::ostream&, const std::vector<int>&);

#endif
