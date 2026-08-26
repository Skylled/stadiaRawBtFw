// 600fe500  FUN_600fe500  size=362 bytes
// --- callers ---
//   600c64c8 FUN_600c64c8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600eef06 FUN_600eef06
//   600aa648 FUN_600aa648
//   600ef6ec FUN_600ef6ec
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600fe500(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_5c0 [764];
  undefined1 local_2c4 [2];
  undefined2 local_2c2;
  undefined4 local_2c0;
  undefined4 uStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 local_2b0;
  undefined4 uStack_2ac;
  undefined4 uStack_2a8;
  undefined4 local_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_29c;
  undefined4 uStack_298;
  undefined4 local_294;
  undefined4 uStack_290;
  undefined1 auStack_28c [24];
  undefined1 *local_274;
  undefined1 local_11;
  
  thunk_EXT_FUN_0000b5ba(local_2c4,0,0x2b0);
  thunk_EXT_FUN_0000b5ba(auStack_5c0,0,0x2fc);
  local_2c4[0] = *(undefined1 *)(param_2 + 9);
  if ((*(int *)(param_2 + 0xc) == 0) || (*(char *)(param_2 + 9) != '\0')) {
    iVar1 = *(int *)(param_1 + 10);
    local_2c0 = *(undefined4 *)(iVar1 + 0xc);
    uStack_2bc = *(undefined4 *)(iVar1 + 0x10);
    uStack_2b8 = *(undefined4 *)(iVar1 + 0x14);
    uStack_2b4 = *(undefined4 *)(iVar1 + 0x18);
    local_2b0 = *(undefined4 *)(iVar1 + 0x1c);
    uStack_2ac = *(undefined4 *)(iVar1 + 0x20);
    uStack_2a8 = *(undefined4 *)(iVar1 + 0x24);
    iVar1 = *(int *)(param_1 + 10);
    local_2a4 = *(undefined4 *)(iVar1 + 0x28);
    uStack_2a0 = *(undefined4 *)(iVar1 + 0x2c);
    uStack_29c = *(undefined4 *)(iVar1 + 0x30);
    uStack_298 = *(undefined4 *)(iVar1 + 0x34);
    local_294 = *(undefined4 *)(iVar1 + 0x38);
    uStack_290 = *(undefined4 *)(iVar1 + 0x3c);
    if (*(int *)(*(int *)(param_1 + 10) + 0x40) != 0) {
      thunk_EXT_FUN_0000b572(auStack_28c,*(undefined4 *)(*(int *)(param_1 + 10) + 0x40),0x18);
    }
  }
  else {
    iVar1 = FUN_600eef06(*(undefined4 *)(param_1 + 8),*(undefined2 *)(*(int *)(param_2 + 0xc) + 2),
                         &local_2c0,&local_2a4,auStack_28c);
    if (iVar1 == 0) {
      local_2c4[0] = 0x81;
    }
    else {
      local_2c4[0] = FUN_600ef6ec(*(undefined4 *)(param_1 + 8),auStack_28c,
                                  *(undefined4 *)(param_2 + 0xc),auStack_5c0);
      local_274 = auStack_5c0;
    }
  }
  if (*(int *)(*(int *)(param_1 + 10) + 0x40) == 0) {
    local_11 = 3;
  }
  else {
    local_11 = 8;
  }
  local_2c2 = *param_1;
  FUN_600aa648(param_1 + 10);
  (*(code *)**(undefined4 **)(param_1 + 6))(local_11,local_2c4);
  return;
}


