/** @file
  Helper functions for PCH SMM

  Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef PCH_SMM_HELPERS_H
#define PCH_SMM_HELPERS_H

#include "PchSmm.h"
#include "PchxSmmHelpers.h"

//
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SUPPORT / HELPER FUNCTIONS (PCH version-independent)
//

/**
  Publish SMI Dispatch protocols.

**/
VOID
PchSmmPublishDispatchProtocols (
  VOID
  );

/**
  Compare 2 SMM source descriptors' enable settings.

  @param[in] Src1                 Pointer to the PCH SMI source description table 1
  @param[in] Src2                 Pointer to the PCH SMI source description table 2

  @retval TRUE                    The enable settings of the 2 SMM source descriptors are identical.
  @retval FALSE                   The enable settings of the 2 SMM source descriptors are not identical.
**/
BOOLEAN
CompareEnables (
  CONST IN PCH_SMM_SOURCE_DESC *Src1,
  CONST IN PCH_SMM_SOURCE_DESC *Src2
  );

/**
  Compare 2 SMM source descriptors' statuses.

  @param[in] Src1                 Pointer to the PCH SMI source description table 1
  @param[in] Src2                 Pointer to the PCH SMI source description table 2

  @retval TRUE                    The statuses of the 2 SMM source descriptors are identical.
  @retval FALSE                   The statuses of the 2 SMM source descriptors are not identical.
**/
BOOLEAN
CompareStatuses (
  CONST IN PCH_SMM_SOURCE_DESC *Src1,
  CONST IN PCH_SMM_SOURCE_DESC *Src2
  );

/**
  Compare 2 SMM source descriptors, based on Enable settings and Status settings of them.

  @param[in] Src1                 Pointer to the PCH SMI source description table 1
  @param[in] Src2                 Pointer to the PCH SMI source description table 2

  @retval TRUE                    The 2 SMM source descriptors are identical.
  @retval FALSE                   The 2 SMM source descriptors are not identical.
**/
BOOLEAN
CompareSources (
  CONST IN PCH_SMM_SOURCE_DESC *Src1,
  CONST IN PCH_SMM_SOURCE_DESC *Src2
  );

/**
  Check if an SMM source is active.

  @param[in] Src                  Pointer to the PCH SMI source description table

  @retval TRUE                    It is active.
  @retval FALSE                   It is inactive.
**/
BOOLEAN
SourceIsActive (
  CONST IN PCH_SMM_SOURCE_DESC *Src
  );

/**
  Enable the SMI source event by set the SMI enable bit, this function would also clear SMI
  status bit to make initial state is correct

  @param[in] SrcDesc              Pointer to the PCH SMI source description table

**/
VOID
PchSmmEnableSource (
  CONST PCH_SMM_SOURCE_DESC *SrcDesc
  );

/**
  Disable the SMI source event by clear the SMI enable bit

  @param[in] SrcDesc              Pointer to the PCH SMI source description table

**/
VOID
PchSmmDisableSource (
  CONST PCH_SMM_SOURCE_DESC *SrcDesc
  );

/**
  Clear the SMI status bit by set the source bit of SMI status register

  @param[in] SrcDesc              Pointer to the PCH SMI source description table

**/
VOID
PchSmmClearSource (
  CONST PCH_SMM_SOURCE_DESC *SrcDesc
  );

/**
  Sets the source to a 1 and then waits for it to clear.
  Be very careful when calling this function -- it will not
  ASSERT.  An acceptable case to call the function is when
  waiting for the NEWCENTURY_STS bit to clear (which takes
  3 RTCCLKs).

  @param[in] SrcDesc              Pointer to the PCH SMI source description table

**/
VOID
PchSmmClearSourceAndBlock (
  CONST PCH_SMM_SOURCE_DESC *SrcDesc
  );

#endif
