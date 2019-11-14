#include "Initializations.h"

void tasksDurations(Orders* order, int total_orders)
{
	for (int i = 0; i < total_orders; i++) 
	{
		order[i].x1.duration = 13;
		order[i].x2.duration = 4;
		order[i].y1.duration = 13;
		order[i].y2.duration = 4;

		for (int j = 0; j < 3; j++)
		{
			order[i].y3[j].duration = 8;
		};
		order[i].y4.duration = 8;
		order[i].t_boil.duration = 600;
		order[i].t_heat.duration = 30;
		for (int j = 0; j < 4; j++)
		{
			order[i].t_wait[j].duration = 20;
		}
	}
}