/**
  ******************************************************************************
  * @file    Zimo.c
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
#ifndef __ZIMO_C
#define __ZIMO_C

/**************************************************************************************************
***                          Include common and project definition header                          
**************************************************************************************************/


/**************************************************************************************************
***                                 Include headers of the component                               
**************************************************************************************************/
#include "Zimo.h"
/**************************************************************************************************
***                                       Include other headers                                    
***************************************************************************************************/
#include "Lcdd.h"
#include "Lib_ascii.h"

/**************************************************************************************************
***                               Definition of Export Micro                           
***************************************************************************************************/


/**************************************************************************************************
***                               Definition of local symbolic constants                           
***************************************************************************************************/


/**************************************************************************************************
**                            Definition of local function like macros                            
***************************************************************************************************/
#define ZIMO_DrawPixel(x,y,color)     LCDD_DrawPixel(x,y,color)
/**************************************************************************************************
***                    Definition of local types (typedef, enum, struct, union)                    *
***************************************************************************************************/

/**************************************************************************************************
***                                     Definition of local variables                              
***************************************************************************************************/
LOCAL u8 ZIMO_FloatResolution = ZIMO_DEFAULT_FLOAT_RESOLUTION;


/**************************************************************************************************
***                                  Definition of local constant data                             
***************************************************************************************************/



/**************************************************************************************************
***                                   Definition of exported variables                             
***************************************************************************************************/
#if 0
const u8 ZIMO_ASCII[ZIMO_ASCII_CHAR_NUM][ZIMO_HEIGHT_PIXEL] = 
{
	/*--  ����:     --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:  !  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x18,0x18,0x00,0x00,},

	/*--  ����:  "  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x12,0x36,0x24,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:  #  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x24,0x24,0x24,0xFE,0x48,0x48,0x48,0xFE,0x48,0x48,0x48,0x00,0x00,},

	/*--  ����:  $  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x10,0x38,0x54,0x54,0x50,0x30,0x18,0x14,0x14,0x54,0x54,0x38,0x10,0x10,},

	/*--  ����:  %  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x44,0xA4,0xA8,0xA8,0xA8,0x54,0x1A,0x2A,0x2A,0x2A,0x44,0x00,0x00,},

	/*--  ����:  &  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x30,0x48,0x48,0x48,0x50,0x6E,0xA4,0x94,0x88,0x89,0x76,0x00,0x00,},

	/*--  ����:  '  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x60,0x60,0x20,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:  (  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00,},

	/*--  ����:  )  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00,},

	/*--  ����:  *  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x10,0x10,0xD6,0x38,0x38,0xD6,0x10,0x10,0x00,0x00,0x00,0x00,},

	/*--  ����:  +  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0xFE,0x10,0x10,0x10,0x10,0x00,0x00,0x00,},

	/*--  ����:  -  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:  .  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,},

	/*--  ����:  /  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x00,},

	/*--  ����:  0  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,},

	/*--  ����:  1  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x10,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,},

	/*--  ����:  2  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x04,0x04,0x08,0x10,0x20,0x42,0x7E,0x00,0x00,},

	/*--  ����:  3  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x3C,0x42,0x42,0x04,0x18,0x04,0x02,0x02,0x42,0x44,0x38,0x00,0x00,},

	/*--  ����:  4  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x04,0x0C,0x14,0x24,0x24,0x44,0x44,0x7E,0x04,0x04,0x1E,0x00,0x00,},

	/*--  ����:  5  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x58,0x64,0x02,0x02,0x42,0x44,0x38,0x00,0x00,},

	/*--  ����:  6  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x1C,0x24,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x24,0x18,0x00,0x00,},

	/*--  ����:  7  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x7E,0x44,0x44,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,},

	/*--  ����:  8  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,},

	/*--  ����:  9  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x26,0x1A,0x02,0x02,0x24,0x38,0x00,0x00,},

	/*--  ����:  :  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,},

	/*--  ����:  ;  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x20,},

	/*--  ����:  <  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00,},

	/*--  ����:  =  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:  >  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00,},

	/*--  ����:  ?  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x3C,0x42,0x42,0x62,0x02,0x04,0x08,0x08,0x00,0x18,0x18,0x00,0x00,},

	/*--  ����:  @  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x38,0x44,0x5A,0xAA,0xAA,0xAA,0xAA,0xB4,0x42,0x44,0x38,0x00,0x00,},

	/*--  ����:  A  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x10,0x10,0x18,0x28,0x28,0x24,0x3C,0x44,0x42,0x42,0xE7,0x00,0x00,},

	/*--  ����:  B  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xF8,0x44,0x44,0x44,0x78,0x44,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,},

	/*--  ����:  C  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x3E,0x42,0x42,0x80,0x80,0x80,0x80,0x80,0x42,0x44,0x38,0x00,0x00,},

	/*--  ����:  D  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xF8,0x44,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,},

	/*--  ����:  E  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xFC,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x42,0x42,0xFC,0x00,0x00,},

	/*--  ����:  F  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xFC,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x40,0x40,0xE0,0x00,0x00,},

	/*--  ����:  G  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x3C,0x44,0x44,0x80,0x80,0x80,0x8E,0x84,0x44,0x44,0x38,0x00,0x00,},

	/*--  ����:  H  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,},

	/*--  ����:  I  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,},

	/*--  ����:  J  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x88,0xF0,},

	/*--  ����:  K  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xEE,0x44,0x48,0x50,0x70,0x50,0x48,0x48,0x44,0x44,0xEE,0x00,0x00,},

	/*--  ����:  L  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xE0,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x42,0xFE,0x00,0x00,},

	/*--  ����:  M  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xEE,0x6C,0x6C,0x6C,0x6C,0x54,0x54,0x54,0x54,0x54,0xD6,0x00,0x00,},

	/*--  ����:  N  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xC7,0x62,0x62,0x52,0x52,0x4A,0x4A,0x4A,0x46,0x46,0xE2,0x00,0x00,},

	/*--  ����:  O  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00,},

	/*--  ����:  P  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xFC,0x42,0x42,0x42,0x42,0x7C,0x40,0x40,0x40,0x40,0xE0,0x00,0x00,},

	/*--  ����:  Q  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0xB2,0xCA,0x4C,0x38,0x06,0x00,},

	/*--  ����:  R  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xFC,0x42,0x42,0x42,0x7C,0x48,0x48,0x44,0x44,0x42,0xE3,0x00,0x00,},

	/*--  ����:  S  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x3E,0x42,0x42,0x40,0x20,0x18,0x04,0x02,0x42,0x42,0x7C,0x00,0x00,},

	/*--  ����:  T  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xFE,0x92,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,},

	/*--  ����:  U  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,},

	/*--  ����:  V  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xE7,0x42,0x42,0x44,0x24,0x24,0x28,0x28,0x18,0x10,0x10,0x00,0x00,},

	/*--  ����:  W  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xD6,0x92,0x92,0x92,0x92,0xAA,0xAA,0x6C,0x44,0x44,0x44,0x00,0x00,},

	/*--  ����:  X  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00,},

	/*--  ����:  Y  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,},

	/*--  ����:  Z  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x7E,0x84,0x04,0x08,0x08,0x10,0x20,0x20,0x42,0x42,0xFC,0x00,0x00,},

	/*--  ����:  [  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00,},

	/*--  ����:  \  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x40,0x40,0x20,0x20,0x10,0x10,0x10,0x08,0x08,0x04,0x04,0x04,0x02,0x02,},

	/*--  ����:  ]  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00,},

	/*--  ����:  ^  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x1C,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:  -  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:     --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:     --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

	/*--  ����:  a  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x1E,0x22,0x42,0x42,0x3F,0x00,0x00,},

	/*--  ����:  b  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x64,0x58,0x00,0x00,},

	/*--  ����:  c  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x22,0x40,0x40,0x40,0x22,0x1C,0x00,0x00,},

	/*--  ����:  d  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x06,0x02,0x02,0x02,0x1E,0x22,0x42,0x42,0x42,0x26,0x1B,0x00,0x00,},

	/*--  ����:  e  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x40,0x40,0x42,0x3C,0x00,0x00,},

	/*--  ����:  f  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x0F,0x11,0x10,0x10,0x7E,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,},

	/*--  ����:  g  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x44,0x44,0x38,0x40,0x3C,0x42,0x42,0x3C,},

	/*--  ����:  h  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x5C,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,},

	/*--  ����:  i  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,},

	/*--  ����:  j  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x1C,0x04,0x04,0x04,0x04,0x04,0x04,0x44,0x78,},

	/*--  ����:  k  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x4E,0x48,0x50,0x68,0x48,0x44,0xEE,0x00,0x00,},

	/*--  ����:  l  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,},

	/*--  ����:  m  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x49,0x49,0x49,0x49,0x49,0xED,0x00,0x00,},

	/*--  ����:  n  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,},

	/*--  ����:  o  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,},

	/*--  ����:  p  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0x64,0x42,0x42,0x42,0x44,0x78,0x40,0xE0,},

	/*--  ����:  q  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x22,0x42,0x42,0x42,0x22,0x1E,0x02,0x07,},

	/*--  ����:  r  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x32,0x20,0x20,0x20,0x20,0xF8,0x00,0x00,},

	/*--  ����:  s  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x42,0x40,0x3C,0x02,0x42,0x7C,0x00,0x00,},

	/*--  ����:  t  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x7C,0x10,0x10,0x10,0x10,0x10,0x0C,0x00,0x00,},

	/*--  ����:  u  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x42,0x42,0x42,0x42,0x46,0x3B,0x00,0x00,},

	/*--  ����:  v  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x10,0x10,0x00,0x00,},

	/*--  ����:  w  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x92,0x92,0xAA,0xAA,0x44,0x44,0x00,0x00,},

	/*--  ����:  x  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0x24,0x18,0x18,0x18,0x24,0x76,0x00,0x00,},

	/*--  ����:  y  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x18,0x10,0x10,0xE0,},

	/*--  ����:  z  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x44,0x08,0x10,0x10,0x22,0x7E,0x00,0x00,},

	/*--  ����:  {  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x03,0x04,0x04,0x04,0x04,0x04,0x08,0x04,0x04,0x04,0x04,0x04,0x04,0x03,0x00,},

	/*--  ����:  |  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,},

	/*--  ����:  }  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x00,0x60,0x10,0x10,0x10,0x10,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x60,0x00,},

	/*--  ����:  ~  --*/
	/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
	{0x30,0x4C,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
};
#endif

const u8 ZIMO_ASCII[ZIMO_ASCII_CHAR_NUM][ZIMO_HEIGHT_PIXEL] = 
{
/*--  ����:     --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ����:  !  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x18,0x18,0x00,0x00,

/*--  ����:  "  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x12,0x36,0x24,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ����:  #  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x24,0x24,0x24,0xFE,0x48,0x48,0x48,0xFE,0x48,0x48,0x48,0x00,0x00,

/*--  ����:  $  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x10,0x38,0x54,0x54,0x50,0x30,0x18,0x14,0x14,0x54,0x54,0x38,0x10,0x10,

/*--  ����:  %  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x44,0xA4,0xA8,0xA8,0xA8,0x54,0x1A,0x2A,0x2A,0x2A,0x44,0x00,0x00,

/*--  ����:  &  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x30,0x48,0x48,0x48,0x50,0x6E,0xA4,0x94,0x88,0x89,0x76,0x00,0x00,

/*--  ����:  '  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x60,0x60,0x20,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ����:  (  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00,

/*--  ����:  )  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00,

/*--  ����:  *  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x10,0x10,0xD6,0x38,0x38,0xD6,0x10,0x10,0x00,0x00,0x00,0x00,

/*--  ����:  +  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0xFE,0x10,0x10,0x10,0x10,0x00,0x00,0x00,

/*--  ����:  ,  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x20,0xC0,

/*--  ����:  -  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ����:  .  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,

/*--  ����:  /  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x00,

/*--  ����:  0  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,

/*--  ����:  1  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x10,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ����:  2  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x04,0x04,0x08,0x10,0x20,0x42,0x7E,0x00,0x00,

/*--  ����:  3  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x3C,0x42,0x42,0x04,0x18,0x04,0x02,0x02,0x42,0x44,0x38,0x00,0x00,

/*--  ����:  4  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x04,0x0C,0x14,0x24,0x24,0x44,0x44,0x7E,0x04,0x04,0x1E,0x00,0x00,

/*--  ����:  5  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x58,0x64,0x02,0x02,0x42,0x44,0x38,0x00,0x00,

/*--  ����:  6  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x1C,0x24,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x24,0x18,0x00,0x00,

/*--  ����:  7  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x7E,0x44,0x44,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,

/*--  ����:  8  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,

/*--  ����:  9  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x26,0x1A,0x02,0x02,0x24,0x38,0x00,0x00,

/*--  ����:  :  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,

/*--  ����:  ;  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x20,

/*--  ����:  <  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00,

/*--  ����:  =  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,

/*--  ����:  >  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00,

/*--  ����:  ?  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x3C,0x42,0x42,0x62,0x02,0x04,0x08,0x08,0x00,0x18,0x18,0x00,0x00,

/*--  ����:  @  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x38,0x44,0x5A,0xAA,0xAA,0xAA,0xAA,0xB4,0x42,0x44,0x38,0x00,0x00,

/*--  ����:  A  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x10,0x10,0x18,0x28,0x28,0x24,0x3C,0x44,0x42,0x42,0xE7,0x00,0x00,

/*--  ����:  B  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xF8,0x44,0x44,0x44,0x78,0x44,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,

/*--  ����:  C  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x3E,0x42,0x42,0x80,0x80,0x80,0x80,0x80,0x42,0x44,0x38,0x00,0x00,

/*--  ����:  D  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xF8,0x44,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,

/*--  ����:  E  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xFC,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x42,0x42,0xFC,0x00,0x00,

/*--  ����:  F  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xFC,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x40,0x40,0xE0,0x00,0x00,

/*--  ����:  G  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x3C,0x44,0x44,0x80,0x80,0x80,0x8E,0x84,0x44,0x44,0x38,0x00,0x00,

/*--  ����:  H  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,

/*--  ����:  I  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ����:  J  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x88,0xF0,

/*--  ����:  K  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xEE,0x44,0x48,0x50,0x70,0x50,0x48,0x48,0x44,0x44,0xEE,0x00,0x00,

/*--  ����:  L  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xE0,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x42,0xFE,0x00,0x00,

/*--  ����:  M  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xEE,0x6C,0x6C,0x6C,0x6C,0x54,0x54,0x54,0x54,0x54,0xD6,0x00,0x00,

/*--  ����:  N  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xC7,0x62,0x62,0x52,0x52,0x4A,0x4A,0x4A,0x46,0x46,0xE2,0x00,0x00,

/*--  ����:  O  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00,

/*--  ����:  P  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xFC,0x42,0x42,0x42,0x42,0x7C,0x40,0x40,0x40,0x40,0xE0,0x00,0x00,

/*--  ����:  Q  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0xB2,0xCA,0x4C,0x38,0x06,0x00,

/*--  ����:  R  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xFC,0x42,0x42,0x42,0x7C,0x48,0x48,0x44,0x44,0x42,0xE3,0x00,0x00,

/*--  ����:  S  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x3E,0x42,0x42,0x40,0x20,0x18,0x04,0x02,0x42,0x42,0x7C,0x00,0x00,

/*--  ����:  T  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xFE,0x92,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,

/*--  ����:  U  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,

/*--  ����:  V  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xE7,0x42,0x42,0x44,0x24,0x24,0x28,0x28,0x18,0x10,0x10,0x00,0x00,

/*--  ����:  W  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xD6,0x92,0x92,0x92,0x92,0xAA,0xAA,0x6C,0x44,0x44,0x44,0x00,0x00,

/*--  ����:  X  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00,

/*--  ����:  Y  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,

/*--  ����:  Z  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x7E,0x84,0x04,0x08,0x08,0x10,0x20,0x20,0x42,0x42,0xFC,0x00,0x00,

/*--  ����:  [  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00,

/*--  ����:  \  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x40,0x40,0x20,0x20,0x10,0x10,0x10,0x08,0x08,0x04,0x04,0x04,0x02,0x02,

/*--  ����:  ]  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00,

/*--  ����:  ^  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x1C,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ����:  _  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,

/*--  ����:     --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ����:  a  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x1E,0x22,0x42,0x42,0x3F,0x00,0x00,

/*--  ����:  b  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x64,0x58,0x00,0x00,

/*--  ����:  c  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x22,0x40,0x40,0x40,0x22,0x1C,0x00,0x00,

/*--  ����:  d  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x06,0x02,0x02,0x02,0x1E,0x22,0x42,0x42,0x42,0x26,0x1B,0x00,0x00,

/*--  ����:  e  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x40,0x40,0x42,0x3C,0x00,0x00,

/*--  ����:  f  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x0F,0x11,0x10,0x10,0x7E,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ����:  g  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x44,0x44,0x38,0x40,0x3C,0x42,0x42,0x3C,

/*--  ����:  h  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x5C,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,

/*--  ����:  i  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ����:  j  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x1C,0x04,0x04,0x04,0x04,0x04,0x04,0x44,0x78,

/*--  ����:  k  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x4E,0x48,0x50,0x68,0x48,0x44,0xEE,0x00,0x00,

/*--  ����:  l  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ����:  m  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x49,0x49,0x49,0x49,0x49,0xED,0x00,0x00,

/*--  ����:  n  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,

/*--  ����:  o  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,

/*--  ����:  p  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0x64,0x42,0x42,0x42,0x44,0x78,0x40,0xE0,

/*--  ����:  q  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x22,0x42,0x42,0x42,0x22,0x1E,0x02,0x07,

/*--  ����:  r  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x32,0x20,0x20,0x20,0x20,0xF8,0x00,0x00,

/*--  ����:  s  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x42,0x40,0x3C,0x02,0x42,0x7C,0x00,0x00,

/*--  ����:  t  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x7C,0x10,0x10,0x10,0x10,0x10,0x0C,0x00,0x00,

/*--  ����:  u  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x42,0x42,0x42,0x42,0x46,0x3B,0x00,0x00,

/*--  ����:  v  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x10,0x10,0x00,0x00,

/*--  ����:  w  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x92,0x92,0xAA,0xAA,0x44,0x44,0x00,0x00,

/*--  ����:  x  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0x24,0x18,0x18,0x18,0x24,0x76,0x00,0x00,

/*--  ����:  y  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x18,0x10,0x10,0xE0,

/*--  ����:  z  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x44,0x08,0x10,0x10,0x22,0x7E,0x00,0x00,

/*--  ����:  {  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x03,0x04,0x04,0x04,0x04,0x04,0x08,0x04,0x04,0x04,0x04,0x04,0x04,0x03,0x00,

/*--  ����:  |  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,

/*--  ����:  }  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x00,0x60,0x10,0x10,0x10,0x10,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x60,0x00,

/*--  ����:  ~  --*/
/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=8x16   --*/
0x30,0x4C,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,




};

/**************************************************************************************************
***                                 Definition of exported constant data                           
***************************************************************************************************/

/**************************************************************************************************
***                                Declaration of local function prototypes                        
***************************************************************************************************/

/**************************************************************************************************
***                                     Definition of local functions                              
***************************************************************************************************/
LOCAL u8 Zimo_NumToAscii(u8 data)
{
	return (ASCII_CHAR_DIGIT_ZERO+data);
}
/**************************************************************************************************
***                                   Definition of exported functions                             
***************************************************************************************************/
void ZIMO_DrawChar(u8 Ch, u16 StartX, u16 StartY, ColorType Color)
{
	const u8* TheCharBmp = &ZIMO_ASCII[Ch - ZIMO_ASCII_START_POS][0];
	u8 Row,Col;
	bool_t IsShow = FALSE;

	for(Row = 0; Row < ZIMO_HEIGHT_PIXEL; Row++)
	{
		for(Col = 0; Col < ZIMO_WIDTH_PIXEL; Col++)
		{
			IsShow = (TheCharBmp[Row] >> (ZIMO_WIDTH_PIXEL-Col-1))&0x01;
			if(TRUE == IsShow)
			{
				ZIMO_DrawPixel(StartX + Col, StartY + Row, Color);
			}
		}
	}
}

void ZIMO_DrawCharSetHorizontal(u8* ChSet, u8 ChLen, Rectangle Rect, ColorType Color)
{
	u8 Index;
	u16 ShiftX;

	for(Index = 0u; Index < ChLen; Index++)
	{
		ShiftX = ZIMO_WIDTH_PIXEL*(Index);
		if(ShiftX > Rect.Width)
		{
			return;
		}

		ZIMO_DrawChar(ChSet[Index], Rect.LeftTop.x+ShiftX, Rect.LeftTop.y, Color);
	}
}

void ZIMO_DrawCharSetVertical(u8* ChSet, u8 ChLen, Rectangle Rect, ColorType Color)
{
	u8 Index;
	u16 ShiftY;

	for(Index = 0u; Index < ChLen; Index++)
	{
		ShiftY = ZIMO_HEIGHT_PIXEL*(Index+1u);
		if(ShiftY > Rect.Height)
		{
			return;
		}

		ZIMO_DrawChar(ChSet[Index], Rect.LeftTop.x, Rect.LeftTop.y+ShiftY, Color);
	}
}

u8 ZIMO_IntToChar(u32 Num, u8* const ReturnCh)
{
	u8 Length = 0u;

	if(Num == 0u)
	{
		ReturnCh[0] = ASCII_CHAR_DIGIT_ZERO;
		Length = 1;
	}
	else
	{
		while(Num > 0u)
		{
			ReturnCh[Length++] = Zimo_NumToAscii(Num%10);
			Num = Num/10;
		}
		ZIMO_ReverseArray(ReturnCh,Length);
	}
	return Length;
}

u8 ZIMO_FloatToChar(f32* const Num, u8* const ReturnCh)
{
	u8 Length = 0u;
	u8 i;
	f32 Data = *Num;
	u32 IntNum = 0u;
	for(i=0;i<ZIMO_FloatResolution;i++)
	{
		Data *= 10.0;
	}
	IntNum = (u32)Data;
	while(IntNum > 0)
	{
		ReturnCh[Length++] = Zimo_NumToAscii(IntNum%10);
		if(Length == ZIMO_FloatResolution)
		{
			ReturnCh[Length++] = ASCII_CHAR_FULL_STOP;
		}
		IntNum = IntNum/10;
	}

	if(*Num < 1)
	{
		ReturnCh[Length++] = ASCII_CHAR_DIGIT_ZERO;
	}
	
	ZIMO_ReverseArray(ReturnCh,Length);
	return Length;
}

extern void ZIMO_SetFloatResolution(u8 Resolution)
{
	ZIMO_FloatResolution = Resolution;
}

void ZIMO_ReverseArray(u8 * const pArr,u8 Len)
{
	u8 HalfPos = Len/2;
	u8 Index;
	u8 Tmp;

	for(Index=0; Index<HalfPos;Index++)
	{
		Tmp               = pArr[Index];
		pArr[Index]       = pArr[Len-Index-1];
		pArr[Len-Index-1] = Tmp;
	}
}

#endif  /* #ifndef __ZIMO_C */
/*************************************************************************************************
***
***                                         EOF:Zimo.c
***
*************************************************************************************************/