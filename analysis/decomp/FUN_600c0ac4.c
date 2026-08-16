// 600c0ac4  FUN_600c0ac4  size=442 bytes
// --- callers ---
//   600fbc02 FUN_600fbc02
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006ddd8 FUN_6006ddd8
//   600ffd7a FUN_600ffd7a
//   600c8454 FUN_600c8454
//   6006dbac FUN_6006dbac


undefined4 FUN_600c0ac4(int param_1,char param_2,int param_3,byte param_4,undefined1 *param_5)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_11e;
  undefined1 auStack_118 [244];
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  
  local_18 = (undefined1 *)0x0;
  local_14 = (undefined1 *)0x0;
  local_1c = (undefined1 *)0x0;
  local_20 = (undefined1 *)0x0;
  local_24 = (undefined1 *)0x0;
  thunk_EXT_FUN_0000b5ba(auStack_118,0,0xf1);
  if ((param_5 == (undefined1 *)0x0) || (param_2 != '\x10')) {
    uVar2 = 0;
  }
  else {
    local_18 = (undefined1 *)FUN_6006dbac(0x40,DAT_600c0c80,0x94);
    if (local_18 == (undefined1 *)0x0) {
      uVar2 = 0;
    }
    else {
      local_11e = param_4;
      if (0x10 < param_4) {
        local_11e = 0x10;
      }
      thunk_EXT_FUN_0000b5ba(local_18,0,0x40);
      local_14 = local_18;
      for (iVar3 = 0; iVar3 < (int)(uint)local_11e; iVar3 = iVar3 + 1) {
        *local_14 = *(undefined1 *)(iVar3 + param_3);
        local_14 = local_14 + 1;
      }
      local_1c = local_18 + 0x10;
      local_14 = local_1c;
      for (iVar3 = 0; puVar1 = local_14, iVar3 < 0x10; iVar3 = iVar3 + 1) {
        *local_14 = local_18[0xf - iVar3];
        local_14 = local_14 + 1;
      }
      local_20 = local_14;
      for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
        *local_14 = *(undefined1 *)((0xf - iVar3) + param_1);
        local_14 = local_14 + 1;
      }
      local_24 = local_14;
      FUN_600c8454(puVar1,0x10,auStack_118);
      FUN_600ffd7a(local_1c,local_14,auStack_118);
      local_14 = param_5 + 4;
      for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
        *local_14 = local_24[0xf - iVar3];
        local_14 = local_14 + 1;
      }
      param_5[1] = 0x10;
      *param_5 = 0;
      *(undefined2 *)(param_5 + 2) = 0x2017;
      FUN_6006ddd8(local_18,DAT_600c0c80,0xb7);
      uVar2 = 1;
    }
  }
  return uVar2;
}


