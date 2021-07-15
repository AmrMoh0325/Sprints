/*
 * SPI_Cfg.h
 *
 * Created: 7/14/2021 10:32:07 AM
 *  Author: Amrth
 */ 


#ifndef __SPI_CFG__
#define __SPI_CFG__
#include "DIO.h"

#define SPI_CONFIG      MASTER


#if (SPI_CONFIG == MASTER)

/* define SS Pins here */

#elif (SPI_CONFIG == SLAVE)

/* define MI Pin here */

#endif


#endif /* __SPI_CFG__ */