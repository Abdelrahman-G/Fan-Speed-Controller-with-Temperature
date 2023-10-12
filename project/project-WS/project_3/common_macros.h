 /******************************************************************************
 *
 * File Name: common_macros.c
 *
 * Description: Header file for the common macros
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/*set a pit in a register*/
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/*clear bit in a register*/
#define CLEAR_BIT(REG,BIT) (REG&=~(1<<BIT))

/*toggle bit in a register*/
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/*check if bit is set*/
#define BIT_IS_SET(REG,BIT) (REG&(1<<BIT))

/*check if bit is clear*/
#define BIT_IS_CLEAR(REG,BIT) (!(REG&(1<<BIT)))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )


#endif /* COMMON_MACROS_H_ */
