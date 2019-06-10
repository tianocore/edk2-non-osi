ARM Trusted Firmware for Raspberry Pi 3
=======================================

The `bl1.bin` and `fip.bin` ATF binaries found in this directory were built from the
[official ATF 2.1 release](https://github.com/ARM-software/arm-trusted-firmware/releases/tag/v2.1)
through an [AppVeyor build script](https://github.com/pbatard/pitf/blob/master/appveyor.yml)
that is designed to provide evidence that these binaries match the vanilla ATF source.

As per the [AppVeyor build log](https://ci.appveyor.com/project/pbatard/pitf/builds/24506898),
the SHA-256 sums for the blobs can be validated to be as follows:
- `bl1.bin`: `57e30ed8572e6a3a161c231e68138ee2c78e9dfc6dc51be8c0b4d9c3fe9bbfad`
- `fip.bin`: `b7eadad3a11088e322c52ab5fd2247a7bc79dc086a21db12cc8079a2ab4789f6`

For Raspberry Pi 3 usage, ATF was built using the command:
```
make PLAT=rpi3 PRELOADED_BL33_BASE=0x30000 RPI3_PRELOADED_DTB_BASE=0x10000 SUPPORT_VFP=1 RPI3_USE_UEFI_MAP=1 fip all
```
which results in the following memory mapping:
```
    0x00000000 +-----------------+
               |       ROM       | BL1
    0x00010000 +-----------------+
               |       DTB       | (Loaded by the VideoCore)
    0x00020000 +-----------------+
               |       FIP       |
    0x00030000 +-----------------+
               |                 |
               |  UEFI PAYLOAD   |
               |                 |
    0x00200000 +-----------------+
               |   Secure SRAM   | BL2, BL31
    0x00300000 +-----------------+
               |   Secure DRAM   | BL32 (Secure payload)
    0x00400000 +-----------------+
               |                 |
               |                 |
               | Non-secure DRAM | BL33
               |                 |
               |                 |
    0x01000000 +-----------------+
               |                 |
               |       ...       |
               |                 |
    0x3F000000 +-----------------+
               |       I/O       |
```
