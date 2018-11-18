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
#ifndef __WIDGET_C
#define __WIDGET_C

/**************************************************************************************************
***                          Include common and project definition header                          
**************************************************************************************************/
#include "Widget.h"


/**************************************************************************************************
***                                 Include headers of the component                               
**************************************************************************************************/


/**************************************************************************************************
***                                       Include other headers                                    
***************************************************************************************************/
#include "Zimo.h"

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
void Pixel_Draw(Pixel pixel,ColorType color)
{
}

void Point_Draw(Point point,ColorType color)
{

}

void Line_Draw(Line line,u8 linewidth,ColorType color)
{

}

void Rectangle_Draw(Rectangle rect,u8 linewidth,ColorType color)
{
}

void Circle_Draw(Circle circle,u8 linewidth,ColorType color)
{
}

void TextBox_Draw(TextBox textbox)
{
	Rectangle TextRect;
	u16 TextPixelLen = ZIMO_WIDTH_PIXEL*textbox.TextLength;

	switch(textbox.TextAlign)
	{
		case TEXTALIGN_TOP_LEFT:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y;
			break;
		}
		case TEXTALIGN_TOP_CENTER:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x+textbox.Rect.Width/2-TextPixelLen/2;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y;
			break;
		}
		case TEXTALIGN_TOP_RIGHT:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x+textbox.Rect.Width-TextPixelLen;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y;
			break;
		}
		case TEXTALIGN_MID_LEFT:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y+textbox.Rect.Height/2-ZIMO_HEIGHT_PIXEL/2;
			break;
		}
		case TEXTALIGN_MID_CENTER:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x+textbox.Rect.Width/2-TextPixelLen/2;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y+textbox.Rect.Height/2-ZIMO_HEIGHT_PIXEL/2;
			break;
		}
		case TEXTALIGN_MID_RIGHT:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x+textbox.Rect.Width-TextPixelLen;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y+textbox.Rect.Height/2-ZIMO_HEIGHT_PIXEL/2;
			break;
		}
		case TEXTALIGN_BOT_LEFT:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y+textbox.Rect.Height-ZIMO_HEIGHT_PIXEL;
			break;
		}
		case TEXTALIGN_BOT_CENTER:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x+textbox.Rect.Width/2-TextPixelLen/2;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y+textbox.Rect.Height-ZIMO_HEIGHT_PIXEL;
			break;
		}
		case TEXTALIGN_BOT_RIGHT:
		{
			TextRect.LeftTop.x = textbox.Rect.LeftTop.x+textbox.Rect.Width-TextPixelLen;
			TextRect.LeftTop.y = textbox.Rect.LeftTop.y+textbox.Rect.Height-ZIMO_HEIGHT_PIXEL;
			break;
		}
	}
	TextRect.Width     = TextPixelLen;
	TextRect.Height    = ZIMO_HEIGHT_PIXEL;
	
	GRAPHIC_DrawFullRectangle(textbox.Rect, textbox.BoundaryColor[textbox.State], textbox.BackGroundColor[textbox.State]);

	ZIMO_DrawCharSetHorizontal(textbox.Text, textbox.TextLength, TextRect, textbox.TextColor[textbox.State]);
}


#endif  /* #ifndef __WIDGET_H */
/*************************************************************************************************
***
***                                         EOF:Widget.h
***
*************************************************************************************************/
