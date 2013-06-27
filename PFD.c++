/**
 * PFD.c++
 * Sophia Hernandez smh3665
 * Enam Ayivi aea787
 */

#include <iostream>  // endl, istream, ostream
#include <cassert>  // assert
#include <vector>   // vector <Vertex>
#include <algorithm> // operator
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

// ------------
// operator, to compare vertices
// ------------

bool operator < (const Vertex& x, const Vertex& y) {
    assert(x.num_deps > -1);
    assert(y.num_deps > -1);

    if(x.num_deps < y.num_deps)
        return false;
    else if(x.num_deps == y.num_deps){
        if(x.number < y.number){
            return false;
        }
    }
    return true;
}

// ------------
// pfd_read
// ------------

std::vector<Vertex> pfd_read(std::istream& r, int& n, int& m){

    r >> n;
    r >> m;
    
    assert(n > 0);
    assert(m >= 0);

    int rules = m;
    std::vector<Vertex> graph;    
    int vertex;
    int deps;   // number of dependencies per task as given in rule
    int value;
    std::vector<int> dependencies;

    for(int i = 0; i < n; ++i){
        graph.push_back(Vertex(i+1));
    }

    while (rules > 0){

        r >> vertex;    // 3 in first example
        r >> deps;      // 2 in first example
        assert(vertex > 0);
        assert(deps >= 0);


        int c = deps;
        while(c > 0){
            r >> value; 
            graph[vertex-1].num_deps = deps;
            graph[vertex-1].edges_in.push_back(value);
            --c;
        }
        --rules;
    }

    return graph;
}


// ------------
// pfd_eval
// ------------

std::vector<int> pfd_eval (std::vector<Vertex>& graph) {

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
        }

     
    return outputArray;
}

// -------------
// pfd_print
// -------------

void pfd_print(std::ostream& w, const std::vector<int>& out){
    assert(out.size() != 0);

    for( std::vector<int>::const_iterator it = out.begin(); it != out.end(); ++it)
        w << *it << ' ';
    w << endl;
}

// -------------
// pfd_solve
// -------------

void pfd_solve(istream& r, ostream& w){
    int n = 0; // N tasks   
    int m; // M rules

    std::vector<Vertex> v = pfd_read(r, n, m);
    std::vector<int> out = pfd_eval(v);
    pfd_print(w, out);
}
