// 600ef0f4  FUN_600ef0f4  size=486 bytes
// --- callers ---
//   600feaca FUN_600feaca
//   600fe960 FUN_600fe960
// --- callees ---
//   600d9202 FUN_600d9202
//   600ef09c FUN_600ef09c
//   6013d3a0 thunk_EXT_FUN_0000b572


bool FUN_600ef0f4(int param_1,undefined2 param_2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar4;
  undefined4 local_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 local_140;
  undefined1 auStack_13c [280];
  undefined4 *local_24;
  ushort local_20;
  byte local_1d;
  undefined4 *local_1c;
  
  local_1c = *(undefined4 **)(param_1 + 0xc);
  local_1d = 0;
  local_20 = 0;
  while ((local_1c != (undefined4 *)0x0 && (local_1d < 10))) {
    uVar2 = local_20 + 1;
    bVar4 = *(ushort *)(param_1 + 0x32) <= local_20;
    local_20 = uVar2;
    if (bVar4) {
      uVar3 = (uint)local_1d;
      local_1d = local_1d + 1;
      FUN_600ef09c(auStack_13c + uVar3 * 0x1c,3,*(undefined2 *)(local_1c + 9),
                   *(undefined2 *)((int)local_1c + 0x26),*(undefined1 *)(local_1c + 5),*local_1c,
                   local_1c[1],local_1c[2],local_1c[3],local_1c[4],0,*(undefined1 *)(local_1c + 6));
    }
    local_24 = (undefined4 *)local_1c[7];
    while ((local_24 != (undefined4 *)0x0 && (local_1d < 10))) {
      if (*(ushort *)(param_1 + 0x32) <= local_20) {
        sVar1 = *(short *)(local_24 + 2);
        if (sVar1 == 2) {
          local_14c = CONCAT22(local_14c._2_2_,*(undefined2 *)*local_24);
        }
        else {
          thunk_EXT_FUN_0000b572(&local_14c,*local_24,0x10);
        }
        uVar3 = (uint)local_1d;
        local_1d = local_1d + 1;
        FUN_600ef09c(auStack_13c + uVar3 * 0x1c,*(undefined1 *)((int)local_24 + 0xe),
                     *(undefined2 *)((int)local_24 + 10),0,*(undefined1 *)(local_24 + 3),sVar1,
                     local_14c,uStack_148,uStack_144,local_140,*(undefined1 *)((int)local_24 + 0xd),
                     0);
      }
      local_20 = local_20 + 1;
      local_24 = (undefined4 *)local_24[1];
    }
    local_1c = (undefined4 *)local_1c[10];
  }
  bVar4 = local_1d != 0;
  if (bVar4) {
    FUN_600d9202(param_1 + 1,0x1d15,local_1d,auStack_13c,*(undefined2 *)(param_1 + 0x32),param_2);
    *(ushort *)(param_1 + 0x32) = (ushort)local_1d + *(short *)(param_1 + 0x32);
  }
  return bVar4;
}


