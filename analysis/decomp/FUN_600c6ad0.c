// 600c6ad0  FUN_600c6ad0  size=472 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---
//   600c6a3c FUN_600c6a3c
//   600efc1a FUN_600efc1a
//   600962dc FUN_600962dc
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ab8d4 FUN_600ab8d4
//   6006dbac FUN_6006dbac


void FUN_600c6ad0(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char local_34;
  char local_33;
  undefined2 *local_20;
  byte local_1b;
  byte local_1a;
  char local_19;
  
  local_19 = '\0';
  local_1b = 0xff;
  if (*param_1 == '\0') {
    FUN_600c6a3c(param_1);
  }
  for (local_1a = 0; local_1a < 10; local_1a = local_1a + 1) {
    if (param_1[(uint)local_1a * 0x20 + 4] != '\0') {
      iVar2 = FUN_600efc1a(*(undefined4 *)(param_1 + (uint)local_1a * 0x20 + 8),
                           *(undefined4 *)(param_1 + (uint)local_1a * 0x20 + 0xc),
                           *(undefined4 *)(param_1 + (uint)local_1a * 0x20 + 0x10),
                           *(undefined4 *)(param_1 + (uint)local_1a * 0x20 + 0x14),
                           *(undefined4 *)(param_1 + (uint)local_1a * 0x20 + 0x18),
                           *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
                           *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                           *(undefined4 *)(param_2 + 0x18));
      if (iVar2 != 0) {
        local_19 = -0x70;
        break;
      }
    }
  }
  if (local_19 == '\0') {
    for (local_1a = 0; local_1a < 10; local_1a = local_1a + 1) {
      if ((local_1b == 0xff) && (param_1[(uint)local_1a * 0x20 + 4] == '\0')) {
        local_1b = local_1a;
        break;
      }
    }
    local_34 = '\0';
    if (local_1b == 0xff) {
      local_19 = -0x80;
    }
    else {
      param_1[(uint)local_1b * 0x20 + 4] = '\x01';
      *(undefined4 *)(param_1 + (uint)local_1b * 0x20 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
      thunk_EXT_FUN_0000b572(param_1 + (uint)local_1b * 0x20 + 8,param_2 + 8,0x14);
      uVar3 = (uint)local_1b;
      cVar1 = FUN_600ab8d4(param_2 + 8,DAT_600c6ca8);
      param_1[uVar3 * 0x20 + 0x20] = cVar1;
      local_34 = param_1[uVar3 * 0x20 + 0x20];
      if (param_1[(uint)local_1b * 0x20 + 0x20] == '\0') {
        local_19 = -0x80;
      }
      else {
        local_20 = (undefined2 *)FUN_6006dbac(10,DAT_600c6cac,0xe5);
        if (local_20 == (undefined2 *)0x0) {
          local_19 = -0x80;
          thunk_EXT_FUN_0000b5ba(param_1 + (uint)local_1b * 0x20 + 4,0,0x20);
        }
        else {
          *local_20 = 0x1e01;
          *(char *)(local_20 + 4) = param_1[(uint)local_1b * 0x20 + 0x20];
          FUN_600962dc(local_20);
        }
      }
    }
  }
  local_33 = local_19;
  if (*(int *)(param_2 + 0x1c) != 0) {
    (**(code **)(param_2 + 0x1c))(0,&local_34);
  }
  return;
}


