/**
  ******************************************************************************
  * @file    Graphic.c
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
#ifndef __GRAPHIC_C
#define __GRAPHIC_C

/**************************************************************************************************
***                          Include common and project definition header                          
**************************************************************************************************/


/**************************************************************************************************
***                                 Include headers of the component                               
**************************************************************************************************/
#include "Graphic.h"
#include "Graphic_Cfg.h"
/**************************************************************************************************
***                                       Include other headers                                    
***************************************************************************************************/
#include "Lcdd.h"

/**************************************************************************************************
***                               Definition of Export Micro                           
***************************************************************************************************/


/**************************************************************************************************
***                               Definition of local symbolic constants                           
***************************************************************************************************/


/**************************************************************************************************
**                            Definition of local function like macros                            
***************************************************************************************************/
#define GRAPHIC_Lcdd_DrawPoint(x,y,color)				LCDD_DrawPixel(x,y,color)
#define GRAPHIC_Lcdd_OpenWindow(x,y,width,height,color) LCDD_OpenWindow(x,y,width,height,color)

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
extern void GRAPHIC_DrawPoint(Point point,ColorType color)
{
	GRAPHIC_Lcdd_DrawPoint(point.x, point.y, color);
}

extern void GRAPHIC_DrawLine(Point sp,Point ep,ColorType color)
{
	u16 StartX,EndX,StartY,EndY;
	u16 x,y;
	float LineSlope;
	if(sp.x == ep.x)
	{/* Horizontal */
		if(sp.y < ep.y)
		{
			GRAPHIC_Lcdd_OpenWindow(sp.x,sp.y,1,ep.y-sp.y,color);
		}
		else if(sp.y > ep.y)
		{
			GRAPHIC_Lcdd_OpenWindow(ep.x,ep.y,1,sp.y-ep.y,color);
		}
		else/* sp.y > ep.y */
		{
			GRAPHIC_DrawPoint(sp,color);
		}
	}
	else if(sp.y == ep.y)
	{
		if(sp.x < ep.x)
		{
			GRAPHIC_Lcdd_OpenWindow(sp.x,sp.y,ep.x-sp.x,1,color);
		}
		else if(sp.x > ep.x)
		{
			GRAPHIC_Lcdd_OpenWindow(ep.x,ep.y,sp.x-ep.x,1,color);
		}
		else/* sp.x == ep.x */
		{
			GRAPHIC_DrawPoint(sp,color);
		}
	}
	else
	{/* Ð±Ïß */
		if(sp.x < ep.x)
		{
			StartX = sp.x;
			StartY = sp.y;
			EndX   = ep.x;
			EndY   = ep.y;
		}
		else
		{
			StartX = ep.x;
			StartY = ep.y;
			EndX   = sp.x;
			EndY   = sp.y;
		}
		LineSlope = (float)(EndY - StartY)/(float)(EndX - StartX);
		for(x=StartX;x<=EndX;x++)
		{
			y = StartX + (u16)((x - StartX)*LineSlope);
			GRAPHIC_Lcdd_DrawPoint(x,y,color);
		}
	}
}

extern void GRAPHIC_DrawRectangle(Rectangle rect,ColorType color)
{
	GRAPHIC_Lcdd_OpenWindow(rect.LeftTop.x, rect.LeftTop.y,			    rect.Width, 1, color);
	GRAPHIC_Lcdd_OpenWindow(rect.LeftTop.x, rect.LeftTop.y+rect.Height, rect.Width, 1, color);

	GRAPHIC_Lcdd_OpenWindow(rect.LeftTop.x,            rect.LeftTop.y, 1, rect.Height, color);
	GRAPHIC_Lcdd_OpenWindow(rect.LeftTop.x+rect.Width, rect.LeftTop.y, 1, rect.Height, color);
}


extern void GRAPHIC_DrawFullRectangle(Rectangle rect,ColorType lcolor,ColorType fcolor)
{
	GRAPHIC_Lcdd_OpenWindow(rect.LeftTop.x, rect.LeftTop.y, rect.Width, rect.Height, fcolor);

	GRAPHIC_DrawRectangle(rect,lcolor);
}

extern void GRAPHIC_DrawCircle(Circle circle,ColorType color)
{
	
}

extern void GRAPHIC_DrawFullCircle(Circle circle,ColorType lcolor,ColorType fcolor)
{
}


#endif  /* #ifndef __GRAPHIC_C */
/*************************************************************************************************
***
***                                         EOF:Graphic.c
***
*************************************************************************************************/
