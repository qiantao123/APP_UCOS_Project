/**
  ******************************************************************************
  * @file    Zimo.h
  * @author  lga
  * @version V0.0.1
  * @date    25-Nov-2017
  * @brief   This file contains all the Task to be Execute
  ******************************************************************************
  * @attention
  *
  *
  * <h2><center>&copy; COPYRIGHT 2017 lga</center></h2>
  ******************************************************************************
  */

/** \file
 *
 * Source file for Task  module which belongs to UCOS.
 *
 * This module is used to provide the base service for IO resources.
 *
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> Source:   </td> <td>                   </td></tr>
 * <tr> <td> Revision: </td> <td> 1.00                                                    </td></tr>
 * <tr> <td> State:    </td> <td> Draft <Draft,Ready,Reviewed,Accepted>                   </td></tr>
 * <tr> <td> Author:   </td> <td> Guoan Liu                     </td></tr>
 * <tr> <td> Date:     </td> <td> 25 Nov, 2017                                            </td></tr>
 * </table>
 *
 * \n
 * <table border="0" cellspacing="0" cellpadding="0">
 * <tr> <td> COMPONENT: </td> <td> Task                                     </td></tr>
 * <tr> <td> SCOPE:     </td> <td> Module <Component,Module,Assets>                       </td></tr>
 * <tr> <td> TARGET:    </td> <td> STM32F103VE                         </td></tr>
 * </table>
 */

/** Header code file identification */
#ifndef __ZIMO_H
#define __ZIMO_H

/**************************************************************************************************
***                          Include common and project definition header                          
**************************************************************************************************/
#include "CommTypeDef.h"
#include "Color.h"

/**************************************************************************************************
***                                 Include headers of the component                               
**************************************************************************************************/

/**************************************************************************************************
***                                       Include other headers                                    
***************************************************************************************************/
#include "Graphic.h"

/**************************************************************************************************
***                               Definition of Export Micro                           
***************************************************************************************************/
#define ZIMO_ASCII_START_POS			(u8)(32u)
#define ZIMO_ASCII_END_POS				(u8)(126u)
#define ZIMO_ASCII_CHAR_NUM				(u8)(ZIMO_ASCII_END_POS - ZIMO_ASCII_START_POS + 1)

#define ZIMO_WIDTH_PIXEL				(u8)(8)
#define ZIMO_HEIGHT_PIXEL				(u8)(16)

#define ZIMO_DEFAULT_FLOAT_RESOLUTION   (u8)(2)
/**************************************************************************************************
***                               Definition of local symbolic constants                           
***************************************************************************************************/


/**************************************************************************************************
**                            Definition of local function like macros                            
***************************************************************************************************/

/**************************************************************************************************
***                    Definition of local types (typedef, enum, struct, union)                    *
***************************************************************************************************/

/**************************************************************************************************
***                                     Definition of local variables                              
***************************************************************************************************/



/**************************************************************************************************
***                                  Definition of local constant data                             
***************************************************************************************************/



/**************************************************************************************************
***                                   Definition of exported variables                             
***************************************************************************************************/
extern const u8 ZIMO_ASCII[ZIMO_ASCII_CHAR_NUM][ZIMO_HEIGHT_PIXEL];

/**************************************************************************************************
***                                 Definition of exported constant data                           
***************************************************************************************************/

/**************************************************************************************************
***                                Declaration of local function prototypes                        
***************************************************************************************************/

/**************************************************************************************************
***                                     Definition of local functions                              
***************************************************************************************************/

/**************************************************************************************************
***                                   Definition of exported functions                             
**************************************************************************************************/
extern void ZIMO_DrawChar(u8 Ch, u16 StartX, u16 StartY, ColorType Color);

extern void ZIMO_DrawCharSetHorizontal(u8* ChSet, u8 ChLen, Rectangle Rect, ColorType Color);

extern void ZIMO_DrawCharSetVertical(u8* ChSet, u8 ChLen, Rectangle Rect, ColorType Color);

extern u8   ZIMO_IntToChar(u32 Num, u8* const ReturnCh);

extern u8   ZIMO_FloatToChar(f32* const Num, u8* const ReturnCh);

extern void ZIMO_SetFloatResolution(u8 Resolution);

extern void ZIMO_ReverseArray(u8 * const pArr,u8 Len);


#endif  /* #ifndef __ZIMO_H */
/*************************************************************************************************
***
***                                         EOF:Zimo.h
***
*************************************************************************************************/
