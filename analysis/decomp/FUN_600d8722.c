// 600d8722  FUN_600d8722  size=86 bytes
// --- callers ---
//   600d87c0 FUN_600d87c0
//   600d87f4 FUN_600d87f4
// --- callees ---
//   600d847c FUN_600d847c
//   600d84ce FUN_600d84ce
//   600d866a FUN_600d866a
//   6013cef8 thunk_EXT_FUN_0000737c


void FUN_600d8722(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  
  cVar1 = FUN_600d84ce(param_1,0,0x42,200,param_4);
  if (cVar1 == '\0') {
    thunk_EXT_FUN_0000737c(100);
    cVar1 = FUN_600d847c(param_1,0x10,0);
    if (cVar1 == '\0') {
      thunk_EXT_FUN_0000737c(5);
      cVar1 = FUN_600d84ce(param_1,0,0x20,200,param_4);
      if (cVar1 == '\0') {
        thunk_EXT_FUN_0000737c(5);
        FUN_600d866a(param_1,0x2000,0x2000,4000);
      }
    }
  }
  return;
}


