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
    //char chn[];
    
    SYSTEM_Initialize();
	uartInitialize(); 
    uartPrint("Début");
    while(1)
    {
        if(uartIsChar()) 
        {
            uartPrint("Test");
            uartRead();
        }
    }
        
}