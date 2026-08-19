// 600d995c  FUN_600d995c  size=44 bytes
// --- callers ---
//   600d7cc4 FUN_600d7cc4
//   60077140 FUN_60077140
// --- callees ---
//   60071348 FUN_60071348


void FUN_600d995c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint local_c;
  
  local_c = 0;
  cVar1 = FUN_60071348(6,&local_c,param_3,0,param_1);
  if (cVar1 == '\0') {
    *(bool *)param_1 = (local_c & 0xc00000) != 0xc00000;
  }
  return;
}


