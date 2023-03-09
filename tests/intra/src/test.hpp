#ifndef TEST_HPP
# define TEST_HPP

#ifdef STD_VER
	#define VERSION "STD_VER"
	#define ft std
	#define FT STD
	#include <map>
#else
	#define VERSION  "FT_VER"
	#include "../../../containers/map.hpp"
	#include "../../../headers/utils.hpp"
#endif

#endif
