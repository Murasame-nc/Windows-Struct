typedef struct _DRIVER_INFO_2W {
    DWORD   cVersion;
    LPWSTR    pName;              // QMS 810
    LPWSTR    pEnvironment;       // Win32 x86
    LPWSTR    pDriverPath;        // c:\drivers\pscript.dll
    LPWSTR    pDataFile;          // c:\drivers\QMS810.PPD
    LPWSTR    pConfigFile;        // c:\drivers\PSCRPTUI.DLL
} DRIVER_INFO_2W, *PDRIVER_INFO_2W, *LPDRIVER_INFO_2W;
typedef struct _FILEVIEW
{
  ULARGE_INTEGER LastWriteTime;  
  PVOID          pvKView;
  PVOID          pvViewFD;  
  ULONG          cjView;  
  PVOID          pSection;  
} FILEVIEW, *PFILEVIEW; 
typedef struct _FONTFILEVIEW // Size 0x38
{
  FILEVIEW;
  DWORD          reserved[2];   // 18 
  PWSTR          pwszPath;      // 20
  SIZE_T         ulRegionSize;  // 24
  ULONG          cKRefCount;    // 28
  ULONG          cRefCountFD;   // 2c  
  PVOID          pvSpoolerBase; // 30  
  DWORD          dwSpoolerPid;  // 34  
} FONTFILEVIEW, *PFONTFILEVIEW;
typedef struct tagDOWNLOADFONTHEADER
{
    ULONG   Type1ID;          // if non-zero then this is a remote Type1 font
    ULONG   NumFiles;
    ULONG   FileOffsets[1];
}DOWNLOADFONTHEADER,*PDOWNLOADFONTHEADER;
typedef struct tagREMOTETYPEONENODE
{
    PDOWNLOADFONTHEADER    pDownloadHeader;
    FONTFILEVIEW           fvPFB;
    FONTFILEVIEW           fvPFM;
    REMOTETYPEONENODE      *pNext;
} REMOTETYPEONDENODE,*PREMOTETYPEONENODE;
typedef  struct  _PDEV 
{  // W2k WXP 
    BASEOBJECT   baseobj ;                     // 000 000 
    PPDEV        ppdevNext ;                   // 010 010 
    int          cPdevRefs ;                   // 014 014 
    int          cPdevOpenRefs ;               // 018 018 
    PPDEV        ppdevParent ;                 // 01C 01C 
    FLONG       标志；                      // 020 020 
    FLONG        flAccelerated ;               // 024 024 
    HSEMAPHORE   hsemDevLock ;                 // 028 028 
    HSEMAPHORE   hsemPointer ;                 // 02C 02C
    POINTL       ptlPointer ;                  // 030 030
    尺寸       szlPointer ;                  // 038 038 
    SPRITESTATE  SpriteState ;                 // 040 040 大小 = 1f4h 
    HFONT        hlfntDefault ;                // 21C 234 HFONT 在 xp 
    HFONT        hlfntAnsiVariable上验证的此偏移量；          // 220 238 HFONT 在 xp 
    HFONT        hlfntAnsiFixed上验证的此偏移量；             // 224 23C HFONT 在 xp 
    HSURF        ahsurf [ HS_DDI_MAX ]         上验证的此偏移量；// 228 240 HSURF 在 XP 
    PUSHORT      pusPrtDataFileName上验证的此偏移量；         // 258
    PVOID        pDevHTInfo ;                  // 244 25C 
    PRFONT       prfntActive ;                 // 248 260 
    PRFONT       prfntInactive ;               // 24C 264 
    ULONG        cInactive ;                   // 250 268 
    BYTE         ajbo [ 0x5C ];                  // 254 26C 
    ULONG        cDirectDrawDisableLocks ;     // 
    2A8 2C8 PVOID        TypeOneInfo ;                 // 2AC 2CC 
    PVOID        pvGammaRamp ;                 // 2B0 2D0 
    PVOID        RemoteTypeOne ;               // 2B4 2D4 
    ULONG        ulHorzRes ;                   // 2B8 2D8 slz 如果 PDEV_META_DEVICE
    ULONG        ulVertRes ;                   // 2BC 2DC 从这里得到它。
    PFN          pfnDrvSetPointerShape ;       // 2C0 2E0 
    PFN          pfnDrvMovePointer ;           // 2C4 2E4 
    PFN          pfnMovePointer ;              // 2C8 
    2E8 PFN          pfnDrvSynchronize ;           // 2CC 2EC (gdikdx: pfnSync) 
    PFN          pfnDrvSynchronizeSurface ;    // 2F0 
    PFN          pfnDrvSetPalette ;            // 2F4 
    PFN          pfnDrvNotify ;                // 2F8 
    ULONG        TagSig ;                      // 2FC = 'Pdev' 
    PLDEV        pldev ;                       // 2E0 300
    DHPDEV       dhpdev ;                      // 2E4 304 
    PPALETTE     ppalSurf ;                    // 2E8 308 -> Gla8 
    DEVINFO      devinfo ;                     // 
    2EC 30C GDIINFO      gdiinfo ;                     // 418 438 
    PSURFACE     pSurface ;                    // 548 568 
    HANDLE       hSpooler ;                    // 54C 56C 
    PVOID        pDesktopId ;                  // 550 570   
    EDD_DIRECTDRAW_GLOBAL  eDirectDrawGlobal ; // 558 W2k 仅
    PGRAPHICS_DEVICE  pGraphicsDevice ;        // 574 
    POINTL       ptlOrigion ;                  // 578
    PDEVMODEW    pdmwDev ;                     // 580 
    DWORD        Unknown3 ;                    // 584 
    FLONG        DxDd_Flags ;                  // 588 
    LONG         devAttr ;                     // 58C 
    PVOID        WatchDogContext ;             // 590 
    PVOID       看门狗；                  // 594 
    PFN          apfn [ INDEX_LAST ];            // B8C 598 
}  PDEV ,  * PPDEV ;  // Xp 大小 0x70C 或 1804
 
// PDEV 和 EDDX 额外数据容器。
typedef  struct  _PDEVEDD 
{ 
    PDEVOBJ                pdevobj ；
    EDD_DIRECTDRAW_GLOBAL  EDDgpl ; 
}  PDEVEDD ,  * PPDEVEDD ;

