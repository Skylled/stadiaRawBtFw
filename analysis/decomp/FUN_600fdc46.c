// 600fdc46  FUN_600fdc46  size=72 bytes
// --- callers ---
// --- callees ---
//   600ef3cc FUN_600ef3cc


void FUN_600fdc46(int param_1,undefined4 param_2)

{
  undefined1 local_2b8 [688];
  
  if (**(int **)(param_1 + 0xc) != 0) {
    local_2b8[0] = 0;
    (*(code *)**(undefined4 **)(param_1 + 0xc))
              (0xe,local_2b8,local_2b8,(code *)**(undefined4 **)(param_1 + 0xc),param_2);
  }
  FUN_600ef3cc(param_1);
  return;
}


