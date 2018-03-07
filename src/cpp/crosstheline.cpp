#include <crosstheline.h>

void CrossTheLine::Start_Autonomous(float distance, float Encoder_Counts_Per_Wheel_Rotation, float Inches_Per_Wheel_Rotation){
	if (Start)
	{
		timer.Reset();
		timer.Start();
		Start = false;
	}
	broadcasted_distance = distance;
	Run_Autonomous();
}
inline float CrossTheLine::Distance_to_Encoder_Counts(){
	return broadcasted_distance * Encoder_Counts_Per_Wheel_Rotation * Inches_Per_Wheel_Rotation;
}
void CrossTheLine::Run_Autonomous(){
	
	//	std::cout<<timer.Get()<<std::endl;
		talon_left_enc->Set(ControlMode::Position, Distance_to_Encoder_Counts());
		talon_right_enc->Set(ControlMode::Position, -1 * Distance_to_Encoder_Counts());
	
}