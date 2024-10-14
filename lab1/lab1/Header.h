#ifndef _HEADER_GUARD_
#define _HEADER_GUARD_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iterator>
#include <regex>
#include <string>
#include <locale.h>
#include <vector>
using namespace std;

int func_h_regex(string l, vector<string>& V, regex h_regex);
int func_p_regex(string l, vector<string>& V, regex p_regex);
int func_ref_regex(string l, vector<string>& V, regex ref_regex);

#endif
