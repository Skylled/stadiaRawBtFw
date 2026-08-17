// 60060170  xbara__60060170  size=74 bytes
// src: xbara.h
// --- callers ---
//   600d49fc FUN_600d49fc
// --- callees ---
//   601016a2 FUN_601016a2


/* src: xbara.h */

void xbara__60060170(char *param_1,byte param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_600601a0;
  if (*param_1 != '\0') {
    FUN_601016a2(DAT_60060198,0x17,DAT_6006019c,*param_1,param_4);
    iVar1 = 0;
  }
  iVar2 = (param_3 & 1) << 3;
  *(ushort *)(iVar1 + (param_3 & 0xfe)) =
       *(ushort *)(iVar1 + (param_3 & 0xfe)) & ~(ushort)(0xff << iVar2) | (ushort)param_2 << iVar2;
  return;
}


