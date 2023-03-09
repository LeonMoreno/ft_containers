#ifndef TEST_HPP
# define TEST_HPP

#ifdef STD_VER
	#define VERSION "STD_VER"
	#define ft std
	#define FT STD
	#include <stack>
	#include <vector>
#else
	#define VERSION  "FT_VER"
	#include "../../../containers/stack.hpp"
	#include "../../../headers/utils.hpp"
#endif

#endif
