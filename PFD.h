/**
 * PFD.h
 * Sophia Hernandez smh3665
 * Enam Ayivi 
 */

 
#ifndef PFD_h
#define PFD_h

// --------
// includes
// --------

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

// -------------
//	pfd_solve
// -------------


/**
 * read, eval, print values
 * @param w a std::ostream
 * @param r a std::istream
 *
 */
void pfd_solve(std::istream&, std::ostream&);


// ------------
// pfd_read
// ------------
/**
 * reads two ints into i and j
 * @param r a std::istream
 * @param i an int by reference
 * @param j an int by reference
 * @return std::vector<std::vector<int> >
 */
std::vector<Vertex> pfd_read (std::istream&, int&, int&);


// ------------
// pfd_eval
// ------------
/**
 * 
 * @param v a vector of struct Vertex
 * @return a set of int that in order of required execution
 */
std::vector<int> pfd_eval (std::vector<Vertex>&);

// -------------
// pfd_print
// -------------
/**
 * print the value to the stream
 * @param w a std::ostream
 * @ param v a vector of int with the values to print
 */
 void pfd_print(std::ostream&, const std::vector<int>&);

#endif
