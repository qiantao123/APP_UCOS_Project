/******************** (C) COPYRIGHT 2009 STMicroelectronics ********************
* File Name          : stm32f10x_type.h
* Author             : MCD Application Team
* Version            : V2.1.0RC2
* Date               : 03/13/2009
* Description        : This file contains all the common data types used for the
*                      STM32F10x firmware library.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMTYPEDEF_H
#define __COMMTYPEDEF_H

#include "stm32f10x.h"
#include "ProjectConfig.h"

#define STD_ON                              (1u)
#define STD_OFF                             (0u)

#define STD_USED                           (STD_ON)
#define STD_UNUSED                       (STD_OFF)

#define LOCAL 							static;

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/*!< STM32F10x Standard Peripheral Library old types (maintained for legacy purpose) */
typedef enum
{
    FALSE = 0u,
    TRUE,
}bool_t;

typedef float		f32;

#define U8_MAX     ((u8)255)
#define S8_MAX     ((s8)127)
#define S8_MIN     ((s8)-128)
#define U16_MAX    ((u16)65535u)
#define S16_MAX    ((s16)32767)
#define S16_MIN    ((s16)-32768)
#define U32_MAX    ((u32)4294967295uL)
#define S32_MAX    ((s32)2147483647)
#define S32_MIN    ((s32)-2147483648)

#define _GET_ARRAY_LENGTH(x)    (sizeof(x) / sizeof(x[0]))

#define _GET_ABS(x)				((x)>0?(x):(-(x)))
/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param expr: If expr is false, it calls assert_failed function
  *   which reports the name of the source file and the source
  *   line number of the call that failed. 
  *   If expr is true, it returns no value.
  * @retval : None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __STM32F10x_TYPE_H */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
