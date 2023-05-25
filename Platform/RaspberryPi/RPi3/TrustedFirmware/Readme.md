ARM Trusted Firmware for Raspberry Pi 3
=======================================

The `bl1.bin` and `fip.bin` TF-A binaries found in this directory were built from the
[official TF-A 2.9 release](https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git/tag/?h=v2.9)
through a [GitHub build script](https://github.com/pftf/pitf/blob/master/.github/workflows/build.yml)
that is designed to provide evidence that these binaries match the vanilla TF-A source.

Per the [GitHub Actions log](https://github.com/pftf/pitf/actions/runs/5071490963),
the SHA-256 sums for the blobs can be validated to be as follows:
- `bl1.bin`: `de32a81d17a3a1251245dd6d9b0a807e6ec54d5b50eecfda31fc9cd2ffb1d5ba`
- `fip.bin`: `7463cec7914469998d3cfab80b80710e371e8d5673959b303a7c851e37b179bb`

For Raspberry Pi 3 usage, TF-A was built using the command:
```
make PLAT=rpi3 RPI3_PRELOADED_DTB_BASE=0x10000 PRELOADED_BL33_BASE=0x30000 SUPPORT_VFP=1 RPI3_USE_UEFI_MAP=1 DEBUG=0 fip all
```
which results in the following memory mapping:
```
    0x00000000 +-----------------+
               |       ROM       | BL1
    0x00010000 +-----------------+
               |     Nothing     |
    0x00020000 +-----------------+
               |       FIP       |
    0x00030000 +-----------------+
               |                 |
               |  UEFI PAYLOAD   |
               |                 |
    0x001f0000 +-----------------+
               |       DTB       | (Loaded by the VideoCore)
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
