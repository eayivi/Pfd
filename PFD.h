/**
 * PFD.h
 * Sophia Hernandez smh3665
 * Enam Ayivi 
 */
 
#ifndef PFD_h
#define PFD_h


#include <iostream>
#include <vector>

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
std::vector<std::vector<int> > pfd_read(std::istream&, int&, int&);

/**
 * pdf_eval
 * @param 
 *
 */
std::vector<int> pfd_eval (std::vector<std::vector<int> >, int);

/**
 * pdf_print
 * @param 
 *
 */
 void pfd_print(std::ostream&, const std::vector<int>&);

#endif
