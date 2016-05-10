#ifndef PARAMETER_H 
#define PARAMETER_H 



/* theta */
#define THETA_DEFALT 0.00001

/* gamma */
#define GAMMA 0.9

/* reward for point A */
#define AREWARD 10 
/* reward for point B */
#define BREWARD 5

/* intial value */
#define VALUE_DEFAULT 0
/* intial policy (North) */
#define POLICY_DEFAULT 0

/* points A and A prime */
#define A_POS StateID(0,1) 
#define AP_POS StateID(4,1) 

/* points B and B prime */
#define B_POS StateID(0,3) 
#define BP_POS StateID(2,3) 

/* probability of going planned direction */
#define DIR1_PROBA 0.8
/* probability of going left/right relative to the planned direction */
#define DIR2_PROBA 0.1


#endif
