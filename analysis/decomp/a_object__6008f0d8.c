// 6008f0d8  a_object__6008f0d8  size=222 bytes
// src: a_object.c
// --- callers ---
//   6008f5e8 tasn_dec__6008f5e8
// --- callees ---
//   6008f0a0 a_object__6008f0a0
//   600e092c FUN_600e092c
//   600ec58a FUN_600ec58a
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e0552 FUN_600e0552
//   6013d3a0 thunk_EXT_FUN_0000b572


/* src: a_object.c */

undefined4 * a_object__6008f0d8(undefined4 *param_1,int *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  char *pcVar2;
  
  if ((((param_3 < 1) || (param_2 == (int *)0x0)) ||
      (pcVar3 = (char *)*param_2, pcVar3 == (char *)0x0)) || (pcVar3[param_3 + -1] < '\0')) {
    uVar4 = 0xab;
LAB_6008f0f6:
    FUN_600e0552(0xc,0,0x92,DAT_6008f1b8,uVar4);
  }
  else {
    pcVar2 = pcVar3;
    do {
      pcVar1 = pcVar2 + 1;
      if ((*pcVar2 == -0x80) && ((pcVar1 + ~(uint)pcVar3 == (char *)0x0 || (-1 < pcVar2[-1])))) {
        uVar4 = 0xb2;
        goto LAB_6008f0f6;
      }
      pcVar2 = pcVar1;
    } while ((int)pcVar1 - (int)pcVar3 < param_3);
    puVar9 = param_1;
    piVar10 = param_2;
    iVar11 = param_3;
    if ((((param_1 != (undefined4 *)0x0) &&
         (puVar6 = (undefined4 *)*param_1, puVar6 != (undefined4 *)0x0)) &&
        ((int)(puVar6[5] << 0x1f) < 0)) ||
       (puVar6 = (undefined4 *)a_object__6008f0a0(), puVar6 != (undefined4 *)0x0)) {
      iVar7 = puVar6[4];
      uVar5 = 0;
      iVar8 = *param_2;
      puVar6[4] = 0;
      if ((iVar7 == 0) || ((int)puVar6[3] < param_3)) {
        puVar6[3] = 0;
        if (iVar7 != 0) {
          thunk_EXT_FUN_0000ac5e(iVar7);
        }
        iVar7 = FUN_600e092c(param_3);
        if (iVar7 == 0) {
          FUN_600e0552(0xc,0,0x41,DAT_6008f1b8,0xe0);
          if ((param_1 != (undefined4 *)0x0) && ((undefined4 *)*param_1 == puVar6)) {
            return (undefined4 *)0x0;
          }
          FUN_600ec58a(puVar6);
          return (undefined4 *)0x0;
        }
        uVar5 = puVar6[5] | 8;
        puVar6[5] = uVar5;
      }
      thunk_EXT_FUN_0000b572(iVar7,iVar8,param_3,uVar5,puVar9,piVar10,iVar11);
      puVar6[3] = param_3;
      puVar6[4] = iVar7;
      *puVar6 = 0;
      puVar6[1] = 0;
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = puVar6;
      }
      *param_2 = param_3 + iVar8;
      return puVar6;
    }
  }
  return (undefined4 *)0x0;
}


