// 600eeffa  FUN_600eeffa  size=162 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ef2da FUN_600ef2da
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600eeffa(undefined2 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 local_2c0 [2];
  undefined1 auStack_2bc [684];
  int local_10;
  int local_c;
  
  local_10 = *(int *)(param_1 + 8);
  for (local_c = *(int *)(local_10 + 0xc); local_c != 0; local_c = *(int *)(local_c + 0x28)) {
    iVar1 = FUN_600ef2da(param_2,local_c,0);
    if ((iVar1 != 0) && (**(int **)(param_1 + 6) != 0)) {
      thunk_EXT_FUN_0000b5ba(local_2c0,0,0x2b0);
      local_2c0[0] = *param_1;
      thunk_EXT_FUN_0000b572(auStack_2bc,local_c,0x1c);
      (*(code *)**(undefined4 **)(param_1 + 6))(7,local_2c0);
    }
  }
  return;
}


