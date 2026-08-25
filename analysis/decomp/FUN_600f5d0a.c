// 600f5d0a  FUN_600f5d0a  size=170 bytes
// --- callers ---
// --- callees ---
//   600af814 FUN_600af814
//   600f77cc FUN_600f77cc
//   600af8ac FUN_600af8ac
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f610e FUN_600f610e
//   600f7912 FUN_600f7912


void FUN_600f5d0a(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined1 auStack_58 [2];
  undefined1 local_56;
  undefined2 local_54;
  int local_10;
  char local_9;
  
  local_9 = '\0';
  local_10 = FUN_600af814(param_1,1);
  if (local_10 == 0) {
    local_10 = FUN_600af8ac(param_1,1);
    if (local_10 == 0) {
      local_9 = '\x04';
    }
    else {
      *(undefined2 *)(local_10 + 0x18) = param_2;
    }
  }
  else {
    local_9 = '\x04';
  }
  FUN_600f77cc(param_1,param_4,param_2,local_9,0);
  if (local_9 == '\0') {
    FUN_600f610e(local_10,3);
    thunk_EXT_FUN_0000b5ba(auStack_58,0,0x48);
    local_56 = 1;
    local_54 = 0x205;
    FUN_600f7912(param_2,auStack_58);
  }
  return;
}


