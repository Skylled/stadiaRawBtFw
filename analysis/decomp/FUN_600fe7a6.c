// 600fe7a6  FUN_600fe7a6  size=88 bytes
// --- callers ---
//   600c64c8 FUN_600c64c8
// --- callees ---
//   600aa648 FUN_600aa648


void FUN_600fe7a6(undefined2 *param_1,int param_2)

{
  undefined1 local_2b8 [2];
  undefined2 local_2b6;
  
  FUN_600aa648(param_1 + 10);
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
  local_2b6 = *param_1;
  local_2b8[0] = *(undefined1 *)(param_2 + 9);
  (*(code *)**(undefined4 **)(param_1 + 6))(0xc,local_2b8);
  return;
}


