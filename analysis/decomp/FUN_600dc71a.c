// 600dc71a  FUN_600dc71a  size=34 bytes
// --- callers ---
//   600dc5ee FUN_600dc5ee
// --- callees ---
//   600dc712 FUN_600dc712
//   6013d310 thunk_EXT_FUN_0000b52a


int FUN_600dc71a(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 8);
  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar2 != puVar1; puVar1 = puVar1 + 3) {
    FUN_600dc712(*puVar1);
  }
  if (*(int *)(param_1 + 4) != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  return param_1;
}


