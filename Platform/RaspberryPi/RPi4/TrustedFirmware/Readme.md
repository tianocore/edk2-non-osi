ARM Trusted Firmware for Raspberry Pi 4
=======================================

The `bl31.bin` TF-A binary found in this directory was built from the
[official TF-A 2.9 release](https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git/tag/?h=v2.9)
through a [GitHub build script](https://github.com/pftf/pitf/blob/master/.github/workflows/build.yml)
that is designed to provide evidence that these binaries match the vanilla TF-A source.

Per the [GitHub Actions log](https://github.com/pftf/pitf/actions/runs/5071490963),
the SHA-256 sum for the bin can be validated to be as follows:
- `bl31.bin`: `681afd3c044ad0020c3182e9f7a8d43f726ab19467dba2db8086bb41f3e4b521`

For Raspberry Pi 4 usage, TF-A was built using the command:
```
make PLAT=rpi4 RPI3_PRELOADED_DTB_BASE=0x1F0000 PRELOADED_BL33_BASE=0x20000 SUPPORT_VFP=1 SMC_PCI_SUPPORT=1 DEBUG=0 all
```
