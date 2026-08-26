// 600d45ba  FUN_600d45ba  size=42 bytes
// --- callers ---
//   600d45e4 thunk_FUN_600d45ba
// --- callees ---
//   6005e39c FUN_6005e39c
//   6010138c FUN_6010138c
//   600cbccc FUN_600cbccc


void FUN_600d45ba(undefined4 param_1,int param_2)

{
  undefined1 auStack_220 [512];
  undefined1 auStack_20 [20];
  
  FUN_6005e39c(auStack_220);
  if (*(char *)(param_2 + 0xb) == '\0') {
    FUN_600cbccc(auStack_220,param_2);
  }
  FUN_6010138c(param_1,auStack_20);
  return;
}


