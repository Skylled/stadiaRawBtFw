// 60067e8c  flash_memory__60067e8c  size=130 bytes
// src: flash_memory.h
// --- callers ---
//   600d8052 FUN_600d8052
//   600d9bc6 FUN_600d9bc6
//   600d808e FUN_600d808e
//   60068024 mimxrt10xx_flash_memory__60068024
//   600d9b8e FUN_600d9b8e
// --- callees ---
//   601016f0 FUN_601016f0
//   60101b76 FUN_60101b76
//   600d801c FUN_600d801c


/* src: flash_memory.h */

undefined4 flash_memory__60067e8c(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  iVar1 = (**(code **)(*param_1 + 0x14))();
  uVar2 = DAT_60067f10;
  if ((uint)(*(int *)(param_1[1] + 4) * iVar1) < (uint)(param_2 + param_3)) {
    local_a8 = local_9a;
    local_a4 = 0x80;
    uStack_a0 = 0;
    local_9c = 0;
    local_9b = 0;
    local_9a[0] = 0;
    FUN_60101b76(&local_a8,DAT_60067f14);
    FUN_600d801c(&local_a8,param_2);
    FUN_60101b76(&local_a8,DAT_60067f18);
    FUN_600d801c(&local_a8,param_3);
    FUN_60101b76(&local_a8,DAT_60067f1c);
    FUN_601016f0(0x28,uVar2,0x132,&local_a8);
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


