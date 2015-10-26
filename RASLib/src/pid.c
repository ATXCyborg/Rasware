#include "pid.h"

typedef struct PID{
    //values for the different pid variables
    float k_p;  //proportional term
    float k_i;  //integral term
    float k_d;  //derivative term
    float fdf;  //feed-foward term

    //state variables (I.C.'s kept 0 to preserve causality)
    float e_sum;    //running sum of error
    float e_prev;   //previous state's error
    float e_curr;   //current error in the system
    float setpnt;   //setpoint for the system

    //limits on outputs and integral value (prevent integral windup)
    float max_out;  //max allowable output
    float min_out;  //min allowable output
};

//Used to initialize the basics needed for a PID module
tPID *InitializePID(float k_p, float k_i, float k_d){
    tPID *pid;
    pid->k_p = k_p;
    pid->k_i = k_i;
    pid->k_d = k_d;

    return pid;
}

//Sets the proportional constant for the provided PID module
void SetP(tPID *pid, float k_p){
    pid->k_p = k_p;
}

//Sets the integral constant for the provided PID module
void SetI(tPID *pid, float k_i){
    pid->k_i = k_i;
}

//Sets the derivative constant for the provided PID module
void SetD(tPID *pid, float k_d){
    pid->k_d = k_d;
}

//Sets the feed-forward constant for the provided PID module
void SetFeedForward(tPID *pid, float fdf){
    pid->fdf = fdf;
}

//Sets the max allowed output for the system. Used to prevent integral windup
void SetMaxOut(tPID *pid, float max){
    pid->max_out = max;
}

//Sets the min allowed output for the system. Used to prevent integral windup
void SetMinOut(tPID *pid, float min){
    pid->min_out = min;
}

//Sets the intended setpoint for the system
void SetSetpoint(tPID *pid, float sp){
    pid->setpnt = sp;
}
