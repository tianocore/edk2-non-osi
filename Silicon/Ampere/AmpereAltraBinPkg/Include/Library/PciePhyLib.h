/** @file

  Copyright (c) 2020 - 2021, Ampere Computing LLC. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef PCIE_PHY_LIB_H_
#define PCIE_PHY_LIB_H_

/**
  Initialize the PCIe PHY.

  @param[in] PhyBase           Base address of the PCIe PHY.

  @retval RETURN_SUCCESS       PCIe PHY has been initialized successfully.
  @retval RETURN_DEVICE_ERROR  Failed to initialize the PCIe PHY.
**/
RETURN_STATUS
PciePhyInit (
  IN PHYSICAL_ADDRESS   PhyBase
  );

#endif /* PCIE_PHY_LIB_H_ */
