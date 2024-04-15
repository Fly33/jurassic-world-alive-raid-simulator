#ifndef JWA_SIMULATOR_STATS_H_
#define JWA_SIMULATOR_STATS_H_

#include <vector>
#include "dino.h"
#include "pack.h"

typedef enum {
	RESULT_DEFEAT = 0,
	RESULT_WIN = 1
} BattleResult;

class Stats
{
	int win_count = 0;
	int defeat_count = 0;

	std::vector<std::vector<std::vector<int>>> death_count[2];
	std::vector<std::vector<std::vector<int>>> min_hp[2];
	std::vector<std::vector<int>> round_turn_count[2];
	std::vector<std::vector<std::vector<std::vector<int>>>> damage[2];
	std::vector<std::tuple<int, int, int, int, int, int, int, int>> hit;
	std::vector<std::tuple<int, int>> turns;
	int curr_turn = 0;
	int curr_round = 0;
	int team_size;

public:
    Stats(int _team_size);
	void NextTurn(int round, int turn);
	void RegisterHit(int attacker, int target, int old_health, int new_health, int damage, int full_damage);
	void RegisterResult(bool win);
	void Print(Dino team[], int team_size);
};


#include "unpack.h"

#endif /* JWA_SIMULATOR_STATS_H_ */
