// 600d9988  FUN_600d9988  size=36 bytes
// --- callers ---
//   60077140 FUN_60077140
// --- callees ---
//   60071348 FUN_60071348


void FUN_600d9988(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint local_c;
  
  local_c = param_2;
  cVar1 = FUN_60071348(0x2f,&local_c,param_3,param_4,param_1);
  if (cVar1 == '\0') {
    *(bool *)param_1 = (local_c & 7) == 3;
  }
  return;
}


