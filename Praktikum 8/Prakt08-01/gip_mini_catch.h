// Datei: gip_mini_catch.h
// Autor: Andreas Claßen
// Version: 1.0
//
// Basiert auf Konzepten und Mechanismen
// des Catch Header-Only (bis v2) Frameworks
// https://github.com/catchorg/Catch2

#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Catch {

    typedef void (*test_fun_ptr_type)();

    class TestCaseInfo {
    public:
        test_fun_ptr_type test_fun_ptr;
        std::string desc, fun_name;
        int line_number;
    public:
        TestCaseInfo(test_fun_ptr_type _test_fun_ptr, std::string _desc,
                     std::string _fun_name, int _line_number):
                test_fun_ptr(_test_fun_ptr), desc(_desc),
                fun_name(_fun_name), line_number(_line_number)
            {}
    };

    class TestCaseRegister {
    public:
        // "inline" loest das C++ Static Initialization Order Fiasco ...
        // Nur verfuegbar C++17 und spaeter ...
        inline static std::vector<TestCaseInfo> test_case_infos;
    public:
            TestCaseRegister(test_fun_ptr_type test_fun_ptr, std::string desc,
                             std::string fun_name, int line_number)
                {
                    test_case_infos.push_back( TestCaseInfo{test_fun_ptr, desc, fun_name, line_number} );
                }
            static void run() {
                for(TestCaseInfo& tc_info : test_case_infos) {
                    tc_info.test_fun_ptr();
                }
            }
    };

    class Session {
    public:
        inline static int assertions_total, assertions_passed, assertions_failed;
    public:
        static void run() {
            assertions_total = assertions_passed = assertions_failed = 0;
            TestCaseRegister::run();
            if (assertions_total == assertions_passed) {
                std::cerr << "Alle Tests erfolgreich ("
                << assertions_total << " REQUIREs in "
                << TestCaseRegister::test_case_infos.size()
                << " Test Cases)" << std::endl;
            }
            else {
                std::cerr << "Tests Cases: "
                << TestCaseRegister::test_case_infos.size()
                << "\nREQUIREs: "
                << assertions_total << " | "
                << assertions_passed << " erfolgreich | "
                << assertions_failed << " fehlgeschlagen\n";
            }
        }
    };

    inline void collect_ok(std::string expr, std::string fun_name, std::string filename, int line_number) {
        Session::assertions_passed += 1;
        Session::assertions_total += 1;
    }

    inline void collect_fail(std::string expr, std::string fun_name, std::string filename, int line_number) {
        Session::assertions_failed += 1;
        Session::assertions_total += 1;
        for(TestCaseInfo& tc_info : TestCaseRegister::test_case_infos) {
            if (tc_info.fun_name == fun_name) {
                std::cerr << "FEHLGESCHLAGEN: Datei " << filename 
                          << ", Zeile " << line_number 
                          << ": " << tc_info.desc
                          << "\nREQUIRE(" << expr << ")" << std::endl;
                break;
            }
        }
    }

    #define Q(x) #x
    #define QUOTE(x) Q(x)

#ifndef TEST_FILE
    #define UNIQUE_NAME3( name , line ) name##line
    #define UNIQUE_NAME2( name , line ) UNIQUE_NAME3( name ,line )
    #define UNIQUE_NAME( name ) UNIQUE_NAME2( name , __LINE__ )
#else
    #define UNIQUE_NAME3( name , file , line ) name##file##line
    #define UNIQUE_NAME2( name , file, line ) UNIQUE_NAME3( name , file , line )
    #define UNIQUE_NAME( name ) UNIQUE_NAME2( name , TEST_FILE, __LINE__ )
#endif
    #define TEST_CASE( desc ) \
        void UNIQUE_NAME( test_function )(); \
        Catch::TestCaseRegister UNIQUE_NAME( regtc )( & UNIQUE_NAME( test_function ), desc , QUOTE( UNIQUE_NAME( test_function ) ) , __LINE__ ); \
        void UNIQUE_NAME( test_function )()


    #define REQUIRE( expr ) \
        if (expr) { Catch::collect_ok(#expr, __func__, __FILE__, __LINE__); } \
        else { Catch::collect_fail(#expr, __func__, __FILE__, __LINE__); }
}
