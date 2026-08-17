// 600ac6ac  FUN_600ac6ac  size=82 bytes
// --- callers ---
//   600f4a3c FUN_600f4a3c
// --- callees ---
//   600b00b4 FUN_600b00b4


void FUN_600ac6ac(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 char param_5)

{
  char local_9;
  
  local_9 = param_5;
  switch(param_3) {
  case 4:
  case 6:
  case 8:
  case 0x10:
    if (param_5 == '\n') {
      local_9 = '\0';
    }
    break;
  default:
  }
  FUN_600b00b4(param_2,local_9,0);
  return;
}


