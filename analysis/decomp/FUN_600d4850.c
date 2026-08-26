// 600d4850  FUN_600d4850  size=44 bytes
// --- callers ---
// --- callees ---
//   6013d058 thunk_EXT_FUN_00000960
//   6013d178 thunk_EXT_FUN_00008996
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013cf40 thunk_EXT_FUN_00007d10


undefined4 FUN_600d4850(int param_1)

{
  undefined4 uVar1;
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x1c);
  if (*(char *)(param_1 + 0x19) == '\0') {
    uVar1 = 9;
  }
  else {
    thunk_EXT_FUN_00000960();
    uVar1 = thunk_EXT_FUN_00008996();
  }
  thunk_EXT_FUN_00007d10(param_1 + 0x1c);
  return uVar1;
}


