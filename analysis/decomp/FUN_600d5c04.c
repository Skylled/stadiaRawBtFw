// 600d5c04  FUN_600d5c04  size=18 bytes
// --- callers ---
//   600d5cfc FUN_600d5cfc
//   600d5c6a FUN_600d5c6a
//   600d5cc4 FUN_600d5cc4
//   600d5d02 FUN_600d5d02
//   600d5c16 FUN_600d5c16
//   600d5cbe FUN_600d5cbe
// --- callees ---


bool FUN_600d5c04(int *param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(char *)((int)param_1 + 5) != '\0') {
    bVar1 = *(byte *)(*param_1 + 2) == param_2;
  }
  return bVar1;
}


