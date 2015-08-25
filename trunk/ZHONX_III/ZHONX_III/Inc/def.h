#ifndef __DEF_H__
#define __DEF_H__

/**************************************************************************************/
/***************                 Times definitions                 ********************/
/**************************************************************************************/
#define LOW_TIME_FREQ			100
#define HI_TIME_FREQ			10000

/**************************************************************************************/
/***************                 Gyro definitions                 ********************/
/**************************************************************************************/
#define GYRO_VOLTAGE			3300   //Gyro is running at 3300mV
#define GYRO_ZERO_VOLTAGE		1658   //Gyro is zeroed at Vrate/2 (mV)
#define GYRO_SENSITIVITY		1.32   //Our example gyro is 6mV/deg/sec
#define ROTATION_THRESHOLD		1.00   //Minimum deg/sec to keep track of - helps with gyro drifting


#endif /* DEF_H_ */
