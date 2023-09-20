Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit 84de50c7d8ca416e504aedb228bb4cab6eed806f (HEAD -> master, origin/master, origin/integration, origin/HEAD)
Merge: 1e038c94d 4796d2d9b
Author: Olivier Deprez <olivier.deprez@arm.com>
Date:   Tue Sep 19 18:15:12 2023 +0200

    Merge "feat(ethos-n): update npu error handling" into integration


This ensures that the following features for qemu_sbsa platform are
merged upstream and included in the build:

commit 408cde8a59080ac2caa11c4d99474b2ef09f90df
Author: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
Date:   Mon Sep 18 12:47:45 2023 +0200

    fix(qemu_sbsa): align FIP base to BL1 size

    RME patch series shown that we can build larger BL1 than we can run:

    NOTICE:  Booting Trusted Firmware
    NOTICE:  BL1: v2.9(debug):v2.9.0-736-g08548888a
    NOTICE:  BL1: Built : 12:10:39, Sep 18 2023
    INFO:    BL1: RAM 0x3ffee000 - 0x3fffb000
    INFO:    BL1: Loading BL2
    WARNING: Firmware Image Package header check failed.

    RME pushed debug build BL1 over 0x8000 in size.
    This exposed an error where FIP_BASE (supposed to be at BL1_SIZE offset
    from start of flash) was actually 0x8000 and not 0x12000.
    Make sure we have space for BL1 by deriving FIP_BASE from it.

    Note: this is a breaking change for edk2 FD image generation, which had
    similarly hardcoded a 0x8000 offset. These images must be updated in
    lock-step.

    Change-Id: I8a1a85e82319945a4412c424467d818d5b6e4ecd
    Signed-off-by: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>

commit 408f9cb485796a73c5b87da70644665a13c685e4
Author: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
Date:   Fri Sep 15 22:44:04 2023 +0200

    feat(qemu): add "neoverse-n2" cpu support

    Add support to qemu "neoverse-n2" cpu for "qemu" platform.
    This one has 2^48 address space so will be used by both systems.

    Signed-off-by: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
    Change-Id: I9f0fa23a4934d9464379495225e08adc121325b4

NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
