/*
 * test.cpp
 *
 *  Created on: Mar 25, 2016
 *      Author: Lichao
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include "car.h"
#include "pid.h"
using namespace std;

int main(){
	float kP=1;
	float kI=0;
	float kD=0.5;
	vector<float> speed;
	vector<float> distance;

	Car simpleCar(1,0.1,0.01,0,0,Car::Still);
	PID pid(kP,kI,kD);

	//cout<<"Input kP kI kD and file number\n";
	//string number;
	//cin>>kP>>kI>>kD>>number;
	cout<<"PID simulation:\n";

	int simulationTime=200;
	cout<<"time\tVelocity\tDistance\n";
	for(int i=0;i<simulationTime;i++){
		//cout<<update(simpleCar,force)<<endl;
		pid.update(simpleCar,100);
		printf("%d\t%.3f\t\t%.3f\n",i,simpleCar.getVelocity(),simpleCar.getDistance());
		speed.push_back(simpleCar.getVelocity());
		distance.push_back(simpleCar.getDistance());
	}

	ofstream file("result.csv");
	for(int i=0;i<simulationTime;i++)
		file<<speed[i]<<","<<distance[i]<<endl;
	file.close();
}
