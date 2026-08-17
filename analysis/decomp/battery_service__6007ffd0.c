// 6007ffd0  battery_service__6007ffd0  size=226 bytes
// src: battery_service.cc
// --- callers ---
//   6005acf4 FUN_6005acf4
// --- callees ---
//   6007fcbc FUN_6007fcbc
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6007fcec battery_service__6007fcec
//   600def50 FUN_600def50
//   600d3b24 FUN_600d3b24
//   6007ff34 FUN_6007ff34
//   600deecc FUN_600deecc
//   600d37ac FUN_600d37ac


/* src: battery_service.cc */

void battery_service__6007ffd0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_b0 [2];
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [130];
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0xd8);
  iVar2 = battery_service__6007fcec(param_1);
  iVar4 = *(int *)(param_1 + 0x184);
  *(int *)(param_1 + 0x184) = iVar2;
  uVar1 = FUN_600deecc(param_1);
  *(undefined2 *)(param_1 + 0x180) = uVar1;
  iVar3 = FUN_600def50(param_1);
  if ((iVar2 != 0) != (iVar4 != 0)) {
    local_b0[0] = DAT_600800b4;
    local_b0[1] = 0x5b;
    local_a8 = local_9a;
    local_a4 = 0x80;
    uStack_a0 = 0;
    local_9c = 0;
    local_9b = 0;
    local_9a[0] = 0;
    FUN_600d37ac(&local_a8,DAT_600800b8);
    FUN_6007fcbc(&local_a8,*(int *)(param_1 + 0x184) == 0);
    FUN_600d37ac(&local_a8,DAT_600800bc);
    FUN_6007fcbc(&local_a8,*(int *)(param_1 + 0x184) != 0);
    FUN_600d3b24(local_b0);
    local_b0[0] = (uint)(*(int *)(param_1 + 0x184) == 0);
    FUN_6007ff34(param_1,local_b0);
  }
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 0x188) == 5) {
      local_b0[0] = 2;
      FUN_6007ff34(param_1,local_b0);
    }
    local_b0[0] = 4;
    FUN_6007ff34(param_1,local_b0);
  }
  thunk_EXT_FUN_00007d10(param_1 + 0xd8);
  return;
}


