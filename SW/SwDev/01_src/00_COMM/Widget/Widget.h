/**
  ******************************************************************************
  * @file    Widget.h
  * @author  lga
  * @version V0.0.1
  * @date    22-12-2017
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
#ifndef __WIDGET_H
#define __WIDGET_H

/**************************************************************************************************
***                          Include common and project definition header                          
**************************************************************************************************/
#include "CommTypeDef.h"
#include "Graphic.h"
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
	TEXTALIGN_TOP_LEFT,
	TEXTALIGN_TOP_CENTER,
	TEXTALIGN_TOP_RIGHT,

	TEXTALIGN_MID_LEFT,
	TEXTALIGN_MID_CENTER,
	TEXTALIGN_MID_RIGHT,

	TEXTALIGN_BOT_LEFT,
	TEXTALIGN_BOT_CENTER,
	TEXTALIGN_BOT_RIGHT,
}TextAlignType;

typedef enum
{
	TB_STATE_STANDBY 	= 0u,
	TB_STATE_SELECTED	= 1u,
	TB_STATE_EDITTING	= 2u,
	TB_STATE_NUM,
}TextBoxState;

typedef struct
{
	Rectangle	    Rect;
	u8*             Text;
	u8              TextLength;
	
}Label;

typedef struct
{
	Rectangle 		Rect;
	u8* 			Text;
	u8 				TextLength;
	u8				RowIndex;
	u8				ColIndex;
	bool_t			IsDraw;
	TextBoxState	State;
	bool_t			IsChanged;
	TextAlignType 	TextAlign;
	ColorType 		TextColor[TB_STATE_NUM]; /* Represent the color of different state */
	ColorType 		BoundaryColor[TB_STATE_NUM];
	ColorType 		BackGroundColor[TB_STATE_NUM];
}TextBox;
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
extern void Pixel_Draw(Pixel pixel,ColorType color);

extern void Point_Draw(Point point,ColorType color);

extern void Line_Draw(Line line,u8 linewidth,ColorType color);

extern void Rectangle_Draw(Rectangle rect,u8 linewidth,ColorType color);

extern void Circle_Draw(Circle circle,u8 linewidth,ColorType color);

extern void TextBox_Draw(TextBox textbox);


#endif  /* #ifndef __WIDGET_H */
/*************************************************************************************************
***
***                                         EOF:Widget.h
***
*************************************************************************************************/
