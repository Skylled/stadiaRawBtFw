// 600fdc8e  FUN_600fdc8e  size=110 bytes
// --- callers ---
// --- callees ---
//   600f3caa FUN_600f3caa
//   60094d24 FUN_60094d24


void FUN_600fdc8e(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_2b8 [688];
  
  iVar1 = FUN_600f3caa(*(undefined1 *)(*(int *)(param_1 + 0xc) + 5),param_2 + 8,1);
  if (iVar1 == 0) {
    if (**(int **)(param_1 + 0xc) != 0) {
      local_2b8[0] = 0x85;
      (*(code *)**(undefined4 **)(param_1 + 0xc))(0xe,local_2b8);
    }
  }
  else {
    FUN_60094d24(param_1,0x1d03,param_2);
  }
  return;
}


