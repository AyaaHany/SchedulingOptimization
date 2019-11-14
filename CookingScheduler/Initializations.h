#pragma once
#ifndef __INITIALIAZATIONS_H__
#define __INITIALIAZATIONS_H__

#include <iostream>
using namespace std;

struct Tasks {
	bool status = 0;
	int start_time = -1;
	int duration = 0;
	int end_time = -1;
};

struct Orders {
	Tasks x1, x2, y1, y2, y3[3], y4, t_boil, t_heat, t_wait[4];
	int boiler_index;
	int heating_index;
	int cooking_index;
};

struct Robots {
	bool status = 0;
};

struct Resources {
	bool boiler[3] = { 0 };
	bool heating_station[1] = { 0 };
	bool cooking_station[2] = { 0 };
};

static Robots robot1, robot2, robot1_check, robot2_check;
static Resources status, status_check;
static int total_orders = 0;
static Orders order[100];

static int arriving_times[100] = {0};
static int order_number = 1;
static int next_order = order_number - 1;

//If any of the following numbers is to be changed, the corresponding number in struct Resources must also be changed, and resetStatusCheck
static int boilers_number = 3;
static int heating_number = 1;
static int cooking_number = 2;

static int boiler_index = 0;
static int heating_index = 0;
static int cooking_index = 0;

void tasksDurations(Orders*, int);

#endif // !__INITIALIAZATIONS_H__

