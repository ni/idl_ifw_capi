// NIIFW_example.cpp
// This example demonstrates how to use the NI-IFW library to communicate with an FPGA board.
// Copyright (c) 2022,
// National Instruments Corporation.
// All rights reserved.



#include "niifw.h"
#include <NiFpga.h>

#include <stdio.h>


#define BitFilepath         "C:/Users/Administrator/Desktop/Multirecord_Acquisition_NI_PXIe-5171R_8CH.lvbitx"
#define BitFileSignature    "BBAB0C3658C0FCD270F5D0C7FBAE2DF7"
#define DevicePath          "PXI1Slot2"


int main()
{
    NiFpga_Session session;
    NiFpga_Status fpga_status;
    niIFW_InstructionTargetHandle handle;
    int32_t ifw_status;
    uint64_t data=0;

    fpga_status = NiFpga_Initialize();
    fpga_status = NiFpga_Open(BitFilepath,BitFileSignature,DevicePath,0,&session);

    ifw_status = niIFW_FifoRegBus_OpenInternal(session,0,&handle,NULL);
    ifw_status = niIFW_Target_Read(handle,0,0,&data,1000,NULL);
    ifw_status = niIFW_Target_CloseInternal(handle,NULL);

    fpga_status = NiFpga_Close(session,NiFpga_CloseAttribute_NoResetIfLastSession);
    fpga_status = NiFpga_Finalize();

    // If the board returned 0x6EA04, that is the desired response.
    printf("Received response from board: %s\n",data==0x6EA04?"CORRECT":"INCORRECT");
}
