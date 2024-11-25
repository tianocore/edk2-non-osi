Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit 4ec2948fe3f65dba2f19e691e702f7de2949179c (tag: v2.12.0, tag: v2.12)
Author: Govindraj Raja <govindraj.raja@arm.com>
Date:   Wed Nov 20 23:30:24 2024 +0100

    Merge "docs(changelog): changelog for v2.12 release" into integration


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
