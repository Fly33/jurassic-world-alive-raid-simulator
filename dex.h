#ifndef __DEX__H__
#define __DEX__H__

#include <map>
#include <string>
#include "dino.h"

extern const char VERSION[];

extern std::map<std::string, std::vector<Dino>> BossDex;
extern std::map<std::string, const DinoKind *> DinoDex;

#endif // __DEX__H__
