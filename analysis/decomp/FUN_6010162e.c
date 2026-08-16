// 6010162e  FUN_6010162e  size=46 bytes
// --- callers ---
//   60058754 buffer__60058754
//   600cbebc logger__600cbebc
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2


void FUN_6010162e(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x174);
  thunk_EXT_FUN_0000b4c2(puVar2);
  for (puVar1 = (undefined4 *)(param_1 + 0x15c); puVar2 != puVar1; puVar1 = puVar1 + 2) {
    (*(code *)*puVar1)(puVar1[1],param_2);
  }
  thunk_EXT_FUN_00007d10(puVar2);
  return;
}


