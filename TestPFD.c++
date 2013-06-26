/*
 *  TestPFD.c++
 *  
 *
 * Sophia Hernandez smh3665
 * Enam Ayivi aea787
 *
 */

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall PFD.c++ TestPFD.c++ -o TestPFD -lcppunit -ldl
    % valgrind TestPFD >& TestPFD.out
*/

// --------
// includes
// --------

#include "PFD.h"

#include <iostream> // cout, endl, ios_base
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

// -----------
// TestPFD
// -----------


struct TestPFD : CppUnit::TestFixture {
    // ----
    // read
    // ----

    void test_read_1 () {
        std::istringstream r("4\n3 2 1 5\n2 2 5 3\n4 1 3\n5 1 1");
        int n = 5;
        int m;
        const std::vector<Vertex> v = pfd_read(r, n, m);
       // CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(n ==   5);
        CPPUNIT_ASSERT(m ==   4);
        CPPUNIT_ASSERT(v[0].num_deps == 0);    //node 1 has no dependencies
        CPPUNIT_ASSERT(v[1].num_deps == 2);    //node 2 has 2 dependencies
        CPPUNIT_ASSERT(v[2].num_deps == 2);    //node 3 has 2 dependencies
        CPPUNIT_ASSERT(v[3].num_deps == 1);    //node 4 has 1 dependency
        CPPUNIT_ASSERT(v[4].num_deps == 1);    //node 5 has 1 dependency
    }


    void test_read_2 () {
        std::istringstream r("4\n3 1 1\n2 2 5 3\n4 1 3\n5 1 1");
        int n = 5;
        int m;
        const std::vector<Vertex> v = pfd_read(r, n, m);
        CPPUNIT_ASSERT(n ==   5);
        CPPUNIT_ASSERT(m ==   4);
        CPPUNIT_ASSERT(v[2].num_deps == 2);    //node 3 has 2 dependencies
        for(int i = 0; i < n; ++i)          // node 1 has 0 dependencies
            CPPUNIT_ASSERT(v[0].edges_in[i] == 0);
    }

    
/*    void test_read_3 () {
        std::istringstream r("55 22\n");
        int i;
        int j;
        const bool b = pfd_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    55);
        CPPUNIT_ASSERT(j ==   22);}*/

    // ----
    // eval
    // ----

    void test_eval_1 () {
        std::istringstream r("4\n3 2 1 5\n2 2 5 3\n4 1 3\n5 1 1");
        int n = 5;
        int m;
        std::vector<Vertex> v = pfd_read(r, n, m);
        std::vector<int> check = {1, 5, 3, 2, 4};
        std::vector<int> out = pfd_eval(v, n);
        for(std::vector<int>::const_iterator it = out.begin(); it != out.end(); ++it){
            CPPUNIT_ASSERT(*it == check.front());
            check.erase(check.begin());
        }
    }

/*    void test_eval_2 () {
        const int v = pfd_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);}

    void test_eval_3 () {
        const int v = pfd_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_4 () {
        const int v = pfd_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}

    // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        pfd_print(w);
        CPPUNIT_ASSERT(w.str() == "11 101 201\n");}

    void test_print_2 () {
        std::ostringstream w;
        pfd_print(w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
        
        
    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        pfd_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
        
    void test_solve_2 () {
        std::istringstream r("5 5\n1 1\n987 987\n54 12\n");
        std::ostringstream w;
        pfd_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "5 5 6\n1 1 1\n987 987 37\n54 12 113\n");}
*/

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestPFD);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
//    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_eval_1);
/*    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);*/
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestPFD.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestPFD::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}

   