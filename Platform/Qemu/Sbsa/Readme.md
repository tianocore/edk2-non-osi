Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit dcf430656ca8ef964fa55ad9eb81cf838c7837f2 (tag: v2.9-rc0)
Merge: 3011e1afe b1af2676f
Author: Manish Pandey <manish.pandey2@arm.com>
Date:   Thu May 11 13:41:35 2023 +0200

    Merge "docs(psci): expound runtime instrumentation docs" into integration


This ensures that the following feature for qemu_sbsa platform is
merged upstream and is included in the build:

commit c598692d0c6a79dd10c34d5a4a740c90261cfc65
Author: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
Date:   Tue Feb 14 09:27:59 2023 +0100

    fix(qemu-sbsa): enable FGT

    QEMU 7.2+ has FEAT_FGT support added to 'max' cpu.

    So let's enable it to make Debian 'bookworm' kernel boot on sbsa-ref/max setup.

    Signed-off-by: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
    Change-Id: I49fb3e742b69ce7be5666e0144525dde21a68238


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
