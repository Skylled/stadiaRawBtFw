// 6008ef7c  a_int__6008ef7c  size=286 bytes
// src: a_int.c
// --- callers ---
//   6008f5e8 tasn_dec__6008f5e8
// --- callees ---
//   6008f338 asn1_lib__6008f338
//   600e092c FUN_600e092c
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e0552 FUN_600e0552
//   600ec720 FUN_600ec720
//   6013d3a0 thunk_EXT_FUN_0000b572


/* src: a_int.c */

uint * a_int__6008ef7c(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  char cVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  char *pcVar7;
  byte *pbVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  if (param_3 < 0x40000000) {
    puVar10 = param_1;
    puVar11 = param_2;
    if ((param_1 == (undefined4 *)0x0) || (puVar6 = (uint *)*param_1, puVar6 == (uint *)0x0)) {
      puVar6 = (uint *)asn1_lib__6008f338(2);
      if (puVar6 == (uint *)0x0) {
        return (uint *)0x0;
      }
      puVar6[1] = 2;
    }
    pcVar7 = (char *)*param_2;
    puVar2 = (undefined1 *)FUN_600e092c(param_3 + 1);
    pcVar9 = pcVar7 + param_3;
    if (puVar2 != (undefined1 *)0x0) {
      if (param_3 == 0) {
        puVar6[1] = 2;
      }
      else if (*pcVar7 < '\0') {
        puVar6[1] = 0x102;
        if ((*pcVar7 == -1) && (param_3 != 1)) {
          pcVar7 = pcVar7 + 1;
          param_3 = param_3 - 1;
        }
        pbVar8 = puVar2 + (param_3 - 1);
        uVar4 = param_3;
        pbVar3 = (byte *)(pcVar7 + (param_3 - 1));
        while( true ) {
          if (*pbVar3 != 0) break;
          if (uVar4 == 0) goto LAB_6008f040;
          *pbVar8 = 0;
          uVar4 = uVar4 - 1;
          pbVar8 = pbVar8 + -1;
          pbVar3 = pbVar3 + -1;
        }
        if (uVar4 == 0) {
LAB_6008f040:
          *puVar2 = 1;
          puVar2[param_3] = 0;
          param_3 = param_3 + 1;
        }
        else {
          iVar5 = uVar4 - (int)pbVar8;
          *pbVar8 = -*pbVar3;
          while( true ) {
            pbVar8 = pbVar8 + -1;
            pbVar3 = pbVar3 + -1;
            if (pbVar8 + iVar5 == (byte *)0x0) break;
            *pbVar8 = ~*pbVar3;
          }
        }
      }
      else {
        puVar6[1] = 2;
        cVar1 = *pcVar7;
        if ((cVar1 == '\0') && (param_3 != 1)) {
          pcVar7 = pcVar7 + 1;
          param_3 = param_3 - 1;
        }
        thunk_EXT_FUN_0000b572(puVar2,pcVar7,param_3,cVar1,puVar10);
      }
      if (puVar6[2] != 0) {
        thunk_EXT_FUN_0000ac5e();
      }
      puVar6[2] = (uint)puVar2;
      *puVar6 = param_3;
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = puVar6;
      }
      *param_2 = pcVar9;
      return puVar6;
    }
    FUN_600e0552(0xc,0,0x41,DAT_6008f09c,0x11b,puVar11);
    if ((param_1 == (undefined4 *)0x0) || ((uint *)*param_1 != puVar6)) {
      FUN_600ec720(puVar6);
    }
  }
  else {
    FUN_600e0552(0xc,0,0xb1,DAT_6008f09c,0xcc,param_2);
  }
  return (uint *)0x0;
}


