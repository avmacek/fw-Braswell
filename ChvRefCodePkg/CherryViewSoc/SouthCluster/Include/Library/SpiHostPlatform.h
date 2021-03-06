/** @file
  Declare the platform requirements for the SPI controller

  Copyright (c) 2014 - 2015, Intel Corporation. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _SPI_PORT_H
#define _SPI_PORT_H

//------------------------------------------------------------------------------
//  Types
//------------------------------------------------------------------------------

//
// Context passed from platform (board) layer to the SPI port driver.
//
typedef struct {
  EFI_PHYSICAL_ADDRESS BaseAddress;
  UINT32 InputFrequencyHertz;
} SPI_PLATFORM_CONTEXT;

//------------------------------------------------------------------------------

#endif  //  _SPI_PORT_H
