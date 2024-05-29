Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit f2735ebccf5173f74c0458736ec526276106097e (tag: v2.11.0, tag: v2.11)
Merge: 6370f2cbb 669e2b159
Author: Manish Pandey <manish.pandey2@arm.com>
Date:   Thu May 23 13:51:22 2024 +0200

    Merge "docs(changelog): changelog for v2.11 release" into integration


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
