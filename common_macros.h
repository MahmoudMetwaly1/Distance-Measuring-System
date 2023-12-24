/*============================================================================================
 * FILE NAME:            common_macros.h
 * AUTHER :              MAHMOUD METWALY
 * DATE CREATED :        30/9/2022
 * DESCRIPTION :         COMANLEY USED MACROS

 ===========================================================================================*/
#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* set bit in any register */
#define SET_BIT(REG,BIT)  (REG |= (1<<BIT))

/* clear bit in any register */
#define CLEAR_BIT(REG,BIT)   (REG &= (~(1<<BIT)))

/* toggle bit in any register */
#define TOGGLE_BIT(REG,BIT)   (REG^= (1<<BIT))

/* rotate right the register value with specific number of Rotate */
#define ROR(REG,num)    (REG = (REG >> num) | (REG << (8*sizeof(REG)-num)))

/* Rotate left  the register value with specific number of Rotate */
#define ROL(REG,num)    (REG = (REG << num) | (REG >> (8*sizeof(REG)-num)))

/* check if specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT)      (REG & (1 << BIT))

/* check if specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT)    (!(REG & (1 << BIT)))

#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )



#endif /* COMMON_MACROS_H_ */
