// 6008f370  tasn_dec__6008f370  size=310 bytes
// src: tasn_dec.c
// --- callers ---
//   6008ffc0 tasn_dec__6008ffc0
//   600901c8 tasn_dec__600901c8
//   6008f4ac tasn_dec__6008f4ac
//   6008fa18 tasn_dec__6008fa18
//   6008f794 tasn_dec__6008f794
// --- callees ---
//   600e0552 FUN_600e0552
//   6008f1bc asn1_lib__6008f1bc


/* src: tasn_dec.c */

undefined4
tasn_dec__6008f370(int *param_1,int *param_2,undefined1 *param_3,undefined1 *param_4,byte *param_5,
                  int *param_6,int param_7,int param_8,int param_9,char param_10,char *param_11)

{
  uint uVar1;
  int iVar2;
  int local_38;
  int local_34;
  int local_30;
  int local_2c [2];
  
  iVar2 = *param_6;
  if ((param_11 == (char *)0x0) || (*param_11 == '\0')) {
    local_2c[0] = iVar2;
    uVar1 = asn1_lib__6008f1bc(local_2c,&local_30,&local_38,&local_34,param_7);
    if (param_11 != (char *)0x0) {
      *(int *)(param_11 + 0x10) = local_34;
      *(uint *)(param_11 + 4) = uVar1;
      *(int *)(param_11 + 0xc) = local_38;
      *(int *)(param_11 + 8) = local_30;
      *param_11 = '\x01';
      *(int *)(param_11 + 0x14) = local_2c[0] - iVar2;
      if (((uVar1 & 0x81) == 0) && (param_7 < local_30 + (local_2c[0] - iVar2))) {
        FUN_600e0552(0xc,0,0xb1,DAT_6008f4a8,0x4aa);
        goto LAB_6008f412;
      }
    }
  }
  else {
    uVar1 = *(uint *)(param_11 + 4);
    local_30 = *(int *)(param_11 + 8);
    local_34 = *(int *)(param_11 + 0x10);
    local_38 = *(int *)(param_11 + 0xc);
    local_2c[0] = *(int *)(param_11 + 0x14) + iVar2;
  }
  if ((uVar1 & 0x80) == 0) {
    if (-1 < param_8) {
      if ((local_38 != param_8) || (local_34 != param_9)) {
        if (param_10 == '\0') {
          if (param_11 != (char *)0x0) {
            *param_11 = '\0';
          }
          FUN_600e0552(0xc,0,0xbe,DAT_6008f4a8,0x4be);
          return 0;
        }
        return 0xffffffff;
      }
      if (param_11 != (char *)0x0) {
        *param_11 = '\0';
      }
    }
    if ((uVar1 & 1) != 0) {
      local_30 = param_7 - (local_2c[0] - iVar2);
    }
    if (param_4 != (undefined1 *)0x0) {
      *param_4 = (char)(uVar1 & 1);
    }
    if (param_5 != (byte *)0x0) {
      *param_5 = (byte)uVar1 & 0x20;
    }
    if (param_1 != (int *)0x0) {
      *param_1 = local_30;
    }
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = (char)local_34;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = local_38;
    }
    *param_6 = local_2c[0];
    return 1;
  }
  FUN_600e0552(0xc,0,0x67,DAT_6008f4a8,0x4b2);
  if (param_11 == (char *)0x0) {
    return 0;
  }
LAB_6008f412:
  *param_11 = '\0';
  return 0;
}


