#include <string>

using namespace std;

class Data {
	public:
		static string program_name() 	{ return _program_name; }
		static string version_stamp() 	{ return _version_stamp; }
		static int version_number() 	{ return _version_number; }
		static int test_run() 			{ return _tests_run; }
		static int tests_passed() 		{ return _tests_passed; }

		static void program_name(const string& npn)
					{ _program_name = npn; }
		static void version_stamp(const string& nst)
					{ _version_stamp = nst; }
		static void version_number(int nval)
					{ _version_number = nval; }
		static void test_run(int nval)
					{ _tests_run = nval; }
		static void tests_passed(int nval)
					{ _tests_passed = nval; }

	private:
		static string _program_name;
		static string _version_stamp;
		static int _version_number;
		static int _tests_run;
		static int _tests_passed;
};
