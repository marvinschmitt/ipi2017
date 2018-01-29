#ifndef SIMPLETESTS_H
#define SIMPLETESTS_H


#include <string>
#include <iostream>

#define test(F) simpletests::is_true(F,#F,__FILE__,__FUNCTION__,__LINE__)
#define test_eq(A,B) simpletests::is_equal(A,#A,B,#B,__FILE__,__FUNCTION__,__LINE__)

namespace simpletests {


	static int tests_total = 0;
	static int tests_failed = 0;

	static inline void is_true(bool ex , std::string name, std::string file, std::string func,  int line ) {
		tests_total++;
		if (!ex) {
			tests_failed++;
			std::cout << file << ":" << line << ":" << func << "() : ";
			std::cout << "The expression '" << name << "' is false" << std::endl;
		}
		
	}

	template <typename S, typename T>
	static inline void is_equal(S a , std::string a_name, T b , std::string b_name, std::string file, std::string func,  int line ) {
		tests_total++;
		if (a != b) {
			tests_failed++;
			std::cout << file << ":" << line << ":" << func << "() : ";
			std::cout << "Not equal: " << a_name << " != " << b_name << " because " << a_name << " = " << a << " and " << b_name << " = " << b << std::endl;
		}
		
	}

	void test_result() {
		std::cout << "Tests failed: " << tests_failed << "/" << tests_total << std::endl;
	}

}

#endif