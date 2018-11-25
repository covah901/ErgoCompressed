ErgoCompressed
========
ErgoCompressed is a modified version of ErgoDone which was a modification of Ergodox

It is based on Arduino pro micro and all of the keys are 1U in size to make it narrower and easier to find a keyset for it
It's possible to do 2u keys in thumb cluster however there is not pcb support for stabilisers for the middle buttton in 2u configuration.

For compact uses the innermost column of thumb cluster can be safely cut away along the line on the PCB 
Precompiled QMK firmware for it is located at: https://github.com/przemo-c/ErgoCompressed/tree/master/Firmware-bin
To Flash it Use QMK Toolbox select the hex file check the AutoFlash checkbox and short pins RST and GND momentarily.

If you want to modify the source and compile QMK yourself checkout the QMK and place contents of https://github.com/przemo-c/ErgoCompressed/tree/master/Firmware-for-qmk-src in root QMK folder
To build the firmware: make ergocompressed:default 

Url for Hardware and Firmware: http://github.com/przemo-c/ErgoCompressed 
