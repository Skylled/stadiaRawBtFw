// 600522b8  FUN_600522b8  size=162 bytes
// --- callers ---
//   600d4724 FUN_600d4724
// --- callees ---
//   60052294 FUN_60052294


void FUN_600522b8(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else if (param_1 == DAT_6005235c) {
    iVar1 = 1;
  }
  else if (param_1 == DAT_6005235c + 0x4000) {
    iVar1 = 2;
  }
  else {
    iVar1 = 3;
  }
  FUN_60052294((int)*(short *)(DAT_60052360 + iVar1 * 2),3,DAT_60052360,iVar1,param_4);
  uVar2 = ((byte)param_2[10] & 3) << 2 |
          ((byte)param_2[9] & 3) << 5 |
          (byte)param_2[8] & 3 | *(uint *)(param_1 + 0x44) & 0xe000 | ((byte)param_2[6] & 3) << 0xb
          | ((byte)param_2[7] & 3) << 8;
  if (*param_2 != '\0') {
    uVar2 = uVar2 | 0x10000;
  }
  if (param_2[4] != '\0') {
    uVar2 = uVar2 | 0x10;
  }
  if (param_2[3] != '\0') {
    uVar2 = uVar2 | 0x80;
  }
  if (param_2[2] != '\0') {
    uVar2 = uVar2 | 0x400;
  }
  *(uint *)(param_1 + 0x44) = uVar2;
  uVar2 = *(uint *)(param_1 + 0x48) & 0xffffffbe;
  if (param_2[1] != '\0') {
    uVar2 = uVar2 | 0x40;
  }
  if (param_2[5] != '\0') {
    uVar2 = uVar2 | 1;
  }
  *(uint *)(param_1 + 0x48) = uVar2;
  return;
}


