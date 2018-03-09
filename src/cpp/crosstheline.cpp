#include <crosstheline.h>

void CrossTheLine::Start_Autonomous(float distance, float Encoder_Counts_Per_Wheel_Rotation, float Inches_Per_Wheel_Rotation, float Speed){
	if (Start)
	{
		timer.Reset();
		timer.Start();
		Start = false;
	}
	broadcasted_distance = distance;
	accessible_inches_per_wheel_rotation = Inches_Per_Wheel_Rotation;
	accessible_encoder_counts_per_wheel_rotation = Encoder_Counts_Per_Wheel_Rotation;
	accessible_speed = Speed;
	Run_Autonomous();
}
inline float CrossTheLine::Distance_to_Encoder_Counts(){
	return (broadcasted_distance * accessible_encoder_counts_per_wheel_rotation) / accessible_inches_per_wheel_rotation;
}
void CrossTheLine::Run_Autonomous(){
	
		talon_left_enc->ConfigPeakOutputForward(accessible_speed, 10);
		talon_left_enc->ConfigPeakOutputReverse(-1 * accessible_speed, 10);
		talon_right_enc->ConfigPeakOutputForward(accessible_speed, 10);
		talon_right_enc->ConfigPeakOutputReverse(-1 * accessible_speed, 10);
		talon_left_enc->Set(ControlMode::Position, Distance_to_Encoder_Counts());
		talon_right_enc->Set(ControlMode::Position, -1 * Distance_to_Encoder_Counts());
	
}