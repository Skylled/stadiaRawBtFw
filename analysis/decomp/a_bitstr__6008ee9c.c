// 6008ee9c  a_bitstr__6008ee9c  size=218 bytes
// src: a_bitstr.c
// --- callers ---
//   6008f5e8 tasn_dec__6008f5e8
// --- callees ---
//   600e092c FUN_600e092c
//   6013d208 thunk_EXT_FUN_0000ac5e
//   6008f338 asn1_lib__6008f338
//   600ec720 FUN_600ec720
//   600e0552 FUN_600e0552
//   6013d3a0 thunk_EXT_FUN_0000b572


/* src: a_bitstr.c */

int * a_bitstr__6008ee9c(int *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  
  if (param_3 < 1) {
    FUN_600e0552(0xc,0,0xae,DAT_6008ef78,0x8b,param_2);
  }
  else {
    puVar8 = param_2;
    if (((param_1 != (int *)0x0) && (piVar3 = (int *)*param_1, piVar3 != (int *)0x0)) ||
       (piVar3 = (int *)asn1_lib__6008f338(3), piVar3 != (int *)0x0)) {
      uVar6 = (uint)*(byte *)*param_2;
      if (uVar6 < 8) {
        pbVar4 = (byte *)*param_2 + 1;
        iVar5 = param_3 + -1;
        piVar3[3] = piVar3[3] & 0xfffffff0U | uVar6 | 8;
        if (param_3 == 1) {
          iVar1 = 0;
LAB_6008ef48:
          *piVar3 = iVar5;
          if (piVar3[2] != 0) {
            thunk_EXT_FUN_0000ac5e();
          }
          piVar3[2] = iVar1;
          piVar3[1] = 3;
          if (param_1 != (int *)0x0) {
            *param_1 = (int)piVar3;
          }
          *param_2 = pbVar4;
          return piVar3;
        }
        iVar1 = FUN_600e092c(iVar5);
        if (iVar1 != 0) {
          thunk_EXT_FUN_0000b572(iVar1,pbVar4,iVar5);
          pbVar4 = pbVar4 + iVar5;
          *(byte *)(iVar1 + param_3 + -2) = *(byte *)(iVar1 + param_3 + -2) & (byte)(0xff << uVar6);
          goto LAB_6008ef48;
        }
        uVar2 = 0x41;
        uVar7 = 0xab;
      }
      else {
        uVar2 = 0x8d;
        uVar7 = 0x9d;
      }
      FUN_600e0552(0xc,0,uVar2,DAT_6008ef78,uVar7,puVar8);
      if ((param_1 == (int *)0x0) || ((int *)*param_1 != piVar3)) {
        FUN_600ec720(piVar3);
      }
    }
  }
  return (int *)0x0;
}


