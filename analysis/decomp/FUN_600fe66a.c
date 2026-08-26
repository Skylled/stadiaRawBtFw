// 600fe66a  FUN_600fe66a  size=316 bytes
// --- callers ---
//   600c64c8 FUN_600c64c8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600eef06 FUN_600eef06
//   600aa648 FUN_600aa648
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600fe66a(undefined2 *param_1,int param_2)

{
  undefined1 local_2c4 [2];
  undefined2 local_2c2;
  undefined1 auStack_2c0 [28];
  undefined1 auStack_2a4 [24];
  undefined1 auStack_28c [635];
  undefined1 local_11;
  
  thunk_EXT_FUN_0000b5ba(local_2c4,0,0x2b0);
  thunk_EXT_FUN_0000b5ba(local_2c4,0,0x2b0);
  local_2c4[0] = *(undefined1 *)(param_2 + 9);
  if (*(int *)(param_2 + 0xc) == 0) {
    thunk_EXT_FUN_0000b572(auStack_2c0,*(int *)(param_1 + 10) + 0xc,0x1c);
    thunk_EXT_FUN_0000b572(auStack_2a4,*(int *)(param_1 + 10) + 0x28,0x18);
    if (*(int *)(*(int *)(param_1 + 10) + 0x40) != 0) {
      thunk_EXT_FUN_0000b572(auStack_28c,*(undefined4 *)(*(int *)(param_1 + 10) + 0x40),0x18);
    }
  }
  else {
    FUN_600eef06(*(undefined4 *)(param_1 + 8),**(undefined2 **)(param_2 + 0xc),auStack_2c0,
                 auStack_2a4,auStack_28c);
  }
  if ((**(short **)(param_1 + 10) == 0x1d05) && (*(char *)(*(int *)(param_1 + 10) + 0x44) == '\x03')
     ) {
    local_11 = 0xb;
  }
  else if (*(int *)(*(int *)(param_1 + 10) + 0x40) == 0) {
    local_11 = 4;
  }
  else {
    local_11 = 9;
  }
  FUN_600aa648(param_1 + 10);
  local_2c2 = *param_1;
  (*(code *)**(undefined4 **)(param_1 + 6))(local_11,local_2c4);
  return;
}


