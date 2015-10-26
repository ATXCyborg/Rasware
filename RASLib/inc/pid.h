#ifndef _R_PID_H_
#define _R_PID_H_

#ifdef __cplusplus
extern "C" {
#endif

// Definition of struct PID in pid.c
typedef struct PID tPID;

/**
 * Initializes a barebones PID module.
 * @param k_p   proportional term
 * @param k_i   integral term
 * @param k_d   derivative term
 * @return Pointer to an initialized tPID, can be used by the SetPID* functions
 */
tPID* InitializePID(float k_p, float k_i, float k_d);

/**
 * Sets the proportional term of the PID module
 * @param *pid  Initialized tPID, returned by InitializePID
 * @param k_p   Value of the proportional constant to set
 */
void SetP(tPID *pid, float k_p);

/**
 * Sets the integral term of the PID module
 * @param *pid  Initialized tPID, returned by InitializePID
 * @param k_i   Value of the integral constant to set
 */
void SetI(tPID *pid, float k_i);

/**
 * Sets the derivative term of the PID module
 * @param *pid  Initialized tPID, returned by InitializePID
 * @param k_d   Value of the derivative constant to set
 */
void SetD(tPID *pid, float k_d);

/**
 * Sets the feed-forward term of the PID module
 * @param *pid  Initialized tPID, returned by InitializePID
 * @param fdf   Value of the feed-forward constant to set
 */
void SetFeedForward(tPID *pid, float fdf);

/**
 * Sets the max output term to limit integral windup
 * @param *pid  Initialized tPID, retured by InitializePID
 * @param max   Maximum output value to allow for the system
 */
void SetMaxOut(tPID *pid, float max);

/**
 * Sets the min output term to limit integral windup
 * @param *pid  Initialized tPID, returned by InitializePID
 * @param min   Min output value to allow for the system
 */
void SetMinOut(tPID *pid, float min);

/**
 * Sets the setpoint for the system
 * @param *pid  Initialized tPID, returned by InitializePID
 * @param sp    Desired setpoint for the system
 */
void SetSetpoint(tPID *pid, float sp);

#endif //  _R_PID_H_
