ARM Trusted Firmware for Raspberry Pi 4
=======================================

The `bl31_#####.bin` TF-A binaries found in this repository were built on a Debian 10.2 system
from https://github.com/pbatard/arm-trusted-firmware/tree/pi4 (pi4 branch) using the command:

```
make PLAT=rpi4 RPI3_PRELOADED_DTB_BASE=0x20000 PRELOADED_BL33_BASE=0x30000 SUPPORT_VFP=1 [RPI3_USE_PL011_UART=1] DEBUG=0 all
```

The only difference between these firmwares is that the `RPI3_USE_PL011_UART=1` option was added
to build `bl31_pl011.bin` so that it uses PL011 for serial output rather than the "mini UART".
