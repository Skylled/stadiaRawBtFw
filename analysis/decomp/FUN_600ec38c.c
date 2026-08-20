// 600ec38c  FUN_600ec38c  size=172 bytes
// --- callers ---
//   600ec7ca FUN_600ec7ca
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


int FUN_600ec38c(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined1 *puVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar5 = *param_1;
  if (0 < iVar5) {
    if (param_1[3] << 0x1c < 0) {
      uVar4 = param_1[3] & 7;
      goto LAB_600ec3a4;
    }
    pcVar3 = (char *)param_1[2];
    pcVar1 = pcVar3 + iVar5;
    do {
      iVar5 = (int)pcVar1 - (int)pcVar3;
      pcVar1 = pcVar1 + -1;
      if (*pcVar1 != '\0') goto LAB_600ec3ea;
    } while (pcVar3 != pcVar1);
    iVar5 = 0;
LAB_600ec3ea:
    uVar4 = (uint)(byte)pcVar3[iVar5 + -1];
    if (-1 < (int)(uVar4 << 0x1f)) {
      if ((int)(uVar4 << 0x1e) < 0) {
        uVar4 = 1;
      }
      else if ((int)(uVar4 << 0x1d) < 0) {
        uVar4 = 2;
      }
      else if ((int)(uVar4 << 0x1c) < 0) {
        uVar4 = 3;
      }
      else if ((int)(uVar4 << 0x1b) < 0) {
        uVar4 = 4;
      }
      else if ((int)(uVar4 << 0x1a) < 0) {
        uVar4 = 5;
      }
      else if ((int)(uVar4 << 0x19) < 0) {
        uVar4 = 6;
      }
      else if ((pcVar3[iVar5 + -1] & 0x80U) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = 7;
      }
      goto LAB_600ec3a4;
    }
  }
  uVar4 = 0;
LAB_600ec3a4:
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = (undefined1 *)*param_2 + 1;
    *(undefined1 *)*param_2 = (char)uVar4;
    if (iVar5 != 0) {
      puVar2 = (undefined1 *)thunk_EXT_FUN_0000b572(puVar2,param_1[2],iVar5,puVar2,param_4);
    }
    puVar2 = puVar2 + iVar5;
    if (0 < iVar5) {
      puVar2[-1] = puVar2[-1] & (byte)(0xff << uVar4);
    }
    *param_2 = puVar2;
  }
  return iVar5 + 1;
}


