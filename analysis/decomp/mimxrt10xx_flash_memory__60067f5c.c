// 60067f5c  mimxrt10xx_flash_memory__60067f5c  size=192 bytes
// src: mimxrt10xx_flash_memory.cc
// --- callers ---
// --- callees ---
//   60101b76 FUN_60101b76
//   600d4752 FUN_600d4752
//   600d8052 FUN_600d8052
//   60101740 FUN_60101740
//   600d80d0 FUN_600d80d0
//   60067f20 FUN_60067f20


/* src: mimxrt10xx_flash_memory.cc */

char mimxrt10xx_flash_memory__60067f5c(int param_1,int param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [130];
  
  if (*(char *)(param_1 + 0x18) != '\x10') {
    local_b0 = DAT_6006801c;
    local_ac = 0x40;
    local_a8 = local_9a;
    local_a4 = 0x80;
    uStack_a0 = 0;
    local_9c = 0;
    local_9b = 0;
    local_9a[0] = 0;
    FUN_60101b76(&local_a8,DAT_60068020);
    FUN_60101740(&local_b0);
  }
  if ((*(int *)(param_1 + 0x24) == 1) &&
     ((uVar4 = (uint)*(byte *)(param_1 + 0x18), param_3 != uVar4 * (param_3 / uVar4) ||
      (param_4 != uVar4 * (param_4 / uVar4))))) {
    cVar2 = '\x03';
  }
  else {
    FUN_60067f20(&local_b0);
    for (; param_4 != 0; param_4 = param_4 - uVar4) {
      cVar2 = FUN_600d8052(param_1,param_2,param_3,*(undefined1 *)(param_1 + 0x18));
      if (cVar2 != '\0') {
        return cVar2;
      }
      if (*(int *)(param_1 + 0x24) == 1) {
        uVar3 = FUN_600d4752(param_1,param_3);
        FUN_600d80d0(&local_a4,uVar3);
        pbVar5 = (byte *)(param_2 + -1);
        iVar6 = 0;
        do {
          pbVar5 = pbVar5 + 1;
          pbVar1 = (byte *)((int)&local_b0 + iVar6);
          iVar6 = iVar6 + 1;
          *pbVar5 = *pbVar5 ^ *pbVar1;
        } while (iVar6 != 0x10);
      }
      uVar4 = (uint)*(byte *)(param_1 + 0x18);
      param_2 = param_2 + uVar4;
      param_3 = param_3 + uVar4;
    }
    cVar2 = '\0';
  }
  return cVar2;
}


