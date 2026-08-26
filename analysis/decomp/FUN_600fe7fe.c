// 600fe7fe  FUN_600fe7fe  size=142 bytes
// --- callers ---
//   600c64c8 FUN_600c64c8
// --- callees ---
//   600aa648 FUN_600aa648


void FUN_600fe7fe(undefined2 *param_1,int param_2)

{
  undefined1 local_2b8 [2];
  undefined2 local_2b6;
  undefined2 local_2b4;
  
  FUN_600aa648(param_1 + 10);
  if ((*(int *)(param_2 + 0xc) != 0) && (*(char *)(param_2 + 9) == '\0')) {
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x34) = **(undefined2 **)(param_2 + 0xc);
  }
  *(undefined1 *)((int)param_1 + 0x1d) = *(undefined1 *)(param_2 + 9);
  local_2b6 = *param_1;
  local_2b8[0] = *(undefined1 *)(param_2 + 9);
  local_2b4 = *(undefined2 *)(*(int *)(param_1 + 8) + 0x34);
  (*(code *)**(undefined4 **)(param_1 + 6))(0x11,local_2b8);
  return;
}


