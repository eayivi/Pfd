/**
 * PFD.c++
 * Sophia Hernandez smh3665
 * Enam Ayivi aea787
 */

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

//read
std::vector<std::vector<int> > pfd_read(std::istream& r, int& n, int& m){
	//    cout << "In function read" << endl;
    // if(!r)
    //     return false;
    r >> m;
    // if(!r)
    //     return false;
    
    assert(n > 0);
    assert(m > 0);
	
	//    cout << "n is " << n << " m is " << m << endl;
	
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
    return adj_matrix;
}


// ------------
// pfd_eval
// ------------

void pfd_eval (std::vector<std::vector<int> > A, int n) {
       // cout << "n is " << n << endl;
/*       cout << "Printing the matrix" << endl;
        
       for ( int j = 0; j< n ; j++ ) {
           for( std::vector<int>::const_iterator it = A[j].begin(); it != A[j].end(); ++it)
               std::cout << *it << ' ';
           cout << endl;
       }*/
        std::vector<int> outputArray;
        std::vector<int>::const_iterator it;
        for ( int j = 0; j< n ; j++ ) {
            if (A[j][0] == -1) continue;
            for(it = A[j].begin(); it != A[j].end(); ++it) {
                //std::cout << *it << ' ';
                if (*it) break;
                if (it == A[j].end() -1) {                    
                    outputArray.push_back(j+1);
                    for(int k = 0; k<n; k++){
                        if(A[k].at(j) != -1)
                            A[k].at(j) = 0;
                    }
                    A[j][0]= -1;
                    j = -1;
                }
            }
            
        }
/*
        for ( int j = 0; j< n ; j++ ) {
            for( std::vector<int>::const_iterator it = A[j].begin(); it != A[j].end(); ++it)
                std::cout << *it << ' ';
            cout << endl;
        }
 */

       // cout << "Final output" << endl;
        for( std::vector<int>::const_iterator it = outputArray.begin(); it != outputArray.end(); ++it)
                std::cout << *it << ' ';
	cout << endl;
}

// print


// solve
void pfd_solve(istream& r, ostream& w){
    int n; // N tasks
    r >> n;
    int m; // M rules
	
	//    cout << "In function solve" << endl;
    pfd_eval(pfd_read(r, n, m), n) ;
}

// ----
// main
// ----

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    pfd_solve(cin, cout);
    return 0;
}


