#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include <math.h>
#include <Timer.h>
#include <crosstheline.h>

#define TALON_TIMEOUT_MILLISECONDS 10

// TODO: Set the SRX up as a regular talon...?
// Set up velocity controls
// Set the feedback device to the encoder

class Robot : public IterativeRobot {
	private:

		TalonSRX *talon_left_noenc, *talon_left_enc, *talon_right_enc, *talon_right_noenc;
		Joystick *joystick;
		//Timer *timer;
		CrossTheLine *autonomous;
		
		void RobotInit() { 

			talon_left_enc = new TalonSRX(3);
			talon_right_enc = new TalonSRX(2);
			talon_right_noenc = new TalonSRX(1);
			talon_left_noenc = new TalonSRX(4);
			talon_left_noenc->Set(ControlMode::Follower, 3);
			talon_right_noenc->Set(ControlMode::Follower, 2);
			autonomous = new CrossTheLine(talon_left_enc, talon_right_enc);
			joystick = new Joystick(0);

			std::cout<<"Oh la la! Un cochon. Il est tres beau. Il est plus beau que des cochons! Je s'adore!"<<std::endl;
			std::cout<<"Green Pig!"<<std::endl;

		}

		void TeleopInit() {
			std::cout<<"Oh la la! Un cochon. Il est tres beau. Il est plus beau que des cochons! Je s'adore!"<<std::endl;
			std::cout<<"Pink Pig!"<<std::endl;
			talon_left_enc->SetSelectedSensorPosition(0, 0, TALON_TIMEOUT_MILLISECONDS);
			talon_right_enc->SetSelectedSensorPosition(0, 0, TALON_TIMEOUT_MILLISECONDS);
				talon_left_enc->Config_kF(0, 0, TALON_TIMEOUT_MILLISECONDS);
			talon_left_enc->Config_kP(0, 2.55, TALON_TIMEOUT_MILLISECONDS);
			talon_left_enc->Config_kI(0, 0, TALON_TIMEOUT_MILLISECONDS);
			talon_left_enc->Config_kD(0, 0, TALON_TIMEOUT_MILLISECONDS);

			talon_right_enc->Config_kF(0, 0, TALON_TIMEOUT_MILLISECONDS);
			talon_right_enc->Config_kP(0, 2.56, TALON_TIMEOUT_MILLISECONDS);
			talon_right_enc->Config_kI(0, 0, TALON_TIMEOUT_MILLISECONDS);
			talon_right_enc->Config_kD(0, 0, TALON_TIMEOUT_MILLISECONDS);
		}

		void TeleopPeriodic() {
			//autonoumous->Start_Autonomous(Inches to go, Encoder counts per wheel rotation, inches traveled per wheel rotation)
			autonomous->Start_Autonomous(2, 600, 4);
			std::cout<<"Left Side: "<<talon_left_enc->GetSelectedSensorPosition(0)<<std::endl;
			std::cout<<"Right Side: "<<talon_right_enc->GetSelectedSensorPosition(0)<<std::endl;
			std::cout<<" "<<std::endl;
		}

		void AutonomousInit() {
			
		}

		void AutonomousPeriodic() {

		}

		void DisabledInit() {
			
			std::cout<<"Hi, I'm a pig. Oink"<<std::endl;
		}

		void TestInit(){

		}

		void TestPeriodic() {

		}
		
};

START_ROBOT_CLASS(Robot);