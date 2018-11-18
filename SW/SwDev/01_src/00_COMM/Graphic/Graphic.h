/**
  ******************************************************************************
  * @file    Graphic.h
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
#ifndef __GRAPHIC_H
#define __GRAPHIC_H

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


/**************************************************************************************************
***                               Definition of Export Micro                           
***************************************************************************************************/
#define CIRCLE_QUARTER_LINE_NUM			(30u)

/**************************************************************************************************
***                               Definition of local symbolic constants                           
***************************************************************************************************/


/**************************************************************************************************
**                            Definition of local function like macros                            
***************************************************************************************************/

/**************************************************************************************************
***                    Definition of local types (typedef, enum, struct, union)                    *
***************************************************************************************************/
typedef enum
{
	LINETYPE_LINE,
	LINETYPE_DASH,
	LINETYPE_DASH_DOT,
}LineType;

typedef struct
{
	u8 x;
	u8 y;
}Pixel_u8;

typedef struct
{
	u16 x;
	u16 y;
}Pixel_u16;

typedef struct
{
	u8 x;
	u8 y;
}Point_u8;

typedef struct
{
	u16 x;
	u16 y;
}Point_u16;

typedef struct
{
	s8 x;
	s8 y;
}Point_s8;

typedef struct
{
	s16 x;
	s16 y;
}Point_s16;

typedef struct
{
	Point_u8 Start;
	Point_u8 End;
}Line_u8;

typedef struct
{
	Point_u16 Start;
	Point_u16 End;
}Line_u16;

typedef struct
{
	Point_s8 Start;
	Point_s8 End;
}Line_s8;

typedef struct
{
	Point_s16 Start;
	Point_s16 End;
}Line_s16;

typedef struct
{
	Point_u8 LeftTop;
	u8 		 Width;
	u8       Height;
}Rectangle_u8;

typedef struct
{
	Point_u16 LeftTop;
	u16       Width;
	u16       Height;
}Rectangle_u16;

typedef struct
{
	Point_s8 LeftTop;
	s8       Width;
	s8       Height;
}Rectangle_s8;

typedef struct
{
	Point_s16 LeftTop;
	s16       Width;
	s16       Height;
}Rectangle_s16;

typedef struct
{
	Point_u8 Center;
	u8 Radius;
}Circle_u8;

typedef struct
{
	Point_u16 Center;
	u16 Radius;
}Circle_u16;

typedef struct
{
	Point_s8 Center;
	u8 Radius;
}Circle_s8;

typedef struct
{
	Point_s16 Center;
	u16 Radius;
}Circle_s16;


#if (STD_ON == LCDD_2_4_INCH_USED)
	typedef Pixel_u8	   Pixel;
	typedef Point_u8       Point;
	typedef Line_u8        Line;
	typedef Rectangle_u8   Rectangle;
	typedef Circle_u8      Circle;
#else
	typedef Pixel_u16	    Pixel;
	typedef Point_u16       Point;
	typedef Line_u16        Line;
	typedef Rectangle_u16   Rectangle;
	typedef Circle_u16      Circle;
#endif

/**************************************************************************************************
***                                     Definition of local variables                              
***************************************************************************************************/



/**************************************************************************************************
***                                  Definition of local constant data                             
***************************************************************************************************/



/**************************************************************************************************
***                                   Definition of exported variables                             
***************************************************************************************************/


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
***************************************************************************************************/
extern void GRAPHIC_DrawPoint(Point point,ColorType color);

extern void GRAPHIC_DrawLine(Point sp,Point ep,ColorType color);

extern void GRAPHIC_DrawRectangle(Rectangle rect,ColorType color);


extern void GRAPHIC_DrawFullRectangle(Rectangle rect,ColorType lcolor,ColorType fcolor);

extern void GRAPHIC_DrawCircle(Circle circle,ColorType color);

extern void GRAPHIC_DrawFullCircle(Circle circle,ColorType lcolor,ColorType fcolor);





#endif  /* #ifndef __GRAPHIC_H */
/*************************************************************************************************
***
***                                         EOF:Graphic.h
***
*************************************************************************************************/
