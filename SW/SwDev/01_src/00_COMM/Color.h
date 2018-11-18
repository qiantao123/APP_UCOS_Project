/**
  ******************************************************************************
  * @file    Task.h
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
#ifndef __COLOR_H
#define __COLOR_H

/**************************************************************************************************
***                          Include common and project definition header                          
**************************************************************************************************/
#include "CommTypeDef.h"

/**************************************************************************************************
***                                 Include headers of the component                               
**************************************************************************************************/


/**************************************************************************************************
***                                       Include other headers                                    
***************************************************************************************************/


/**************************************************************************************************
***                               Definition of Export Micro                           
***************************************************************************************************/
#define COLOR_BIT_NUM_8				STD_OFF
#define COLOR_BIT_NUM_16			STD_ON
#define COLOR_BIT_NUM_18			STD_OFF
#define COLOR_BIT_NUM_24			STD_OFF


#if (STD_ON == COLOR_BIT_NUM_16)
typedef u16 ColorType;
#elif(STD_ON == COLOR_BIT_NUM_8)
typedef u8 ColorType;
#else
typedef u32 ColorType;
#endif



/**************************************************************************************************
***                               Definition of local symbolic constants                           
***************************************************************************************************/


/**************************************************************************************************
**                            Definition of local function like macros                            
***************************************************************************************************/
#define COLOR_CONVERT_888TO565(R,G,B) (ColorType)(((ColorType)((R>>3)<<11))|((ColorType)((G>>2)<<5))|((ColorType)(B>>3)))
#define COLOR_CONVERT_888TO666(R,G,B) (ColorType)(((ColorType)((R>>2)<<12))|((ColorType)((G>>2)<<6))|((ColorType)(B>>2)))
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
/***********************************Define some usual Color***************************************/
#define COLOR_RED       					(ColorType)(0xF800)
#define COLOR_LIGHTPINK       				(ColorType)(0xFDB8)
#define COLOR_PINK       					(ColorType)(0xFE19)
#define COLOR_CRIMSON       				(ColorType)(0xD8A7)
#define COLOR_LAVENDERBLUSH     			(ColorType)(0xFF9E)
#define COLOR_PALEVIOLETRED     			(ColorType)(0xDB92)
#define COLOR_HOTPINK       				(ColorType)(0xFB56)
#define COLOR_DEEPPINK       				(ColorType)(0xF8B2)
#define COLOR_MEDIUMVIOLETRED   			(ColorType)(0xC0B0)
#define COLOR_ORCHID       					(ColorType)(0xDB9A)
#define COLOR_THISTLE       				(ColorType)(0xDDFB)
#define COLOR_PLUM       					(ColorType)(0xDD1B)
#define COLOR_VIOLET       					(ColorType)(0xEC1D)
#define COLOR_MAGENTA       				(ColorType)(0xF81F)
#define COLOR_FUCHSIA       				(ColorType)(0xF81F)
#define COLOR_DARKMAGENTA       			(ColorType)(0x8811)
#define COLOR_PURPLE       					(ColorType)(0x8010)
#define COLOR_MEDIUMORCHID      			(ColorType)(0xBABA)
#define COLOR_DARKVOILET       				(ColorType)(0x901A)
#define COLOR_DARKORCHID       				(ColorType)(0x9999)
#define COLOR_INDIGO       					(ColorType)(0x4810)
#define COLOR_BLUEVIOLET       				(ColorType)(0x895C)
#define COLOR_MEDIUMPURPLE      			(ColorType)(0x939B)
#define COLOR_MEDIUMSLATEBLUE   			(ColorType)(0x7B5D)
#define COLOR_SLATEBLUE       				(ColorType)(0x6AD9)
#define COLOR_DARKSLATEBLUE     			(ColorType)(0x49F1)
#define COLOR_LAVENDER       				(ColorType)(0xE73F)
#define COLOR_GHOSTWHITE       				(ColorType)(0xFFDF)
#define COLOR_BLUE       					(ColorType)(0x001F)
#define COLOR_MEDIUMBLUE       				(ColorType)(0x0019)
#define COLOR_MIDNIGHTBLUE      			(ColorType)(0x18CE)
#define COLOR_DARKBLUE       				(ColorType)(0x0011)
#define COLOR_NAVY       					(ColorType)(0x0010)
#define COLOR_ROYALBLUE       				(ColorType)(0x435C)
#define COLOR_CORNFLOWERBLUE    			(ColorType)(0x64BD)
#define COLOR_LIGHTSTEELBLUE    			(ColorType)(0xB63B)
#define COLOR_LIGHTSLATEGRAY    			(ColorType)(0x7453)
#define COLOR_SLATEGRAY       				(ColorType)(0x7412)
#define COLOR_DODERBLUE       				(ColorType)(0x1C9F)
#define COLOR_ALICEBLUE       				(ColorType)(0xF7DF)
#define COLOR_STEELBLUE       				(ColorType)(0x4416)
#define COLOR_LIGHTSKYBLUE      			(ColorType)(0x867F)
#define COLOR_SKYBLUE       				(ColorType)(0x867D)
#define COLOR_DEEPSKYBLUE       			(ColorType)(0x05FF)
#define COLOR_LIGHTBLUE       				(ColorType)(0xAEDC)
#define COLOR_POWDERBLUE       				(ColorType)(0xB71C)
#define COLOR_CADETBLUE       				(ColorType)(0x5CF4)
#define COLOR_AZURE       					(ColorType)(0xF7FF)
#define COLOR_LIGHTCYAN       				(ColorType)(0xE7FF)
#define COLOR_PALETURQUOISE     			(ColorType)(0xAF7D)
#define COLOR_CYAN       					(ColorType)(0x07FF)
#define COLOR_AQUA       					(ColorType)(0x07FF)
#define COLOR_DARKTURQUOISE    				(ColorType)(0x067A)
#define COLOR_DARKSLATEGRAY     			(ColorType)(0x2A69)
#define COLOR_DARKCYAN       				(ColorType)(0x0451)
#define COLOR_TEAL       					(ColorType)(0x0410)
#define COLOR_MEDIUMTURQUOISE   			(ColorType)(0x4E99)
#define COLOR_LIGHTSEAGREEN     			(ColorType)(0x2595)
#define COLOR_TURQUOISE       				(ColorType)(0x471A)
#define COLOR_BABYGREEN       				(ColorType)(0x7FF5)
#define COLOR_MEDIUMAQUAMARINE  			(ColorType)(0x07D3)
#define COLOR_MEDIUMSPRINGGREEN 			(ColorType)(0xF7FF)
#define COLOR_MINTCREAM       				(ColorType)(0x07EF)
#define COLOR_SPRINGGREEN       			(ColorType)(0x3D8E)
#define COLOR_SEAGREEN       				(ColorType)(0x2C4A)
#define COLOR_HONEYDEW       				(ColorType)(0xF7E0)
#define COLOR_LIGHTGREEN       				(ColorType)(0x9772)
#define COLOR_PALEGREEN       				(ColorType)(0x9FD3)
#define COLOR_DARKSEAGREEN      			(ColorType)(0x8DF1)
#define COLOR_LIMEGREEN       				(ColorType)(0x3666)
#define COLOR_LIME       					(ColorType)(0x07E0)
#define COLOR_FORESTGREEN       			(ColorType)(0x2444)
#define COLOR_GREEN       					(ColorType)(0x0400)
#define COLOR_DARKGREEN       				(ColorType)(0x0320)
#define COLOR_CHARTREUSE       				(ColorType)(0x7FE0)
#define COLOR_LAWNGREEN       				(ColorType)(0x7FE0)
#define COLOR_GREENYELLOW     				(ColorType)(0xAFE5)
#define COLOR_OLIVEDRAB       				(ColorType)(0x5345)
#define COLOR_BEIGE       					(ColorType)(0x6C64)
#define COLOR_LIGHTGOLDENRODYELLOW 			(ColorType)(0xFFDA)
#define COLOR_IVORY       					(ColorType)(0xFFFE)
#define COLOR_LIGHTYELLOW       			(ColorType)(0xFFFC)
#define COLOR_YELLOW       					(ColorType)(0xFFE0)
#define COLOR_OLIVE       					(ColorType)(0x8400)
#define COLOR_DARKKHAKI       				(ColorType)(0xBDAD)
#define COLOR_LEMONCHIFFON       			(ColorType)(0xFFD9)
#define COLOR_PALEGODENROD       			(ColorType)(0xEF55)
#define COLOR_KHAKI       					(ColorType)(0xF731)
#define COLOR_GOLD       					(ColorType)(0xFEA0)
#define COLOR_CORNISLK       				(ColorType)(0xFFDB)
#define COLOR_GOLDENROD       				(ColorType)(0xDD24)
#define COLOR_FLORALWHITE       			(ColorType)(0xFFDE)
#define COLOR_OLDLACE       				(ColorType)(0xFFBC)
#define COLOR_WHEAT       					(ColorType)(0xF6F6)
#define COLOR_MOCCASIN       				(ColorType)(0xFF36)
#define COLOR_ORANGE       					(ColorType)(0xFD20)
#define COLOR_PAPAYAWHIP       				(ColorType)(0xFF7A)
#define COLOR_BLANCHEDALMOND       			(ColorType)(0xFF59)
#define COLOR_NAVAJOWHITE       			(ColorType)(0xFEF5)
#define COLOR_ANTIQUEWHITE       			(ColorType)(0xFF5A)
#define COLOR_TAN       					(ColorType)(0xD5B1)
#define COLOR_BRULYWOOD       				(ColorType)(0xDDD0)
#define COLOR_BISQUE       					(ColorType)(0xFF38)
#define COLOR_DARKORANGE       				(ColorType)(0xFC60)
#define COLOR_LINEN       					(ColorType)(0xFF9C)
#define COLOR_PERU       					(ColorType)(0xCC27)
#define COLOR_PEACHPUFF       				(ColorType)(0xFED7)
#define COLOR_SANDYBROWN       				(ColorType)(0xF52C)
#define COLOR_CHOCOLATE       				(ColorType)(0xD343)
#define COLOR_SADDLEBROWN       			(ColorType)(0x8A22)
#define COLOR_SEASHELL       				(ColorType)(0xFFBD)
#define COLOR_SIENNA       					(ColorType)(0xA285)
#define COLOR_LIGHTSALMON       			(ColorType)(0xFD0F)
#define COLOR_CORAL       					(ColorType)(0xFBEA)
#define COLOR_ORANGERED       				(ColorType)(0xFA20)
#define COLOR_DARKSALMON      	 			(ColorType)(0xECAF)
#define COLOR_TOMATO       					(ColorType)(0xFB08)
#define COLOR_MISTYROSE       				(ColorType)(0xFF3C)
#define COLOR_SALMON       					(ColorType)(0xFC0E)
#define COLOR_SNOW       					(ColorType)(0xFFDF)
#define COLOR_LIGHTCORAL       				(ColorType)(0xF410)
#define COLOR_ROSYBROWN       				(ColorType)(0xBC71)
#define COLOR_INDIANRED       				(ColorType)(0xCAEB)
#define COLOR_RED       					(ColorType)(0xF800)
#define COLOR_BROWN       					(ColorType)(0xA145)
#define COLOR_FIREBRICK       				(ColorType)(0xB104)
#define COLOR_DARKRED       				(ColorType)(0x8800)
#define COLOR_MAROON       					(ColorType)(0x8000)
#define COLOR_WHITE       					(ColorType)(0xFFFF)
#define COLOR_WHITESMOKE       				(ColorType)(0xF7BE)
#define COLOR_GAINSBORO       				(ColorType)(0xDEFB)
#define COLOR_LIGHTGRAY       				(ColorType)(0xD69A)
#define COLOR_SILVER       					(ColorType)(0xC618)
#define COLOR_DARKGRAY       				(ColorType)(0xAD55)
#define COLOR_GRAY       					(ColorType)(0x8410)
#define COLOR_DIMGRAY       				(ColorType)(0x6B4D)
#define COLOR_BLACK       					(ColorType)(0x0000)

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



#endif  /* #ifndef __COLOR_H */
/*************************************************************************************************
***
***                                         EOF:Graphic.h
***
*************************************************************************************************/
