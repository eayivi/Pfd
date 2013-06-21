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



std::vector<std::vector<int> > pfd_read(std::istream&, int&, int&);

#endif
