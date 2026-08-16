// 600cbdf4  buffer__600cbdf4  size=94 bytes
// src: buffer.cc
// --- callers ---
//   60058600 FUN_60058600
// --- callees ---
//   60101536 FUN_60101536
//   60101b76 FUN_60101b76
//   60101740 FUN_60101740


/* src: buffer.cc */

int buffer__600cbdf4(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  if ((param_2 < *param_1) || (*param_1 + param_1[1] <= param_2)) {
    local_a8 = DAT_600cbe54;
    local_a4 = 0x18;
    local_a0 = local_92;
    local_9c = 0x80;
    uStack_98 = 0;
    local_94 = 0;
    local_93 = 0;
    local_92[0] = 0;
    FUN_60101b76(&local_a0,DAT_600cbe58);
    FUN_60101740(&local_a8);
  }
  uVar3 = *param_1;
  uVar1 = FUN_60101536(param_1,param_2 - uVar3);
  if (param_1[2] == uVar1) {
    iVar2 = 0;
  }
  else {
    iVar2 = uVar1 + uVar3;
  }
  return iVar2;
}


