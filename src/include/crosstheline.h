#ifndef CROSS_THE_LINE_H
#define CROSS_THE_LINE_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include <math.h>
#include <Timer.h>

class CrossTheLine
{
public:
	CrossTheLine(TalonSRX *talon_left_enc, TalonSRX *talon_right_enc) : talon_right_enc(talon_right_enc), talon_left_enc(talon_left_enc) {
	};
	bool Start = 1;
	float broadcasted_distance;
	float accessible_inches_per_wheel_rotation;
	float accessible_encoder_counts_per_wheel_rotation;
	float accessible_speed;
	void Start_Autonomous(float distance, float Encoder_Counts_Per_Wheel_Rotation, float Inches_Per_Wheel_Rotation, float Speed);

private:
	TalonSRX *talon_left_enc, *talon_right_enc;
	Timer timer;
	inline float Distance_to_Encoder_Counts();
	void Run_Autonomous();
		
};

#endif
