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

# Usage notes
This API has been tested using an x64 build configuration in Visual Studio 2022, on Windows 11, and interacting with a NI PXIe-5171R device.

niifwu.dll can be found in the `resource` subdirectory of the LabVIEW directory on your system, after installing FlexRIO, IDLs for Reconfigurable Oscilloscopes,
or any other NI software product which uses the Common IDLs.

This C API will work with the version of niifwu.dll that is installed into LabVIEW 2019 or newer (version is reported as 1.1.1f0 or newer in the niifwu.dll file properties).
Most LabVIEW 2018 installations will have niifwu.dll version 1.1.0f0, although there are a few newer 2018 packages out there which will use niifwu.dll version 1.1.1f0.

Copy niifwu.dll into the same directory as your built application. It is **not recommended** to install niifwu.dll into the system library (`C:\Windows\System32`).

Use `*_OpenInternal` and `*_CloseInternal` functions instead of `*_Open` and `*_Close` when using this library outside of a LabVIEW process.

# See Also
For more information about the Instruction Framework, see the Instruction Framework Tutorial on NI Labs:  
https://forums.ni.com/t5/NI-Labs-Toolkits/Instruction-Framework-Tutorial/ta-p/3533500
