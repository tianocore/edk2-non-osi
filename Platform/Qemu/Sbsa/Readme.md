Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit f36faa71578a14a8c9910aaa57e761f0256ccd52 (HEAD -> master, origin/master, origin/integration, origin/HEAD)
Merge: 8dad296d6 57ab6d897
Author: Lauren Wehrmeister <lauren.wehrmeister@arm.com>
Date:   Tue Mar 12 19:17:49 2024 +0100

    Merge "fix(cpus): fix a defect in Cortex-A715 erratum 2561034" into integration


This ensures that the following features for qemu_sbsa platform are
merged upstream and included in the build:

commit 42925c15bee09162c6dfc8c2204843ffac6201c1
Author: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
Date:   Tue Nov 21 14:53:26 2023 +0100

    feat(qemu-sbsa): handle CPU information

    We want to remove use of DeviceTree from EDK2. So we move
    functions to TF-A:

    - counting cpu cores
    - checking NUMA node id
    - checking MPIDR

    And then it gets passed to EDK2 via SMC calls.

    Change-Id: I1c7fc234ba90ba32433b6e4aa2cf127f26da00fd
    Signed-off-by: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>

commit 8b7dd8397dd017b61ecda8447e8956a1d9d6d5d3
Author: Xiong Yining <xiongyining1480@phytium.com.cn>
Date:   Fri Jan 12 10:47:03 2024 +0000

    feat(qemu-sbsa): handle memory information

    As a part of removing DeviceTree from EDK2, we move functions to TF-A:

    - counting the number of memory nodes
    - checking NUMA node id
    - checking the memory address

    Signed-off-by: Xiong Yining <xiongyining1480@phytium.com.cn>
    Signed-off-by: Chen Baozi <chenbaozi@phytium.com.cn>
    Change-Id: Ib7bce3a65c817a5b3bef6c9e0a459c7ce76c7e35


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
