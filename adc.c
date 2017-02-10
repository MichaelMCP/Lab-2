/**
  ******************************************************************************
  * File Name          : ADC.c
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "adc.h"

/* USER CODE BEGIN 0 */
ADC_HandleTypeDef ADC1_Handle;
ADC_ChannelConfTypeDef ADC1_channel16;
//Initializes the ADC.
void ADC_Init(void){
	ADC1_Handle.Instance = ADC1;
	//Sets all ADCs clock to their maximum value of half the system clock (4MHz).
	ADC1_Handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	//Sets resolution of ADC to 8bit for ease of computation.
	ADC1_Handle.Init.Resolution = ADC_RESOLUTION_8B;
	ADC1_Handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	//Disables multi channel scanning and instead only uses a single channel.
	ADC1_Handle.Init.ScanConvMode = DISABLE;
	//I dunno what this does so I disabled it.
	ADC1_Handle.Init.EOCSelection = DISABLE;
	//Sets the ADC to continuously convert data.
	ADC1_Handle.Init.ContinuousConvMode = ENABLE;
	//Allows for interupts by activating continuous direct memory access requests.
	ADC1_Handle.Init.DMAContinuousRequests = ENABLE;
	//Sets the ADC to make one conversion at a time
	ADC1_Handle.Init.NbrOfDiscConversion = 1;
	//Disables external triggers, unsure if needed.
	ADC1_Handle.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	ADC1_Handle.Init.ExternalTrigConvEdge = ADC_SOFTWARE_START;
	
	//Sets up the temperature sensor to work.
	ADC1_channel16.Channel = ADC_CHANNEL_16;
	ADC1_channel16.Rank = 1;
	//Lists the sampling time for the ADC [THIS STILL NEEDS TO BE CALCULATED]
	ADC1_channel16.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	
	//Sets up the ADC clock
	__ADC1_CLK_ENABLE();
	return;
}
//Initialized the requested channel.


/* USER CODE END 0 */



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
