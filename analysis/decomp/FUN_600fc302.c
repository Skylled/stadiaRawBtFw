// 600fc302  FUN_600fc302  size=126 bytes
// --- callers ---
//   600c0e14 FUN_600c0e14
//   600c15a8 FUN_600c15a8
// --- callees ---
//   600fbc02 FUN_600fbc02
//   600c0ed4 FUN_600c0ed4
//   6009ab94 FUN_6009ab94
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600fc9c4 FUN_600fc9c4
//   600c1a34 FUN_600c1a34


void FUN_600fc302(int param_1)

{
  int iVar1;
  undefined1 local_2d;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [16];
  undefined1 auStack_18 [16];
  
  local_2d = 8;
  FUN_6009ab94(auStack_18);
  iVar1 = FUN_600fbc02(auStack_18,0x10,param_1 + 0x1d6,2,auStack_2c);
  if (iVar1 == 0) {
    FUN_600c1a34(param_1,0x17,&local_2d);
  }
  else {
    FUN_600fc9c4(*(undefined1 *)(param_1 + 0x1b1),auStack_28);
    thunk_EXT_FUN_0000b572(param_1 + 0x1c6,auStack_28,0x10);
    FUN_600c0ed4(param_1,0);
  }
  return;
}


