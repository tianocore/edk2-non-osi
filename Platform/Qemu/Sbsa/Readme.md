Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit adc63c99f14ff0584dd8899eb15d8751d7bf4e6e
Author: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
Date:   Thu Jun 27 10:11:31 2024 +0200

    refactor(qemu-sbsa): use fdt_read_uint32_default more

    We have fdt_read_uint32_default() function which allows us to use less
    temporary variables. Let make use of it where applicable.

    Signed-off-by: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
    Change-Id: I6fc8a87d5aac427703fd3c8b689e153ed58fa8b7


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
