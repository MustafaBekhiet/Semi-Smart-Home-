

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/**
 * @details configure the INT0 sense control, options are:	1- EXTI_LOW_LEVEL
 * 															2- EXTI_ON_CHANGE
 * 															3- EXTI_FALLING_EDGE
 * 															4- EXTI_RISING_EDGE
 */

#define INT0_SENSE_CTRL			EXTI_FALLING_EDGE


/**
 * @details configure the INT0 initial state, options are:	1- ENABLED
 * 															2- DISABLED
 *
 */
#define INT0_INITIAL_STATE			DISABLED





/**
 * @details configure the INT1 sense control, options are:	1- EXTI_LOW_LEVEL
 * 															2- EXTI_ON_CHANGE
 * 															3- EXTI_FALLING_EDGE
 * 															4- EXTI_RISING_EDGE
 */

#define INT1_SENSE_CTRL			EXTI_FALLING_EDGE


/**
 * @details configure the INT1 initial state, options are:	1- ENABLED
 * 															2- DISABLED
 *
 */
#define INT1_INITIAL_STATE			DISABLED






/**
 * @details configure the INT2 sense control, options are:	1- EXTI_RISING_EDGE
 * 															2- EXTI_FALLING_EDGE
 */
#define INT2_SENSE_CTRL			EXTI_FALLING_EDGE


/**
 * @details configure the INT2 initial state, options are:	1- ENABLED
 * 															2- DISABLED
 *
 */
#define INT2_INITIAL_STATE			ENABLED



#endif
