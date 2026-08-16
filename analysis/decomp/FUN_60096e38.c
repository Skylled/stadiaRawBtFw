// 60096e38  FUN_60096e38  size=606 bytes
// --- callers ---
//   600efe24 FUN_600efe24
// --- callees ---
//   6006de78 FUN_6006de78
//   6006ddd8 FUN_6006ddd8
//   600d93a8 FUN_600d93a8
//   600968b0 FUN_600968b0
//   600969e0 FUN_600969e0


void FUN_60096e38(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  short local_e;
  ushort local_c;
  undefined1 local_9;
  
  local_9 = 0;
  pbVar3 = (byte *)((int)param_2 + param_2[2] + 8);
  uVar1 = *param_2 & 0xff00;
  uVar2 = *param_2;
  local_c = 0;
  local_e = 0;
  FUN_600968b0(0);
  if (uVar1 == 0x2100) {
    local_9 = 2;
  }
  else if (uVar1 == 0x2200) {
    local_9 = 3;
  }
  else if (uVar1 == 0x2000) {
    local_9 = 1;
  }
  else if (uVar1 == 0x2c00) {
    local_9 = 7;
  }
  else if (*param_2 == 0x4000) {
    local_9 = 0x10;
  }
  if ((uVar2 & 0xff) == 0) {
    local_c = *(ushort *)(DAT_60097098 + 0x5a);
    local_e = *(short *)(DAT_60097098 + 0x58);
  }
  else if ((uVar2 & 0xff) == 1) {
    local_c = *(ushort *)(DAT_60097098 + 0x5e);
    local_e = *(short *)(DAT_60097098 + 0x5c);
  }
  if ((uVar1 == 0x2100) && (local_c < param_2[1])) {
    uVar2 = (ushort)pbVar3[1] * 0x100 + (ushort)*pbVar3 & 0xcfff;
    do {
      if (param_2[1] <= local_c) goto LAB_60097044;
      uVar1 = param_2[3];
      if ((*(uint *)(param_1 + 0x10) & 2) == 0) {
        puVar4 = (undefined1 *)((int)param_2 + param_2[2] + 7);
        *puVar4 = local_9;
        FUN_600d93a8(*(undefined1 *)(DAT_6009709c + 0xb),puVar4,local_c + 1);
      }
      param_2[3] = uVar1;
      param_2[2] = local_e + param_2[2];
      param_2[1] = param_2[1] - local_e;
      puVar4 = (undefined1 *)((int)param_2 + param_2[2] + 8);
      *puVar4 = (char)uVar2;
      puVar4[1] = (byte)(uVar2 >> 8) | 0x10;
      if (local_c < param_2[1]) {
        puVar4[2] = (char)local_e;
        puVar4[3] = (char)((ushort)local_e >> 8);
      }
      else {
        puVar4[2] = (char)param_2[1] + -4;
        puVar4[3] = (char)(param_2[1] - 4 >> 8);
      }
    } while ((param_2[3] == 0) || (param_2[3] = param_2[3] - 1, param_2[3] != 0));
    *param_2 = 0x1900;
    FUN_6006de78(*(undefined1 *)(DAT_6009709c + 0xd),0,param_2,DAT_600970a0,0x38f);
  }
  else {
LAB_60097044:
    if ((*(uint *)(DAT_6009709c + 0x10) & 2) == 0) {
      puVar4 = (undefined1 *)((int)param_2 + param_2[2] + 7);
      *puVar4 = local_9;
      FUN_600d93a8(*(undefined1 *)(DAT_6009709c + 0xb),puVar4,param_2[1] + 1);
      FUN_6006ddd8(param_2,DAT_600970a0,0x3a5);
    }
    FUN_600969e0(1);
  }
  return;
}


