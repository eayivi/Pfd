/**
 * PFD.c++
 * Sophia Hernandez smh3665
 * Enam Ayivi aea787
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include "PFD.h"

using namespace std;

struct Vertex{
    int number;
    int num_deps;
    std::vector<int> edges_in;

    Vertex(int n, int d, std::vector<int> e) : number(n), num_deps(d){
        std::vector<int> edges_in = e;
    }

    Vertex(int n, int d) : number(n), num_deps(d){
        std::vector<int> edges_in (d, 0);
    }

};

bool operator < (const Vertex& x, const Vertex& y) {
    if(x.num_deps < y.num_deps)
        return true;
    else if(x.num_deps == y.num_deps)
        if(x.number < y.number)
            return true;
    return false;
}

//read
std::vector<std::vector<int> > pfd_read(std::istream& r, int& n, int& m){
    cout << "In function read" << endl;
    // if(!r)
    //     return false;
    r >> m;
    // if(!r)
    //     return false;
    
    assert(n > 0);
    assert(m > 0);
    int rules = m;

    cout << "n is " << n << " m is " << m << endl;

    std::vector<std::vector<int> > adj_matrix (n, std::vector<int>(n, 0));
    std::priority_queue<Vertex> graph;


    int vertex;
    int deps;   // number of dependencies per task as given in rule
    int value;
    std::vector<int> dependencies;
    while (rules > 0){
        // cout << "In first while m =" << m << endl;
        r >> vertex;
        r >> deps;

        while(deps > 0){
           // cout << "In second while deps =" << deps << endl;
            r >> value;
            dependencies.push_back(value);
//            adj_matrix[(vertex - 1)].at(value-1) = 1;
            --deps;
        }
        graph.push(Vertex(vertex, deps, dependencies));
        dependencies.clear();
        int x = graph.top().number;
        cout << "graph num " << x << endl;
        --rules; 
    }



    return adj_matrix;
}


// ------------
// pfd_eval
// ------------

std::vector<int> pfd_eval (std::vector<std::vector<int> > A, int n) {
       // cout << "n is " << n << endl;
       cout << "Printing the matrix" << endl;
        
       for ( int j = 0; j< n ; ++j ) {
           for( std::vector<int>::const_iterator it = A[j].begin(); it != A[j].end(); ++it)
               std::cout << *it << ' ';
           cout << endl;
       }
        std::vector<int> outputArray;
        std::vector<int>::const_iterator it;
        for ( int j = 0; j< n ; ++j ) {
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
        for ( int j = 0; j< n ; ++j ) {
            for( std::vector<int>::const_iterator it = A[j].begin(); it != A[j].end(); ++it)
                std::cout << *it << ' ';
            cout << endl;
        }
 */

      
    return outputArray;
}

// print
void pfd_print(std::ostream& w, const std::vector<int>& out){
     cout << "Final output" << endl;
        for( std::vector<int>::const_iterator it = out.begin(); it != out.end(); ++it)
                std::cout << *it << ' ';
    cout << endl;
}

// solve
void pfd_solve(istream& r, ostream& w){
    int n; // N tasks
    r >> n;
    int m; // M rules
        
   cout << "In function solve" << endl;


    std::vector<int> out = pfd_eval(pfd_read(r, n, m), n);
    pfd_print(w, out);
}
