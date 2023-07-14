Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit 2503c8f3204c60013de8caa2e165b2875ad735e5 (HEAD -> master, origin/master, origin/HEAD)
Merge: 9b81d117b bd596a101
Author: Bipin Ravi <bipin.ravi@arm.com>
Date:   Thu Jul 13 16:45:54 2023 +0200

    Merge "build(fpga): remove a710 from fpga build" into integration


This ensures that the following feature for qemu_sbsa platform is
merged upstream and is included in the build:

commit 214de62c92b2fc4b7edda9d9d637b7a4c0ba1fa5
Author: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
Date:   Tue Jul 4 15:41:40 2023 +0200

    feat(qemu): add "neoverse-v1" cpu support

    Add support to qemu "neoverse-v1" cpu for "qemu_sbsa" ('sbsa-ref')
    platform.

    Change-Id: Id710e2b960e7938d2dbe7a88d9e158a7009fc3d1
    Signed-off-by: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
