/**
 * TP II0905 
 *
 * Nom binôme : SHAITA Yanis / BERTAUX Quentin
 *
 * Version : 0.000.000
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
    char chn[]="";
    uint8_t detect;
    bool wake;
    
    SYSTEM_Initialize();
	uartInitialize(); 
    
    MiApp_ProtocolInit(false);
    MiApp_SetChannel(11);
    detect = MiApp_SearchConnection(12,0X1L<<11);

    if(detect == 0) MiApp_StartConnection(START_CONN_DIRECT, 10, 0xFF);
     
    while(1)
    {
        MiApp_FlushTx();
        MiApp_WriteData(0x63);
        MiApp_MessageAvailable();
        if(uartIsChar()) 
        {
            uartRead();
        }
    }
        
}