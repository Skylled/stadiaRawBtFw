// 600f6c4c  FUN_600f6c4c  size=336 bytes
// --- callers ---
//   600ab424 FUN_600ab424
// --- callees ---
//   600bd730 FUN_600bd730
//   600bd65c FUN_600bd65c
//   600bdb7c FUN_600bdb7c
//   600bda54 FUN_600bda54
//   600bdb14 FUN_600bdb14
//   600bd848 FUN_600bd848


int FUN_600f6c4c(short *param_1,undefined2 param_2,undefined2 param_3)

{
  short sVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 local_68 [62];
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  int local_18;
  undefined1 *local_14;
  
  local_2a = 0x1002;
  local_14 = local_68;
  local_18 = FUN_600bd65c();
  if (local_18 == 0) {
    local_18 = 0;
  }
  else {
    sVar1 = *param_1;
    if (sVar1 == 4) {
      puVar2 = local_14 + 1;
      *local_14 = 0x1a;
      local_14 = puVar2;
      puVar2 = local_14 + 1;
      *local_14 = (char)((uint)*(undefined4 *)(param_1 + 2) >> 0x18);
      local_14 = puVar2;
      puVar2 = local_14 + 1;
      *local_14 = (char)((uint)*(undefined4 *)(param_1 + 2) >> 0x10);
      local_14 = puVar2;
      puVar2 = local_14 + 1;
      *local_14 = (char)((uint)*(undefined4 *)(param_1 + 2) >> 8);
      local_14 = puVar2;
      puVar2 = local_14 + 1;
      *local_14 = (char)*(undefined4 *)(param_1 + 2);
      local_14 = puVar2;
      FUN_600bd848(local_18,1,6,(int)local_14 - (int)local_68,local_68);
    }
    else if (sVar1 == 0x10) {
      puVar2 = local_14 + 1;
      *local_14 = 0x1c;
      local_14 = puVar2;
      for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
        puVar2 = local_14 + 1;
        *local_14 = *(undefined1 *)((int)param_1 + iVar3 + 4);
        local_14 = puVar2;
      }
      FUN_600bd848(local_18,1,6,(int)local_14 - (int)local_68,local_68);
    }
    else {
      if (sVar1 != 2) {
        FUN_600bd730(local_18);
        return 0;
      }
      FUN_600bdb7c(local_18,1,param_1 + 2);
    }
    local_28 = 0x100;
    local_26 = 1;
    local_24 = 0x1f;
    local_20 = 7;
    local_1e = 2;
    local_1c = param_2;
    local_1a = param_3;
    FUN_600bdb14(local_18,2,&local_28);
    FUN_600bda54(local_18,5,1,&local_2a);
  }
  return local_18;
}


