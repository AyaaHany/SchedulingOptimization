#pragma once
#ifndef __TASKS_OPTIMIZATION_H__
#define __TASKS_OPTIMIZATION_H__

#include "Initializations.h"

void orderSequence(Orders*, int, int, Robots*, Robots*);
void intervalCheck(int, Orders*, int, Robots*, Robots*, Resources*);
void resetStatusCheck(Robots*, Robots*, Resources*);
void tasksAssignment(int, Orders*, int, Robots*, Robots*, Resources*);
void printSchedule(int, Orders*, int, Robots*, Robots*, Resources*);
void ordersScheduling();

#endif // !__TASKS_OPTIMIZATION_H__

 
