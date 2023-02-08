Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit 6264643a0711faef346cbbb6e3d928a198aeaf31
Merge: d9248e851 cb3e9650f
Author: Manish V Badarkhe <manish.badarkhe@arm.com>
Date:   Fri Feb 3 17:04:42 2023 +0100

    Merge "refactor(tc): update total compute gpu device node" into integration


This ensures that the following fix for qemu_sbsa platform is
merged upstream and is included in the build:

commit 9bff7ce37545162d417953ac36c6878216815b94
Author: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
Date:   Wed Nov 16 14:47:51 2022 +0100

    fix(qemu-sbsa): enable SVE and SME

    Commit 337ff4f1dd6604738d79fd3fa275ae74d74256b2 enabled SVE/SME for
    qemu platform. Let do the same for qemu-sbsa one too.

    With this change I can boot Debian 'bookworm' installed using Max cpu.

    Info from referenced commit:

    Starting with QEMU v3.1.0 (Dec 2018), QEMU's TCG emulation engine supports
    the SVE architecture extension. In QEMU v7.1.0 (Aug 2022) it also gained
    SME support.

    As it stands today, running TF-A under QEMU with "-cpu max" makes Linux
    hang, because SME and SVE accesses trap to EL3, but are never handled
    there. This is because the Linux kernel sees the SVE or SME feature bits,
    and assumes firmware has enabled the feature for lower exception levels.
    This requirement is described in the Linux kernel booting protocol.

    Enable those features in the TF-A build, so that BL31 does the proper
    EL3 setup to make the feature usable in non-secure world.
    We check the actual feature bits before accessing SVE or SME registers,
    so this is safe even for older QEMU version or when not running with
    -cpu max. As SVE and SME are AArch64 features only, do not enable them
    when building for AArch32.

    Signed-off-by: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
    Change-Id: I9ea1f91e6b801218d944e8a7d798d5ae568ed59a


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
