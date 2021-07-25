#include "MCAL/I2C/I2C.h"



/*I2C MASTER OPERATIONS */ 

#define I2C_READ        1
#define I2C_WRITE       0

/* STATUS CODES FOR I2C BUS */
/* MASTER CODES */
#define START_TRANSMITTED                                         0x08
#define RESTART_TRANSMITTED                                       0x10
#define ARBITRATION_LOST                                          0x38

/* MASTER TRANSMITTER MODE */

#define SLA_W_TRANSMITTED_ACK                                     0x18
#define SLA_W_TRANSMITTED_NACK                                    0x20
#define MASTER_DATA_TRANSMITTED_ACK                               0x28
#define MASTER_DATA_TRANSMITTED_NACK                              0x30


/* MASTER RECEIVER MODE */
#define SLA_R_TRANSMITTED_ACK                                     0x40
#define SLA_R_TRANSMITTED_NACK                                    0x48
#define DATA_RECEIVED_ACK                                         0x50
#define DATA_RECEIVED_NACK                                        0x58


/* SLAVE MODE */
/* SLAVE RECEIVER MODE */
#define OWN_SLA_W_RECEIVED_ACK                                    0x60
#define M_ARBITRATION_LOST_OWN_SLA_W_RECEIVED_ACK                 0x68
#define GENERAL_CALL_ADDRESS_RECEIVED_ACK                         0x70
#define M_ARBITRATION_LOST_GENERAL_CALL_ADDRESS_RECEIVED_ACK      0x78
#define OWN_SLA_W_DATA_RECEIVED_ACK                               0x80
#define OWN_SLA_W_DATA_RECEIVED_NACK                              0x88
#define GENERAL_CALL_DATA_RECEIVED_ACK                            0x80
#define GENERAL_CALL_DATA_RECEIVED_NACK                           0x88
#define RECEIVED_STOP_OR_RESTART_AS_SLAVE                         0xA0

/* SLAVE TRASMITTER MODE */       
#define OWN_SLA_R_RECEIVED_ACK                                    0xA8
#define M_ARBITRATION_LOST_OWN_SLA_R_RECEIVED_ACK                 0xB0
#define SLAVE_DATA_TRANSMITTED_ACK                                0xB8
#define SLAVE_DATA_TRANSMITTED_NACK                               0xC0
#define SLAVE_LAST_DATA_BYTE_TRANSMITTED_ACK                      0xC8


/* MISC CODES */
#define NO_INFO_AVAILABLE                                         0xF8
#define BUS_ERROR                                                 0x00



static uint8_t I2C_GetStatus(void)
{
   return (TWSR_R & 0xF8);
}

enuErrorStatus_t I2C_Init(void)
{
   /* set up master clock */ 
   CLR_BIT(TWSR_R,TWPS0_B);
   CLR_BIT(TWSR_R,TWPS1_B);
   
   TWBR_R=32;
   /* set up slave address */
   TWAR_R= (0x01<<1) & 1; 
   /* write 1 to TWINT bit */
   SET_BIT(TWCR_R,TWINT_B);
   /*Enable I2C Communication*/
   SET_BIT(TWCR_R,TWEN_B);
}


enuErrorStatus_t I2C_Start(void)
{
   CLR_BIT(TWCR_R,TWSTO_B);
   SET_BIT(TWCR_R,TWSTA_B);
   SET_BIT(TWCR_R,TWEN_B);
   SET_BIT(TWCR_R,TWINT_B);
}
enuErrorStatus_t I2C_Repeated_Start(void)
{
   CLR_BIT(TWCR_R,TWSTO_B);
   SET_BIT(TWCR_R,TWSTA_B);
   SET_BIT(TWCR_R,TWEN_B);
   SET_BIT(TWCR_R,TWINT_B);
}

enuErrorStatus_t I2C_Stop(void)
{
   CLR_BIT(TWCR_R,TWSTA_B);
   SET_BIT(TWCR_R,TWSTO_B);
   SET_BIT(TWCR_R,TWEN_B);
   SET_BIT(TWCR_R,TWINT_B);
}

enuErrorStatus_t I2C_MASTER_SendData(uint8_t u8SlaveAddress,uint8_t u8Data)
{
   I2C_Start();
   while(!GET_BIT(TWCR_R,TWINT_B));
   if(I2C_GetStatus()!=START_TRANSMITTED)
   {
      return ERROR;
   }
   TWDR_R= (u8SlaveAddress<<1) | I2C_WRITE;
   SET_BIT(TWCR_R,TWINT_B);
   while(!GET_BIT(TWCR_R,TWINT_B));
   if(I2C_GetStatus()!=SLA_W_TRANSMITTED_ACK)
   {
      return ERROR;
   }
   TWDR_R=u8Data;
   SET_BIT(TWCR_R,TWINT_B);
   while(!GET_BIT(TWCR_R,TWINT_B));
   if(I2C_GetStatus()!=MASTER_DATA_TRANSMITTED_ACK)
   {
      return ERROR;
   }
   I2C_Stop();
}

enuErrorStatus_t I2C_MASTER_RecieveData(uint8_t u8SlaveAddress,uint8_t  *pu8Data)
{
   I2C_Start();
   while(!GET_BIT(TWCR_R,TWINT_B));
   if(I2C_GetStatus()!=START_TRANSMITTED)
   {
      return ERROR;
   }
   TWDR_R= (u8SlaveAddress<<1) | I2C_READ;
   SET_BIT(TWCR_R,TWINT_B);
   while(!GET_BIT(TWCR_R,TWINT_B));
   if(I2C_GetStatus()!=SLA_R_TRANSMITTED_ACK)
   {
      return ERROR;
   }   
   SET_BIT(TWCR_R,TWINT_B);
   while(!GET_BIT(TWCR_R,TWINT_B));
   if(I2C_GetStatus()!=DATA_RECEIVED_ACK)
   {
      return ERROR;
   }
   *pu8Data=TWDR_R;
   I2C_Stop();
   return SUCCESS;
}


enuErrorStatus_t I2C_SLAVE_SendData(uint8_t u8Data)
{
   while(!GET_BIT(TWCR_R,TWINT_B));
   if(I2C_GetStatus()==OWN_SLA_R_RECEIVED_ACK || I2C_GetStatus()==M_ARBITRATION_LOST_OWN_SLA_R_RECEIVED_ACK)
   {
      TWDR_R=u8Data;
      SET_BIT(TWCR_R,TWINT_B);
      while(!GET_BIT(TWCR_R,TWINT_B));
      if(I2C_GetStatus()!=SLAVE_DATA_TRANSMITTED_ACK && I2C_GetStatus()!=SLAVE_LAST_DATA_BYTE_TRANSMITTED_ACK)
      {
         return ERROR;
      }
      return SUCCESS;
   }
   return ERROR;
}

enuErrorStatus_t I2C_SLAVE_ReceiveData(uint8_t *pu8Data)
{
   while(!GET_BIT(TWCR_R,TWINT_B));
   if(I2C_GetStatus()==OWN_SLA_W_RECEIVED_ACK || I2C_GetStatus()== GENERAL_CALL_ADDRESS_RECEIVED_ACK)
   {
      SET_BIT(TWCR_R,TWINT_B);
      while(!GET_BIT(TWCR_R,TWINT_B));
      if(I2C_GetStatus()!=OWN_SLA_W_DATA_RECEIVED_ACK && I2C_GetStatus()!=GENERAL_CALL_DATA_RECEIVED_ACK)
      {
         return ERROR;
      }
      *pu8Data=TWDR_R;
      SET_BIT(TWCR_R,TWINT_B);
      while(!GET_BIT(TWCR_R,TWINT_B));
      if(I2C_GetStatus()==RECEIVED_STOP_OR_RESTART_AS_SLAVE)
      {
         return SUCCESS;
      }
   }
   return ERROR;
}

enuErrorStatus_t I2C_SendString(uint8_t *pu8Data);
enuErrorStatus_t I2C_ReceiveString(uint8_t *pu8Data,uint8_t u8bufferMaxSize);

enuErrorStatus_t I2C_Enable_Interrupt(void);
enuErrorStatus_t I2C_Disable_Interrupt(void);
enuErrorStatus_t I2C_SetCallBack(void(*local_fptr)(void));