/**
 * PFD.c++
 * Sophia Hernandez smh3665
 * Enam Ayivi aea787
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <functional>
#include "PFD.h"

using namespace std;

/*struct Vertex{
    int number;
    int num_deps;
    std::vector<int> edges_in;

    Vertex(int n, int d, std::vector<int> e) : number(n), num_deps(d){
        std::vector<int> edges_in = e;
    }

    Vertex(int n, int d) : number(n), num_deps(d){
        std::vector<int> edges_in (d, 0);
    }

};*/

bool operator < (const Vertex& x, const Vertex& y) {
    if(x.num_deps < y.num_deps)
        return false;
    else if(x.num_deps == y.num_deps){
        if(x.number < y.number){
            return false;
        }
    }
    return true;
}

//read
std::vector<Vertex> pfd_read(std::istream& r, int& n, int& m){
   // cout << "In function read" << endl;
    // if(!r)
    //     return false;
    r >> n;
    r >> m;
    // if(!r)
    //     return false;
    
    assert(n > 0);
    assert(m >= 0);
    int rules = m;

   // cout << "n is " << n << " m is " << m << endl;

//    std::vector<std::vector<int> > adj_matrix (n, std::vector<int>(n, 0));
    std::vector<Vertex> graph;    
    int vertex;
    int deps;   // number of dependencies per task as given in rule
    int value;
    std::vector<int> dependencies;

    for(int i = 0; i < n; ++i){
        graph.push_back(Vertex(i+1));
    }

    while (rules > 0){
        // cout << "In first while m =" << m << endl;
        r >> vertex;    // 3 in our example
        r >> deps;      // 2 in our example
        int c = deps;
        while(c > 0){
           // cout << "In second while deps =" << deps << endl;
            r >> value; 
            graph[vertex-1].num_deps = deps;
//            adj_matrix[(vertex - 1)].at(value-1) = 1;
            graph[vertex-1].edges_in.push_back(value);
            --c;
        }
        --rules; 
    }

    // for (int i=0; i<n; ++i) {
    //     cout << "vertex number " << graph[i].number << " ";
    //     cout << "has " << graph[i].num_deps << " dependencies";
    //     cout << " which are ";

    //     for (int j=0; j< graph[i].num_deps; ++j) {
    //         cout << graph[i].edges_in[j] << " ";
    //     }

    //     cout << endl;


    // }
    //     cout << endl;
    //     cout << endl;

        // for (int i=0; i<n; ++i) {
        // cout << "vertex number " << graph[i].number << " ";
        // cout << "has " << graph[i].num_deps << " dependencies";
        // cout << " which are ";

        // for (int j=0; j< graph[i].num_deps; ++j) {
        //     cout << graph[i].edges_in[j] << " ";
        // }



    //}
//    return adj_matrix;
    return graph;
}


// ------------
// pfd_eval
// ------------

std::vector<int> pfd_eval (std::vector<Vertex>& graph, int n) {
       // cout << "n is " << n << endl;
//       cout << "Printing the matrix" << endl;
        
/*       for ( int j = 0; j< n ; ++j ) {
           for( std::vector<int>::const_iterator it = A[j].begin(); it != A[j].end(); ++it)
               std::cout << *it << ' ';
           cout << endl;
       }*/
        std::vector<int> outputArray;
        std::vector<Vertex>::const_iterator it;

        while(!graph.empty()){

            std::make_heap(graph.begin(), graph.end());
            int deleted_vertex =  graph.front().number;
            outputArray.push_back(deleted_vertex);


            pop_heap(graph.begin(), graph.end());
            graph.pop_back();
            
            for (it = graph.begin() ; it !=graph.end(); ++it) {

                for (unsigned int i = 0; i < it->edges_in.size(); ++i) {

                    if (deleted_vertex == it->edges_in[i]) {
                        it->num_deps--;
                    }

                }   
            } 

            // cout << "New graph size is " <<graph.size() << endl;
        }

        // cout << "out of while loop but still in eval";


      
    return outputArray;
}

// print
void pfd_print(std::ostream& w, const std::vector<int>& out){
 //    cout << "Final output" << endl;
        for( std::vector<int>::const_iterator it = out.begin(); it != out.end(); ++it)
                w << *it << ' ';
    w << endl;
}

// solve
void pfd_solve(istream& r, ostream& w){
    int n = 0; // N tasks   
    int m; // M rules
        
   // cout << "In function solve" << endl;

    std::vector<Vertex> v = pfd_read(r, n, m);
    std::vector<int> out = pfd_eval(v, n);
    pfd_print(w, out);
}
