// 600f46b4  FUN_600f46b4  size=58 bytes
// --- callers ---
//   600f46ee FUN_600f46ee
//   600f3b0a FUN_600f3b0a
//   600f4a3c FUN_600f4a3c
// --- callees ---
//   600ffada FUN_600ffada
//   600b00b4 FUN_600b00b4


void FUN_600f46b4(undefined4 param_1,int param_2,undefined1 param_3)

{
  undefined1 local_19;
  int local_18;
  undefined4 local_14;
  char local_9;
  
  local_19 = param_3;
  local_18 = param_2;
  local_14 = param_1;
  local_9 = FUN_600ffada(param_1,*(undefined2 *)(param_2 + 0x26),0x18,&local_19);
  if (local_9 != '\0') {
    FUN_600b00b4(local_18,local_9,0);
  }
  return;
}


