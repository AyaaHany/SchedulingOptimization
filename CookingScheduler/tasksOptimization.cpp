#include "tasksOptimization.h"

void orderSequence(Orders* order, int order_number, int start_time, Robots* robot1, Robots* robot2) {
	int i = order_number - 1;

	//R1 --> X1
	order[i].x1.start_time = start_time;
	order[i].x1.end_time = order[i].x1.start_time + order[i].x1.duration;
	//cout << "order " << order_number << ": x1 starts at " << order[i].x1.start_time << endl;
	//cout << "order " << order_number << ": x1 ends at " << order[i].x1.end_time << endl;
	//BOIL
	order[i].t_boil.start_time = order[i].x1.end_time;
	order[i].t_boil.end_time = order[i].t_boil.start_time + order[i].t_boil.duration;
	//cout << "order " << order_number << ": boiling starts at " << order[i].t_boil.start_time << endl;
	//cout << "order " << order_number << ": boiling ends at " << order[i].t_boil.end_time << endl;
	//R1 --> X2
	order[i].x2.start_time = order[i].t_boil.end_time;
	order[i].x2.end_time = order[i].x2.start_time + order[i].x2.duration;
	//cout << "order " << order_number << ": x2 starts at " << order[i].x2.start_time << endl;
	//cout << "order " << order_number << ": x2 ends at " << order[i].x2.end_time << endl;
	//HEAT
	order[i].t_heat.end_time = order[i].x2.end_time;
	order[i].t_heat.start_time = order[i].t_heat.end_time - order[i].t_heat.duration;
	//cout << "order " << order_number << ": heating starts at " << order[i].t_heat.start_time << endl;
	//cout << "order " << order_number << ": heating ends at " << order[i].t_heat.end_time << endl;
	//R2 --> Y1
	order[i].y1.end_time = order[i].t_heat.start_time;
	order[i].y1.start_time = order[i].y1.end_time - order[i].y1.duration;
	//cout << "order " << order_number << ": y1 starts at " << order[i].y1.start_time << endl;
	//cout << "order " << order_number << ": y1 ends at " << order[i].y1.end_time << endl;
	//R2 --> Y2
	order[i].y2.start_time = order[i].t_heat.end_time;
	order[i].y2.end_time = order[i].y2.start_time + order[i].y2.duration;
	//cout << "order " << order_number << ": y2 starts at " << order[i].y2.start_time << endl;
	//cout << "order " << order_number << ": y2 ends at " << order[i].y2.end_time << endl;
	//WAIT
	order[i].t_wait[0].start_time = order[i].y2.end_time;
	order[i].t_wait[0].end_time = order[i].t_wait[0].start_time + order[i].t_wait[0].duration;
	//cout << "order " << order_number << ": waiting 1 starts at " << order[i].t_wait[0].start_time << endl;
	//cout << "order " << order_number << ": waiting 1 ends at " << order[i].t_wait[0].end_time << endl;
	//R2 --> Y3
	order[i].y3[0].start_time = order[i].t_wait[0].end_time;
	order[i].y3[0].end_time = order[i].y3[0].start_time + order[i].y3[0].duration;
	//cout << "order " << order_number << ": y3 1 starts at " << order[i].y3[0].start_time << endl;
	//cout << "order " << order_number << ": y3 1 ends at " << order[i].y3[0].end_time << endl;
	//WAIT
	order[i].t_wait[1].start_time = order[i].y3[0].end_time;
	order[i].t_wait[1].end_time = order[i].t_wait[1].start_time + order[i].t_wait[1].duration;
	//cout << "order " << order_number << ": waiting 2 starts at " << order[i].t_wait[1].start_time << endl;
	//cout << "order " << order_number << ": waiting 2 ends at " << order[i].t_wait[1].end_time << endl;
	//R2 --> Y3
	order[i].y3[1].start_time = order[i].t_wait[1].end_time;
	order[i].y3[1].end_time = order[i].y3[1].start_time + order[i].y3[1].duration;
	//cout << "order " << order_number << ": y3 2 starts at " << order[i].y3[1].start_time << endl;
	//cout << "order " << order_number << ": y3 2 ends at " << order[i].y3[1].end_time << endl;
	//WAIT
	order[i].t_wait[2].start_time = order[i].y3[1].end_time;
	order[i].t_wait[2].end_time = order[i].t_wait[2].start_time + order[i].t_wait[2].duration;
	//cout << "order " << order_number << ": waiting 3 starts at " << order[i].t_wait[2].start_time << endl;
	//cout << "order " << order_number << ": waiting 3 ends at " << order[i].t_wait[2].end_time << endl;
	//R2 --> Y3
	order[i].y3[2].start_time = order[i].t_wait[2].end_time;
	order[i].y3[2].end_time = order[i].y3[2].start_time + order[i].y3[2].duration;
	//cout << "order " << order_number << ": y3 3 starts at " << order[i].y3[2].start_time << endl;
	//cout << "order " << order_number << ": y3 3 ends at " << order[i].y3[2].end_time << endl;
	//WAIT
	order[i].t_wait[3].start_time = order[i].y3[2].end_time;
	order[i].t_wait[3].end_time = order[i].t_wait[3].start_time + order[i].t_wait[3].duration;
	//cout << "order " << order_number << ": waiting 4 starts at " << order[i].t_wait[3].start_time << endl;
	//cout << "order " << order_number << ": waiting 4 ends at " << order[i].t_wait[3].end_time << endl;
	//R2 --> Y4
	order[i].y4.start_time = order[i].t_wait[3].end_time;
	order[i].y4.end_time = order[i].y4.start_time + order[i].y4.duration;
	//cout << "order " << order_number << ": y4 starts at " << order[i].y4.start_time << endl;
	//cout << "order " << order_number << ": y4 ends at " << order[i].y4.end_time << endl;
}

void intervalCheck(int interval_check, Orders* order, int order_number, Robots* robot1_check, Robots* robot2_check, Resources* status_check) {
	for (int i = 0; i < order_number; i++) {
		if (interval_check >= order[i].x1.start_time && interval_check < order[i].x1.end_time) robot1_check->status = true;

		if (interval_check >= order[i].t_boil.start_time && interval_check < order[i].t_boil.end_time) status_check->boiler[order[i].boiler_index] = true;

		if (interval_check >= order[i].y1.start_time && interval_check < order[i].y1.end_time) robot2_check->status = true;

		if (interval_check >= order[i].t_heat.start_time && interval_check < order[i].t_heat.end_time) status_check->heating_station[order[i].heating_index] = true;

		if (interval_check >= order[i].x2.start_time && interval_check < order[i].x2.end_time) robot1_check->status = true;

		if (interval_check >= order[i].y2.start_time && interval_check < order[i].y2.end_time) robot2_check->status = true;

		if (interval_check >= order[i].t_wait[0].start_time && interval_check < order[i].t_wait[3].end_time) status_check->cooking_station[order[i].cooking_index] = true;

		if (interval_check >= order[i].y3[0].start_time && interval_check < order[i].y3[0].end_time) robot2_check->status = true;
		if (interval_check >= order[i].y3[1].start_time & interval_check < order[i].y3[1].end_time) robot2_check->status = true;
		if (interval_check >= order[i].y3[2].start_time && interval_check < order[i].y3[2].end_time) robot2_check->status = true;

		if (interval_check >= order[i].y4.start_time && interval_check < order[i].y4.end_time) robot2_check->status = true;
	}

}

void resetStatusCheck(Robots* robot1_check, Robots* robot2_check, Resources* status_check) {
	robot1_check->status = false;
	robot2_check->status = false;

	status_check->boiler[0] = false;
	status_check->boiler[1] = false;
	status_check->boiler[2] = false;

	status_check->heating_station[0] = false;

	status_check->cooking_station[0] = false;
	status_check->cooking_station[1] = false;
}

void tasksAssignment(int now, Orders* order, int order_number, Robots* robot1, Robots* robot2, Resources* status) {
	for (int i = 0; i < order_number - 1; i++) {
		if (now == order[i].x1.start_time) robot1->status = true;
		else if (now == order[i].x1.end_time) robot1->status = false;

		if (now == order[i].t_boil.start_time) status->boiler[order[i].boiler_index] = true;
		else if (now == order[i].t_boil.end_time) status->boiler[order[i].boiler_index] = false;

		if (now == order[i].y1.start_time) robot2->status = true;
		else if (now == order[i].y1.end_time) robot2->status = false;

		if (now == order[i].t_heat.start_time) status->heating_station[order[i].heating_index] = true;
		else if (now == order[i].t_heat.end_time) status->heating_station[order[i].heating_index] = false;

		if (now == order[i].x2.start_time) robot1->status = true;
		else if (now == order[i].x2.end_time) robot1->status = false;

		if (now == order[i].y2.start_time) robot2->status = true;
		else if (now == order[i].y2.end_time) robot2->status = false;

		if (now == order[i].t_wait[0].start_time) status->cooking_station[order[i].cooking_index] = true;

		if (now == order[i].y3[0].start_time) robot2->status = true;
		else if (now == order[i].y3[0].end_time) robot2->status = false;
		if (now == order[i].y3[1].start_time) robot2->status = true;
		else if (now == order[i].y3[1].end_time) robot2->status = false;
		if (now == order[i].y3[2].start_time) robot2->status = true;
		else if (now == order[i].y3[2].end_time) robot2->status = false;

		if (now == order[i].t_wait[3].end_time) status->cooking_station[order[i].cooking_index] = false;

		if (now == order[i].y4.start_time) robot2->status = true;
		else if (now == order[i].y4.end_time) robot2->status = false;
	}

}

void printSchedule(int now, Orders* order, int order_number, Robots* robot1, Robots* robot2, Resources* status) {

	cout << "Second " << now << ": " << endl;
	cout << "	Robot #1 is " << (robot1->status ? "BUSY" : "AVAILABLE") << endl;
	cout << "	Robot #2 is " << (robot2->status ? "BUSY" : "AVAILABLE") << endl;

	for (int i = 0; i < order_number - 1; i++) {
		if (now > order[i].y4.end_time)
		{
			continue;
		}

		if (now == order[i].x1.start_time) {
			cout << "	Order " << i + 1 << " has started" << endl;
		}
		else if (now == order[i].y4.end_time) {
			cout << "	Order " << i + 1 << " is done" << endl;
		}

		if (now >= order[i].t_boil.start_time && now <= order[i].t_boil.end_time && status->boiler[order[i].boiler_index] == true) {
			cout << "	Boiler " << order[i].boiler_index + 1 << " is occupied with Order " << i + 1 << endl;
		}
		if (now >= order[i].t_heat.start_time && now <= order[i].t_heat.end_time && status->heating_station[order[i].heating_index] == true) {
			cout << "	Heating Station " << order[i].heating_index + 1 << " is occupied with Order " << i + 1 << endl;
		}
		if (now >= order[i].t_wait[0].start_time && now <= order[i].t_wait[3].end_time && status->cooking_station[order[i].cooking_index] == true) {
			cout << "	Cooking Station " << order[i].cooking_index + 1 << " is occupied with Order " << i + 1 << endl;
		}
	}

	cout << endl;
}

void ordersScheduling()
{
	cout << "Enter the number of orders: ";
	cin >> total_orders;

	for (int i = 0; i < total_orders; i++)
	{
		cout << "Enter the arriving time of Order(" << i + 1 << ") in seconds: ";
		cin >> arriving_times[i];
	}

	tasksDurations(order, total_orders);

	int x2_check = order[0].x1.duration + order[0].t_boil.duration; // general start of X2
	int y1_check = x2_check + order[0].x2.duration - order[0].t_heat.duration - order[0].y1.duration; // general start of Y1
	int y2_check = x2_check + order[0].x2.duration; // general start of Y2
	int y3_1_check = y2_check + order[0].y2.duration + order[0].t_wait[0].duration; // general start of Y3 (1)
	int y3_2_check = y3_1_check + order[0].y3[0].duration + order[0].t_wait[1].duration; // general start of Y3 (2)
	int y3_3_check = y3_2_check + order[0].y3[1].duration + order[0].t_wait[2].duration; // general start of Y3 (3)
	int y4_check = y3_3_check + order[0].y3[2].duration + order[0].t_wait[3].duration; // general start of Y4

	bool unavailable_slot = false;

	//Time Loop
	for (int time_count = 0; time_count <= 3600 + 1; time_count++)
	{

		if (time_count > 0) {
			tasksAssignment(time_count - 1, order, order_number, &robot1, &robot2, &status);
			//printSchedule(time_count - 1, order, order_number, &robot1, &robot2, &status);
		}

		unavailable_slot = false;
		boiler_index = 0;
		heating_index = 0;
		cooking_index = 0;

		if (time_count >= arriving_times[next_order])
		{
			if (arriving_times[next_order] == 0 && next_order != 0)
			{
				continue;
			}

			//Task X1 Check
			for (int interval_check = time_count; interval_check < (time_count + order[0].x1.duration); interval_check++)
			{
				resetStatusCheck(&robot1_check, &robot2_check, &status_check);
				intervalCheck(interval_check, order, order_number, &robot1_check, &robot2_check, &status_check);
				if (robot1_check.status == 0)
				{
					for (int check = 0; check < boilers_number; check++)
					{
						if (status_check.boiler[check] == 0 && boiler_index == 0)
						{
							boiler_index = check + 1;
						}
					}
					if (boiler_index == 0) unavailable_slot = true;
				}
				else
				{
					unavailable_slot = true;
					break;
				}
			}
			if (unavailable_slot == true)
			{
				continue;
			}

			//Task Y1 Check
			for (int interval_check = (time_count + y1_check); interval_check < (time_count + y1_check + order[0].y1.duration); interval_check++)
			{
				resetStatusCheck(&robot1_check, &robot2_check, &status_check);
				intervalCheck(interval_check, order, order_number, &robot1_check, &robot2_check, &status_check);
				if (robot2_check.status == 0)
				{
					for (int check = 0; check < heating_number; check++)
					{
						if (status_check.heating_station[check] == 0 && heating_index == 0)
						{
							heating_index = check + 1;
						}
					}
					if (heating_index == 0) unavailable_slot = true;
				}
				else
				{
					unavailable_slot = true;
					break;
				}
			}
			if (unavailable_slot == true)
			{
				continue;
			}

			//Task X2 Check
			for (int interval_check = (time_count + x2_check); interval_check < (time_count + x2_check + order[0].x2.duration); interval_check++)
			{
				resetStatusCheck(&robot1_check, &robot2_check, &status_check);
				intervalCheck(interval_check, order, order_number, &robot1_check, &robot2_check, &status_check);
				if (robot1_check.status != 0)
				{
					unavailable_slot = true;
					break;
				}
			}
			if (unavailable_slot == true)
			{
				continue;
			}

			//Task Y2 Check
			for (int interval_check = (time_count + y2_check); interval_check < (time_count + y2_check + order[0].y2.duration); interval_check++)
			{
				resetStatusCheck(&robot1_check, &robot2_check, &status_check);
				intervalCheck(interval_check, order, order_number, &robot1_check, &robot2_check, &status_check);
				if (robot2_check.status == 0)
				{
					for (int check = 0; check < cooking_number; check++)
					{
						if (status_check.cooking_station[check] == 0 && cooking_index == 0)
						{
							cooking_index = check + 1;
						}
					}
					if (cooking_index == 0) unavailable_slot = true;
				}
				else
				{
					unavailable_slot = true;
					break;
				}
			}
			if (unavailable_slot == true)
			{
				continue;
			}

			//Task Y3 Check
			//ONE
			for (int interval_check = (time_count + y3_1_check); interval_check < (time_count + y3_1_check + order[0].y3[0].duration); interval_check++)
			{
				resetStatusCheck(&robot1_check, &robot2_check, &status_check);
				intervalCheck(interval_check, order, order_number, &robot1_check, &robot2_check, &status_check);
				if (robot2_check.status != 0)
				{
					unavailable_slot = true;
					break;
				}
			}
			if (unavailable_slot == true)
			{
				continue;
			}
			//TWO
			for (int interval_check = (time_count + y3_2_check); interval_check < (time_count + y3_2_check + order[0].y3[1].duration); interval_check++)
			{
				resetStatusCheck(&robot1_check, &robot2_check, &status_check);
				intervalCheck(interval_check, order, order_number, &robot1_check, &robot2_check, &status_check);
				if (robot2_check.status != 0)
				{
					unavailable_slot = true;
					break;
				}
			}
			if (unavailable_slot == true)
			{
				continue;
			}
			//THREE
			for (int interval_check = (time_count + y3_3_check); interval_check < (time_count + y3_3_check + order[0].y3[2].duration); interval_check++)
			{
				resetStatusCheck(&robot1_check, &robot2_check, &status_check);
				intervalCheck(interval_check, order, order_number, &robot1_check, &robot2_check, &status_check);
				if (robot2_check.status != 0)
				{
					unavailable_slot = true;
					break;
				}
			}
			if (unavailable_slot == true)
			{
				continue;
			}

			//Task Y4 Check
			for (int interval_check = (time_count + y4_check); interval_check < (time_count + y4_check + order[0].y4.duration); interval_check++)
			{
				resetStatusCheck(&robot1_check, &robot2_check, &status_check);
				intervalCheck(interval_check, order, order_number, &robot1_check, &robot2_check, &status_check);
				if (robot2_check.status != 0)
				{
					unavailable_slot = true;
					break;
				}
			}
			if (unavailable_slot == true)
			{
				continue;
			}

			order[next_order].boiler_index = boiler_index - 1;
			order[next_order].heating_index = heating_index - 1;
			order[next_order].cooking_index = cooking_index - 1;

			orderSequence(order, order_number, time_count, &robot1, &robot2);

			order_number++;
			next_order = order_number - 1;
		}
	}

	for (int i = 0; i < total_orders; i++)
	{
		cout << endl << "order " << i + 1 << ": arrived at second " << arriving_times[i] << endl;

		if (order[i].x1.start_time < 60)
		{
			cout << "order " << i + 1 << ": started at second " << order[i].x1.start_time << endl;
		}
		else
			cout << "order " << i + 1 << ": started at minute " << order[i].x1.start_time/60.0 << endl;
		
		cout << "order " << i + 1 << ": ended at minute " << (order[i].y4.end_time/60.0) << endl;

		
	}

}