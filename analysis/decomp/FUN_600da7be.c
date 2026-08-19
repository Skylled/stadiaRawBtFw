// 600da7be  FUN_600da7be  size=62 bytes
// --- callers ---
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   60075c50 headphone_state_machine__60075c50
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60075d78 headphone_state_machine__60075d78


undefined4 FUN_600da7be(int param_1,int param_2)

{
  undefined4 uVar1;
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x80);
  if (param_2 == 1) {
    uVar1 = headphone_state_machine__60075c50(*(undefined4 *)(param_1 + 0x7c),param_1);
  }
  else if (param_2 == 2) {
    uVar1 = headphone_state_machine__60075d78(*(undefined4 *)(param_1 + 0x7c),param_1);
  }
  else {
    uVar1 = 1;
  }
  thunk_EXT_FUN_00007d10(param_1 + 0x80);
  return uVar1;
}


