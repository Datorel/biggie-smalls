#include "main.h"

using namespace okapi;
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor r1			(12, 0);
	pros::Motor r2			(13, 1);
	pros::Motor r3			(14, 0);
	pros::Motor rr			(11, 1);
	pros::Motor rf			(15, 1);
	pros::Motor l1			(19, 1);
	pros::Motor l2			(18, 0);
	pros::Motor l3			(17, 1);
	pros::Motor lr			(20, 0);
	pros::Motor lf			(16, 0);
	pros::Motor tailR		(8, 1);
	pros::Motor tailL		(2, 0);
	pros::Motor liftRT	(3, 0);
	pros::Motor liftRB	(1, 0);
	pros::Motor liftLT	(10, 1);
	pros::Motor liftLB	(9, 1);
	pros::Motor claw		(5, 0);
	pros::Imu Inert			(6);
	Inert.reset();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {


	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor r1			(12, 0);
	pros::Motor r2			(13, 1);
	pros::Motor r3			(14, 0);
	pros::Motor rr			(11, 1);
	pros::Motor rf			(15, 1);
	pros::Motor l1			(19, 1);
	pros::Motor l2			(18, 0);
	pros::Motor l3			(17, 1);
	pros::Motor lr			(20, 0);
	pros::Motor lf			(16, 0);
	pros::Motor tailR		(8, 1);
	pros::Motor tailL		(2, 0);
	pros::Motor liftRT	(3, 0);
	pros::Motor liftRB	(1, 0);
	pros::Motor liftLT	(10, 1);
	pros::Motor liftLB	(9, 1);
	pros::ADIDigitalOut rClaw('b');
	pros::ADIDigitalOut lClaw('a');
	pros::ADIDigitalIn lBump('c');
	pros::ADIDigitalIn rBump('d');
	pros::Imu Inert			(6);

	//motors{16,17,18,19,20}

	#define VISION_PORT 7
	#define YELLER 1

	pros::Vision vision_sensor (7);

  pros::vision_signature_s_t YEL_GOAL = pros::Vision::signature_from_utility(YELLER, 1281, 1963, 1622, -3975, -3271, -3623, 3.000, 0);


  vision_sensor.set_signature(YELLER, &YEL_GOAL);

	//vision::signature YELLER (1, 1281, 1963, 1622, -3975, -3271, -3623, 3.000, 0);
	//vision::signature BLEW (2, -2269, -785, -1527, 4699, 7835, 6267, 2.200, 0);
	//vision::signature READ (3, 6337, 8103, 7220, -1087, -241, -664, 3.000, 0);
	//vision::signature SIG_4 (4, 0, 0, 0, 0, 0, 0, 3.000, 0);
	//vision::signature SIG_5 (5, 0, 0, 0, 0, 0, 0, 3.000, 0);
	//vision::signature SIG_6 (6, 0, 0, 0, 0, 0, 0, 3.000, 0);
	//vision::signature SIG_7 (7, 0, 0, 0, 0, 0, 0, 3.000, 0);
	//vex::vision vision1 ( vex::PORT1, 51, YELLER, BLEW, READ, SIG_4, SIG_5, SIG_6, SIG_7 );

	int select = 2;

	if (select == 0) {
		//lLift.move_velocity(-100);
		//rLift.move_velocity(-100);
		lf.move_voltage(12000);
		rf.move_voltage(12000);
		lr.move_voltage(12000);
		rr.move_voltage(12000);
		pros::delay(300);
		//lLift.move_velocity(0);
		//rLift.move_velocity(0);
		lf.move_voltage(-12000);
		rf.move_voltage(-12000);
		lr.move_voltage(-12000);
		rr.move_voltage(-12000);
		pros::delay(500);
		lf.move_velocity(0);
		rf.move_velocity(0);
		lr.move_velocity(0);
		rr.move_velocity(0);

	}

	else if (select == 1) {

		liftRT.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		liftRB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		liftLT.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		liftLB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

		//lLift.move_velocity(-100);
		//rLift.move_velocity(-100);
		lf.move_velocity(150);
		rf.move_velocity(180);
		lr.move_velocity(150);
		rr.move_velocity(180);
		pros::delay(2500);
		lf.move_velocity(150);
		rf.move_velocity(150);
		lr.move_velocity(150);
		rr.move_velocity(150);
		pros::delay(3500);
		//lLift.move_velocity(0);
		//rLift.move_velocity(0);
		lf.move_voltage(-12000);
		rf.move_voltage(-12000);
		lr.move_voltage(-12000);
		rr.move_voltage(-12000);
		pros::delay(1000);
		lf.move_velocity(0);
		rf.move_velocity(0);
		lr.move_velocity(0);
		rr.move_velocity(0);
	}

	else if (select == 2) {
		std::shared_ptr<ChassisController> chassis =
		ChassisControllerBuilder()
			.withMotors({16, 17, 18, 19, 20}, {11, 12, 13, 14, 15}) //{lF, lR}, {rF, rR}	{16, 17}, {13, 14}
			.withDimensions(AbstractMotor::gearset::green, {{5.875_in, 17.6_in}, imev5GreenTPR})
			.withOdometry()
			.withMaxVelocity(180)
			.withMaxVoltage(6000)
			.buildOdometry();
		std::shared_ptr<AsyncPositionController<double, double>> lift =
		AsyncPosControllerBuilder()
			.withMotor({10, 9, 3, 1})
			.withMaxVelocity(80)
			//.withMaxVelocity(80)
			//.withGains({liftkP, liftkI, liftkD})
			.build();
		std::shared_ptr<AsyncPositionController<double, double>> tail =
		AsyncPosControllerBuilder()
			.withMotor({-2, -8})
			.withMaxVelocity(200)
			//.withGains({liftkP, liftkI, liftkD})
			.build();
		pros::delay(50);

		//lift->setTarget(500);//up max
		//tail->setTarget(4000);//up max
		//chassis->turnAngle(360_deg);
		//tail->setTarget(6000);//up max
		lClaw.set_value(HIGH);
		rClaw.set_value(HIGH);
		lift->setTarget(200);
		pros::delay(50);
		chassis->moveDistanceAsync(60_in);

		lift->waitUntilSettled();
		lift->setTarget(0);
		while(r1.get_actual_velocity() > 160) {
			if (lBump.get_new_press()) {
				lClaw.set_value(LOW);
			}
			pros::delay(10);
		}
		chassis->waitUntilSettled();
		lift->tarePosition();
		chassis->setMaxVelocity(80);
		chassis->moveDistance(-30_in);
		chassis->turnAngle(28_deg);
		chassis->moveDistanceAsync(48_in);
		pros::delay(200); //wait for drivetrain to speed up
		while(r1.get_actual_velocity() > 160) {
			if (rBump.get_new_press()) {
				rClaw.set_value(LOW);
			}
			pros::delay(10);
		}
		chassis->waitUntilSettled();
		chassis->moveDistance(-48_in);
		chassis->turnAngle(-28_deg);
		chassis->moveDistance(-36_in);
		pros::delay(100000);
		tailR.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		tailL.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

		/*
		claw.move_velocity(-160);
		pros::delay(500);
		while (claw.get_voltage() > -11000) {
				pros::delay(20);
		}
		claw.move_velocity(0);
		*/
		chassis->moveDistance(8_in);
		chassis->turnAngle(107_deg);
		chassis->setMaxVelocity(80);
		chassis->moveDistance(90_in);
		chassis->setMaxVelocity(50);
		chassis->turnAngle(-102_deg);
		chassis->moveDistanceAsync(28_in);
		pros::delay(3000);
		chassis->stop();
		chassis->turnAngle(-90_deg);
		chassis->moveDistance(80_in);
		chassis->setMaxVelocity(200);
		chassis->moveDistance(-70_in);
		//tail->setTarget(4000);//up max
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor r1			(12, 0);
	pros::Motor r2			(13, 1);
	pros::Motor r3			(14, 0);
	pros::Motor rr			(11, 1);
	pros::Motor rf			(15, 1);
	pros::Motor l1			(19, 1);
	pros::Motor l2			(18, 0);
	pros::Motor l3			(17, 1);
	pros::Motor lr			(20, 0);
	pros::Motor lf			(16, 0);
	pros::Motor tailR		(8, 1);
	pros::Motor tailL		(2, 0);
	pros::Motor liftRT	(3, 0);
	pros::Motor liftRB	(1, 0);
	pros::Motor liftLT	(10, 1);
	pros::Motor liftLB	(9, 1);
	//pros::Motor claw		(5, 0);
	pros::Imu Inert			(6);
	pros::ADIDigitalIn rButton({{5, 'g'}});
	pros::ADIDigitalIn lButton({{5, 'h'}});
	pros::ADIDigitalIn armLimit('d');
	pros::ADIDigitalOut rClaw({{5, 'e'}});
	pros::ADIDigitalOut lClaw({{5, 'f'}});


	//pros::Rotation r(1);
	//pros::ADIDigitalOut stab('g');
	//pros::ADIDigitalOut claw('h');

	int rDrive;
	int lDrive;
	//r.reset_position();
	//lLift.set_zero_position(lLift.get_position());
	//int liftPos = r.get_position();
	r1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	l1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	r2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	l2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	r3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	l3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	lr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	lf.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	tailR.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	tailL.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	liftRT.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	liftRB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	liftLT.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	liftLB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//claw.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);



	int resetToggle = 0;
	int count = 0;

	bool rReady, lReady;

	while (true) {

		//std::cout << std::to_string(rClaw.get_value()) << std::endl;
		//std::cout << std::to_string(lClaw.get_value()) << std::endl;
		//rClaw.set_value(rButton.get_value());
		//lClaw.set_value(lButton.get_value());

		//drivetrain
		rDrive = master.get_analog(ANALOG_RIGHT_Y) - master.get_analog(ANALOG_RIGHT_X);
		lDrive = master.get_analog(ANALOG_RIGHT_Y) + master.get_analog(ANALOG_RIGHT_X);
		l1.move(lDrive);
		r1.move(rDrive);
		l2.move(lDrive);
		r2.move(rDrive);
		l3.move(lDrive);
		r3.move(rDrive);
		lr.move(lDrive);
		rr.move(rDrive);
		lf.move(lDrive);
		rf.move(rDrive);

		if (master.get_analog(ANALOG_LEFT_Y) < -20 && armLimit.get_value() == LOW) {
			liftRT.move(master.get_analog(ANALOG_LEFT_Y));
			liftRB.move(master.get_analog(ANALOG_LEFT_Y));
			liftLT.move(master.get_analog(ANALOG_LEFT_Y));
			liftLB.move(master.get_analog(ANALOG_LEFT_Y));
		}
		else if (master.get_analog(ANALOG_LEFT_Y) > 20) {
			liftRT.move(master.get_analog(ANALOG_LEFT_Y));
			liftRB.move(master.get_analog(ANALOG_LEFT_Y));
			liftLT.move(master.get_analog(ANALOG_LEFT_Y));
			liftLB.move(master.get_analog(ANALOG_LEFT_Y));
		}
		else {
			liftRT.move_velocity(0);
			liftRB.move_velocity(0);
			liftLT.move_velocity(0);
			liftLB.move_velocity(0);
		}

		if (master.get_digital(DIGITAL_UP)) {
			liftRT.move(-200);
			liftRB.move(-200);
			liftLT.move(-200);
			liftLB.move(-200);
		}



		/*//__arm
		//printf("Angle: %i \n", r.get_position());
		master.clear();
		master.print(0, 0,"Angle: %d", r.get_position());

			if (master.get_digital(DIGITAL_R1)) {
				//move up
				rLift.move_velocity(170);
				lLift.move_velocity(170);
			}
			 else if (master.get_digital(DIGITAL_R2)) {
				//move up
				rLift.move_velocity(-170);
				lLift.move_velocity(-170);
			}
			else {
				//move up
				rLift.move_velocity(0);
				lLift.move_velocity(0);
			}
*/

		if (rReady) {
			if (rButton.get_new_press()) {
				rReady = false;
				rClaw.set_value(HIGH);
			}
		}
		if (lReady) {
			if (lButton.get_new_press()) {
				lReady = false;
				lClaw.set_value(HIGH);
			}
		}

		if (master.get_digital(DIGITAL_R1)) {
			rClaw.set_value(LOW);
			rReady = true;
		}
		else if (master.get_digital(DIGITAL_R2)) {
			rClaw.set_value(HIGH);
		}

		if (master.get_digital(DIGITAL_L1)) {
			lClaw.set_value(LOW);
			lReady = true;
		}
		else if (master.get_digital(DIGITAL_L2)) {
			lClaw.set_value(HIGH);
		}

		//tail
		if (master.get_digital(DIGITAL_A)) {
			tailR.move_velocity(170);
			tailL.move_velocity(170);
		}
		else if (master.get_digital(DIGITAL_B)) {
			tailR.move_velocity(-170);
			tailL.move_velocity(-170);
		}
		else {
			tailR.move_velocity(0);
			tailL.move_velocity(0);
		}

		//reset
		if (master.get_digital(DIGITAL_X) && resetToggle == 0) {
			master.clear();
			master.print(0,0,"resetting");
			Inert.reset();
			resetToggle = 1;
		}
		else if (!master.get_digital(DIGITAL_X) && resetToggle == 1) {
			resetToggle = 0;
		}
		count++;
		if (count == 5) {
			master.clear();
			//printf("IMU roll: %f\n", Inert.get_roll());
			master.print(0,0,"roll: %f",Inert.get_roll());
			count = 0;
		}
		master.clear();
		//printf("IMU roll: %f\n", Inert.get_roll());
		master.print(0,0,"roll: %f",Inert.get_roll());
		//balance robot
		//while (master.get_digital(DIGITAL_Y)) {		}

		/*
		//claw
		if (master.get_digital(DIGITAL_L1)) {
			liftRT.move_velocity(170);
			liftRB.move_velocity(170);
			liftLT.move_velocity(170);
			liftLB.move_velocity(170);
		}
		else if (master.get_digital(DIGITAL_L2)) {
			liftRT.move_velocity(-80);
			liftRB.move_velocity(-80);
			liftLT.move_velocity(-80);
			liftLB.move_velocity(-80);
		}
		else {
			liftRT.move_velocity(0);
			liftRB.move_velocity(0);
			liftLT.move_velocity(0);
			liftLB.move_velocity(0);
		}*/
		//if (system("CLS")) system("clear");

		pros::delay(20);
	}
}
