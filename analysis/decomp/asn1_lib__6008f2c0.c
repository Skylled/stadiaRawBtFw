// 6008f2c0  asn1_lib__6008f2c0  size=116 bytes
// src: asn1_lib.c
// --- callers ---
//   6008f5e8 tasn_dec__6008f5e8
//   600ec6fc FUN_600ec6fc
// --- callees ---
//   600e092c FUN_600e092c
//   600e093e FUN_600e093e
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600e0552 FUN_600e0552
//   6004cb28 FUN_6004cb28


/* src: asn1_lib.c */

undefined4 asn1_lib__6008f2c0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2;
  if (param_3 < 0) {
    if (param_2 == 0) {
      return 0;
    }
    param_3 = FUN_6004cb28(param_2);
  }
  iVar2 = param_1[2];
  if ((*param_1 <= param_3) || (iVar2 == 0)) {
    if (iVar2 == 0) {
      iVar1 = FUN_600e092c(param_3 + 1);
    }
    else {
      iVar1 = FUN_600e093e(iVar2);
    }
    param_1[2] = iVar1;
    if (param_1[2] == 0) {
      FUN_600e0552(0xc,0,0x41,DAT_6008f334,0x163,iVar3);
      param_1[2] = iVar2;
      return 0;
    }
  }
  *param_1 = param_3;
  if (param_2 != 0) {
    if (param_3 != 0) {
      thunk_EXT_FUN_0000b572(param_1[2],param_2,param_3);
    }
    *(undefined1 *)(param_1[2] + param_3) = 0;
  }
  return 1;
}


