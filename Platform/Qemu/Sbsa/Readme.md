Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit 5fdb2e5471c6ae564ea60d986505418134e7516f
Merge: e550fa127 ccc61e100
Author: Olivier Deprez <olivier.deprez@arm.com>
Date:   Tue Mar 21 10:46:41 2023 +0100

    Merge changes I924ea85d,I22e128c4,I7a5cfaac into integration

    * changes:
      feat(mt8195): add support for SMC from OP-TEE
      feat(mediatek): add SMC handler for EMI MPU
      feat(mediatek): add SiP service for OP-TEE

This ensures that the following feature for qemu_sbsa platform is
merged upstream and is included in the build:

commit 226f4c8e35c4441e80ad523b9105eab4ca630396
Author: Chen Baozi <chenbaozi@phytium.com.cn>
Date:   Wed Feb 22 06:58:39 2023 +0000

    feat(qemu): add "neoverse-n1" cpu support

    Add support to qemu "neoverse-n1" cpu for "qemu_sbsa" ('sbsa-ref')
    platform.

    Signed-off-by: Chen Baozi <chenbaozi@phytium.com.cn>
    Change-Id: I4620e879c71115451ae91a1643812d89ec7c071f


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
