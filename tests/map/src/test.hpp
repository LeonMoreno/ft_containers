#ifndef TEST_HPP
# define TEST_HPP

#ifdef STD_VER
	#define VERSION "STD_VER"
	#define ft std
	#define FT STD
	#include <map>
#else
	#define VERSION  "FT_VER"
	#include "../../../include/map.hpp"
	#include "../../../include/utils.hpp"
#endif

#endif
