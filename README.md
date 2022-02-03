# idl_ifw_capi
C API for Instruction Framework Instrument Design Library

This repo contains the essentials for using the Instruction Framework (IFw) Instrument Design Library (IDL)
with C or other C-compatible languages.

## include/niifw.h
This header provides function declarations for the functions that are exported by the Instruction Framework dynamic library.

## import_lib/niifwu.lib
This import library is needed to implicitly link functions which are exported by the Instruction Framework dynamic library.
This copy of niifwu.lib comes from the 64-bit build of niifwu.dll, version 1.1.1f0. It should be forward-compatible with
newer versions.

## example/niifw_example.c
This C program shows a very simple usage of the NiFpga API in tandem with niifw.

# See Also
For more information about the Instruction Framework, see the Instruction Framework Tutorial on NI Labs:  
https://forums.ni.com/t5/NI-Labs-Toolkits/Instruction-Framework-Tutorial/ta-p/3533500
