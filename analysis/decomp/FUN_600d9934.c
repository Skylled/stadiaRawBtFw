// 600d9934  FUN_600d9934  size=40 bytes
// --- callers ---
//   600d7cdc FUN_600d7cdc
//   60077140 FUN_60077140
// --- callees ---
//   60071348 FUN_60071348


void FUN_600d9934(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 local_c;
  
  local_c = 0;
  cVar1 = FUN_60071348(0x26,&local_c,param_3,0,param_1);
  if (cVar1 == '\0') {
    *param_1 = ((byte)((uint)local_c >> 8) ^ 1) & 1;
  }
  return;
}


