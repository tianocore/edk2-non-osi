Qemu SBSA TF-A binaries
-----------------------

These binaries have been created from the mainline TF-A
code checked out at the following commit ID:

commit 56b263cb2a25892038761acea8c2b57a638d19bf (HEAD -> integration, origin/integration, gerrit/integration)
Merge: 09d3fd141 e769f830d
Author: Yann Gautier <yann.gautier@st.com>
Date:   Tue Apr 23 10:42:01 2024 +0200

    Merge "feat(qemu): allow ARM_ARCH_MAJOR/MINOR override" into integration


This ensures that the following features for qemu_sbsa platform are
merged upstream and included in the build:

commit 5436047a0e1f32543042d6de9f1f6a3edcd47591
Author: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>
Date:   Mon Apr 22 17:27:56 2024 +0200

    refactor(qemu): do not hardcode counter frequency

    From QEMU change:

    > In previous versions of the Arm architecture, the frequency of the
    > generic timers as reported in CNTFRQ_EL0 could be any IMPDEF value,
    > and for QEMU we picked 62.5MHz, giving a timer tick period of 16ns.
    > In Armv8.6, the architecture standardized this frequency to 1GHz.

    This change stops TF-A from hardcoding 62.5MHz frequency. Instead value
    stored in CNTFRQ_EL0 would be used. As a result we get 62.5MHz on older
    cores and 1GHz on newer ones.

    Change-Id: I7d414ce6d3708e598bbb5a6f79eb2d4ec8e15ac4
    Signed-off-by: Marcin Juszkiewicz <marcin.juszkiewicz@linaro.org>

commit 1b694c77c497cb8272c97417ef1fa4f5f9c869c1
Author: Jean-Philippe Brucker <jean-philippe@linaro.org>
Date:   Mon Apr 15 14:28:11 2024 +0100

    feat(qemu): enable FEAT_ECV when present

    QEMU supports FEAT_ECV since commit 2808d3b38a52 ("target/arm: Implement
    FEAT_ECV CNTPOFF_EL2 handling"), in the v9.0.0 release. Enable
    auto-detecting the feature on the QEMU platforms, in order to set
    SCR.ECVEN. Without this, EL2 gets undefined instruction exceptions when
    trying to access the new CNTPOFF register.

    Change-Id: I555a5f9a9a84fd23e64ca85219ed1599204c6bb2
    Signed-off-by: Jean-Philippe Brucker <jean-philippe@linaro.org>


NOTE: No modifications to the source code have been done.
      The binaries have been generated for the AARCH64 platform
      with the following command:

	make PLAT=qemu_sbsa all fip
