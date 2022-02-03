/*
 * Instrument Framework Interface C API header file.
 *
 * Copyright (c) 2022,
 * National Instruments Corporation.
 * All rights reserved.
 */

#ifndef NIIFW_NIIFW_H
#define NIIFW_NIIFW_H

#include <stdint.h>

#include <NiFpga.h>

typedef uint32_t niIFW_InstructionTargetHandle;
typedef uint32_t niIFW_SubsystemMapHandle;
typedef uint32_t niIFW_ContextToken;


#ifndef NiFpga_Linux
#if defined(__linux__)       \
   || defined(__linux)       \
   || defined(linux)         \
   || defined(__gnu_linux__)
#define NiFpga_Linux 1
#endif // symbol check
#endif // NiFpga_Linux

#ifdef NiFpga_Linux

// This symbol should be set during the build of the NI library
#ifdef kNIIFW_LIBExportSymbols
#define _NIIFWBIN_EXPORT __attribute__ ((section (".export"))) __attribute__((__visibility__("default")))
#else
#define _NIIFWBIN_EXPORT
#endif

#else // assume Windows if not linux

// This symbol should be set during the build of the NI library
#ifdef kNIIFW_LIBExportSymbols
#define _NIIFWBIN_EXPORT __declspec(dllexport) __cdecl
#else
#define _NIIFWBIN_EXPORT __cdecl
#endif
#endif // ifndef NiFpga_Linux


extern "C" {

    /*
       This file contains the declarations for exported functions in niifwu.dll
    */

    /*******************************************************************************
     Instruction Target API
    *******************************************************************************/

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_GetInfoForResourceName(
        const char* resourceName,
        char* targetInfo,
        uint32_t* targetInfoSize,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_Open(
        const char* targetInfo,
        niIFW_InstructionTargetHandle* instructionTargetHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_OpenInternal(
        const char* targetInfo,
        niIFW_InstructionTargetHandle* instructionTargetHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_Read(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        uint8_t subsystem,
        uint64_t address,
        uint64_t* data,
        int32_t timeout,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_ReadArray(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        uint8_t* subsystems,
        uint64_t* addresses,
        uint64_t instructionCount,
        uint64_t* data,
        int32_t timeout,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_Write(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        uint8_t subsystem,
        uint64_t address,
        uint64_t data,
        uint8_t waitUntilCommitted,
        int32_t timeout,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_WriteArray(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        uint8_t* subsystems,
        uint64_t* addresses,
        uint64_t* data,
        uint64_t instructionCount,
        uint8_t waitUntilCommitted,
        int32_t timeout,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_Reset(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_Close(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Target_CloseInternal(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        void* reserved_pass_NULL
    );

    /*******************************************************************************
     FIFO Reg Bus API
    *******************************************************************************/
    int32_t
    _NIIFWBIN_EXPORT
    niIFW_FifoRegBus_Open(
        NiFpga_Session fpgaSession,
        uint8_t instance,
        niIFW_InstructionTargetHandle* instructionTargetHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_FifoRegBus_OpenInternal(
        NiFpga_Session fpgaSession,
        uint8_t instance,
        niIFW_InstructionTargetHandle* instructionTargetHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_FifoRegBus_OpenSimulated(
        NiFpga_Session fpgaSession,
        uint8_t instance,
        const uintptr_t* registerFullNamesBuf,
        size_t registerFullNamesBufSize,
        const uintptr_t* registerDynamicNamesBuf,
        size_t registerDynamicNamesBufSize,
        const uintptr_t* dmaFifoFullNamesBuf,
        size_t dmaFifoFullNamesBufSize,
        const uintptr_t* dmaFifoDynamicNamesBuf,
        size_t dmaFifoDynamicNamesBufSize,
        niIFW_InstructionTargetHandle* instructionTargetHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_FifoRegBus_SetInstructionFifoDepth(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        uint32_t instructionFifoDepth,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_FifoRegBus_GetInstructionFifoDepth(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        uint32_t* instructionFifoDepth,
        void* reserved_pass_NULL
    );

    /*******************************************************************************
     Subsystem Map API
    *******************************************************************************/
    int32_t
    _NIIFWBIN_EXPORT
    niIFW_SubsystemMap_Open(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        niIFW_SubsystemMapHandle* subsystemMapHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_SubsystemMap_OpenInternal(
        niIFW_InstructionTargetHandle instructionTargetHandle,
        niIFW_SubsystemMapHandle* subsystemMapHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_SubsystemMapFake_Open(
        niIFW_SubsystemMapHandle* subsystemMapHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_SubsystemMapFake_OpenInternal(
        niIFW_SubsystemMapHandle* subsystemMapHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_SubsystemMap_Close(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_SubsystemMap_CloseInternal(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        void* reserved_pass_NULL
    );

    /*******************************************************************************
    Context API
    *******************************************************************************/
    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Context_Contextualize(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        niIFW_ContextToken contextToken,
        uint64_t relativeAddress,
        uint8_t* subsystem,
        uint64_t* address,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Context_GetInfo(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        niIFW_ContextToken contextToken,
        uint16_t* uid,
        uint8_t* instance,
        uint16_t* version,
        uint16_t* oldestCompatibleVersion,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Context_GetSubsystemAndOffset(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        niIFW_ContextToken contextToken,
        uint8_t* subsystem,
        uint64_t* offset,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Context_CheckVersion(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        niIFW_ContextToken contextToken,
        uint16_t version,
        uint16_t oldestCompatibleVersion,
        uint8_t errorIfVersionMismatch,
        uint8_t* targetTooOld,
        uint8_t* targetTooNew,
        void* reserved_pass_NULL
    );

    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Context_GetChild(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        uint16_t uid,
        uint8_t instance,
        niIFW_ContextToken parentContextToken,
        niIFW_ContextToken* contextToken,
        void* reserved_pass_NULL
    );

    // niIFW_Context_GetChildrenByUid returns an array of child contexts.
    // The caller has to allocate memory for the array.
    // The caller can call into this method first with childContextTokensSize = 0,
    // and this method will set actualChildCount, so the caller can allocate memory,
    // and then call back with enough memory to store all of the tokens.
    // Caller may pass in NULL for childContextTokens or actualChildCount.
    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Context_GetChildrenByUid(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        niIFW_ContextToken parentContextToken,
        uint16_t uid,
        niIFW_ContextToken* childContextTokens,
        size_t childContextTokensSize,
        size_t* actualChildCount,
        void* reserved_pass_NULL
    );

    // niIFW_Context_GetAllChildren returns an array of child contexts.
    // The caller has to allocate memory for the array.
    // The caller can call into this method first with childContextTokensSize = 0,
    // and this method will set actualChildCount, so the caller can allocate memory,
    // and then call back with enough memory to store all of the tokens.
    // Caller may pass in NULL for childContextTokens or actualChildCount.
    int32_t
    _NIIFWBIN_EXPORT
    niIFW_Context_GetAllChildren(
        niIFW_SubsystemMapHandle subsystemMapHandle,
        niIFW_ContextToken parentContextToken,
        niIFW_ContextToken* childContextTokens,
        size_t childContextTokensSize,
        size_t* actualChildCount,
        void* reserved_pass_NULL
    );

} // extern "C"

#endif // NIIFW_NIIFW_H
