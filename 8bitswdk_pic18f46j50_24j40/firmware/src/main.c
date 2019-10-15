/**
 * TP II0905 
 *
 * Nom binôme : SHAITA Yanis / BERTAUX Quentin
 *
 * Version : 0.500.000
 *
 */
/************************ HEADERS ****************************************/
#include "VT100.h"
#include "system.h"
#include "system_config.h"
#include "miwi/miwi_api.h"

/************************** PROTOTYPES ************************************/

/************************** VARIABLES ************************************/
        
extern API_UINT16_UNION                 myPANID;        						// mon PANID
extern uint8_t                          myLongAddress[MY_ADDRESS_LENGTH];		// mon adresse IEEE
extern API_UINT16_UNION                 myShortAddress;                     	// mon adresse logique
extern ACTIVE_SCAN_RESULT               ActiveScanResults[ACTIVE_SCAN_RESULT_SIZE];		// table des actives scan
extern RECEIVED_MESSAGE  rxMessage;

void main (void)
{
    //char chn[]="Reception";
    uint8_t dtct;
    //bool wake;
    
    //Initialisation système & UART
    SYSTEM_Initialize();
	uartInitialize(); 
    //Initialisation MiWi
    MiApp_ProtocolInit(false);
    MiApp_SetChannel(15);
    
    //Procédure de connexion
    dtct = MiApp_SearchConnection(10,0xFFFF);

    if(dtct == 0) 
    {
        MiApp_StartConnection(START_CONN_DIRECT, 0, 0);
       uartPrint("Pas de PAN, creation");
    }
    else
    {
        MiApp_EstablishConnection(0xFF, CONN_MODE_INDIRECT);
       uartPrint("PAN trouve");
    }
    
    //Fin de connexion
   // CleanScreen();
    
    while(1)
    {
        MiApp_FlushTx();
        MiApp_WriteData(0xDD);
        MiApp_BroadcastPacket(false);
        
        if(uartIsChar()) uartPrint(rxMessage.Payload);
    }    
}