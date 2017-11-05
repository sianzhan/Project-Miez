#include "Skeleton.h"

void Skeleton::actJoint(JOINT joint)
{
	joints[joint].act();
}