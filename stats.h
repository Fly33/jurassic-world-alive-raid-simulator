#ifndef JWA_SIMULATOR_STATS_H_
#define JWA_SIMULATOR_STATS_H_

#include <vector>
#include "dino.h"
#include "pack.h"

typedef enum {
	RESULT_DEFEAT = 0,
	RESULT_WIN = 1
} BattleResult;

class BaseStats
{
	int win_count = 0;
	int defeat_count = 0;

	std::vector<std::vector<std::vector<int>>> death_count[2];
	std::vector<std::vector<std::vector<int>>> min_hp[2];
	std::vector<std::vector<int>> round_turn_count[2];
	std::vector<std::vector<std::vector<std::vector<int>>>> damage[2];
	std::vector<std::tuple<int, int, int, int, int, int>> hit;
	std::vector<std::tuple<int, int>> turns;
	int curr_turn = 0;
	int curr_round = 0;
	int team_size;

public:
    static bool on;
    static BaseStats &Get()
    {
        static BaseStats stats;
        return stats;
    }

    void Init(int _team_size);
	void NextTurn(int round, int turn);
	void RegisterHit(const Dino &attacker, const Dino &target, int damage);
	void RegisterResult(bool win);
	void Print(Dino team[], int team_size);
};

template<auto F>
class Wrapper;

template<typename Klass, typename ...Args, void (Klass::*F)(Args...)>
class Wrapper<F>
{
public:
    void operator()(Args ...args)
    {
        if (!Klass::on)
            return;
        Klass &stats = Klass::Get();
        (stats.*F)(std::forward<Args>(args)...);
    }
};

class Stats : private BaseStats
{
public:
    using BaseStats::on;
    static Wrapper<&BaseStats::Init> Init;
    static Wrapper<&BaseStats::NextTurn> NextTurn;
    static Wrapper<&BaseStats::RegisterHit> RegisterHit;
    static Wrapper<&BaseStats::RegisterResult> RegisterResult;
    static Wrapper<&BaseStats::Print> Print;
};

#include "unpack.h"

#endif /* JWA_SIMULATOR_STATS_H_ */
