/** @file
  This file is automatically generated. Please do NOT modify !!!

  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __FSPUPDVPD_H__
#define __FSPUPDVPD_H__

#pragma pack(1)


#define MAX_CHANNELS_NUM 2
#define MAX_DIMMS_NUM    2

typedef struct {
  UINT32  VendorDeviceId;
  UINT16  SubSystemId;
  UINT8   RevisionId;                       /// 0xFF applies to all steppings
  UINT8   FrontPanelSupport;
  UINT16  NumberOfRearJacks;
  UINT16  NumberOfFrontJacks;
} BL_PCH_AZALIA_VERB_TABLE_HEADER;

typedef struct {
  BL_PCH_AZALIA_VERB_TABLE_HEADER  VerbTableHeader;
  UINT32                        *VerbTableData;
} BL_PCH_AZALIA_VERB_TABLE;

typedef struct {
  UINT8                 Pme       : 1;      /// 0: Disable; 1: Enable
  UINT8                 DS        : 1;      /// 0: Docking is not supported; 1:Docking is supported
  UINT8                 DA        : 1;      /// 0: Docking is not attached; 1:Docking is attached
  UINT8                 HdmiCodec : 1;      /// 0: Disable; 1: Enable
  UINT8                 AzaliaVCi : 1;      /// 0: Disable; 1: Enable
  UINT8                 Rsvdbits  : 3;
  UINT8                 AzaliaVerbTableNum; /// Number of verb tables provided by platform
  BL_PCH_AZALIA_VERB_TABLE  *AzaliaVerbTable;   /// Pointer to the actual verb table(s)
  UINT16                ResetWaitTimer;     /// The delay timer after Azalia reset, the value is number of microseconds
} BL_PCH_AZALIA_CONFIG;

typedef struct {
  UINT32            Confg;
  UINT32            ConfgChanges;
  UINT32            Misc;
  UINT32            MmioAddr;
  CHAR16            *Name;
} BL_GPIO_FAMILY_INIT;

typedef struct {
  UINT32            Confg0;
  UINT32            Confg0Changes;
  UINT32            Confg1;
  UINT32            Confg1Changes;
  UINT32            Community;
  UINT32            MmioAddr;
  CHAR16            *Name;
  UINT32            Misc;
} BL_GPIO_PAD_INIT;

typedef struct {
  UINT8         DimmId;
  UINT32        SizeInMb;
  UINT16        MfgId;
  /** Module part number for DRR3 is 18 bytes 
  but DRR4 is 20 bytes as per JEDEC Spec, so 
  reserving 20 bytes **/
  UINT8         ModulePartNum[20];
} DIMM_INFO;

typedef struct {
  UINT8         ChannelId;
  UINT8         DimmCount;
  DIMM_INFO     DimmInfo[MAX_DIMMS_NUM];
} CHANNEL_INFO;

typedef struct {
  UINT8         Revision;
  UINT8         DataWidth;
  /** As defined in SMBIOS 3.0 spec
    Section 7.18.2 and Table 75
  **/
  UINT8         MemoryType;
  UINT16        MemoryFrequencyInMHz;
  /** As defined in SMBIOS 3.0 spec
    Section 7.17.3 and Table 72
  **/
  UINT8         ErrorCorrectionType;
  UINT8         ChannelCount;
  CHANNEL_INFO  ChannelInfo[MAX_CHANNELS_NUM];
} FSP_SMBIOS_MEMORY_INFO;



typedef struct {
/** Offset 0x0020
**/
  UINT64                      Signature;
/** Offset 0x0028
**/
  UINT8                       Revision;
/** Offset 0x0029
**/
  UINT8                       UnusedUpdSpace2[7];
/** Offset 0x0030
    Tseg Size
    Size of SMRAM memory reserved.
**/
  UINT16                      PcdMrcInitTsegSize;
/** Offset 0x0032
    MMIO Size
    Size of memory address space reserved for MMIO (Memory Mapped I/O).
**/
  UINT16                      PcdMrcInitMmioSize;
/** Offset 0x0034
    DIMM 0 SPD SMBus Address
    SPD Address of DIMM.
**/
  UINT8                       PcdMrcInitSpdAddr1;
/** Offset 0x0035
    DIMM 1 SPD SMBus Address
    SPD Address of DIMM.
**/
  UINT8                       PcdMrcInitSpdAddr2;
/** Offset 0x0036
**/
  UINT8                       PcdMemChannel0Config;
/** Offset 0x0037
**/
  UINT8                       PcdMemChannel1Config;
/** Offset 0x0038
**/
  UINT32                      PcdMemorySpdPtr;
/** Offset 0x003C
    Internal Graphics Pre-allocated Memory
    Size of memory preallocated for internal graphics
**/
  UINT8                       PcdIgdDvmt50PreAlloc;
/** Offset 0x003D
    Aperture Size
    Select the Aperture Size.
**/
  UINT8                       PcdApertureSize;
/** Offset 0x003E
    GTT Size
    Select the GTT Size.
**/
  UINT8                       PcdGttSize;
/** Offset 0x003F
    Enable Legacy E/F segments decoding to ROM
    If disabled, E0000h-FFFFFh decoding will be routed to DRAM.
**/
  UINT8                       PcdLegacySegDecode;
/** Offset 0x0040
    Enable DVFS
    Enable/disable DVFS.
**/
  UINT8                       PcdDvfsEnable;
/** Offset 0x0041
    MemoryType
    To Configure Memory Type
**/
  UINT8                       PcdMemoryTypeEnable;
/** Offset 0x0042
    CaMirrorEn
    To Enable/Disable CaMirrorEn
**/
  UINT8                       PcdCaMirrorEn;
/** Offset 0x0043
**/
  UINT8                       ReservedMemoryInitUpd[189];
} MEMORY_INIT_UPD;

typedef struct {
/** Offset 0x0100
**/
  UINT64                      Signature;
/** Offset 0x0108
**/
  UINT8                       Revision;
/** Offset 0x0109
**/
  UINT8                       UnusedUpdSpace3[7];
/** Offset 0x0110
    SD Card Mode
    SD Card Mode
**/
  UINT8                       PcdSdcardMode;
/** Offset 0x0111
    Enable HSUART0
    Enable/disable HSUART0.
**/
  UINT8                       PcdEnableHsuart0;
/** Offset 0x0112
    Enable HSUART1
    Enable/disable HSUART1.
**/
  UINT8                       PcdEnableHsuart1;
/** Offset 0x0113
    Enable Azalia
    Enable/disable Azalia controller.
**/
  UINT8                       PcdEnableAzalia;
/** Offset 0x0114
**/
  BL_PCH_AZALIA_CONFIG*       AzaliaConfigPtr;
/** Offset 0x0118
    Enable SATA
    Enable/disable SATA controller.
**/
  UINT8                       PcdEnableSata;
/** Offset 0x0119
    Enable XHCI
    Enable/disable XHCI controller.
**/
  UINT8                       PcdEnableXhci;
/** Offset 0x011A
    Enable LPE
    Choose LPE Mode.
**/
  UINT8                       PcdEnableLpe;
/** Offset 0x011B
    Enable DMA0
    Enable/disable DMA0.
**/
  UINT8                       PcdEnableDma0;
/** Offset 0x011C
    Enable DMA1
    Enable/disable DMA1.
**/
  UINT8                       PcdEnableDma1;
/** Offset 0x011D
    Enable I2C0
    Enable/disable I2C0.
**/
  UINT8                       PcdEnableI2C0;
/** Offset 0x011E
    Enable I2C1
    Enable/disable I2C1.
**/
  UINT8                       PcdEnableI2C1;
/** Offset 0x011F
    Enable I2C2
    Enable/disable I2C2.
**/
  UINT8                       PcdEnableI2C2;
/** Offset 0x0120
    Enable I2C3
    Enable/disable I2C3.
**/
  UINT8                       PcdEnableI2C3;
/** Offset 0x0121
    Enable I2C4
    Enable/disable I2C4.
**/
  UINT8                       PcdEnableI2C4;
/** Offset 0x0122
    Enable I2C5
    Enable/disable I2C5.
**/
  UINT8                       PcdEnableI2C5;
/** Offset 0x0123
    Enable I2C6
    Enable/disable I2C6.
**/
  UINT8                       PcdEnableI2C6;
/** Offset 0x0124
**/
  UINT32                      GraphicsConfigPtr;
/** Offset 0x0128
**/
  BL_GPIO_FAMILY_INIT*        GpioFamilyInitTablePtr;
/** Offset 0x012C
**/
  BL_GPIO_PAD_INIT*           GpioPadInitTablePtr;
/** Offset 0x0130
**/
  UINT8                       PunitPwrConfigDisable;
/** Offset 0x0131
**/
  UINT8                       ChvSvidConfig;
/** Offset 0x0132
**/
  UINT8                       DptfDisable;
/** Offset 0x0133
    eMMC Mode
    EMMC Mode
**/
  UINT8                       PcdEmmcMode;
/** Offset 0x0134
**/
  UINT8                       PcdUsb3ClkSsc;
/** Offset 0x0135
**/
  UINT8                       PcdDispClkSsc;
/** Offset 0x0136
**/
  UINT8                       PcdSataClkSsc;
/** Offset 0x0137
**/
  UINT8                       Usb2Port0PerPortPeTxiSet;
/** Offset 0x0138
**/
  UINT8                       Usb2Port0PerPortTxiSet;
/** Offset 0x0139
**/
  UINT8                       Usb2Port0IUsbTxEmphasisEn;
/** Offset 0x013A
**/
  UINT8                       Usb2Port0PerPortTxPeHalf;
/** Offset 0x013B
**/
  UINT8                       Usb2Port1PerPortPeTxiSet;
/** Offset 0x013C
**/
  UINT8                       Usb2Port1PerPortTxiSet;
/** Offset 0x013D
**/
  UINT8                       Usb2Port1IUsbTxEmphasisEn;
/** Offset 0x013E
**/
  UINT8                       Usb2Port1PerPortTxPeHalf;
/** Offset 0x013F
**/
  UINT8                       Usb2Port2PerPortPeTxiSet;
/** Offset 0x0140
**/
  UINT8                       Usb2Port2PerPortTxiSet;
/** Offset 0x0141
**/
  UINT8                       Usb2Port2IUsbTxEmphasisEn;
/** Offset 0x0142
**/
  UINT8                       Usb2Port2PerPortTxPeHalf;
/** Offset 0x0143
**/
  UINT8                       Usb2Port3PerPortPeTxiSet;
/** Offset 0x0144
**/
  UINT8                       Usb2Port3PerPortTxiSet;
/** Offset 0x0145
**/
  UINT8                       Usb2Port3IUsbTxEmphasisEn;
/** Offset 0x0146
**/
  UINT8                       Usb2Port3PerPortTxPeHalf;
/** Offset 0x0147
**/
  UINT8                       Usb2Port4PerPortPeTxiSet;
/** Offset 0x0148
**/
  UINT8                       Usb2Port4PerPortTxiSet;
/** Offset 0x0149
**/
  UINT8                       Usb2Port4IUsbTxEmphasisEn;
/** Offset 0x014A
**/
  UINT8                       Usb2Port4PerPortTxPeHalf;
/** Offset 0x014B
**/
  UINT8                       Usb3Lane0Ow2tapgen2deemph3p5;
/** Offset 0x014C
**/
  UINT8                       Usb3Lane1Ow2tapgen2deemph3p5;
/** Offset 0x014D
**/
  UINT8                       Usb3Lane2Ow2tapgen2deemph3p5;
/** Offset 0x014E
**/
  UINT8                       Usb3Lane3Ow2tapgen2deemph3p5;
/** Offset 0x014F
    SATA Interface Speed
    Select SATA controller Interface Speed.
**/
  UINT8                       PcdSataInterfaceSpeed;
/** Offset 0x0150
**/
  UINT8                       PcdPchUsbSsicPort;
/** Offset 0x0151
**/
  UINT8                       PcdPchUsbHsicPort;
/** Offset 0x0152
**/
  UINT8                       PcdPcieRootPortSpeed;
/** Offset 0x0153
**/
  UINT8                       PcdPchSsicEnable;
/** Offset 0x0154
**/
  UINT32                      PcdLogoPtr;
/** Offset 0x0158
**/
  UINT32                      PcdLogoSize;
/** Offset 0x015C
**/
  UINT8                       PcdRtcLock;
/** Offset 0x015D
    PMIC I2c Bus Number
    I2c Bus Number to communicate with PMIC
**/
  UINT8                       PMIC_I2CBus;
/** Offset 0x015E
    Enable ISP
    Enable/disable ISP.
**/
  UINT8                       ISPEnable;
/** Offset 0x015F
    Select ISP Device Number
    Select ISP PCI Device Configuration
**/
  UINT8                       ISPPciDevConfig;
/** Offset 0x0160
    Processor Turbo Mode
    Enable/disable Processor Turbo Mode.
**/
  UINT8                       PcdTurboMode;
/** Offset 0x0161
    Pnp-Power & Performance
    select Pnp type 
**/
  UINT8                       PcdPnpSettings;
/** Offset 0x0162
    SdDetectChk
    Check for Sd card detect 
**/
  UINT8                       PcdSdDetectChk;
/** Offset 0x0163
**/
  UINT8                       ReservedSiliconInitUpd[411];
} SILICON_INIT_UPD;

#define FSP_UPD_SIGNATURE                0x2444505557534224        /* '$BSWUPD$' */
#define FSP_MEMORY_INIT_UPD_SIGNATURE    0x244450554D454D24        /* '$MEMUPD$' */
#define FSP_SILICON_INIT_UPD_SIGNATURE   0x244450555F495324        /* '$SI_UPD$' */

typedef struct _UPD_DATA_REGION {
/** Offset 0x0000
**/
  UINT64                      Signature;
/** Offset 0x0008
**/
  UINT8                       Revision;
/** Offset 0x0009
**/
  UINT8                       UnusedUpdSpace0[7];
/** Offset 0x0010
**/
  UINT32                      MemoryInitUpdOffset;
/** Offset 0x0014
**/
  UINT32                      SiliconInitUpdOffset;
/** Offset 0x0018
**/
  UINT64                      UnusedUpdSpace1;
/** Offset 0x0020
**/
  MEMORY_INIT_UPD             MemoryInitUpd;
/** Offset 0x0100
**/
  SILICON_INIT_UPD            SiliconInitUpd;
/** Offset 0x02FE
**/
  UINT16                      PcdRegionTerminator;
} UPD_DATA_REGION;

#define FSP_IMAGE_ID    0x2450534657534224        /* '$BSWFSP$' */
#define FSP_IMAGE_REV   0x01010200 

typedef struct _VPD_DATA_REGION {
/** Offset 0x0000
**/
  UINT64                      PcdVpdRegionSign;
/** Offset 0x0008
    PcdImageRevision
**/
  UINT32                      PcdImageRevision;
/** Offset 0x000C
**/
  UINT32                      PcdUpdRegionOffset;
} VPD_DATA_REGION;

#pragma pack()

#endif