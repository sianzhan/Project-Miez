#include "Skeleton.h"
#define PI 3.14159

void Skeleton::actJoint(JOINT joint)
{
	joints[joint].act();
}

void Skeleton::resetJoint()
{
	for (int i = 0; i < 7; ++i) targets[i] = Joint();
}

void Skeleton::toggleAnimation(ANI ani)
{
	printf("TEST\n");
	if (getAnimation() == ani) animate(STILL);
	else animate(ani);
}

void Skeleton::animate(ANI ani)
{
	if (this->ani != ani)
	{
		this->ani = ani;
		tick = 0;
	}
}

void Skeleton::update()
{
	tick++;
	switch (ani)
	{
	case STILL:
		resetJoint();
		break;
	case RUN:
		targets[TORSO].setAngle(Joint::X_AXIS, rand() % 10 - 5);
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, sin(tick / 4.0) * 70);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, cos(tick / 4.0+PI/2) * 70);
		targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, sin(tick / 4.0+PI/4) * 60);
		targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, cos(tick / 4.0+PI/3) * 60);
		targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, sin(tick / 4.0) * (rand() % 40));
		targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, cos(tick / 4.0) * (rand() % 40));
		break;
	case BOW:
		targets[TORSO].setAngle(Joint::X_AXIS, 80);
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, 0);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, 0);
		break;
	case SIT:
		targets[TORSO].setAngle(Joint::X_AXIS, 0);
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, -90);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, -90);
		break;
	case PLACE_HEAD:
		if (tick < 5)
		{
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -40);
		}
		else if (tick < 10)
		{
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -80);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -80);
			targets[TORSO$R_ARM].setAngle(Joint::Y_AXIS, 20);
			targets[TORSO$L_ARM].setAngle(Joint::Y_AXIS, -20);
		}
		else if (tick < 20)
		{
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -120);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -120);
		}
		else
		{
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 0);
			animate(NONE);
		}
		break;
	case HELLO:
		if (tick < 10) {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 20);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 150);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, -0);

		}
		else if (tick < 20) {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 110);
		}
		else if (tick < 30) {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 20);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 150);
		}
		else if (tick < 40) {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 110);
		}
		else {
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 0);
			animate(NONE);
		}
		break;
	case DANCE:	
			if (tick%80 < 20) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 20);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 80);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -20);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 80);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO].setAngle(Joint::Z_AXIS, -20);
				targets[TORSO].setAngle(Joint::X_AXIS, 0);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 20);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 0);
			}
			else if (tick % 80  < 40) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -20);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -80);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 20);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -80);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO].setAngle(Joint::Z_AXIS, 20);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, -20);
			}
			else if (tick % 80  < 60) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -20);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 80);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 20);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 80);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO].setAngle(Joint::Z_AXIS, -20);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 20);

			}
			else if (tick % 80  < 80) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 20);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -80);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -20);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -80);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO].setAngle(Joint::Z_AXIS, 20);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, -20);
			}
			break;
	case GANGNAM:
		if (tick % 240 < 20) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -180+sin(tick / 4.0 ) *-25);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 4.0 ) *-25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -80);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -40);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick % 240 < 40) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -180 + sin(tick / 4.0) *-25);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 4.0) *-25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 0);
		}
		else if (tick % 240 < 60) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -180 + sin(tick / 4.0) *-25);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 4.0) *-25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 40);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
		}
		else if (tick % 240 < 80) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -180 + sin(tick / 4.0) *-25);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 4.0) *-25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 0);
		}
		else if (tick % 240 < 100) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -180 + sin(tick / 4.0) *-25);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 4.0) *-25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -40);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, -10);
		}
		else if (tick % 240 < 120) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -180 + sin(tick / 4.0) *-25);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 4.0) *-25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 0);
		}
		else if (tick % 240 < 140) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -40);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
		}
		else if (tick % 240 < 160) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 0);
		}
		else if (tick % 240 < 180) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 40);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
		}
		else if (tick % 240 < 200) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 0);
		}
		else if (tick % 240 < 220) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -40);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, -10);
		}
		else if (tick % 240 < 240) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 25);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 0);
		}
		break;
	case SOMERSAULT:
		targets[PIVOT].setAngle(Joint::X_AXIS, tick * 9);

		if (tick == 1)
		{
			this->setHeight(0.8);
			targets[TORSO].setAngle(Joint::X_AXIS, 45);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 90);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -90);
			break;
		}
		else if (tick == 5)
		{
			targets[TORSO].setAngle(Joint::X_AXIS, 100);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 90);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -90);
		}
		else if (tick == 15)
		{
			targets[TORSO].setAngle(Joint::X_AXIS, 120);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 90);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -90);
		}
		else if (tick == 30)
		{
			targets[TORSO].setAngle(Joint::X_AXIS, 70);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 150);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -150);
		}
		else if (tick == 40)
		{
			targets[TORSO].setAngle(Joint::X_AXIS, 20);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 30);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -30);
		}
		else if (tick > 45)
		{
			joints[PIVOT].setAngle(Joint::X_AXIS, 0);
			targets[PIVOT].setAngle(Joint::X_AXIS, 0);
			animate(STILL);
		}
		break;
	
	case WAVEHAND_R:
		if (tick == 1) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -60);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -20);
		}
		else if (tick == 5)
		{
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -120);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -rand()%30 + 30);
		}
		else if (tick == 10)
		{
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -rand()%20 + 20);
		}
		else if (tick == 15)
		{
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick == 20)
			animate(NONE);
		break;

	case WAVEHAND_L:
		if (tick == 1) {
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -60);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -20);
		}
		else if (tick == 5)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -120);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -rand() % 30 + 30);
		}
		else if (tick == 10)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -70);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -rand() % 20 + 20);
		}
		else if (tick == 15)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick > 20)
			animate(NONE);
		break;
	case FLOWER:
		if (tick  %640< 20) {
			i = 0;
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -95);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS,45);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::Y_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
			targets[TORSO$L_LEG].setAngle(Joint::Y_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
			targets[TORSO$R_LEG].setAngle(Joint::Y_AXIS, 0);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO].setAngle(Joint::Y_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick%640 < 40) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -95 );
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS,-45);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
	}
		else if (tick %640< 60) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 45);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick %640 < 80) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -45);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick%640  < 160) {
			i += 1;
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -85+  sin(tick / 4.0) *-10);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 40-i);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -85 + sin(tick / 4.0) *-10);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -40+i);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO].setAngle(Joint::X_AXIS, -10);
				targets[TORSO].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick %640 < 200) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -65);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -40);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -35);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 10);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$L_LEG].setAngle(Joint::Y_AXIS, -10);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
			targets[TORSO$R_LEG].setAngle(Joint::Y_AXIS, -10);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Y_AXIS, -50);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick %640 < 240) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -10);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 40);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -35);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 10);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
			targets[TORSO$L_LEG].setAngle(Joint::Y_AXIS, 10);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Y_AXIS, 10);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Y_AXIS, 0);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick%640  < 280) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -10);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -0);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 80);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
			targets[TORSO$L_LEG].setAngle(Joint::Y_AXIS, 10);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_LEG].setAngle(Joint::Y_AXIS, 10);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Y_AXIS, 20);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick%640 < 320) {
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -80);
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -10);
			targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$L_LEG].setAngle(Joint::Y_AXIS, -10);
			targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
			targets[TORSO$R_LEG].setAngle(Joint::Y_AXIS, -10);
			targets[TORSO].setAngle(Joint::X_AXIS, -10);
			targets[TORSO].setAngle(Joint::Y_AXIS, -20);
			targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
			targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
		}
		
		else if (tick %640 < 340) {
				i = 0;
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -95);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 45);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 0);
				targets[TORSO$L_ARM].setAngle(Joint::Y_AXIS, 0);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$L_LEG].setAngle(Joint::Y_AXIS, 0);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO$R_LEG].setAngle(Joint::Y_AXIS, 0);
				targets[TORSO].setAngle(Joint::X_AXIS, -10);
				targets[TORSO].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO].setAngle(Joint::Y_AXIS, 0);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			}
		else if (tick%640  < 360) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -95);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -45);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO].setAngle(Joint::X_AXIS, -10);
				targets[TORSO].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			}
		else if (tick%640  < 380) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 45);
				//targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -80);
				//targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO].setAngle(Joint::X_AXIS, -10);
				targets[TORSO].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			}
			else if (tick%640 <400) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -40);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -45);
				//targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -80);
				//targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -25);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO].setAngle(Joint::X_AXIS, -10);
				targets[TORSO].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			}
			else if (tick%640  <480) {
				i += 1;
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -85 + sin(tick / 4.0) *-10);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 40 - i);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -85 + sin(tick / 4.0) *-10);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -40 + i);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO].setAngle(Joint::X_AXIS, -10);
				targets[TORSO].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, 10);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			}
			else if (tick%640 < 560) {
				
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -90+ sin(tick / 4.0) *-25);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 35);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -90 +cos(tick / 4.0) *-25);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -35 );
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, -10);
				targets[TORSO$L_LEG].setAngle(Joint::Y_AXIS, 10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO$R_LEG].setAngle(Joint::Y_AXIS, 10);
				targets[TORSO].setAngle(Joint::X_AXIS, -20);
				targets[TORSO].setAngle(Joint::Y_AXIS, 45);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, -20);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			}
			else if (tick%640 < 640) {
				targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -90 + sin(tick / 4.0) *-25);
				targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 35);
				targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -90 + cos(tick / 4.0) *-25);
				targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -35);
				targets[TORSO$L_LEG].setAngle(Joint::Z_AXIS, 0);
				targets[TORSO$L_LEG].setAngle(Joint::Y_AXIS, -10);
				targets[TORSO$R_LEG].setAngle(Joint::Z_AXIS, 10);
				targets[TORSO$R_LEG].setAngle(Joint::Y_AXIS, -10);
				targets[TORSO].setAngle(Joint::X_AXIS, -20);
				targets[TORSO].setAngle(Joint::Y_AXIS, -45);
				targets[TORSO$HEAD].setAngle(Joint::X_AXIS, -20);
				targets[TORSO$HEAD].setAngle(Joint::Z_AXIS, 0);
			}
		break;
	case DA:
		
		targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, sin(tick / 7.0) * 10);
		targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, cos(tick / 7.0) * 90 - 80);
		targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, sin(tick / 7.0) * 10);
		targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -cos(tick / 7.0) * 90 + 80);
		targets[TORSO$L_LEG].setAngle(Joint::X_AXIS, cos(tick / 14.0) * 60);
		targets[TORSO$R_LEG].setAngle(Joint::X_AXIS, -cos(tick / 14.0) * 60);
		setHeight(sin(tick / 7.0) / 1.5);
		
		break;
	case MEOW:
		if (tick == 1) {
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -50);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 30);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -50);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -30);
		}
		else if (tick == 4)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -100);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 30);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -100);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, -30);
		}
		else if (tick == 8)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -130);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -15);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -130);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 15);
		}
		else if (tick == 12)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, -100);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, -30);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, -100);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 30);
		}
		else if (tick == 17)
		{
			targets[TORSO$L_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$L_ARM].setAngle(Joint::Z_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::X_AXIS, 0);
			targets[TORSO$R_ARM].setAngle(Joint::Z_AXIS, 0);
		}
		else if (tick > 20)
			animate(NONE);
		break;

	case NONE:
	default:;
	}


	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (fabs(joints[i].getAngle(j) - targets[i].getAngle(j)) > 0.001) {
				joints[i].setAngle(j, (joints[i].getAngle(j) + targets[i].getAngle(j)) / 2);
			}
			if (fabs(joints[i].getX(j) - targets[i].getX(j)) > 0.001)
				joints[i].setX(j, (joints[i].getX(j) + targets[i].getX(j))/2);
			if (fabs(joints[i].getY(j) != targets[i].getY(j)) > 0.001)
				joints[i].setY(j, (joints[i].getY(j) + targets[i].getY(j))/2);
			if (fabs(joints[i].getZ(j) != targets[i].getZ(j)) > 0.001)
				joints[i].setZ(j, (joints[i].getZ(j) + targets[i].getZ(j))/2);
		}
	}
}